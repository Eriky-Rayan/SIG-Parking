#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
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
    printf("\t >>Escolha uma opção: ");
    scanf("%c", &op);
    getchar();
    printf("\n");
    return op;
}

void add_cadastro_vagas(void) {
    system("clear||cls");

    FILE *arq_cadastro_vagas;
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

    arq_cadastro_vagas = fopen("cadastro_vagas.csv", "at");
    if (arq_cadastro_vagas == NULL) {
        printf("\t Erro ao abrir o arquivo do cadastro das vagas.\n");
        printf("\t >>Tecle <ENTER> para continuar...\n");
        return;
    }
    fprintf(arq_cadastro_vagas, "%d;%d\n", qtd_vagas, num_andar);
    fclose(arq_cadastro_vagas);

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

    FILE *arq_cadastro_vagas;
    int qtd_vagas;
    int num_andar;
    int num_andar_lido;

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
    scanf("%d", &num_andar_lido);
    getchar();
    printf("\n");

    arq_cadastro_vagas = fopen("cadastro_vagas.csv", "rt");
    if (arq_cadastro_vagas == NULL) {
        printf("\t Erro ao abrir o arquivo de cadastro das vagas.\n");
        printf("\t >>Tecle <ENTER> para continuar...\n");
        getchar();
        return;
    }
    while (!feof(arq_cadastro_vagas )) {
        fscanf(arq_cadastro_vagas , "%d", &num_andar);
        fgetc(arq_cadastro_vagas );
        fscanf(arq_cadastro_vagas , "%d", &qtd_vagas);
        fgetc(arq_cadastro_vagas );
        if (num_andar == num_andar_lido) {
            printf("<<<Vaga encontrada>>");
            printf("\n");
            printf("Número do andar: %d\n", num_andar);
            printf("Quantidade de vagas: %d\n", qtd_vagas);
            printf("\t >>Tecle <ENTER> para continuar...\n");
            getchar();
            fclose(arq_cadastro_vagas);
            return;
        }
    }

    printf("A quantidade de vagas do seguinte andar foi exibida: %d\n", num_andar);
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
