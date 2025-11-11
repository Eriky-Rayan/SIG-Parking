#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include "../include/dono_veiculo.h"
#include "../include/validacoes.h"

typedef struct dono_veiculo DV;

//==============================
// Caminhos dos arquivos
//==============================
#define ARQ_DONO_VEICULO "dados/dono_veiculo.dat"
#define TEMP_DONO_VEICULO "dados/temp_dono_veiculo.dat"

//=====================================
//= Funções do Módulo Dono de Veículo =
//=====================================

void switch_dono_veiculo(void) {
    char op;
    do {
        op = dono_veiculo();
        switch (op) {
            case '1':
                add_dono_veiculo();
                break;
            case '2':
                exib_dono_veiculo();
                break;
            case '3':
                alterar_dono_veiculo();
                break;
            case '4':
                exclu_logica_dono_veiculo();
                break;
            case '5':
                recu_registro_dono_veiculo();
                break;
        }
    } while (op != '0');
}

char dono_veiculo(void) {
    system("clear||cls");

    char op;

    printf("\n");
    printf("=====================================================================================\n");
    printf("||                                  -SIG-Parking-                                 ||\n");
    printf("=====================================================================================\n");
    printf("||                           Módulo Donos dos Veículos                            ||\n");
    printf("=====================================================================================\n");
    printf("|| [1] -> Cadastrar Dono de Veículo                                               ||\n");
    printf("|| [2] -> Exibir Dados do Dono de Veículo                                         ||\n");
    printf("|| [3] -> Alterar Dados do Dono de Veículo                                        ||\n");
    printf("|| [4] -> Excluir logicamente Dono de Veículo                                     ||\n");
    printf("|| [5] -> Recuperar registro Dono de Veículo                                      ||\n");
    printf("|| [0] -> Voltar ao Menu Principal                                                ||\n");
    printf("=====================================================================================\n");
    printf("\t >>Escolha uma opção: ");
    Ler_Opcao_Menu(&op);
    printf("\n");
    return op;
}

void add_dono_veiculo(void) {
    system("clear||cls");
    verifica_diretorio_dados();

    FILE *arq_dono_veiculo;
    DV *dono = (DV*)malloc(sizeof(DV));

    printf("\n====================================================================================\n");
    printf("||                  -Módulo Donos dos Veículos -> Cadastrar Dono-                 ||\n");
    printf("====================================================================================\n");
    printf("\n");

    Ler_CPF(dono->cpf);
    printf("\n");
    Ler_Telefone(dono->telefone);
    printf("\n");
    Ler_Nome(dono->nome, sizeof(dono->nome));
    printf("\n");
    Ler_Quantidade(&dono->quantidade);
    printf("\n");

    dono->status = True;

    arq_dono_veiculo = fopen(ARQ_DONO_VEICULO, "ab");
    if (arq_dono_veiculo == NULL) {
        printf("\t Erro ao abrir o arquivo dos donos dos veículos.\n");
        printf("\t >>Tecle <ENTER> para continuar...\n");
        getchar();
        free(dono);
        return;
    }

    fwrite(dono, sizeof(DV), 1, arq_dono_veiculo);
    fclose(arq_dono_veiculo);

    printf("\nDono do veículo cadastrado com sucesso!\n");
    printf("\nCPF: %s", dono->cpf);
    printf("\nTelefone: %s", dono->telefone);
    printf("\nNome: %s", dono->nome);
    printf("\nQuantidade de veículos: %d\n", dono->quantidade);
    printf("\t >>Tecle <ENTER> para continuar...\n");
    getchar();

    free(dono);
}

void exib_dono_veiculo(void) {
    system("clear||cls");
    verifica_diretorio_dados();

    FILE *arq_dono_veiculo = fopen(ARQ_DONO_VEICULO, "rb");
    DV *dono = (DV*)malloc(sizeof(DV));
    char cpf_lido[15];
    int encontrado = 0;

    printf("\n====================================================================================\n");
    printf("||                 -Módulo Donos dos Veículos -> Exibir Dados-                    ||\n");
    printf("====================================================================================\n");
    printf("\n >>Digite o CPF do dono a ser exibido: \n");
    Ler_CPF(cpf_lido);
    printf("\n");

    if (arq_dono_veiculo == NULL) {
        printf("\t Erro ao abrir o arquivo de dono_veiculo.\n");
        printf("\t >>Tecle <ENTER> para continuar...\n");
        getchar();
        free(dono);
        return;
    }

    while (fread(dono, sizeof(DV), 1, arq_dono_veiculo)) {
        if ((strcmp(dono->cpf, cpf_lido) == 0) && (dono->status)) {
            encontrado = 1;
            printf("\n<<< Dono do veículo encontrado >>>\n");
            printf("CPF: %s\n", dono->cpf);
            printf("Telefone: %s\n", dono->telefone);
            printf("Nome: %s\n", dono->nome);
            printf("Quantidade de veículos: %d\n", dono->quantidade);
            break;
        }
    }

    fclose(arq_dono_veiculo);
    free(dono);

    if (!encontrado)
        printf("\nCPF não encontrado!\n");

    printf("\t >>Tecle <ENTER> para continuar...\n");
    getchar();
}

