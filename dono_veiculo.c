#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "dono_veiculo.h"
#include "validacoes.h"

typedef struct dono_veiculo DV;

//=====================================
//= Funções do Módulo Dono de Veículo =
//=====================================

void switch_dono_veiculo(void){

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
    printf("||                                                                                 ||\n");
    printf("||                                   -SIG-Parking-                                 ||\n");
    printf("||                                                                                 ||\n");
    printf("=====================================================================================\n");
    printf("||                                                                                 ||\n");
    printf("||                            -Módulo Donos dos Veículos-                          ||\n");
    printf("||                                                                                 ||\n");
    printf("=====================================================================================\n");
    printf("||                                                                                 ||\n");
    printf("|| [1] -> Cadastrar Dono de Veículo                                                ||\n");
    printf("|| [2] -> Exibir Dados do Dono de Veículo                                          ||\n");
    printf("|| [3] -> Alterar Dados do Dono de Veículo                                         ||\n");
    printf("|| [4] -> Excluir logicamente Dono de Veículo                                      ||\n");
    printf("|| [5] -> Recuperar registro Dono de Veículo                                       ||\n");
    printf("|| [0] -> Voltar ao Menu Principal                                                 ||\n");
    printf("||                                                                                 ||\n");
    printf("=====================================================================================\n");
    printf("\n");
    printf("\t >>Escolha uma opção: ");
    Ler_Opcao_Menu(&op);
    getchar();
    printf("\n");
    return op;
}

void add_dono_veiculo(void) {
    system("clear||cls");

    FILE *arq_dono_veiculo;
    DV *dono;

    printf("\n");
    printf("====================================================================================\n");
    printf("||                                                                                ||\n");
    printf("||                                   -SIG-Parking-                                ||\n");
    printf("||                                                                                ||\n");
    printf("====================================================================================\n");
    printf("||                                                                                ||\n");
    printf("||                  -Módulo Donos dos Veículos -> Cadastrar Dono-                 ||\n");
    printf("||                                                                                ||\n");
    printf("====================================================================================\n");
    printf("\n");
    dono = (DV*)malloc(sizeof(DV));
    printf(" >>Digite o CPF do dono do veículo a ser cadastrado:  ");
    Ler_CPF(dono->cpf);
    printf("\n");
    printf(" >>Telefone do dono: ");
    Ler_Telefone(dono->telefone);
    printf("\n");
    printf(" >>Nome do dono: ");
    Ler_Nome(dono->nome, sizeof(dono->nome));
    printf("\n");
    printf(" >>Quantidade de veículos: ");
    Ler_Quantidade(&dono->quantidade);
    printf("\n");

    dono->status = True;
    arq_dono_veiculo = fopen("dono_veiculo.dat", "ab");
    if (arq_dono_veiculo == NULL) {
        printf("\t Erro ao abrir o arquivo dos donos dos veículos.\n");
        printf("\t >>Tecle <ENTER> para continuar...\n");
        getchar();
        return;
    }

    fwrite(dono, sizeof(DV), 1, arq_dono_veiculo);
    fclose(arq_dono_veiculo);

    printf("\nDono do veículo cadastrado com sucesso!\n");
    printf("\nCPF: %s", dono->cpf);
    printf("\nTelefone: %s", dono->telefone);
    printf("\nNome: %s", dono->nome);
    printf("\nQuantidade de veículos: %d\n", dono->quantidade);
    printf("\n");
    printf("\t >>Tecle <ENTER> para continuar...\n");
    getchar();
    printf("\n");

    free(dono);
}

void exib_dono_veiculo(void) {
    system("clear||cls");

    FILE *arq_dono_veiculo;
    DV *dono;
    char cpf_lido[15];
    int encontrado = 0;

    printf("\n");
    printf("====================================================================================\n");
    printf("||                                                                                ||\n");
    printf("||                                   -SIG-Parking-                                ||\n");
    printf("||                                                                                ||\n");
    printf("====================================================================================\n");
    printf("||                                                                                ||\n");
    printf("||                   -Módulo Donos dos Veículos -> Exibir Dados-                  ||\n");
    printf("||                                                                                ||\n");
    printf("====================================================================================\n");
    printf("\n");
    dono = (DV*)malloc(sizeof(DV));
    printf(" >>Digite o CPF do dono a ser exibido: ");
    Ler_CPF_Lido(cpf_lido);
    printf("\n");

    arq_dono_veiculo = fopen("dono_veiculo.dat", "rb");
    if (arq_dono_veiculo == NULL) {
        printf("\t Erro ao abrir o arquivo de dono_veiculo.\n");
        printf("\t >>Tecle <ENTER> para continuar...\n");
        getchar();
        return;
    }
    while (fread(dono, sizeof(DV), 1, arq_dono_veiculo)) {
        if ((strcmp(dono->cpf, cpf_lido) == 0) && (dono->status)) {
            encontrado = 1;
            printf("<<<dono do veículo encontrado>>");
            printf("\n");
            printf("CPF: %s\n", dono->cpf);
            printf("Teledone: %s\n", dono->telefone);
            printf("Nome: %s\n", dono->nome);
            printf("Quantidade: %d\n", dono->quantidade);
            printf("\t >>Tecle <ENTER> para continuar...\n");
            getchar();
            break;
        }
    }

    fclose(arq_dono_veiculo);
    free(dono);

    if (encontrado) {
        printf("O dono com o seguinte cpf foi exibido: %s\n", cpf_lido);
    }
    else{
        printf("\nCPF não encontrado!\n");
    }
    printf("\n");
    printf("\t >>Tecle <ENTER> para continuar...\n");
    getchar();
    printf("\n");
}

