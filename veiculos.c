#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
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
    printf("|| [1] ⟶ Cadastrar Veículo                                                            ||\n");
    printf("|| [2] ⟶ Exibir Dados do Veículo                                                      ||\n");
    printf("|| [3] ⟶ Alterar Dados do Veículo                                                     ||\n");
    printf("|| [4] ⟶ Excluir Veículo                                                              ||\n");
    printf("|| [0] ⟶ Voltar ao Menu Principal                                                     ||\n");
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
    printf("||                        -Módulo Veículos - Cadastrar veículo-                      ||\n");
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

    printf("Veículo cadastrado com sucesso!\n");
    printf("\nPlaca: %s", placa);
    printf("\nTipo: %s", tipo);
    printf("\nModelo: %s", model);
    printf("\nCor: %s", cor);
    printf("\nNº do estacionamento: %s", n_estaci);
    printf("\nCPF: %s", cpf);
    printf("\n");
    printf("\t >>Tecle <ENTER> para continuar...\n");
}

void exib_veiculo(void) {
    system("clear||cls");

    char placa[12];

    printf("\n");
    printf("=====================================================================================\n");
    printf("||                                                                                 ||\n");
    printf("||                                  -SIG-Parking-                                  ||\n");
    printf("||                                                                                 ||\n");
    printf("=====================================================================================\n");
    printf("||                                                                                 ||\n");
    printf("||                       -Módulo Veículos - Exibir veículo-                        ||\n");
    printf("||                                                                                 ||\n");
    printf("=====================================================================================\n");
    printf("\n");
    printf(" >>Digite a placa do veículo a ser exibido:  \n");
    scanf("%s", placa);
    getchar();
    printf("\n");
    printf("O veículo com a seguinte placa foi exibido: %s\n", placa);
    printf("\n");
    printf("\t >>Tecle <ENTER> para continuar...\n");
}

void alterar_veiculo(void) {
    system("clear||cls");

    char placa[12];
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
    printf("||                       -Módulo Veículos - Alterar Dados-                         ||\n");
    printf("||                                                                                 ||\n");
    printf("=====================================================================================\n");
    printf("\n");
    printf(" -Digite os novos dados do veículo-");
    printf("\n");
    printf(" >>Digite a placa do veículo a ser alterado: \n");
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

    printf("Dados do veículo alterados com sucesso!\n");
    printf("\nPlaca: %s", placa);
    printf("\nTipo: %s", tipo);
    printf("\nModelo: %s", model);
    printf("\nCor: %s", cor);
    printf("\nNº do estacionamento: %s", n_estaci);
    printf("\nCPF: %s", cpf);
    printf("\n");
    printf("\t >>Tecle <ENTER> para continuar...\n");
}

void exclu_veiculo(void) {
    system("clear||cls");

    char placa[12];

    printf("\n");
    printf("======================================================================================\n");
    printf("||                                                                                  ||\n");
    printf("||                                   -SIG-Parking-                                  ||\n");
    printf("||                                                                                  ||\n");
    printf("======================================================================================\n");
    printf("||                                                                                  ||\n");
    printf("||                         -Módulo Veículos - Excluir Dados-                        ||\n");
    printf("||                                                                                  ||\n");
    printf("======================================================================================\n");
    printf("\n");
    printf(" >>Digite a placa do veículo a ser excluido: ");
    scanf("%s", placa);
    getchar();
    printf("\n");

    printf("Veículo com placa %s excluído com sucesso!\n", placa);
    printf("\n");
    printf("\t >>Tecle <ENTER> para continuar...\n");
}