void alterar_dono_veiculo(void) {
    system("clear||cls");
    verifica_diretorio_dados();

    FILE *arq_dono_veiculo = fopen(ARQ_DONO_VEICULO, "r+b");
    DV *dono = (DV*)malloc(sizeof(DV));
    char cpf_lido[15];
    int encontrado = 0;

    printf("\n====================================================================================\n");
    printf("||                 -Módulo Donos dos Veículos -> Alterar Dados-                   ||\n");
    printf("====================================================================================\n");
    printf("\n >>Digite o CPF do dono a ser alterado: \n");
    Ler_CPF(cpf_lido);
    printf("\n");

    if (arq_dono_veiculo == NULL) {
        printf("\t Erro ao abrir o arquivo de dono_veiculo.\n");
        printf("\t >>Tecle <ENTER> para continuar...\n");
        getchar();
        free(dono);
        return;
    }

    while (fread(dono, sizeof(DV), 1, arq_dono_veiculo)) {
        if ((strcmp(dono->cpf, cpf_lido) == 0) && (dono->status)) {
            encontrado = 1;
            Ler_Telefone(dono->telefone);
            Ler_Nome(dono->nome, sizeof(dono->nome));
            Ler_Quantidade(&dono->quantidade);
            fseek(arq_dono_veiculo, (-1)*sizeof(DV), SEEK_CUR);
            fwrite(dono, sizeof(DV), 1, arq_dono_veiculo);
            break;
        }
    }

    fclose(arq_dono_veiculo);
    free(dono);

    if (encontrado)
        printf("\nDados do dono do veículo alterados com sucesso!\n");
    else
        printf("\nCPF não encontrado!\n");

    printf("\t >>Tecle <ENTER> para continuar...\n");
    getchar();
}

void exclu_logica_dono_veiculo(void) {
    system("clear||cls");
    verifica_diretorio_dados();

    FILE *arq_dono_veiculo = fopen(ARQ_DONO_VEICULO, "r+b");
    DV *dono = (DV*)malloc(sizeof(DV));
    char cpf_lido[15];
    int encontrado = 0;

    printf("\n====================================================================================\n");
    printf("||              -Módulo Donos dos Veículos -> Exclusão Lógica-                    ||\n");
    printf("====================================================================================\n");
    printf("\n >>Digite o CPF do dono a ser excluído: \n");
    Ler_CPF(cpf_lido);
    printf("\n");

    if (arq_dono_veiculo == NULL) {
        printf("\t Erro ao abrir o arquivo de dono_veiculo.\n");
        printf("\t >>Tecle <ENTER> para continuar...\n");
        getchar();
        free(dono);
        return;
    }

    while (fread(dono, sizeof(DV), 1, arq_dono_veiculo)) {
        if ((strcmp(dono->cpf, cpf_lido) == 0) && (dono->status)) {
            dono->status = False;
            encontrado = 1;
            fseek(arq_dono_veiculo, (-1)*sizeof(DV), SEEK_CUR);
            fwrite(dono, sizeof(DV), 1, arq_dono_veiculo);
            break;
        }
    }

    fclose(arq_dono_veiculo);
    free(dono);

    if (encontrado)
        printf("Dono do veículo com CPF %s excluído logicamente com sucesso!\n", cpf_lido);
    else
        printf("\nCPF não encontrado!\n");

    printf("\t >>Tecle <ENTER> para continuar...\n");
    getchar();
}

void recu_registro_dono_veiculo(void) {
    system("clear||cls");
    verifica_diretorio_dados();

    FILE *arq_dono_veiculo = fopen(ARQ_DONO_VEICULO, "r+b");
    DV *dono = (DV*)malloc(sizeof(DV));
    char cpf_lido[15];
    int encontrado = 0;

    printf("\n====================================================================================\n");
    printf("||              -Módulo Donos dos Veículos -> Recuperar Registro-                 ||\n");
    printf("====================================================================================\n");
    printf("\n >>Digite o CPF do dono a ser recuperado: \n");
    Ler_CPF(cpf_lido);
    printf("\n");

    if (arq_dono_veiculo == NULL) {
        printf("\t Erro ao abrir o arquivo de dono_veiculo.\n");
        printf("\t >>Tecle <ENTER> para continuar...\n");
        getchar();
        free(dono);
        return;
    }

    while (fread(dono, sizeof(DV), 1, arq_dono_veiculo)) {
        if ((strcmp(dono->cpf, cpf_lido) == 0) && (!dono->status)) {
            dono->status = True;
            encontrado = 1;
            fseek(arq_dono_veiculo, (-1)*sizeof(DV), SEEK_CUR);
            fwrite(dono, sizeof(DV), 1, arq_dono_veiculo);
            break;
        }
    }

    fclose(arq_dono_veiculo);
    free(dono);

    if (encontrado)
        printf("Registro do dono com CPF %s recuperado com sucesso!\n", cpf_lido);
    else
        printf("\nCPF não encontrado!\n");

    printf("\t >>Tecle <ENTER> para continuar...\n");
    getchar();
}
