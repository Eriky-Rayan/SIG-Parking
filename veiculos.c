#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "veiculos.h"

//==============================
//= Funções do Módulo Veículos =
//==============================

void switch_veiculos(void){
    
    char op;

    do {
        op = veiculos();
        switch (op) {
            case '1': 
                add_veiculos();
                break;
            case '2': 
                exib_veiculo();
                break;
            case '3': 
                alterar_veiculo();
                break;
            case '4': 
                exclu_veiculo();
                break;
        }
    } while (op != '0');
}

char veiculos(void) {
    system("clear||cls");

    char op;

    printf("\n");
    printf("========================================================================================\n");
    printf("||                                                                                    ||\n");
    printf("||                                  -SIG-Parking-                                     ||\n");
    printf("||                                                                                    ||\n");
    printf("========================================================================================\n");
    printf("||                                                                                    ||\n");
    printf("||                                -Módulo Veículos-                                   ||\n");
    printf("||                                                                                    ||\n");
    printf("========================================================================================\n");
    printf("||                                                                                    ||\n");
    printf("|| [1] -> Cadastrar Veículo                                                           ||\n");
    printf("|| [2] -> Exibir Dados do Veículo                                                     ||\n");
    printf("|| [3] -> Alterar Dados do Veículo                                                    ||\n");
    printf("|| [4] -> Excluir Veículo                                                             ||\n");
    printf("|| [0] -> Voltar ao Menu Principal                                                    ||\n");
    printf("||                                                                                    ||\n");
    printf("========================================================================================\n");
    printf("\n");
    printf("\t >>Escolha uma opção: ");
    scanf("%c", &op);
    getchar();
    printf("\n");
    return op;
}

void add_veiculos(void) {
    system("clear||cls");

    FILE *arq_veiculos;
    char placa[12];
    char tipo[10];
    char model[20];
    char cor [15];
    char n_estaci[8];
    char cpf[15];

    printf("\n");
    printf("=======================================================================================\n");
    printf("||                                                                                   ||\n");
    printf("||                                   -SIG-Parking-                                   ||\n");
    printf("||                                                                                   ||\n");
    printf("=======================================================================================\n");
    printf("||                                                                                   ||\n");
    printf("||                        -Módulo Veículos -> Cadastrar veículo-                     ||\n");
    printf("||                                                                                   ||\n");
    printf("=======================================================================================\n");
    printf("\n");
    printf(" >>Digite a placa do veículo a ser cadastrado: ");
    scanf("%s", placa);
    getchar();
    printf("\n");
    printf(" >>Tipo de Veículo (Carro/Moto): ");
    scanf("%s", tipo);
    getchar();
    printf("\n");
    printf(" >>Modelo do veículo: ");
    scanf("%s", model);
    getchar();
    printf("\n");
    printf(" >>Cor do Veículo: ");
    scanf("%s", cor);
    getchar();
    printf("\n");
    printf(" >>Nº do estacionamento: ");
    scanf("%s", n_estaci);
    getchar();
    printf("\n");
    printf(" >>CPF do Dono do Veículo: ");
    scanf("%s", cpf);
    getchar();
    printf("\n");

    arq_veiculos = fopen("veiculos.csv", "at");
    if (arq_veiculos == NULL) {
        printf("\t Erro ao abrir o arquivo de veículos.\n");
        printf("\t >>Tecle <ENTER> para continuar...\n");
        getchar();
        return;
    }
    fprintf(arq_veiculos, "%s;%s;%s;%s;%s;%s\n", placa, tipo, model, cor, n_estaci, cpf);
    fclose(arq_veiculos);

    printf("Veículo cadastrado com sucesso!\n");
    printf("\nPlaca: %s", placa);
    printf("\nTipo: %s", tipo);
    printf("\nModelo: %s", model);
    printf("\nCor: %s", cor);
    printf("\nNº do estacionamento: %s", n_estaci);
    printf("\nCPF: %s", cpf);
    printf("\n");
    printf("\t >>Tecle <ENTER> para continuar...\n");
    getchar();
    printf("\n");
}

