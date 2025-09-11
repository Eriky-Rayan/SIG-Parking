#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "estacionamentos.h"

void switch_estacionamentos(void){

    char op;

    do {
        op = estacionamentos();
        switch (op) {
            case '1': 
                add_estacionamentos();
                break;
            case '2': 
                exib_estacionamentos();
                break;
            case '3': 
                alterar_estacionamentos();
                break;
            case '4': 
                exclu_estacionamentos();
                break;
        }
    } while (op != '0');
}

char estacionamentos(void) {
    system("clear||cls");

    char op;

    printf("\n");
    printf("⎸==================================================================================⎸\n");
    printf("⎸                                   SIG-Parking                                    ⎸\n");
    printf("⎸==================================================================================⎸\n");
    printf("⎸                             Módulo Estacionamentos                               ⎸\n");
    printf("⎸==================================================================================⎸\n");
    printf("⎸ 1 - Cadastrar Estacionamento                                                     ⎸\n");
    printf("⎸ 2 - Exibir Dados do Estacionamento                                               ⎸\n");
    printf("⎸ 3 - Alterar Dados do Estacionamento                                              ⎸\n");
    printf("⎸ 4 - Excluir Estacionamento                                                       ⎸\n");
    printf("⎸ 0 - Voltar ao Menu Principal                                                     ⎸\n");
    printf("⎸==================================================================================⎸\n");
    printf("\n");
    printf("\t >>Escolha uma opção: ");
    scanf("%c", &op);
    getchar();
    printf("\n");
    return op;
}

void add_estacionamentos(void) {
    system("clear||cls");

    char n_estaci[8];
    char tipo[10];
    char placa[12];

    printf("\n");
    printf("⎸==================================================================================⎸\n");
    printf("⎸                                   SIG-Parking                                    ⎸\n");
    printf("⎸==================================================================================⎸\n");
    printf("⎸                 Módulo Estacionamentos - Cadastrar Estacionamento                ⎸\n");
    printf("⎸==================================================================================⎸\n");
    printf("\n");
    printf(" >>Digite o Nº da vaga onde o veículo será cadastrado: ");
    scanf("%s", n_estaci);
    getchar();
    printf("\n");
    printf(" >>Tipo de Veículo no estacionamento (Carro/Moto): ");
    scanf("%s", tipo);
    getchar();
    printf("\n");
    printf(" >>Digite a placa do veículo: ");
    scanf("%s", placa);
    getchar();
    printf("\n");

    printf("Veículo cadastrado no estacionamento com sucesso!\n");
    printf("\nNº do estacionamento: %s", n_estaci);
    printf("\nTipo do veículo: %s", tipo);
    printf("\nPlaca: %s", placa);
    printf("\n");
    printf("\t >>Tecle <ENTER> para continuar...\n");
}

void exib_estacionamentos(void) {
    system("clear||cls");

    char n_estaci[8];

    printf("\n");
    printf("⎸==================================================================================⎸\n");
    printf("⎸                                   SIG-Parking                                    ⎸\n");
    printf("⎸==================================================================================⎸\n");
    printf("⎸                 Módulo Estacionamentos - Exibir Estacionamento                   ⎸\n");
    printf("⎸==================================================================================⎸\n");
    printf("\n");
    printf(" >>Digite Nº da vaga que deseja ver: ");
    scanf("%s", n_estaci);
    getchar();
    printf("\n");
    printf("O veículo na seguinte vaga foi exibido: %s\n", n_estaci);
    printf("\n");
    printf("\t >>Tecle <ENTER> para continuar...\n");
}

void alterar_estacionamentos(void) {
    system("clear||cls");

    char n_estaci[8];
    char tipo[10];
    char placa[12];

    printf("\n");
    printf("⎸==================================================================================⎸\n");
    printf("⎸                                   SIG-Parking                                    ⎸\n");
    printf("⎸==================================================================================⎸\n");
    printf("⎸                 Módulo Estacionamentos - Alterar Estacionamento                  ⎸\n");
    printf("⎸==================================================================================⎸\n");
    printf("\n");
    printf(" -Digite os novos dados do estacionamento-");
    printf("\n");
    printf(" >>Digite o Nº da vaga que deseja alterar: ");
    scanf("%s", n_estaci);
    getchar();
    printf("\n");
    printf(" >>Tipo de Veículo no estacionamento (Carro/Moto): ");
    scanf("%s", tipo);
    getchar();
    printf("\n");
    printf(" >>Digite a placa do veículo: ");
    scanf("%s", placa);
    getchar();
    printf("\n");

    printf("Vaga de estacionamento alterada com sucesso!\n");
    printf("\nNº do estacionamento: %s", n_estaci);
    printf("\nTipo do veículo: %s", tipo);
    printf("\nPlaca: %s", placa);
    printf("\n");
    printf("\t >>Tecle <ENTER> para continuar...\n");
}

void exclu_estacionamentos(void) {
    system("clear||cls");

    char n_estaci[8];

    printf("\n");
    printf("⎸==================================================================================⎸\n");
    printf("⎸                                   SIG-Parking                                    ⎸\n");
    printf("⎸==================================================================================⎸\n");
    printf("⎸                 Módulo Estacionamentos - Excluir Estacionamento                   ⎸\n");
    printf("⎸==================================================================================⎸\n");
    printf("\n");
    printf(" >>Digite o Nº da vaga que deseja excluir: ");
    scanf("%s", n_estaci);
    getchar();
    printf("\n");

    printf("O veículo na vaga %s excluído com sucesso!\n", n_estaci);
    printf("\n");
    printf("\t >>Tecle <ENTER> para continuar...\n");
}