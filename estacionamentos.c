#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "estacionamentos.h"

//=====================================
//= Funções do Módulo Estacionamentos =
//=====================================

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
    printf("=====================================================================================\n");
    printf("||                                                                                 ||\n");
    printf("||                                  -SIG-Parking-                                  ||\n");
    printf("||                                                                                 ||\n");
    printf("=====================================================================================\n");
    printf("||                                                                                 ||\n");
    printf("||                             -Módulo Estacionamentos-                            ||\n");
    printf("||                                                                                 ||\n");
    printf("=====================================================================================\n");
    printf("||                                                                                 ||\n");
    printf("|| [1] -> Cadastrar Estacionamento                                                 ||\n");
    printf("|| [2] -> Exibir Dados do Estacionamento                                           ||\n");
    printf("|| [3] -> Alterar Dados do Estacionamento                                          ||\n");
    printf("|| [4] -> Excluir Estacionamento                                                   ||\n");
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

void add_estacionamentos(void) {
    system("clear||cls");

    FILE *arq_estacionamentos;
    Estacionamentos estacionamento;

    printf("\n");
    printf("=====================================================================================\n");
    printf("||                                                                                 ||\n");
    printf("||                                  -SIG-Parking-                                  ||\n");
    printf("||                                                                                 ||\n");
    printf("=====================================================================================\n");
    printf("||                                                                                 ||\n");
    printf("||                -Módulo Estacionamentos -> Cadastrar Estacionamento-             ||\n");
    printf("||                                                                                 ||\n");
    printf("=====================================================================================\n");
    printf("\n");
    printf(" >>Digite o Nº da vaga onde o veículo será cadastrado: ");
    scanf("%s", estacionamento.n_estaci);
    getchar();
    printf("\n");
    printf(" >>Digite a placa do veículo: ");
    scanf("%s", estacionamento.placa);
    getchar();
    printf("\n");

    arq_estacionamentos = fopen("estacionamentos.csv", "at");
    if (arq_estacionamentos == NULL) {
        printf("\t Erro ao abrir o arquivo de estacionamentos.\n");
        printf("\t >>Tecle <ENTER> para continuar...\n");
        return;
    }
    fprintf(arq_estacionamentos, "%s;%s\n", estacionamento.n_estaci, estacionamento.placa);
    fclose(arq_estacionamentos);

    printf("Veículo cadastrado no estacionamento com sucesso!\n");
    printf("\nNº do estacionamento: %s", estacionamento.n_estaci);
    printf("\nPlaca: %s", estacionamento.placa);
    printf("\n");
    printf("\t >>Tecle <ENTER> para continuar...\n");
    getchar();
    printf("\n");
}

void exib_estacionamentos(void) {

    FILE *arq_estacionamentos;
    Estacionamentos estacionamento;

    printf("\n");
    printf("=====================================================================================\n");
    printf("||                                                                                 ||\n");
    printf("||                                  -SIG-Parking-                                  ||\n");
    printf("||                                                                                 ||\n");
    printf("=====================================================================================\n");
    printf("||                                                                                 ||\n");
    printf("||                -Módulo Estacionamentos -> Exibir Estacionamento-                ||\n");
    printf("||                                                                                 ||\n");
    printf("=====================================================================================\n");
    printf("\n");
    printf(" >>Digite Nº da vaga que deseja ver: ");
    scanf("%s", estacionamento.n_estaci_lida);
    getchar();
    printf("\n");

    arq_estacionamentos = fopen("estacionamentos.csv", "rt");
    if (arq_estacionamentos == NULL) {
        printf("\t Erro ao abrir o arquivo de dono_veiculo.\n");
        printf("\t >>Tecle <ENTER> para continuar...\n");
        getchar();
        return;
    }
    while (!feof(arq_estacionamentos)) {
        fscanf(arq_estacionamentos, "%[^;]", estacionamento.n_estaci);
        fgetc(arq_estacionamentos);
        fscanf(arq_estacionamentos, "%[^;]", estacionamento.placa);
        fgetc(arq_estacionamentos);
        if (strcmp(estacionamento.n_estaci, estacionamento.n_estaci_lida) == 0) {
            printf("<<<estacionamento encontrado>>");
            printf("\n");
            printf("Nº do estacionamento: %s\n", estacionamento.n_estaci);
            printf("placa: %s\n", estacionamento.placa);
            printf("\t >>Tecle <ENTER> para continuar...\n");
            getchar();
            fclose(arq_estacionamentos);
            return;
        }
    }
    printf("O veículo na seguinte vaga foi exibido: %s\n", estacionamento.n_estaci);
    printf("\n");
    printf("\t >>Tecle <ENTER> para continuar...\n");
    getchar();
    printf("\n");
}

