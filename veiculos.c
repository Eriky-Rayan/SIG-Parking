#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "veiculos.h"
#include "validacoes.h"

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
                exclu_logica_veiculo();
                break;
            case '5':
                recu_registro_veiculo();
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
    printf("|| [5] -> Recuperar registro Veículo                                                  ||\n");
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
    Veiculos *veiculo;

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
    Ler_Placa(veiculo->placa);
    printf("\n");
    Ler_Tipo(veiculo->tipo);
    printf("\n");
    Ler_model(veiculo->model, sizeof(veiculo->model));
    printf("\n");
    Ler_cor(veiculo->cor, sizeof(veiculo->cor));
    printf("\n");
    Ler_Estacionamento(veiculo->n_estaci);
    printf("\n");
    Ler_CPF(veiculo->cpf);
    printf("\n");

    veiculo->status = True;
    arq_veiculos = fopen("veiculos.dat", "ab");
    if (arq_veiculos == NULL) {
        printf("\t Erro ao abrir o arquivo de veículos.\n");
        printf("\t >>Tecle <ENTER> para continuar...\n");
        free(veiculo);
        getchar();
        return;
    }

    fwrite(veiculo, sizeof(Veiculos), 1, arq_veiculos);
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
    Veiculos *veiculo;
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
    printf(" >>Digite a placa do veículo a ser exibido.  \n");
    Ler_Placa_Lida(placa_lida);
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
    Veiculos *veiculo;
    char placa_lida [12];
    int encontrado = 0;

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
    veiculo = (Veiculos*)malloc(sizeof(Veiculos));
    printf(" -Digite os novos dados do veículo-");
    printf("\n");
    printf(" >>Digite a placa do veículo a ser alterado. \n");
    Ler_Placa_Lida(placa_lida);
    printf("\n");

    arq_veiculos = fopen("veiculos.dat", "r+b");
    if (arq_veiculos == NULL) {
        printf("\t Erro ao abrir o arquivo de veículos.\n");
        printf("\t >>Tecle <ENTER> para continuar...\n");
        getchar();
        return;
    }

    while (fread(veiculo, sizeof(Veiculos), 1, arq_veiculos)) {
        if ((strcmp(veiculo->placa, placa_lida) == 0) && (veiculo->status)) {
            encontrado = 1;
            printf("\n");
            Ler_Tipo(veiculo->tipo);
            printf("\n");
            Ler_model(veiculo->model, sizeof(veiculo->model));
            printf("\n");
            Ler_cor(veiculo->cor, sizeof(veiculo->cor));
            printf("\n");
            Ler_Estacionamento(veiculo->n_estaci);
            printf("\n");
            Ler_CPF(veiculo->cpf);
            printf("\n");

            fseek(arq_veiculos, (-1)*sizeof(Veiculos), SEEK_CUR);
            fwrite(veiculo, sizeof(Veiculos), 1, arq_veiculos);
        }
    }

    fclose(arq_veiculos);
    free(veiculo);

    if (encontrado) {
        printf("\nDados do veículo alterados com sucesso!\n");
    }
    else{
        printf("\nPlaca não encontrada!\n");
    }
    printf("\t >>Tecle <ENTER> para continuar...\n");
    getchar();
    printf("\n");
}

void exclu_logica_veiculo(void) {
    system("clear||cls");

    FILE *arq_veiculos;
    Veiculos *veiculo;
    char placa_lida [12];
    int encontrado = 0;

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
    printf(" >>Digite a placa do veículo a ser excluido. \n");
    Ler_Placa_Lida(placa_lida);
    printf("\n");

    arq_veiculos = fopen("veiculos.dat", "r+b");
    if (arq_veiculos == NULL) {
        printf("\t Erro ao abrir o arquivo de veículos. \n");
        printf("\t >>Tecle <ENTER> para continuar...\n");
        getchar();
        return;
    }

    while (fread(veiculo, sizeof(Veiculos), 1, arq_veiculos)) {
        if ((strcmp(veiculo->placa, placa_lida) == 0) && (veiculo->status)) {
            veiculo->status = False;
            encontrado = 1;
            fseek(arq_veiculos, (-1)*sizeof(Veiculos), SEEK_CUR);
            fwrite(veiculo, sizeof(Veiculos), 1, arq_veiculos);
        }
    }

    fclose(arq_veiculos);
    free(veiculo);

    if (encontrado) {
        printf("Veículo com placa %s excluído com sucesso!\n", placa_lida);
    } else {
        printf("Placa não encontrada!\n");
    }
    
    printf("\n");
    printf("\t >>Tecle <ENTER> para continuar...\n");
    getchar();
    printf("\n");
}

void recu_registro_veiculo(void){
    system("clear||cls");

    FILE *arq_veiculos;
    Veiculos *veiculo;
    char placa_lida[12];
    int encontrado = 0;

    printf("\n");
    printf("======================================================================================\n");
    printf("||                                                                                  ||\n");
    printf("||                                  -SIG-Parking-                                   ||\n");
    printf("||                                                                                  ||\n");
    printf("======================================================================================\n");
    printf("||                                                                                  ||\n");
    printf("||                     -Módulo Veículos -> Recuperar registro -                     ||\n");
    printf("||                                                                                  ||\n");
    printf("======================================================================================\n");
    printf("\n");
    veiculo = (Veiculos*)malloc(sizeof(Veiculos));
    printf(" >>Digite a placa do veículo a ser recuperado. \n");
    Ler_Placa_Lida(placa_lida);
    printf("\n");

    arq_veiculos = fopen("veiculos.dat", "r+b");
    if (arq_veiculos == NULL) {
        printf("\t Erro ao abrir o arquivo de veículos.\n");
        printf("\t >>Tecle <ENTER> para continuar...\n");
        getchar();
        return;
    }

    while (fread(veiculo, sizeof(Veiculos), 1, arq_veiculos)) {
        if ((strcmp(veiculo->placa, placa_lida) == 0) && (!veiculo->status)) {
            veiculo->status = True;
            encontrado = 1;
            fseek(arq_veiculos, (-1)*sizeof(Veiculos), SEEK_CUR);
            fwrite(veiculo, sizeof(Veiculos), 1, arq_veiculos);
            break;
        }
    }

    fclose(arq_veiculos);
    free(veiculo);

    if (encontrado) {
        printf("registro do Veículo com placa %s recuperado logicamente com sucesso!\n", placa_lida);
    } else {
        printf("Placa não encontrada!\n");
    }

    printf("\n");
    printf("\t >>Tecle <ENTER> para continuar...\n");
    getchar();
    printf("\n");
}