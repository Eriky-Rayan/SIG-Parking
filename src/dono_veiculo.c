#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "../include/dono_veiculo.h"
#include "../include/validacoes.h"
#include "../include/veiculos.h"

// ============================
// Lista dinâmica inversa
// ============================

DonoVeiculoLista* newDonoVeiculoList(void) {
    DonoVeiculoLista* l = (DonoVeiculoLista*) malloc(sizeof(DonoVeiculoLista));
    if (!l) {
        fprintf(stderr, "Memoria indisponivel\n");
        exit(EXIT_FAILURE);
    }
    l->dados = NULL;
    l->prox = NULL;
    return l;
}

// Inserção no início da lista (inversa)
void appendDonoVeiculo(DonoVeiculoLista *l, DonoVeiculo *data) {
    DonoVeiculoLista* novo = (DonoVeiculoLista*) malloc(sizeof(DonoVeiculoLista));
    if (!novo) {
        fprintf(stderr, "Memoria indisponivel\n");
        exit(EXIT_FAILURE);
    }

    novo->dados = (DonoVeiculo*) malloc(sizeof(DonoVeiculo));
    if (!novo->dados) {
        fprintf(stderr, "Memoria indisponivel\n");
        free(novo);
        exit(EXIT_FAILURE);
    }

    *(novo->dados) = *data;  // copia os dados
    
    novo->prox = l->prox;
    l->prox = novo;
}

void preencherListaDonoVeiculo(DonoVeiculoLista *lista) {
    FILE *arq = fopen(ARQ_DONO_VEICULO, "rb");
    if (!arq) return;

    DonoVeiculo leitura;
    while (fread(&leitura, sizeof(DonoVeiculo), 1, arq)) {
        if (leitura.status == True)
            appendDonoVeiculo(lista, &leitura);
    }
    fclose(arq);
}

void preencherListaDonoVeiculo_Tudo(DonoVeiculoLista *lista) {
    FILE *arq = fopen(ARQ_DONO_VEICULO, "rb");
    if (!arq) return;

    DonoVeiculo leitura;
    while (fread(&leitura, sizeof(DonoVeiculo), 1, arq))
        appendDonoVeiculo(lista, &leitura);
    fclose(arq);
}

void clearDonoVeiculo(DonoVeiculoLista* l) {
    DonoVeiculoLista* temp = l->prox;
    while (temp) {
        DonoVeiculoLista* next = temp->prox;
        free(temp->dados);
        free(temp);
        temp = next;
    }
    l->prox = NULL;
}

void deleteDonoVeiculo(DonoVeiculoLista* l) {
    clearDonoVeiculo(l);
    free(l);
}

int gravarListaDonoVeiculoEmArquivo(DonoVeiculoLista* l) {
    FILE *arq = fopen(ARQ_DONO_VEICULO, "wb");
    if (!arq) return 0;

    DonoVeiculoLista* temp = l->prox;
    while (temp) {
        fwrite(temp->dados, sizeof(DonoVeiculo), 1, arq);
        temp = temp->prox;
    }
    fclose(arq);
    return 1;
}

// ===========================================================
// Verifica se veículo existe no arquivo
// ===========================================================
int verifica_veiculo_existe(const char *placa) {
    FILE *arq = fopen("dados/veiculos.dat", "rb");
    if (!arq) return 0;

    Veiculos v;
    while (fread(&v, sizeof(Veiculos), 1, arq)) {
        if (strcmp(v.placa, placa) == 0 && v.status == True) {
            fclose(arq);
            return 1;
        }
    }
    fclose(arq);
    return 0;
}

// ===========================================================
// Menu principal
// ===========================================================
void switch_dono_veiculo(void) {
    char op;
    do {
        op = dono_veiculo();
        switch (op) {
            case '1': add_dono_veiculo(); break;
            case '2': exib_dono_veiculo(); break;
            case '3': alterar_dono_veiculo(); break;
            case '4': exclu_logica_dono_veiculo(); break;
            case '5': recu_registro_dono_veiculo(); break;
        }
    } while (op != '0');
}

char dono_veiculo(void) {
    system("clear||cls");
    char op;
    printf("\n=====================================================================\n");
    printf("||                       - SIG-Parking -                           ||\n");
    printf("=====================================================================\n");
    printf("||                       Módulo Dono Veículo                       ||\n");
    printf("=====================================================================\n");
    printf("|| [1] -> Cadastrar Dono                                           ||\n");
    printf("|| [2] -> Exibir Dono                                              ||\n");
    printf("|| [3] -> Alterar Dono                                             ||\n");
    printf("|| [4] -> Exclusão lógica                                          ||\n");
    printf("|| [5] -> Recuperar dono                                           ||\n");
    printf("|| [0] -> Voltar                                                   ||\n");
    printf("=====================================================================\n");
    printf(">> Escolha uma opção: ");
    Ler_Opcao_Menu(&op);
    return op;
}

