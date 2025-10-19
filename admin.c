#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "admin.h"

//==============================
//= Funções de Administrador   =
//==============================

void switch_admin(void){
    
    char op;

    do {
        op = admin();
        switch (op) {
            case '1': 
                exclu_veiculo();
                break;
            case '2': 
                exclu_estacionamentos();
                break;
            case '3': 
                exclu_dono_veiculo();
                break;
            case '4': 
                exclu_cadastro_vagas();
                break;
        }
    } while (op != '0');
}

char admin(void) {
    system("clear||cls");

    char op;

    printf("\n");
    printf("========================================================================================\n");
    printf("||                                                                                    ||\n");
    printf("||                                  -SIG-Parking-                                     ||\n");
    printf("||                                                                                    ||\n");
    printf("========================================================================================\n");
    printf("||                                                                                    ||\n");
    printf("||                             -Funções de Administrador-                             ||\n");
    printf("||                                                                                    ||\n");
    printf("========================================================================================\n");
    printf("||                                                                                    ||\n");
    printf("|| [1] -> Excluir Veículo                                                             ||\n");
    printf("|| [2] -> Excluir Estacionamentos                                                     ||\n");
    printf("|| [3] -> Excluir Dono de Veículo                                                     ||\n");
    printf("|| [4] -> Excluir Cadastro de Vagas                                                   ||\n");
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

void exclu_veiculo(void) {}

void exclu_estacionamentos(void) {}

void exclu_dono_veiculo(void) {}

void exclu_cadastro_vagas(void) {}

