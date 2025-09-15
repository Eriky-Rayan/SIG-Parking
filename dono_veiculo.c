#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "dono_veiculo.h"

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
    printf("|| [1] ⟶ Cadastrar Dono de Veículo                                                 ||\n");
    printf("|| [2] ⟶ Exibir Dados do Dono de Veículo                                           ||\n");
    printf("|| [3] ⟶ Alterar Dados do Dono de Veículo                                          ||\n");
    printf("|| [4] ⟶ Excluir Dono de Veículo                                                   ||\n");
    printf("|| [0] ⟶ Voltar ao Menu Principal                                                  ||\n");
    printf("||                                                                                 ||\n");
    printf("====================================================================================\n");
    printf("\n");
    printf("\t >>Escolha uma opção: ");
    scanf("%c", &op);
    getchar();
    printf("\n");
    return op;
}

void add_dono_veiculo(void) {
    system("clear||cls");

    char cpf[15];
    char telefone[20];
    char nome[50];
    int quantidade;

    printf("\n");
    printf("⎸==================================================================================⎸\n");
    printf("⎸                                   SIG-Parking                                    ⎸\n");
    printf("⎸==================================================================================⎸\n");
    printf("⎸                  Módulo Donos dos Veículos - Cadastrar Dono                      ⎸\n");
    printf("⎸==================================================================================⎸\n");
    printf("\n");
    printf(" >>Digite o CPF do dono do veículo a ser cadastrado:  ");
    scanf("%s", cpf);
    getchar();
    printf("\n");
    printf(" >>Telefone do dono: ");
    scanf("%s", telefone);
    getchar();
    printf("\n");
    printf(" >>Nome do dono: ");
    scanf("%s", nome);
    getchar();
    printf("\n");
    printf(" >>Quantidade de veículos: ");
    scanf("%d", &quantidade);
    getchar();
    printf("\n");

    printf("\nDono do veículo cadastrado com sucesso!\n");
    printf("\nCPF: %s", cpf);
    printf("\nTelefone: %s", telefone);
    printf("\nNome: %s", nome);
    printf("\nQuantidade de veículos: %d\n", quantidade);
    printf("\n");
    printf("\t >>Tecle <ENTER> para continuar...\n");
}

void exib_dono_veiculo(void) {
    system("clear||cls");

    char cpf[15];

    printf("\n");
    printf("⎸==================================================================================⎸\n");
    printf("⎸                                   SIG-Parking                                    ⎸\n");
    printf("⎸==================================================================================⎸\n");
    printf("⎸                     Módulo Donos dos Veículos - Exibir Dados                     ⎸\n");
    printf("⎸==================================================================================⎸\n");
    printf("\n");
    printf(" >>Digite o CPF do dono a ser exibido: ");
    scanf("%s", cpf);
    getchar();
    printf("\n");
    printf("O seguinte CPF foi exibido: %s\n", cpf);
    printf("\n");
    printf("\t >>Tecle <ENTER> para continuar...\n");
}

void alterar_dono_veiculo(void) {
    system("clear||cls");

    char cpf[15];
    char telefone[20];
    char nome[50];
    int quantidade;

    printf("\n");
    printf("⎸==================================================================================⎸\n");
    printf("⎸                                   SIG-Parking                                    ⎸\n");
    printf("⎸==================================================================================⎸\n");
    printf("⎸                   Módulo Donos dos Veículos - Alterar Dados                      ⎸\n");
    printf("⎸==================================================================================⎸\n");
    printf("\n");
    printf(" -Digite os novos dados do dono do veículo-");
    printf("\n");
    printf(" >>Digite o CPF do dono do veículo a ser alterado: ");
    scanf("%s", cpf);
    getchar();
    printf("\n");
    printf(" >>Telefone do dono: ");
    scanf("%s", telefone);
    getchar();
    printf("\n");
    printf(" >>Nome do dono: ");
    scanf("%s", nome);
    getchar();
    printf("\n");
    printf(" >>Quantidade de veículos cadastrados: ");
    scanf("%d", &quantidade);
    getchar();
    printf("\n");

    printf("Dados do dono do veículo alterados com sucesso!\n");
    printf("\nCPF: %s", cpf);
    printf("\nTelefone: %s", telefone);
    printf("\nNome: %s", nome);
    printf("\nQuantidade de veículos: %d\n", quantidade);
    printf("\n");
    printf("\t >>Tecle <ENTER> para continuar...\n");
}

void exclu_dono_veiculo(void) {
    system("clear||cls");

    char cpf[15];

    printf("\n");
    printf("⎸==================================================================================⎸\n");
    printf("⎸                                   SIG-Parking                                    ⎸\n");
    printf("⎸==================================================================================⎸\n");
    printf("⎸                   Módulo Donos dos Veículos - Excluir Dados                      ⎸\n");
    printf("⎸==================================================================================⎸\n");
    printf("\n");
    printf(" >>Digite o CPF do dono a ser excluido: ");
    scanf("%s", cpf);
    getchar();
    printf("\n");

    printf("Dono do veículo com CPF %s excluído com sucesso!\n", cpf);
    printf("\n");
    printf("\t >>Tecle <ENTER> para continuar...\n");
}