void alterar_dono_veiculo(void) {
    system("clear||cls");

    FILE *arq_dono_veiculo;
    DV *dono;
    char cpf_lido[15];
    int encontrado = 0;

    printf("\n");
    printf("======================================================================================\n");
    printf("||                                                                                  ||\n");
    printf("||                                  -SIG-Parking-                                   ||\n");
    printf("||                                                                                  ||\n");
    printf("======================================================================================\n");
    printf("||                                                                                  ||\n");
    printf("||                  -Módulo Donos dos Veículos -> Alterar Dados-                    ||\n");
    printf("||                                                                                  ||\n");
    printf("======================================================================================\n");
    printf("\n");
    dono = (DV*)malloc(sizeof(DV));
    printf(" -Digite os novos dados do dono do veículo-");
    printf("\n");
    printf(" >>Digite o CPF do dono do veículo a ser alterado: ");
    Ler_CPF_lido(cpf_lido);
    printf("\n");

    arq_dono_veiculo = fopen("dono_veiculo.dat", "r+b");
    if (arq_dono_veiculo == NULL) {
        printf("\t Erro ao abrir o arquivo de dono_veiculo.\n");
        printf("\t >>Tecle <ENTER> para continuar...\n");
        getchar();
        return;
    }

    while (fread(dono, sizeof(DV), 1, arq_dono_veiculo)) {
        if ((strcmp(dono->cpf, cpf_lido) == 0) && (dono->status)) {
            encontrado = 1;
            printf("\n>>Digite o telefone do dono: ");
            Ler_Telefone(dono->telefone);
            printf(">>Digite o nome do dono: ");
            Ler_Nome(dono->nome, sizeof(dono->nome));
            printf(">>Digite a quantidade de veículos: ");
            Ler_Quantidade(&dono->quantidade);

            fseek(arq_dono_veiculo, (-1)*sizeof(DV), SEEK_CUR);
            fwrite(dono, sizeof(DV), 1, arq_dono_veiculo);
        }
    }

    fclose(arq_dono_veiculo);
    free(dono);

    if (encontrado) {
        printf("\nDados do dono do veículo alterados com sucesso!\n");
    }
    else{
        printf("\nCPF não encontrado!\n");
    }

    printf("\t >>Tecle <ENTER> para continuar...\n");
    getchar();
    printf("\n");
}

void exclu_logica_dono_veiculo(void) {
    system("clear||cls");

    FILE *arq_dono_veiculo;
    DV *dono;
    char cpf_lido[15];
    int encontrado = 0;

    printf("\n");
    printf("======================================================================================\n");
    printf("||                                                                                  ||\n");
    printf("||                                  -SIG-Parking-                                   ||\n");
    printf("||                                                                                  ||\n");
    printf("======================================================================================\n");
    printf("||                                                                                  ||\n");
    printf("||                  -Módulo Donos dos Veículos -> Excluir Dados Logicamente-        ||\n");
    printf("||                                                                                  ||\n");
    printf("======================================================================================\n");
    printf("\n");
    dono = (DV*)malloc(sizeof(DV));
    printf(" >>Digite o CPF do dono a ser excluido: ");
    Ler_CPF_lido(cpf_lido);
    printf("\n");

    arq_dono_veiculo = fopen("dono_veiculo.dat", "r+b");
    if (arq_dono_veiculo == NULL) {
        printf("\t Erro ao abrir o arquivo de dono_veiculo.\n");
        printf("\t >>Tecle <ENTER> para continuar...\n");
        getchar();
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

    if (encontrado) {
        printf("Dono do veículo com CPF %s excluído logicamente com sucesso!\n", cpf_lido);
    } else {
        printf("CPF não encontrado!\n");
    }

    printf("\n");
    printf("\t >>Tecle <ENTER> para continuar...\n");
    getchar();
    printf("\n");
}

void recu_registro_dono_veiculo(void){
    system("clear||cls");

    FILE *arq_dono_veiculo;
    DV *dono;
    char cpf_lido[15];
    int encontrado = 0;

    printf("\n");
    printf("======================================================================================\n");
    printf("||                                                                                  ||\n");
    printf("||                                  -SIG-Parking-                                   ||\n");
    printf("||                                                                                  ||\n");
    printf("======================================================================================\n");
    printf("||                                                                                  ||\n");
    printf("||                  -Módulo Donos dos Veículos -> Recuperar registro -              ||\n");
    printf("||                                                                                  ||\n");
    printf("======================================================================================\n");
    printf("\n");
    dono = (DV*)malloc(sizeof(DV));
    printf(" >>Digite o CPF do dono a ser recuperado: ");
    Ler_CPF_lido(cpf_lido);
    printf("\n");

    arq_dono_veiculo = fopen("dono_veiculo.dat", "r+b");
    if (arq_dono_veiculo == NULL) {
        printf("\t Erro ao abrir o arquivo de dono_veiculo.\n");
        printf("\t >>Tecle <ENTER> para continuar...\n");
        getchar();
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

    if (encontrado) {
        printf("registro do Dono do veículo com CPF %s recuperado logicamente com sucesso!\n", cpf_lido);
    } else {
        printf("CPF não encontrado!\n");
    }

    printf("\n");
    printf("\t >>Tecle <ENTER> para continuar...\n");
    getchar();
    printf("\n");
}