// ===========================================================
// CRUD DONO
// ===========================================================
void add_dono_veiculo(void) {
    system("clear||cls");
    verifica_diretorio_dados();

    DonoVeiculo dono;
    char placa[12];

    printf("\n====================== Cadastro do Dono ======================\n\n");
    Ler_CPF(dono.cpf);
    Ler_Telefone(dono.telefone);
    Ler_Nome(dono.nome, sizeof(dono.nome));

    printf("\nInforme a placa do veiculo: ");
    Ler_Placa(placa);

    if (!verifica_veiculo_existe(placa)) {
        printf("\n>>> ERRO: Veículo não existe!\nTecle ENTER..."); getchar(); return;
    }

    strcpy(dono.placa, placa);
    dono.status = True;

    DonoVeiculoLista* lista = newDonoVeiculoList();
    preencherListaDonoVeiculo(lista);
    appendDonoVeiculo(lista, &dono);

    if (gravarListaDonoVeiculoEmArquivo(lista))
        printf("\nDono cadastrado com sucesso!\n");
    else
        printf("\nErro ao gravar arquivo!\n");

    printf("\nTecle ENTER..."); getchar();
    deleteDonoVeiculo(lista);
}

void exib_dono_veiculo(void) {
    system("clear||cls");
    char cpf_busca[15];
    int achou = 0;

    printf("\nDigite o CPF para buscar: ");
    Ler_CPF(cpf_busca);

    DonoVeiculoLista* lista = newDonoVeiculoList();
    preencherListaDonoVeiculo(lista);

    DonoVeiculoLista* temp = lista->prox;
    while (temp) {
        if (strcmp(temp->dados->cpf, cpf_busca) == 0 && temp->dados->status == True) {
            achou = 1;
            printf("\n=== Dono Encontrado ===\n");
            printf("CPF: %s\nNome: %s\nTelefone: %s\nPlaca: %s\n",
                   temp->dados->cpf, temp->dados->nome, temp->dados->telefone, temp->dados->placa);
            break;
        }
        temp = temp->prox;
    }

    deleteDonoVeiculo(lista);
    if (!achou) printf("\nCPF não encontrado!\n");
    printf("Tecle ENTER..."); getchar();
}

void alterar_dono_veiculo(void) {
    system("clear||cls");
    char cpf_busca[15];
    int achou = 0;

    printf("\nCPF para alterar: ");
    Ler_CPF(cpf_busca);

    DonoVeiculoLista* lista = newDonoVeiculoList();
    preencherListaDonoVeiculo(lista);

    DonoVeiculoLista* temp = lista->prox;
    while (temp) {
        if (strcmp(temp->dados->cpf, cpf_busca) == 0 && temp->dados->status == True) {
            achou = 1;
            Ler_Telefone(temp->dados->telefone);
            Ler_Nome(temp->dados->nome, sizeof(temp->dados->nome));
            break;
        }
        temp = temp->prox;
    }

    if (achou) {
        if (gravarListaDonoVeiculoEmArquivo(lista)) printf("\nDados alterados com sucesso!\n");
        else printf("\nErro ao gravar arquivo!\n");
    } else printf("\nCPF não encontrado!\n");

    deleteDonoVeiculo(lista);
    printf("Tecle ENTER..."); getchar();
}

void exclu_logica_dono_veiculo(void) {
    system("clear||cls");
    char cpf_busca[15];
    int achou = 0;

    printf("\nCPF para excluir: ");
    Ler_CPF(cpf_busca);

    DonoVeiculoLista* lista = newDonoVeiculoList();
    preencherListaDonoVeiculo(lista);

    DonoVeiculoLista* temp = lista->prox;
    while (temp) {
        if (strcmp(temp->dados->cpf, cpf_busca) == 0 && temp->dados->status == True) {
            temp->dados->status = False;
            achou = 1;
            break;
        }
        temp = temp->prox;
    }

    if (achou) {
        if (gravarListaDonoVeiculoEmArquivo(lista)) printf("\nExclusão lógica feita.\n");
        else printf("\nErro ao gravar arquivo.\n");
    } else printf("\nCPF não encontrado!\n");

    deleteDonoVeiculo(lista);
    printf("Tecle ENTER..."); getchar();
}

void recu_registro_dono_veiculo(void) {
    system("clear||cls");
    char cpf_busca[15];
    int achou = 0;

    printf("\nCPF para recuperar: ");
    Ler_CPF(cpf_busca);

    DonoVeiculoLista* lista = newDonoVeiculoList();
    preencherListaDonoVeiculo_Tudo(lista);

    DonoVeiculoLista* temp = lista->prox;
    while (temp) {
        if (strcmp(temp->dados->cpf, cpf_busca) == 0 && temp->dados->status == False) {
            temp->dados->status = True;
            achou = 1;
            break;
        }
        temp = temp->prox;
    }

    if (achou) {
        if (gravarListaDonoVeiculoEmArquivo(lista)) printf("\nRegistro recuperado!\n");
        else printf("\nErro ao gravar arquivo.\n");
    } else printf("\nCPF não encontrado ou já ativo!\n");

    deleteDonoVeiculo(lista);
    printf("Tecle ENTER..."); getchar();
}
