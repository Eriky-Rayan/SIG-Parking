#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "estacionamentos.h"
#include "validacoes.h"

typedef struct estacionamentos Estacionamentos;

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
                exclu_logica_estacionamentos();
                break;
            case '5':
                recu_registro_estacionamentos();
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
    printf("|| [5] -> Recuperar registro do Estacionamento                                     ||\n");
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
    Estacionamentos *estacionamento;

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
    estacionamento = (Estacionamentos*) malloc(sizeof(Estacionamentos));
    printf(" >>Digite o Nº da vaga onde o veículo será cadastrado: ");
    Ler_Estacionamento(estacionamento->n_estaci);
    printf("\n");
    printf(" >>Digite a placa do veículo: ");
    Ler_Placa(estacionamento->placa);
    printf("\n");

    estacionamento->status = True;
    arq_estacionamentos = fopen("estacionamentos.dat", "ab");
    if (arq_estacionamentos == NULL) {
        printf("\t Erro ao abrir o arquivo de estacionamentos.\n");
        printf("\t >>Tecle <ENTER> para continuar...\n");
        getchar();
        return;
    }

    fwrite(estacionamento, sizeof(Estacionamentos), 1, arq_estacionamentos);
    fclose(arq_estacionamentos);

    printf("Veículo cadastrado no estacionamento com sucesso!\n");
    printf("\nNº do estacionamento: %s", estacionamento->n_estaci);
    printf("\nPlaca: %s", estacionamento->placa);
    printf("\n");
    printf("\t >>Tecle <ENTER> para continuar...\n");
    getchar();
    printf("\n");

    free(estacionamento);
}

void exib_estacionamentos(void) {
    system("clear||cls");

    FILE *arq_estacionamentos;
    Estacionamentos *estacionamento;
    char n_estaci_lida[8];
    int encontrado = 0;

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
    estacionamento = (Estacionamentos*)malloc(sizeof(Estacionamentos));
    printf(" >>Digite Nº da vaga que deseja ver: ");
    Ler_Estacionamento_Lida(n_estaci_lida);
    printf("\n");

    arq_estacionamentos = fopen("estacionamentos.dat", "rb");
    if (arq_estacionamentos == NULL) {
        printf("\t Erro ao abrir o arquivo de dono_veiculo.\n");
        printf("\t >>Tecle <ENTER> para continuar...\n");
        getchar();
        return;
    }
    while (fread(estacionamento, sizeof(Estacionamentos), 1, arq_estacionamentos)) {
        if ((strcmp(estacionamento->n_estaci, n_estaci_lida) == 0) && (estacionamento->status)) {
            encontrado = 1;
            printf("<<<estacionamento encontrado>>");
            printf("\n");
            printf("Nº do estacionamento: %s\n", estacionamento->n_estaci);
            printf("placa: %s\n", estacionamento->placa);
            printf("\t >>Tecle <ENTER> para continuar...\n");
            getchar();
            return;
        }
    }

    fclose(arq_estacionamentos);
    free(estacionamento);

    if (encontrado) {
        printf("O veículo na seguinte vaga foi exibido: %s\n", n_estaci_lida);
    }
    else {
        printf("Nº da vaga não encontrado!\n");
    }
    printf("\n");
    printf("\t >>Tecle <ENTER> para continuar...\n");
    getchar();
    printf("\n");
}

void alterar_estacionamentos(void) {
    system("clear||cls");

    FILE *arq_estacionamentos;
    Estacionamentos *estacionamento;
    char n_estaci_lida[8];
    int encontrado = 0;

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
    estacionamento = (Estacionamentos*)malloc(sizeof(Estacionamentos));
    printf(" -Digite os novos dados do estacionamento-");
    printf("\n");
    printf(" >>Digite o Nº da vaga que deseja alterar: ");
    Ler_Estacionamento_Lida(n_estaci_lida);
    printf("\n");

    arq_estacionamentos = fopen("estacionamentos.dat", "r+b");
    if (arq_estacionamentos == NULL) {
        printf("\t Erro ao abrir o arquivo de veículos.\n");
        printf("\t >>tecle <ENTER> para continuar...\n");
        getchar();
        return;
    }

    while (fread(estacionamento, sizeof(Estacionamentos), 1, arq_estacionamentos)){
        if ((strcmp(estacionamento->n_estaci, n_estaci_lida) == 0) && (estacionamento->status)){
            encontrado = 1;
            printf("\n>>Digite o novo nº da vaga: ");
            Ler_Estacionamento(estacionamento->n_estaci);
            printf("\n");
            printf(" >>Digite a placa do veículo: ");
            Ler_Placa(estacionamento->placa);

            fseek(arq_estacionamentos, (-1)*sizeof(Estacionamentos), SEEK_CUR);
            fwrite(estacionamento, sizeof(Estacionamentos), 1, arq_estacionamentos);
        }
    }

    fclose(arq_estacionamentos);
    free(estacionamento);

    if (encontrado) {
        printf("Vaga de estacionamento alterada com sucesso!\n");
    }
    else {
        printf("Nº da vaga não encontrado!\n");
    }

    printf("\t >>Tecle <ENTER> para continuar...\n");
    getchar();
    printf("\n");
}