void exib_veiculo(void) {
    system("clear||cls");

    FILE *arq_veiculos;
    char placa[12];
    char placa_lida[12];
    char tipo[10];
    char model[20];
    char cor [15];
    char n_estaci[8];
    char cpf[15];

    printf("\n");
    printf("=====================================================================================\n");
    printf("||                                                                                 ||\n");
    printf("||                                  -SIG-Parking-                                  ||\n");
    printf("||                                                                                 ||\n");
    printf("=====================================================================================\n");
    printf("||                                                                                 ||\n");
    printf("||                       -Módulo Veículos -> Exibir veículo-                       ||\n");
    printf("||                                                                                 ||\n");
    printf("=====================================================================================\n");
    printf("\n");
    printf(" >>Digite a placa do veículo a ser exibido:  \n");
    scanf("%s", placa_lida);
    getchar();
    printf("\n");

    arq_veiculos = fopen("veiculos.csv", "rt");
    if (arq_veiculos == NULL) {
        printf("\t Erro ao abrir o arquivo de veículos.\n");
        printf("\t >>Tecle <ENTER> para continuar...\n");
        getchar();
        return;
    }
    while (!feof(arq_veiculos)) {
        fscanf(arq_veiculos, "%[^;]", placa);
        fgetc(arq_veiculos);
        fscanf(arq_veiculos, "%[^;]", tipo);
        fgetc(arq_veiculos);
        fscanf(arq_veiculos, "%[^;]", model);
        fgetc(arq_veiculos);
        fscanf(arq_veiculos, "%[^;]", cor);
        fgetc(arq_veiculos);
        fscanf(arq_veiculos, "%[^;]", n_estaci);
        fgetc(arq_veiculos);
        fscanf(arq_veiculos, "%[^\n]", cpf);
        fgetc(arq_veiculos);
        if (strcmp(placa, placa_lida) == 0) {
            printf("<<<Veículo encontrado>>>");
            printf("\n");
            printf("Placa: %s\n", placa);
            printf("Tipo: %s\n", tipo);
            printf("Modelo: %s\n", model);
            printf("Cor: %s\n", cor);
            printf("Nº do Estacionamento: %s\n", n_estaci);
            printf("CPF: %s\n", cpf);
            printf("\t >>Tecle <ENTER> para continuar...\n");
            getchar();
            fclose(arq_veiculos);
            return;
        }
    }

    printf("O veículo com a seguinte placa foi exibido: %s\n", placa);
    printf("\n");
    printf("\t >>Tecle <ENTER> para continuar...\n");
    getchar();
    printf("\n");
}

