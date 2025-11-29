#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "../include/dono_veiculo.h"
#include "../include/validacoes.h"
#include "../include/veiculos.h"

// ================|
// Funções de lista| 
// ================|

DonoVeiculoLista* newDonoVeiculoList(void) {
    DonoVeiculoLista* l = (DonoVeiculoLista*) malloc(sizeof(DonoVeiculoLista));
    if (l == NULL) {
        fprintf(stderr, "Memoria indisponivel\n");
        exit(EXIT_FAILURE);
    }
    l->prox = NULL;
    return l;
}

void appendDonoVeiculo(DonoVeiculoLista *l, DonoVeiculo *data) {
    DonoVeiculoLista* novo = (DonoVeiculoLista*) malloc(sizeof(DonoVeiculoLista));
    if (novo == NULL) {
        fprintf(stderr, "Memoria indisponivel\n");
        exit(EXIT_FAILURE);
    }

    
    strcpy(novo->cpf, data->cpf);
    strcpy(novo->telefone, data->telefone);
    strcpy(novo->nome, data->nome);
    strcpy(novo->placa, data->placa);
    novo->status = data->status;

    novo->prox = NULL;

    DonoVeiculoLista* temp = l;
    while (temp->prox != NULL) {
        temp = temp->prox;
    }
    temp->prox = novo;
}

void preencherListaDonoVeiculo(DonoVeiculoLista *lista) {
    int encontrado = 0;
    DonoVeiculo leitura;
    FILE *arq = fopen(ARQ_DONO_VEICULO, "rb");
    if (arq == NULL) {
        
        return;
    }

    while (fread(&leitura, sizeof(DonoVeiculo), 1, arq)) {
        if (leitura.status == 1) {
            encontrado = 1;
            
            DonoVeiculo dvTemp;
            strcpy(dvTemp.cpf, leitura.cpf);
            strcpy(dvTemp.telefone, leitura.telefone);
            strcpy(dvTemp.nome, leitura.nome);
            strcpy(dvTemp.placa, leitura.placa);
            dvTemp.status = leitura.status;

            appendDonoVeiculo(lista, &dvTemp);
        }
    }

    if (!encontrado) {
        
        
    }

    fclose(arq);
    return;
}


void preencherListaDonoVeiculo_Tudo(DonoVeiculoLista *lista) {
    int encontrouAlgo = 0;
    DonoVeiculo leitura;
    FILE *arq = fopen(ARQ_DONO_VEICULO, "rb");
    if (arq == NULL) {
        return;
    }

    while (fread(&leitura, sizeof(DonoVeiculo), 1, arq)) {
        encontrouAlgo = 1;
        DonoVeiculo dvTemp;
        strcpy(dvTemp.cpf, leitura.cpf);
        strcpy(dvTemp.telefone, leitura.telefone);
        strcpy(dvTemp.nome, leitura.nome);
        strcpy(dvTemp.placa, leitura.placa);
        dvTemp.status = leitura.status;

        appendDonoVeiculo(lista, &dvTemp);
    }

    if (!encontrouAlgo) {
        
    }

    fclose(arq);
    return;
}

