#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "cadastro_vagas.h"

typedef struct cadastro_vagas CV;

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
    CV *vagas;

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
    vagas = (CV*)malloc(sizeof(CV));
    printf(" >>Digite a quantidade de vagas a ser cadastrada: ");
    scanf("%d", &vagas->qtd_vagas);
    getchar();
    printf("\n");
    printf(" >>Digite o número do andar: ");
    scanf("%d", &vagas->num_andar);
    getchar();
    printf("\n");

    vagas->status = True;
    arq_cadastro_vagas = fopen("cadastro_vagas.dat", "ab");
    if (arq_cadastro_vagas == NULL) {
        printf("\t Erro ao abrir o arquivo do cadastro das vagas.\n");
        printf("\t >>Tecle <ENTER> para continuar...\n");
        return;
    }
       
    fwrite(vagas, sizeof(CV), 1, arq_cadastro_vagas);
    fclose(arq_cadastro_vagas);

    printf("Vaga cadastrada com sucesso!\n");
    printf("\nQuantidade de vagas no andar: %d", vagas->qtd_vagas);
    printf("\nNúmero do andar: %d", vagas->num_andar);
    printf("\n");
    printf("\t >>Tecle <ENTER> para continuar...\n");
    getchar();
    printf("\n");
}

void exib_cadastro_vagas(void) {
    system("clear||cls");

    FILE *arq_cadastro_vagas;
    CV vagas;

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
    scanf("%d", &vagas.num_andar_lido);
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
        fscanf(arq_cadastro_vagas , "%d", &vagas.num_andar);
        fgetc(arq_cadastro_vagas );
        fscanf(arq_cadastro_vagas , "%d", &vagas.qtd_vagas);
        fgetc(arq_cadastro_vagas );
        if (vagas.num_andar == vagas.num_andar_lido) {
            printf("<<<Vaga encontrada>>");
            printf("\n");
            printf("Número do andar: %d\n", vagas.num_andar);
            printf("Quantidade de vagas: %d\n", vagas.qtd_vagas);
            printf("\t >>Tecle <ENTER> para continuar...\n");
            getchar();
            fclose(arq_cadastro_vagas);
            return;
        }
    }
    printf("A quantidade de vagas do seguinte andar foi exibida: %d\n", vagas.num_andar);
    printf("\n");
    printf("\t >>Tecle <ENTER> para continuar...\n");
    getchar();
    printf("\n");
}

void alterar_cadastro_vagas(void) {
    system("clear||cls");

    FILE *arq_cadastro_vagas;
    FILE *arq_cadastro_vagas_temp;
    CV vagas;

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
    scanf("%d", &vagas.num_andar_lido);
    getchar();
    printf("\n");

    arq_cadastro_vagas = fopen("cadastro_vagas.csv", "rt");
    arq_cadastro_vagas_temp = fopen("cadastro_vagas_temp.csv", "wt");
    if (arq_cadastro_vagas == NULL) {
        printf("\t Erro ao abrir o arquivo do cadastro das vagas.\n");
        printf("\t >>Tecle <ENTER> para continuar...\n");
        return;
    }

    while (fscanf(arq_cadastro_vagas, "%d;%d\n", &vagas.qtd_vagas, &vagas.num_andar) == 2) {

        if (vagas.num_andar != vagas.num_andar_lido) {
            fprintf(arq_cadastro_vagas_temp, "%d;%d\n", vagas.qtd_vagas, vagas.num_andar);
        } 
        else {
            printf("\n");
            printf(" >>Digite a nova quantidade de vagas: ");
            scanf("%d", &vagas.qtd_vagas);
            getchar();
            printf("\n");

            fprintf(arq_cadastro_vagas_temp, "%d;%d\n", vagas.qtd_vagas, vagas.num_andar_lido);
        }
    }

    fclose(arq_cadastro_vagas);
    fclose(arq_cadastro_vagas_temp);

    remove("cadastro_vagas.csv");
    rename("cadastro_vagas_temp.csv", "cadastro_vagas.csv");

    printf("Dados das vagas alterados com sucesso!\n");
    printf("\t >>Tecle <ENTER> para continuar...\n");
    getchar();
    printf("\n");
}

void exclu_cadastro_vagas(void) {
    system("clear||cls");

    FILE *arq_cadastro_vagas;
    FILE *arq_cadastro_vagas_temp;
    CV vagas;

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
    scanf("%d", &vagas.num_andar_lido);
    getchar();
    printf("\n");

    arq_cadastro_vagas = fopen("cadastro_vagas.csv", "rt");
    arq_cadastro_vagas_temp = fopen("cadastro_vagas_temp.csv", "wt");
    if (arq_cadastro_vagas == NULL) {
        printf("\t Erro ao abrir o arquivo do cadastro das vagas.\n");
        printf("\t >>Tecle <ENTER> para continuar...\n");
        return;
    }

    while (fscanf(arq_cadastro_vagas, "%d;%d\n", &vagas.qtd_vagas, &vagas.num_andar) == 2) {

        if (vagas.num_andar != vagas.num_andar_lido) {
            fprintf(arq_cadastro_vagas_temp, "%d;%d\n", vagas.qtd_vagas, vagas.num_andar);
        }
    }

    fclose(arq_cadastro_vagas);
    fclose(arq_cadastro_vagas_temp);

    remove("cadastro_vagas.csv");
    rename("cadastro_vagas_temp.csv", "cadastro_vagas.csv");

    printf("Vagas do andar %d excluídas com sucesso!\n", vagas.num_andar_lido);
    printf("\n");
    printf("\t >>Tecle <ENTER> para continuar...\n");
    getchar();
    printf("\n");
}
