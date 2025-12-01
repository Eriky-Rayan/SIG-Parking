#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "../include/veiculos.h"
#include "../include/validacoes.h"

#define ARQ_VEICULOS "dados/veiculos.dat"


// ============================
// Funções de lista dinâmica
// ============================
VeiculoLista* newVeiculoList(void) {
    VeiculoLista* l = (VeiculoLista*) malloc(sizeof(VeiculoLista));
    if (!l) {
        fprintf(stderr, "Memoria indisponivel\n");
        exit(EXIT_FAILURE);
    }
    l->prox = NULL;
    return l;
}

void appendVeiculo(VeiculoLista *l, Veiculos *data) {
    VeiculoLista* novo = (VeiculoLista*) malloc(sizeof(VeiculoLista));
    if (!novo) {
        fprintf(stderr, "Memoria indisponivel\n");
        exit(EXIT_FAILURE);
    }

    novo->dados = *data;  // copia o struct Veiculos para o nó
    novo->prox = NULL;

    VeiculoLista* temp = l;
    while (temp->prox != NULL) temp = temp->prox;
    temp->prox = novo;
}

void preencherListaVeiculos(VeiculoLista *lista) {
    FILE *arq = fopen(ARQ_VEICULOS, "rb");
    if (!arq) return;

    Veiculos v;
    while (fread(&v, sizeof(Veiculos), 1, arq)) {
        if (v.status == True) appendVeiculo(lista, &v);
    }
    fclose(arq);
}

void preencherListaVeiculos_Tudo(VeiculoLista *lista) {
    FILE *arq = fopen(ARQ_VEICULOS, "rb");
    if (!arq) return;

    Veiculos v;
    while (fread(&v, sizeof(Veiculos), 1, arq)) {
        appendVeiculo(lista, &v);
    }
    fclose(arq);
}

void clearVeiculos(VeiculoLista* l) {
    VeiculoLista* temp = l->prox;
    while (temp) {
        VeiculoLista* next = temp->prox;
        free(temp);
        temp = next;
    }
    l->prox = NULL;
}

void deleteVeiculos(VeiculoLista* l) {
    clearVeiculos(l);
    free(l);
}

int gravarListaVeiculosEmArquivo(VeiculoLista* l) {
    FILE *arq = fopen(ARQ_VEICULOS, "wb");
    if (!arq) return 0;

    VeiculoLista* temp = l->prox;
    while (temp) {
        Veiculos vWrite = temp->dados;
        fwrite(&vWrite, sizeof(Veiculos), 1, arq);
        temp = temp->prox;
    }

    fclose(arq);
    return 1;
}

// ========================================
// Menu principal de veículos
// ========================================
void switch_veiculos(void) {
    char op;
    do {
        op = veiculos();
        switch (op) {
            case '1': add_veiculos(); break;
            case '2': exib_veiculo(); break;
            case '3': alterar_veiculo(); break;
            case '4': exclu_logica_veiculo(); break;
            case '5': recu_registro_veiculo(); break;
        }
    } while (op != '0');
}

// ========================================
// Exibe menu e retorna opção escolhida
// ========================================
char veiculos(void) {
    system("clear||cls");
    char op;

    printf("\n");
    printf("=============================================================\n");
    printf("||                    - SIG-Parking -                      ||\n");
    printf("=============================================================\n");
    printf("|| [1] -> Cadastrar Veículo                                ||\n");
    printf("|| [2] -> Exibir Dados do Veículo                          ||\n");
    printf("|| [3] -> Alterar Dados do Veículo                         ||\n");
    printf("|| [4] -> Excluir Veículo                                  ||\n");
    printf("|| [5] -> Recuperar Registro de Veículo                    ||\n");
    printf("|| [0] -> Voltar ao Menu Principal                         ||\n");
    printf("=============================================================\n");

    Ler_Opcao_Menu(&op);
    return op;
}

// ========================================
// Função: Cadastrar Veículo
// ========================================
void add_veiculos(void) {
    system("clear||cls");
    verifica_diretorio_dados();

    Veiculos veiculo;

    printf("\n=== Cadastro de Veículo ===\n");
    Ler_Placa(veiculo.placa);
    Ler_Tipo(veiculo.tipo);

    printf(" >>Digite o modelo: ");
    scanf(" %19[^\n]", veiculo.model);
    getchar();

    printf(" >>Digite a cor: ");
    scanf(" %14[^\n]", veiculo.cor);
    getchar();

    Ler_num_andar(&veiculo.andar);

    printf(" >>Digite o número da vaga nesse andar: ");
    scanf("%d", &veiculo.vaga);
    getchar();

    Ler_CPF(veiculo.cpf);

    veiculo.status = True;

    // Carrega lista existente (apenas ativos), adiciona novo e grava tudo
    VeiculoLista* lista = newVeiculoList();
    preencherListaVeiculos(lista);
    appendVeiculo(lista, &veiculo);

    if (gravarListaVeiculosEmArquivo(lista))
        printf("\nVeículo cadastrado com sucesso!\n");
    else
        printf("\nErro ao gravar arquivo!\n");

    printf("Placa: %s | Tipo: %s | Modelo: %s | Cor: %s | Andar: %d | Vaga: %d | CPF: %s\n",
           veiculo.placa, veiculo.tipo, veiculo.model, veiculo.cor,
           veiculo.andar, veiculo.vaga, veiculo.cpf);

    deleteVeiculos(lista);

    printf("\n\t>>Tecle <ENTER> para continuar...");
    getchar();
}