void alterar_estacionamentos(void) {
    system("clear||cls");

    FILE *arq_estacionamentos;
    FILE *arq_estacionamentos_temp;
    Estacionamentos estacionamento;

    printf("\n");
    printf("=====================================================================================\n");
    printf("||                                                                                 ||\n");
    printf("||                                  -SIG-Parking-                                  ||\n");
    printf("||                                                                                 ||\n");
    printf("=====================================================================================\n");
    printf("||                                                                                 ||\n");
    printf("||                -Módulo Estacionamentos -> Alterar Estacionamento-               ||\n");
    printf("||                                                                                 ||\n");
    printf("=====================================================================================\n");
    printf("\n");
    printf(" -Digite os novos dados do estacionamento-");
    printf("\n");
    printf(" >>Digite o Nº da vaga que deseja alterar: ");
    scanf("%s", estacionamento.n_estaci_lida);
    getchar();
    printf("\n");

    arq_estacionamentos = fopen("estacionamentos.csv", "rt");
    arq_estacionamentos_temp = fopen("estacionamentos_temp.csv", "wt");
    if (arq_estacionamentos == NULL) {
        printf("\t Erro ao abrir o arquivo de veículos.\n");
        printf("\t >>tecle <ENTER> para continuar...\n");
        getchar();
        return;
    }

    while (fscanf(arq_estacionamentos, "%[^;];%[^\n]\n", estacionamento.n_estaci, estacionamento.placa) == 2){

        if (strcmp(estacionamento.n_estaci, estacionamento.n_estaci_lida) != 0){
            fprintf(arq_estacionamentos_temp, "%s;%s\n", estacionamento.n_estaci, estacionamento.placa);
        }
        else {
            printf("\n");
            printf(" >>Digite a placa do veículo: ");
            scanf("%s", estacionamento.placa);
            getchar();
            printf("\n");

            fprintf(arq_estacionamentos_temp, "%s;%s\n", estacionamento.n_estaci_lida, estacionamento.placa);
        }
    }

    fclose(arq_estacionamentos);
    fclose(arq_estacionamentos_temp);

    remove("estacionamentos.csv");
    rename("estacionamentos_temp.csv", "estacionamentos.csv");

    printf("Vaga de estacionamento alterada com sucesso!\n");
    printf("\t >>Tecle <ENTER> para continuar...\n");
    getchar();
    printf("\n");
}

void exclu_estacionamentos(void) {
    system("clear||cls");

    FILE *arq_estacionamentos;
    FILE *arq_estacionamentos_temp;
    Estacionamentos estacionamento;

    printf("\n");
    printf("=====================================================================================\n");
    printf("||                                                                                 ||\n");
    printf("||                                  -SIG-Parking-                                  ||\n");
    printf("||                                                                                 ||\n");
    printf("=====================================================================================\n");
    printf("||                                                                                 ||\n");
    printf("||                -Módulo Estacionamentos -> Excluir Estacionamento-               ||\n");
    printf("||                                                                                 ||\n");
    printf("=====================================================================================\n");
    printf("\n");
    printf(" >>Digite o Nº da vaga que deseja excluir: ");
    scanf("%s", estacionamento.n_estaci_lida);
    getchar();
    printf("\n");
    
    arq_estacionamentos = fopen("estacionamentos.csv", "rt");
    arq_estacionamentos_temp = fopen("estacionamentos_temp.csv", "wt");
    if (arq_estacionamentos == NULL) {
        printf("\t Erro ao abrir o arquivo de veículos.\n");
        printf("\t >>tecle <ENTER> para continuar...\n");
        getchar();
        return;
    }

    while (fscanf(arq_estacionamentos, "%[^;];%[^\n]\n", estacionamento.n_estaci, estacionamento.placa) == 2){

        if (strcmp(estacionamento.n_estaci, estacionamento.n_estaci_lida) != 0){
            fprintf(arq_estacionamentos_temp, "%s;%s\n", estacionamento.n_estaci, estacionamento.placa);
        }
    }

    fclose(arq_estacionamentos);
    fclose(arq_estacionamentos_temp);

    remove("estacionamentos.csv");
    rename("estacionamentos_temp.csv", "estacionamentos.csv");

    printf("O veículo na vaga %s excluído com sucesso!\n", estacionamento.n_estaci_lida);
    printf("\n");
    printf("\t >>Tecle <ENTER> para continuar...\n");
    getchar();
    printf("\n");
}