void alterar_veiculo(void) {
    system("clear||cls");

    FILE *arq_veiculos;
    FILE *arq_veiculos_temp;
    char placa[12];
    char placa_lida[12];
    char tipo[10];
    char model[20];
    char cor [15];
    char n_estaci[8];
    char cpf[15];

    printf("\n");
    printf("=====================================================================================\n");
    printf("||                                                                                 ||\n");
    printf("||                                  -SIG-Parking-                                  ||\n");
    printf("||                                                                                 ||\n");
    printf("=====================================================================================\n");
    printf("||                                                                                 ||\n");
    printf("||                       -Módulo Veículos -> Alterar Dados-                        ||\n");
    printf("||                                                                                 ||\n");
    printf("=====================================================================================\n");
    printf("\n");
    printf(" -Digite os novos dados do veículo-");
    printf("\n");
    printf(" >>Digite a placa do veículo a ser alterado: \n");
    scanf("%s", placa_lida);
    getchar();
    printf("\n");

    arq_veiculos = fopen("veiculos.csv", "rt");
    arq_veiculos_temp = fopen("veiculos_temp.csv", "wt");
    if (arq_veiculos == NULL) {
        printf("\t Erro ao abrir o arquivo de veículos.\n");
        printf("\t >>Tecle <ENTER> para continuar...\n");
        getchar();
        return;
    }

    while (fscanf(arq_veiculos, "%[^;];%[^;];%[^;];%[^;];%[^;];%[^\n]\n", placa, tipo, model, cor, n_estaci, cpf) == 6) {

        if (strcmp(placa, placa_lida) != 0){
            fprintf(arq_veiculos_temp, "%s;%s;%s;%s;%s;%s\n", placa, tipo, model, cor, n_estaci, cpf);
        }
        else {
            printf("\n");
            printf(" >>Tipo de Veículo (Carro/Moto): ");
            scanf("%s", tipo);
            getchar();
            printf("\n");
            printf(" >>Modelo do veículo: ");
            scanf("%s", model);
            getchar();
            printf("\n");
            printf(" >>Cor do Veículo: ");
            scanf("%s", cor);
            getchar();
            printf("\n");
            printf(" >>Nº do estacionamento: ");
            scanf("%s", n_estaci);
            getchar();
            printf("\n");
            printf(" >>CPF do Dono do Veículo: ");
            scanf("%s", cpf);
            getchar();
            printf("\n");

            fprintf(arq_veiculos_temp, "%s;%s;%s;%s;%s;%s\n", placa_lida, tipo, model, cor, n_estaci, cpf);
        }
    }

    fclose(arq_veiculos);
    fclose(arq_veiculos_temp);

    remove("veiculos.csv");
    rename("veiculos_temp.csv", "veiculos.csv");

    printf("Dados do veículo alterados com sucesso!\n");
    printf("\t >>Tecle <ENTER> para continuar...\n");
    getchar();
    printf("\n");
}

void exclu_veiculo(void) {
    system("clear||cls");

    FILE *arq_veiculos;
    FILE *arq_veiculos_temp;
    char placa[12];
    char placa_lida[12];
    char tipo[10];
    char model[20];
    char cor [15];
    char n_estaci[8];
    char cpf[15];

    printf("\n");
    printf("======================================================================================\n");
    printf("||                                                                                  ||\n");
    printf("||                                   -SIG-Parking-                                  ||\n");
    printf("||                                                                                  ||\n");
    printf("======================================================================================\n");
    printf("||                                                                                  ||\n");
    printf("||                         -Módulo Veículos -> Excluir Dados-                       ||\n");
    printf("||                                                                                  ||\n");
    printf("======================================================================================\n");
    printf("\n");
    printf(" >>Digite a placa do veículo a ser excluido: ");
    scanf("%s", placa_lida);
    getchar();
    printf("\n");

    arq_veiculos = fopen("veiculos.csv", "rt");
    arq_veiculos_temp = fopen("veiculos_temp.csv", "wt");
    if (arq_veiculos == NULL) {
        printf("\t Erro ao abrir o arquivo de veículos. \n");
        printf("\t >>Tecle <ENTER> para continuar...\n");
        getchar();
        return;
    }

    while (fscanf(arq_veiculos, "%[^;];%[^;];%[^;];%[^;];%[^;];%[^\n]\n", placa, tipo, model, cor, n_estaci, cpf) == 6) {

        if (strcmp(placa, placa_lida) != 0){
            fprintf(arq_veiculos_temp, "%s;%s;%s;%s;%s;%s\n", placa, tipo, model, cor, n_estaci, cpf);
        }
    }

    fclose(arq_veiculos);
    fclose(arq_veiculos_temp);

    remove("veiculos.csv");
    rename("veiculos_temp.csv", "veiculos.csv");

    printf("Veículo com placa %s excluído com sucesso!\n", placa_lida);
    printf("\n");
    printf("\t >>Tecle <ENTER> para continuar...\n");
    getchar();
    printf("\n");
}