#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "cadastro_vagas.h"

//=======================================
//= Funções do Módulo Cadastro de Vagas =
//=======================================

void switch_cadastro_vagas(void){

    char op;

    do {
        op = cadastro_vagas();
        switch (op) {
            case '1': 
                add_cadastro_vagas();
                break;
            case '2': 
                exib_cadastro_vagas();
                break;
            case '3': 
                alterar_cadastro_vagas();
                break;
            case '4': 
                exclu_cadastro_vagas();
                break;
        }
    } while (op != '0');
}

char cadastro_vagas(void) {
    system("clear||cls");

    char op;

    printf("\n");
    printf("=====================================================================================\n");
    printf("||                                                                                 ||\n");
    printf("||                                  -SIG-Parking-                                  ||\n");
    printf("||                                                                                 ||\n");
    printf("=====================================================================================\n");
    printf("||                                                                                 ||\n");
    printf("||                            Módulo Cadastro de Vagas                             ||\n");
    printf("||                                                                                 ||\n");
    printf("=====================================================================================\n");
    printf("||                                                                                 ||\n");
    printf("|| [1] -> Cadastrar Vagas                                                          ||\n");
    printf("|| [2] -> Exibir Dados das Vagas                                                   ||\n");
    printf("|| [3] -> Alterar Dados das Vagas                                                  ||\n");
    printf("|| [4] -> Excluir Dados das Vagas                                                  ||\n");
    printf("|| [0] -> Voltar ao Menu Principal                                                 ||\n");
    printf("||                                                                                 ||\n");
    printf("=====================================================================================\n");
    printf("\n");
    printf("\t >>Tecle '0' para voltar ao Menu Principal: ");
    scanf("%c", &op);
    getchar();
    printf("\n");
    return op;
}

void add_cadastro_vagas(void) {
    system("clear||cls");

    int qtd_vagas;
    int num_andar;

    printf("\n");
    printf("=====================================================================================\n");
    printf("||                                                                                 ||\n");
    printf("||                                  -SIG-Parking-                                  ||\n");
    printf("||                                                                                 ||\n");
    printf("=====================================================================================\n");
    printf("||                                                                                 ||\n");
    printf("||                  -Módulo Cadastro de Vagas -> Cadastrar Vagas-                  ||\n");
    printf("||                                                                                 ||\n");
    printf("=====================================================================================\n");
    printf("\n");
    printf(" >>Digite a quantidade de vagas a ser cadastrada: ");
    scanf("%d", &qtd_vagas);
    getchar();
    printf("\n");
    printf(" >>Digite o número do andar: ");
    scanf("%d", &num_andar);
    getchar();
    printf("\n");

    printf("Vaga cadastrada com sucesso!\n");
    printf("\nQuantidade de vagas no andar: %d", qtd_vagas);
    printf("\nNúmero do andar: %d", num_andar);
    printf("\n");
    printf("\t >>Tecle <ENTER> para continuar...\n");
    getchar();
    printf("\n");
}

void exib_cadastro_vagas(void) {
    system("clear||cls");

    //int qtd_vagas;
    int num_andar;

    printf("\n");
    printf("=====================================================================================\n");
    printf("||                                                                                 ||\n");
    printf("||                                  -SIG-Parking-                                  ||\n");
    printf("||                                                                                 ||\n");
    printf("=====================================================================================\n");
    printf("||                                                                                 ||\n");
    printf("||                 -Módulo Cadastro de Vagas -> Exibir Dados das Vagas-            ||\n");
    printf("||                                                                                 ||\n");
    printf("=====================================================================================\n");
    printf("\n");
    printf(" >>Digite o número do andar: ");
    scanf("%d", &num_andar);
    getchar();
    printf("\n");
    printf("Será exibido a quantidade de vagas do seguinte andar: %d\n", num_andar);
    printf("\n");
    printf("\t >>Tecle <ENTER> para continuar...\n");
    getchar();
    printf("\n");
}

void alterar_cadastro_vagas(void) {
    system("clear||cls");

    int qtd_vagas;
    int num_andar;

    printf("\n");
    printf("=====================================================================================\n");
    printf("||                                                                                 ||\n");
    printf("||                                  -SIG-Parking-                                  ||\n");
    printf("||                                                                                 ||\n");
    printf("=====================================================================================\n");
    printf("||                                                                                 ||\n");
    printf("||               -Módulo Cadastro de Vagas -> Alterar Dados das Vagas-             ||\n");
    printf("||                                                                                 ||\n");
    printf("=====================================================================================\n");
    printf("\n");
    printf(" -Digite os novos dados das vagas-");
    printf("\n");
    printf(" >>Digite o número do andar: ");
    scanf("%d", &num_andar);
    getchar();
    printf("\n");
    printf(" >>Digite a quantidade de vagas a ser cadastrada: ");
    scanf("%d", &qtd_vagas);
    getchar();
    printf("\n");

    printf("Dados das vagas alterados com sucesso!\n");
    printf("\nQuantidade de vagas no andar: %d", qtd_vagas);
    printf("\nTNúmero do andar: %d", num_andar);
    printf("\n");
    printf("\t >>Tecle <ENTER> para continuar...\n");
    getchar();
    printf("\n");
}

void exclu_cadastro_vagas(void) {
    system("clear||cls");

    int num_andar;

    printf("\n");
    printf("=====================================================================================\n");
    printf("||                                                                                 ||\n");
    printf("||                                  -SIG-Parking-                                  ||\n");
    printf("||                                                                                 ||\n");
    printf("=====================================================================================\n");
    printf("||                                                                                 ||\n");
    printf("||                -Módulo Cadastro de Vagas -> Excluir Dados das Vagas-            ||\n");
    printf("||                                                                                 ||\n");
    printf("=====================================================================================\n");
    printf("\n");
    printf(" >>Digite o número do andar que deseja excluir: ");
    scanf("%d", &num_andar);
    getchar();
    printf("\n");

    printf("Vagas do andar %d excluídas com sucesso!\n", num_andar);
    printf("\n");
    printf("\t >>Tecle <ENTER> para continuar...\n");
    getchar();
    printf("\n");
}
