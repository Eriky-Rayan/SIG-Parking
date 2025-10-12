#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "veiculos.h"

typedef struct veiculos Veiculos;

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
    Veiculos* veiculo;

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
    veiculo = (Veiculos*)malloc(sizeof(Veiculos));
    printf(" >>Digite a placa do veículo a ser cadastrado: ");
    scanf("%s", veiculo->placa);
    getchar();
    printf("\n");
    printf(" >>Tipo de Veículo (Carro/Moto): ");
    scanf("%s", veiculo->tipo);
    getchar();
    printf("\n");
    printf(" >>Modelo do veículo: ");
    scanf("%s", veiculo->model);
    getchar();
    printf("\n");
    printf(" >>Cor do Veículo: ");
    scanf("%s", veiculo->cor);
    getchar();
    printf("\n");
    printf(" >>Nº do estacionamento: ");
    scanf("%s", veiculo->n_estaci);
    getchar();
    printf("\n");
    printf(" >>CPF do Dono do Veículo: ");
    scanf("%s", veiculo->cpf);
    getchar();
    printf("\n");

    veiculo->status = True;
    arq_veiculos = fopen("veiculos.dat", "ab");
    if (arq_veiculos == NULL) {
        printf("\t Erro ao abrir o arquivo de veículos.\n");
        printf("\t >>Tecle <ENTER> para continuar...\n");
        getchar();
        return;
    }
    fwrite(veiculos, sizeof(Veiculos), 1, arq_veiculos);
    fclose(arq_veiculos);

    printf("Veículo cadastrado com sucesso!\n");
    printf("\nPlaca: %s", veiculo->placa);
    printf("\nTipo: %s", veiculo->tipo);
    printf("\nModelo: %s", veiculo->model);
    printf("\nCor: %s", veiculo->cor);
    printf("\nNº do estacionamento: %s", veiculo->n_estaci);
    printf("\nCPF: %s", veiculo->cpf);
    printf("\n");
    printf("\t >>Tecle <ENTER> para continuar...\n");
    getchar();
    printf("\n");

    free(veiculo);
}

void exib_veiculo(void) {
    system("clear||cls");

    FILE *arq_veiculos;
    Veiculos* veiculo;
    char placa_lida [12];
    int encontrado = 0;

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
    veiculo = (Veiculos*)malloc(sizeof(Veiculos));
    printf(" >>Digite a placa do veículo a ser exibido:  \n");
    scanf("%s", placa_lida);
    getchar();
    printf("\n");

    arq_veiculos = fopen("veiculos.dat", "rb");
    if (arq_veiculos == NULL) {
        printf("\t Erro ao abrir o arquivo de veículos.\n");
        printf("\t >>Tecle <ENTER> para continuar...\n");
        getchar();
        return;
    }
    while (fread(veiculo, sizeof(Veiculos), 1, arq_veiculos)) {
        if ((strcmp(veiculo->placa, placa_lida) == 0) && (veiculo->status)) {
            encontrado = 1;
            printf("<<<Veículo encontrado>>>");
            printf("\n");
            printf("Placa: %s\n", veiculo->placa);
            printf("Tipo: %s\n", veiculo->tipo);
            printf("Modelo: %s\n", veiculo->model);
            printf("Cor: %s\n", veiculo->cor);
            printf("Nº do Estacionamento: %s\n", veiculo->n_estaci);
            printf("CPF: %s\n", veiculo->cpf);
            printf("\t >>Tecle <ENTER> para continuar...\n");
            getchar();
            return;
        }
    }

    fclose(arq_veiculos);
    free(veiculo);

    if (encontrado) {
        printf("O veículo com a seguinte placa foi exibido: %s\n", placa_lida);
    }
    else{
        printf("Placa não encontrada!\n");
    }
    printf("\n");
    printf("\t >>Tecle <ENTER> para continuar...\n");
    getchar();
    printf("\n");
}

void alterar_veiculo(void) {
    system("clear||cls");

    FILE *arq_veiculos;
    FILE *arq_veiculos_temp;
    Veiculos veiculo;
    char placa_lida [12];

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

    while (fscanf(arq_veiculos, "%[^;];%[^;];%[^;];%[^;];%[^;];%[^\n]\n", veiculo.placa, veiculo.tipo, veiculo.model, veiculo.cor, veiculo.n_estaci, veiculo.cpf) == 6) {

        if (strcmp(veiculo.placa, placa_lida) != 0){
            fprintf(arq_veiculos_temp, "%s;%s;%s;%s;%s;%s\n", veiculo.placa, veiculo.tipo, veiculo.model, veiculo.cor, veiculo.n_estaci, veiculo.cpf);
        }
        else {
            printf("\n");
            printf(" >>Tipo de Veículo (Carro/Moto): ");
            scanf("%s", veiculo.tipo);
            getchar();
            printf("\n");
            printf(" >>Modelo do veículo: ");
            scanf("%s", veiculo.model);
            getchar();
            printf("\n");
            printf(" >>Cor do Veículo: ");
            scanf("%s", veiculo.cor);
            getchar();
            printf("\n");
            printf(" >>Nº do estacionamento: ");
            scanf("%s", veiculo.n_estaci);
            getchar();
            printf("\n");
            printf(" >>CPF do Dono do Veículo: ");
            scanf("%s", veiculo.cpf);
            getchar();
            printf("\n");

            fprintf(arq_veiculos_temp, "%s;%s;%s;%s;%s;%s\n", placa_lida, veiculo.tipo, veiculo.model, veiculo.cor, veiculo.n_estaci, veiculo.cpf);
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
    Veiculos* veiculo;
    char placa_lida [12];
    char encontrado;

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
    veiculo = (Veiculos*)malloc(sizeof(Veiculos));
    printf(" >>Digite a placa do veículo a ser excluido: ");
    scanf("%s", placa_lida);
    getchar();
    encontrado = False;
    printf("\n");

    arq_veiculos = fopen("veiculos.dat", "r+b");
    if (arq_veiculos == NULL) {
        printf("\t Erro ao abrir o arquivo de veículos. \n");
        printf("\t >>Tecle <ENTER> para continuar...\n");
        getchar();
        return;
    }

    while (fread(veiculo, sizeof(Veiculos), 1, arq_veiculos) && (!encontrado)) {

        if (strcmp(veiculo->placa, placa_lida) == 0){
            veiculo->status = False;
            encontrado = True;
            fseek(arq_veiculos, (-1)*sizeof(Veiculos), SEEK_CUR);
            fwrite(veiculo, sizeof(Veiculos), 1, arq_veiculos);
        }
    }

    fclose(arq_veiculos);

    printf("Veículo com placa %s excluído com sucesso!\n", placa_lida);
    printf("\n");
    printf("\t >>Tecle <ENTER> para continuar...\n");
    getchar();
    printf("\n");

    free(veiculo);
    if (!encontrado) {
        printf("Item não encontrado! \n");
    }
}