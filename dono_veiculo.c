#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "dono_veiculo.h"

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
                exclu_dono_veiculo();
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
    printf("|| [4] -> Excluir Dono de Veículo                                                  ||\n");
    printf("|| [0] -> Voltar ao Menu Principal                                                 ||\n");
    printf("||                                                                                 ||\n");
    printf("=====================================================================================\n");
    printf("\n");
    printf("\t >>Escolha uma opção: ");
    scanf("%c", &op);
    getchar();
    printf("\n");
    return op;
}

void add_dono_veiculo(void) {
    system("clear||cls");

    FILE *arq_dono_veiculo;
    DV* dono;

    printf("\n");
    printf("====================================================================================\n");
    printf("||                                                                                ||\n");
    printf("||                                   -SIG-Parking-                                ||\n    ");
    printf("||                                                                                ||\n");
    printf("====================================================================================\n");
    printf("||                                                                                ||\n");
    printf("||                  -Módulo Donos dos Veículos -> Cadastrar Dono-                 ||\n");
    printf("||                                                                                ||\n");
    printf("====================================================================================\n");
    printf("\n");
    dono = (DV*)malloc(sizeof(DV));
    printf(" >>Digite o CPF do dono do veículo a ser cadastrado:  ");
    scanf("%s", dono->cpf);
    getchar();
    printf("\n");
    printf(" >>Telefone do dono: ");
    scanf("%s", dono->telefone);
    getchar();
    printf("\n");
    printf(" >>Nome do dono: ");
    scanf("%s", dono->nome);
    getchar();
    printf("\n");
    printf(" >>Quantidade de veículos: ");
    scanf("%d", &dono->quantidade);
    getchar();
    printf("\n");

    dono->status = True;
    arq_dono_veiculo = fopen("dono_veiculo.dat", "ab");
    if (arq_dono_veiculo == NULL) {
        printf("\t Erro ao abrir o arquivo dos donos dos veículos.\n");
        printf("\t >>Tecle <ENTER> para continuar...\n");
        free(dono);
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
    char cpf_lido[12];

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
    scanf("%s", cpf_lido);
    getchar();
    printf("\n");

    arq_dono_veiculo = fopen("dono_veiculo.dat", "rb");
    if (arq_dono_veiculo == NULL) {
        printf("\t Erro ao abrir o arquivo de dono_veiculo.\n");
        printf("\t >>Tecle <ENTER> para continuar...\n");
        getchar();
        return;
    }
    while (!feof(arq_dono_veiculo)) {
        fread(dono, sizeof(DV), 1, arq_dono_veiculo);
        if ((strcmp(dono->cpf, cpf_lido) == 0) && (dono->status)) {
            printf("<<<dono do veículo encontrado>>");
            printf("\n");
            printf("CPF: %s\n", dono->cpf);
            printf("Teledone: %s\n", dono->telefone);
            printf("Nome: %s\n", dono->nome);
            printf("Quantidade: %d\n", dono->quantidade);
            printf("\t >>Tecle <ENTER> para continuar...\n");
            getchar();
            return;
        }
    }

    printf("O dono com o seguinte cpf foi exibido: %s\n", cpf_lido);
    printf("\n");
    printf("\t >>Tecle <ENTER> para continuar...\n");
    getchar();
    printf("\n");

    fclose(arq_dono_veiculo);
    free(dono);
}

void alterar_dono_veiculo(void) {
    system("clear||cls");

    FILE *arq_dono_veiculo;
    FILE *arq_dono_veiculo_temp;
    DV dono;

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
    printf(" -Digite os novos dados do dono do veículo-");
    printf("\n");
    printf(" >>Digite o CPF do dono do veículo a ser alterado: ");
    scanf("%s", dono.cpf_lido);
    getchar();
    printf("\n");

    arq_dono_veiculo = fopen("dono_veiculo.csv", "rt");
    arq_dono_veiculo_temp = fopen("dono_veiculo_temp.csv", "wt");
    if (arq_dono_veiculo == NULL) {
        printf("\t Erro ao abrir o arquivo de dono_veiculo.\n");
        printf("\t >>Tecle <ENTER> para continuar...\n");
        getchar();
        return;
    }

    while (fscanf(arq_dono_veiculo, "%[^;];%[^;];%[^;];%d\n", dono.cpf, dono.telefone, dono.nome, &dono.quantidade) == 4){

        if (strcmp(dono.cpf, dono.cpf_lido) != 0){
            fprintf(arq_dono_veiculo_temp, "%s;%s;%s;%d\n", dono.cpf, dono.telefone, dono.nome, dono.quantidade);
        }
        else {
            printf("\n>>Digite o telefone do dono: ");
            scanf("%s", dono.telefone);
            getchar();

            printf(">>Digite o nome do dono: ");
            scanf("%s", dono.nome); 
            getchar();

            printf(">>Digite a quantidade de veículos: ");
            scanf("%d", &dono.quantidade);
            getchar();

            fprintf(arq_dono_veiculo_temp, "%s;%s;%s;%d\n", dono.cpf, dono.telefone, dono.nome, dono.quantidade);
        }      
    }

    fclose(arq_dono_veiculo);
    fclose(arq_dono_veiculo_temp);

    remove("dono_veiculo.csv");
    rename("dono_veiculo_temp.csv", "dono_veiculo.csv");

    printf("Dados do dono do veículo alterados com sucesso!\n");
    printf("\t >>Tecle <ENTER> para continuar...\n");
    getchar();
    printf("\n");
}

void exclu_dono_veiculo(void) {
    system("clear||cls");

    FILE *arq_dono_veiculo;
    FILE *arq_dono_veiculo_temp;
    DV dono;

    printf("\n");
    printf("======================================================================================\n");
    printf("||                                                                                  ||\n");
    printf("||                                  -SIG-Parking-                                   ||\n");
    printf("||                                                                                  ||\n");
    printf("======================================================================================\n");
    printf("||                                                                                  ||\n");
    printf("||                  -Módulo Donos dos Veículos -> Excluir Dados-                    ||\n");
    printf("||                                                                                  ||\n");
    printf("======================================================================================\n");
    printf("\n");
    printf(" >>Digite o CPF do dono a ser excluido: ");
    scanf("%s", dono.cpf_lido);
    getchar();
    printf("\n");

    arq_dono_veiculo = fopen("dono_veiculo.csv", "rt");
    arq_dono_veiculo_temp = fopen("dono_veiculo_temp.csv", "wt");
    if (arq_dono_veiculo == NULL) {
        printf("\t Erro ao abrir o arquivo de dono_veiculo.\n");
        printf("\t >>Tecle <ENTER> para continuar...\n");
        getchar();
        return;
    }

    while (fscanf(arq_dono_veiculo, "%[^;];%[^;];%[^;];%d\n", dono.cpf, dono.telefone, dono.nome, &dono.quantidade) == 4) {

        if (strcmp(dono.cpf, dono.cpf_lido) != 0){
            fprintf(arq_dono_veiculo_temp, "%s;%s;%s;%d\n", dono.cpf, dono.telefone, dono.nome, dono.quantidade);
        }
    }

    fclose(arq_dono_veiculo);
    fclose(arq_dono_veiculo_temp);

    remove("dono_veiculo.csv");
    rename("dono_veiculo_temp.csv", "dono_veiculo.csv");

    printf("Dono do veículo com CPF %s excluído com sucesso!\n", dono.cpf_lido);
    printf("\n");
    printf("\t >>Tecle <ENTER> para continuar...\n");
    getchar();
    printf("\n");
}