void exclu_logica_estacionamentos(void) {
    system("clear||cls");

    FILE *arq_estacionamentos;
    Estacionamentos *estacionamento;
    char n_estaci_lida[8];
    int encontrado = 0;

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
    estacionamento = (Estacionamentos*)malloc(sizeof(Estacionamentos));
    printf(" >>Digite o Nº da vaga que deseja excluir: ");
    scanf("%s", n_estaci_lida);
    getchar();
    printf("\n");
    
    arq_estacionamentos = fopen("estacionamentos.dat", "r+b");
    if (arq_estacionamentos == NULL) {
        printf("\t Erro ao abrir o arquivo de veículos.\n");
        printf("\t >>tecle <ENTER> para continuar...\n");
        getchar();
        return;
    }

    while (fread(estacionamento, sizeof(Estacionamentos), 1, arq_estacionamentos)) {
        if ((strcmp(estacionamento->n_estaci, n_estaci_lida) == 0) && (estacionamento->status)) {
            estacionamento->status = False;
            encontrado = 1;
            fseek(arq_estacionamentos, (-1)*sizeof(Estacionamentos), SEEK_CUR);
            fwrite(estacionamento, sizeof(Estacionamentos), 1, arq_estacionamentos);
        }
    }

    fclose(arq_estacionamentos);
    free(estacionamento);

    if (encontrado) {
        printf("O veículo na vaga %s excluído com sucesso!\n", n_estaci_lida);
    }
    else {
        printf("Nº da vaga não encontrado!\n");
    }

    printf("\n");
    printf("\t >>Tecle <ENTER> para continuar...\n");
    getchar();
    printf("\n");
}

void recu_registro_estacionamentos(void){
    system("clear||cls");

    FILE *arq_estacionamentos;
    Estacionamentos *estacionamento;
    char n_estaci_lida[8];
    int encontrado = 0;

    printf("\n");
    printf("=====================================================================================\n");
    printf("||                                                                                 ||\n");
    printf("||                                  -SIG-Parking-                                  ||\n");
    printf("||                                                                                 ||\n");
    printf("=====================================================================================\n");
    printf("||                                                                                 ||\n");
    printf("||               -Módulo Estacionamentos -> Recuperar registro -                   ||\n");
    printf("||                                                                                 ||\n");
    printf("=====================================================================================\n");
    printf("\n");
    estacionamento = (Estacionamentos*)malloc(sizeof(Estacionamentos));
    printf(" >>Digite o Nº da vaga a ser recuperada: ");
    scanf("%s", n_estaci_lida);
    getchar();
    printf("\n");

    arq_estacionamentos = fopen("estacionamentos.dat", "r+b");
    if (arq_estacionamentos == NULL) {
        printf("\t Erro ao abrir o arquivo de estacionamentos.\n");
        printf("\t >>Tecle <ENTER> para continuar...\n");
        getchar();
        return;
    }

    while (fread(estacionamento, sizeof(Estacionamentos), 1, arq_estacionamentos)) {
        if ((strcmp(estacionamento->n_estaci, n_estaci_lida) == 0) && (!estacionamento->status)) {
            estacionamento->status = True;
            encontrado = 1;
            fseek(arq_estacionamentos, (-1)*sizeof(Estacionamentos), SEEK_CUR);
            fwrite(estacionamento, sizeof(Estacionamentos), 1, arq_estacionamentos);
            break;
        }
    }

    fclose(arq_estacionamentos);
    free(estacionamento);

    if (encontrado) {
        printf("registro do Estacionamento com Nº %s recuperado logicamente com sucesso!\n", n_estaci_lida);
    } else {
        printf("Nº da vaga não encontrado!\n");
    }

    printf("\n");
    printf("\t >>Tecle <ENTER> para continuar...\n");
    getchar();
    printf("\n");
}