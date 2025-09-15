#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "relatorios.h"

//===============================
//= Funções do Módulo Relatorio =
//===============================

void switch_relatorio(void){

    char op;

    do {
        op = relatorio();
        switch (op) {
            case '1': 
                relatorio_veiculos();
                break;
            case '2': 
                relatorio_estacionamentos();
                break;
            case '3': 
                relatorio_dono_veiculo();
                break;
            case '4': 
                relatorio_veiculo_estacionamento_dono();
                break;
        }
    } while (op != '0');
}

char relatorio(void) {
    system("clear||cls");

    char op;

    printf("\n");
    printf("=====================================================================================\n");
    printf("||                                                                                 ||\n");
    printf("||                                  -SIG-Parking-                                  ||\n");
    printf("||                                                                                 ||\n");
    printf("=====================================================================================\n");
    printf("||                                                                                 ||\n");
    printf("||                                 Módulo Relatórios                               ||\n");
    printf("||                                                                                 ||\n");
    printf("=====================================================================================\n");
    printf("||                                                                                 ||\n");
    printf("|| [1] ⟶ Relatório de Veículos Cadastrados                                         ||\n");
    printf("|| [2] ⟶ Relatório de Estacionamentos                                              ||\n");
    printf("|| [3] ⟶ Relatório de Donos dos Veículos                                           ||\n");
    printf("|| [4] ⟶ Relatório de Veículo/Estacionamento/Dono                                  ||\n");
    printf("|| [0] ⟶ Voltar ao Menu Principal                                                  ||\n");
    printf("||                                                                                 ||\n");
    printf("=====================================================================================\n");
    printf("\n");
    printf("\t >>Escolha uma opção: ");
    scanf("%c", &op);
    getchar();
    printf("\n");
    return op;
}

void relatorio_veiculos(void) {
    system("clear||cls");

    printf("\n");
    printf("=====================================================================================\n");
    printf("||                                                                                 ||\n");
    printf("||                                  -SIG-Parking-                                  ||\n");
    printf("||                                                                                 ||\n");
    printf("=====================================================================================\n");
    printf("||                                                                                 ||\n");
    printf("||                     -Módulo Relatórios - Veículos Cadastrados-                  ||\n");
    printf("||                                                                                 ||\n");
    printf("=====================================================================================\n");
    printf("\n");
    printf("Relatório de veículos cadastrados gerado com sucesso!\n");
    printf("\n");
    printf("\t >>Tecle <ENTER> para continuar...\n");
    getchar();
}

void relatorio_estacionamentos(void) {
    system("clear||cls");

    printf("\n");
    printf("=====================================================================================\n");
    printf("||                                                                                 ||\n");
    printf("||                                  -SIG-Parking-                                  ||\n");
    printf("||                                                                                 ||\n");
    printf("=====================================================================================\n");
    printf("||                                                                                 ||\n");
    printf("||                     -Módulo Relatórios - Estacionamentos-                       ||\n");
    printf("||                                                                                 ||\n");
    printf("=====================================================================================\n");
    printf("\n");
    printf("Relatório de estacionamentos gerado com sucesso!\n");
    printf("\n");
    printf("\t >>Tecle <ENTER> para continuar...\n");
    getchar();
}

void relatorio_dono_veiculo(void) {
    system("clear||cls");

    printf("\n");
    printf("=====================================================================================\n");
    printf("||                                                                                 ||\n");
    printf("||                                  -SIG-Parking-                                  ||\n");
    printf("||                                                                                 ||\n");
    printf("=====================================================================================\n");
    printf("||                                                                                 ||\n");
    printf("||                    -Módulo Relatórios - Donos dos Veículos-                     ||\n");
    printf("||                                                                                 ||\n");
    printf("=====================================================================================\n");
    printf("\n");
    printf("Relatório de donos dos veículos gerado com sucesso!\n");
    printf("\n");
    printf("\t >>Tecle <ENTER> para continuar...\n");
    getchar();
}

void relatorio_veiculo_estacionamento_dono(void) {
    system("clear||cls");

    printf("\n");
    printf("=====================================================================================\n");
    printf("||                                                                                 ||\n");
    printf("||                                  -SIG-Parking-                                  ||\n");
    printf("||                                                                                 ||\n");
    printf("=====================================================================================\n");
    printf("||                                                                                 ||\n");
    printf("||                -Módulo Relatórios - Veículo/Estacionamento/Dono-                ||\n");
    printf("||                                                                                 ||\n");
    printf("=====================================================================================\n");
    printf("\n");
    printf("Relatório de veículo/estacionamento/dono gerado com sucesso!\n");
    printf("\n");
    printf("\t >>Tecle <ENTER> para continuar...\n");
    getchar();
}