// ========================================
// Função: Exibir Veículo
// ========================================
void exib_veiculo(void) {
    system("clear||cls");

    VeiculoLista* lista = newVeiculoList();
    preencherListaVeiculos(lista);

    VeiculoLista* temp;
    char placa_lida[TAM_PLACA];
    int encontrado = 0;

    printf("\n=========== Exibir Veículo ===========\n");
    Ler_Placa(placa_lida);

    temp = lista->prox;
    while (temp) {
        if ((strcmp(temp->dados.placa, placa_lida) == 0) && temp->dados.status) {
            encontrado = 1;
            printf("\n<<< Veículo encontrado >>>\n");
            printf("Placa: %s\nTipo: %s\nModelo: %s\nCor: %s\nAndar: %d\nVaga: %d\nCPF: %s\n",
                   temp->dados.placa, temp->dados.tipo, temp->dados.model,
                   temp->dados.cor, temp->dados.andar, temp->dados.vaga, temp->dados.cpf);
            break;
        }
        temp = temp->prox;
    }

    deleteVeiculos(lista);

    if (!encontrado)
        printf("\nPlaca não encontrada!\n");

    printf("\n\t>>Tecle <ENTER> para continuar...");
    getchar();
}

// ========================================
// Função: Alterar Veículo
// ========================================
void alterar_veiculo(void) {
    system("clear||cls");

    VeiculoLista* lista = newVeiculoList();
    preencherListaVeiculos(lista);

    VeiculoLista* temp;
    char placa_lida[TAM_PLACA];
    int encontrado = 0;

    printf("\n=========== Alterar Veículo ===========\n");
    Ler_Placa(placa_lida);

    temp = lista->prox;
    while (temp) {
        if ((strcmp(temp->dados.placa, placa_lida) == 0) && temp->dados.status) {
            encontrado = 1;
            printf("\n--- Informe os novos dados ---\n");

            Ler_Tipo(temp->dados.tipo);

            printf(" >>Digite o modelo: ");
            scanf(" %19[^\n]", temp->dados.model);
            getchar();

            printf(" >>Digite a cor: ");
            scanf(" %14[^\n]", temp->dados.cor);
            getchar();

            Ler_num_andar(&temp->dados.andar);

            printf(" >>Digite o número da vaga nesse andar: ");
            scanf("%d", &temp->dados.vaga);
            getchar();

            Ler_CPF(temp->dados.cpf);

            break;
        }
        temp = temp->prox;
    }

    if (encontrado) {
        if (gravarListaVeiculosEmArquivo(lista))
            printf("\nDados do veículo alterados com sucesso!\n");
        else
            printf("\nErro ao gravar arquivo!\n");
    } else {
        printf("\nPlaca não encontrada!\n");
    }

    deleteVeiculos(lista);
    printf("\t>>Tecle <ENTER> para continuar...");
    getchar();
}

// ========================================
// Função: Exclusão lógica
// ========================================
void exclu_logica_veiculo(void) {
    system("clear||cls");

    VeiculoLista* lista = newVeiculoList();
    preencherListaVeiculos(lista);

    VeiculoLista* temp;
    char placa_lida[TAM_PLACA];
    int encontrado = 0;

    printf("\n=========== Excluir Veículo ===========\n");
    Ler_Placa(placa_lida);

    temp = lista->prox;
    while (temp) {
        if ((strcmp(temp->dados.placa, placa_lida) == 0) && temp->dados.status) {
            temp->dados.status = False;
            encontrado = 1;
            break;
        }
        temp = temp->prox;
    }

    if (encontrado) {
        if (gravarListaVeiculosEmArquivo(lista))
            printf("\nVeículo excluído logicamente.\n");
        else
            printf("\nErro ao gravar arquivo!\n");
    } else {
        printf("\nPlaca não encontrada!\n");
    }

    deleteVeiculos(lista);
    printf("\t>>Tecle <ENTER> para continuar...");
    getchar();
}

// ========================================
// Função: Recuperar veículo excluído
// ========================================
void recu_registro_veiculo(void) {
    system("clear||cls");

    VeiculoLista* lista = newVeiculoList();
    preencherListaVeiculos_Tudo(lista); // carrega todos, inclusive inativos

    VeiculoLista* temp;
    char placa_lida[TAM_PLACA];
    int encontrado = 0;

    printf("\n=========== Recuperar Veículo ===========\n");
    Ler_Placa(placa_lida);

    temp = lista->prox;
    while (temp) {
        if ((strcmp(temp->dados.placa, placa_lida) == 0) && !temp->dados.status) {
            temp->dados.status = True;
            encontrado = 1;
            break;
        }
        temp = temp->prox;
    }

    if (encontrado) {
        if (gravarListaVeiculosEmArquivo(lista))
            printf("\nVeículo recuperado com sucesso!\n");
        else
            printf("\nErro ao gravar arquivo!\n");
    } else {
        printf("\nPlaca não encontrada!\n");
    }

    deleteVeiculos(lista);
    printf("\t>>Tecle <ENTER> para continuar...");
    getchar();
}