void clearDonoVeiculo(DonoVeiculoLista* l) {
    DonoVeiculoLista* temp = l->prox;
    DonoVeiculoLista* next;
    while (temp != NULL) {
        next = temp->prox;
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

    DonoVeiculoLista *temp = l->prox;
    while (temp != NULL) {
        
        DonoVeiculo dvWrite;
        strcpy(dvWrite.cpf, temp->cpf);
        strcpy(dvWrite.telefone, temp->telefone);
        strcpy(dvWrite.nome, temp->nome);
        strcpy(dvWrite.placa, temp->placa);
        dvWrite.status = temp->status;

        fwrite(&dvWrite, sizeof(DonoVeiculo), 1, arq);
        temp = temp->prox;
    }

    fclose(arq);
    return 1;
}

/* ===========================================================
   Função auxiliar - verifica se o veículo existe no arquivo
   =========================================================== */
int verifica_veiculo_existe(const char *placa) {
    FILE *arq = fopen("dados/veiculos.dat", "rb");
    Veiculos v;

    if (!arq) return 0;

    while (fread(&v, sizeof(Veiculos), 1, arq)) {
        if (strcmp(v.placa, placa) == 0 && v.status == True) {
            fclose(arq);
            return 1;
        }
    }

    fclose(arq);
    return 0;
}

/* ===========================================================
   Menu principal
   =========================================================== */
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

/* ===========================================================
   Cadastrar dono do veículo
   - carrega lista de ativos
   - append
   - grava lista inteira
   =========================================================== */
void add_dono_veiculo(void) {
    system("clear||cls");
    verifica_diretorio_dados();

    FILE *arq = fopen(ARQ_DONO_VEICULO, "ab");
    if (!arq) {
        printf("\nERRO ao abrir o arquivo de donos!\nTecle ENTER...");
        getchar();
        return;
    }
    fclose(arq);

    DonoVeiculo dono;
    char placa[12];

    printf("\n====================== Cadastro do Dono ======================\n\n");

    Ler_CPF(dono.cpf);
    Ler_Telefone(dono.telefone);
    Ler_Nome(dono.nome, sizeof(dono.nome));

    /* Solicitar placa do carro */
    printf("\nInforme a PLACA do carro: ");
    Ler_Placa(placa);

    if (!verifica_veiculo_existe(placa)) {
        printf("\n>>> ERRO: Este veículo NÃO existe! Cadastre-o primeiro no módulo Veículos.\n");
        printf("Tecle ENTER para voltar...");
        getchar();
        return;
    }

    strcpy(dono.placa, placa);
    dono.status = True;

    /* carregar lista atual de ativos, adicionar e gravar lista inteira */
    DonoVeiculoLista *lista = newDonoVeiculoList();
    preencherListaDonoVeiculo(lista); /* carrega apenas ativos */
    appendDonoVeiculo(lista, &dono);

    if (gravarListaDonoVeiculoEmArquivo(lista)) {
        printf("\nDono cadastrado com sucesso!\n");
        printf("CPF: %s\nNome: %s\nTelefone: %s\nPlaca: %s\n",
               dono.cpf, dono.nome, dono.telefone, dono.placa);
    } else {
        printf("\nErro ao gravar o arquivo de donos!\n");
    }

    printf("\nTecle ENTER para continuar...");
    getchar();
    deleteDonoVeiculo(lista);
}

/* ===========================================================
   Exibir dono (busca por CPF)
   =========================================================== */
void exib_dono_veiculo(void) {
    system("clear||cls");

    FILE *arq = fopen(ARQ_DONO_VEICULO, "rb");
    if (!arq) {
        printf("\nNenhum dono cadastrado ainda.\nTecle ENTER...");
        getchar();
        return;
    }
    fclose(arq);

    char cpf_busca[15];
    int achou = 0;

    printf("\nDigite o CPF para buscar: ");
    Ler_CPF(cpf_busca);

    DonoVeiculoLista *lista = newDonoVeiculoList();
    preencherListaDonoVeiculo(lista);

    DonoVeiculoLista *temp = lista->prox;
    while (temp != NULL) {
        if (strcmp(temp->cpf, cpf_busca) == 0 && temp->status == True) {
            achou = 1;
            printf("\n=== Dono Encontrado ===\n");
            printf("CPF: %s\nNome: %s\nTelefone: %s\nPlaca: %s\n",
                   temp->cpf, temp->nome, temp->telefone, temp->placa);
            break;
        }
        temp = temp->prox;
    }

    deleteDonoVeiculo(lista);

    if (!achou)
        printf("\nCPF não encontrado!\n");

    printf("Tecle ENTER...");
    getchar();
}

/* ===========================================================
   Alterar dono
   - carrega lista de ativos, altera nó, regrava arquivo
   =========================================================== */
void alterar_dono_veiculo(void) {
    system("clear||cls");

    FILE *arq = fopen(ARQ_DONO_VEICULO, "rb");
    if (!arq) {
        printf("\nErro ao abrir arquivo!\nTecle ENTER...");
        getchar();
        return;
    }
    fclose(arq);

    char cpf_busca[15];
    int achou = 0;

    printf("\nCPF para alterar: ");
    Ler_CPF(cpf_busca);

    DonoVeiculoLista *lista = newDonoVeiculoList();
    preencherListaDonoVeiculo(lista);

    DonoVeiculoLista *temp = lista->prox;
    while (temp != NULL) {
        if (strcmp(temp->cpf, cpf_busca) == 0 && temp->status == True) {
            achou = 1;

            Ler_Telefone(temp->telefone);
            Ler_Nome(temp->nome, sizeof(temp->nome));

            break;
        }
        temp = temp->prox;
    }

    if (achou) {
        if (gravarListaDonoVeiculoEmArquivo(lista))
            printf("\nDados alterados com sucesso!\n");
        else
            printf("\nErro ao gravar alterações no arquivo!\n");
    } else {
        printf("\nCPF não encontrado!\n");
    }

    deleteDonoVeiculo(lista);
    printf("Tecle ENTER...");
    getchar();
}

/* ===========================================================
   Exclusão lógica
   - marca status = 0 e regrava arquivo
   =========================================================== */
void exclu_logica_dono_veiculo(void) {
    system("clear||cls");

    FILE *arq = fopen(ARQ_DONO_VEICULO, "rb");
    if (!arq) {
        printf("\nErro ao abrir arquivo!\nTecle ENTER...");
        getchar();
        return;
    }
    fclose(arq);

    char cpf_busca[15];
    int achou = 0;

    printf("\nCPF para excluir: ");
    Ler_CPF(cpf_busca);

    /* carregar lista (ativos) */
    DonoVeiculoLista *lista = newDonoVeiculoList();
    preencherListaDonoVeiculo(lista);

    DonoVeiculoLista *temp = lista->prox;
    while (temp != NULL) {
        if (strcmp(temp->cpf, cpf_busca) == 0 && temp->status == True) {
            temp->status = False;
            achou = 1;
            break;
        }
        temp = temp->prox;
    }

    if (achou) {
        if (gravarListaDonoVeiculoEmArquivo(lista))
            printf("\nExclusão lógica feita.\n");
        else
            printf("\nErro ao gravar arquivo após exclusão lógica.\n");
    } else {
        printf("\nCPF não encontrado!\n");
    }

    deleteDonoVeiculo(lista);
    printf("Tecle ENTER...");
    getchar();
}

/* ===========================================================
   Recuperar registro
   - carrega TODOS os registros (ativos e inativos), marca ativo e regrava
   =========================================================== */
void recu_registro_dono_veiculo(void) {
    system("clear||cls");

    FILE *arq = fopen(ARQ_DONO_VEICULO, "rb");
    if (!arq) {
        printf("\nErro ao abrir arquivo!\nTecle ENTER...");
        getchar();
        return;
    }
    fclose(arq);

    char cpf_busca[15];
    int achou = 0;

    printf("\nCPF para recuperar: ");
    Ler_CPF(cpf_busca);

    DonoVeiculoLista *lista = newDonoVeiculoList();
    preencherListaDonoVeiculo_Tudo(lista);

    DonoVeiculoLista *temp = lista->prox;
    while (temp != NULL) {
        if (strcmp(temp->cpf, cpf_busca) == 0 && temp->status == False) {
            temp->status = True;
            achou = 1;
            break;
        }
        temp = temp->prox;
    }

    if (achou) {
        if (gravarListaDonoVeiculoEmArquivo(lista))
            printf("\nRegistro recuperado!\n");
        else
            printf("\nErro ao gravar arquivo ao recuperar registro.\n");
    } else {
        printf("\nCPF não encontrado ou já está ativo!\n");
    }

    deleteDonoVeiculo(lista);
    printf("Tecle ENTER...");
    getchar();
}
