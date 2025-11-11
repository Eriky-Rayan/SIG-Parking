#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "../include/estacionamentos.h"
#include "../include/validacoes.h"

typedef struct estacionamentos Estacionamentos;

//=====================================
//= Funções do Módulo Estacionamentos =
//=====================================

void switch_estacionamentos(void) {
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
    printf("||                                  -SIG-Parking-                                  ||\n");
    printf("=====================================================================================\n");
    printf("||                             -Módulo Estacionamentos-                            ||\n");
    printf("=====================================================================================\n");
    printf("|| [1] -> Cadastrar Estacionamento                                                 ||\n");
    printf("|| [2] -> Exibir Dados do Estacionamento                                           ||\n");
    printf("|| [3] -> Alterar Dados do Estacionamento                                          ||\n");
    printf("|| [4] -> Excluir Estacionamento                                                   ||\n");
    printf("|| [5] -> Recuperar registro do Estacionamento                                     ||\n");
    printf("|| [0] -> Voltar ao Menu Principal                                                 ||\n");
    printf("=====================================================================================\n");
    printf("\n\t >>Escolha uma opção: ");
    Ler_Opcao_Menu(&op);
    printf("\n");
    return op;
}

void add_estacionamentos(void) {
    system("clear||cls");

    FILE *arq_estacionamentos;
    Estacionamentos *estacionamento;

    verifica_diretorio_dados(); // ✅ Garante diretório

    printf("\n=====================================================================================\n");
    printf("||                -Módulo Estacionamentos -> Cadastrar Estacionamento-             ||\n");
    printf("=====================================================================================\n\n");

    estacionamento = (Estacionamentos*) malloc(sizeof(Estacionamentos));

    printf(" >>Digite o Nº da vaga onde o veículo será cadastrado.\n");
    Ler_Estacionamento(estacionamento->n_estaci);
    printf("\n");
    Ler_Placa(estacionamento->placa);
    printf("\n");

    estacionamento->status = True;
    arq_estacionamentos = fopen("dados/estacionamentos.dat", "ab");
    if (arq_estacionamentos == NULL) {
        printf("\tErro ao abrir o arquivo de estacionamentos.\n");
        printf("\t>>Tecle <ENTER> para continuar...\n");
        getchar();
        free(estacionamento);
        return;
    }

    fwrite(estacionamento, sizeof(Estacionamentos), 1, arq_estacionamentos);
    fclose(arq_estacionamentos);

    printf("✅ Veículo cadastrado e salvo no arquivo com sucesso!\n");
    printf("\nNº da vaga: %s\nPlaca: %s\n", estacionamento->n_estaci, estacionamento->placa);
    printf("\n\t>>Tecle <ENTER> para continuar...\n");
    getchar();

    free(estacionamento);
}

void exib_estacionamentos(void) {
    system("clear||cls");

    FILE *arq_estacionamentos;
    Estacionamentos *estacionamento;
    char n_estaci_lida[8];
    int encontrado = 0;

    verifica_diretorio_dados(); // ✅

    printf("\n=====================================================================================\n");
    printf("||                -Módulo Estacionamentos -> Exibir Estacionamento-                ||\n");
    printf("=====================================================================================\n\n");

    estacionamento = (Estacionamentos*)malloc(sizeof(Estacionamentos));
    printf(" >>Digite o Nº da vaga que deseja ver:\n");
    Ler_Estacionamento(n_estaci_lida);
    printf("\n");

    arq_estacionamentos = fopen("dados/estacionamentos.dat", "rb");
    if (arq_estacionamentos == NULL) {
        printf("\tErro ao abrir o arquivo de estacionamentos.\n");
        printf("\t>>Tecle <ENTER> para continuar...\n");
        getchar();
        free(estacionamento);
        return;
    }

    while (fread(estacionamento, sizeof(Estacionamentos), 1, arq_estacionamentos)) {
        if ((strcmp(estacionamento->n_estaci, n_estaci_lida) == 0) && (estacionamento->status)) {
            encontrado = 1;
            printf("\n✅ Estacionamento encontrado!\n");
            printf("Nº da vaga: %s\n", estacionamento->n_estaci);
            printf("Placa: %s\n", estacionamento->placa);
            break;
        }
    }

    fclose(arq_estacionamentos);
    free(estacionamento);

    if (!encontrado)
        printf("❌ Nº da vaga não encontrado!\n");

    printf("\n\t>>Tecle <ENTER> para continuar...\n");
    getchar();
}

void alterar_estacionamentos(void) {
    system("clear||cls");

    FILE *arq_estacionamentos;
    Estacionamentos *estacionamento;
    char n_estaci_lida[8];
    int encontrado = 0;

    verifica_diretorio_dados(); // ✅

    printf("\n=====================================================================================\n");
    printf("||                -Módulo Estacionamentos -> Alterar Estacionamento-               ||\n");
    printf("=====================================================================================\n\n");

    estacionamento = (Estacionamentos*)malloc(sizeof(Estacionamentos));
    printf(" >>Digite o Nº da vaga que deseja alterar:\n");
    Ler_Estacionamento(n_estaci_lida);
    printf("\n");

    arq_estacionamentos = fopen("dados/estacionamentos.dat", "r+b");
    if (arq_estacionamentos == NULL) {
        printf("\tErro ao abrir o arquivo de estacionamentos.\n");
        printf("\t>>Tecle <ENTER> para continuar...\n");
        getchar();
        free(estacionamento);
        return;
    }

    while (fread(estacionamento, sizeof(Estacionamentos), 1, arq_estacionamentos)) {
        if ((strcmp(estacionamento->n_estaci, n_estaci_lida) == 0) && (estacionamento->status)) {
            encontrado = 1;
            printf(" >>Digite os novos dados da vaga:\n");
            Ler_Estacionamento(estacionamento->n_estaci);
            printf("\n");
            Ler_Placa(estacionamento->placa);
            fseek(arq_estacionamentos, (-1)*sizeof(Estacionamentos), SEEK_CUR);
            fwrite(estacionamento, sizeof(Estacionamentos), 1, arq_estacionamentos);
            break;
        }
    }

    fclose(arq_estacionamentos);
    free(estacionamento);

    if (encontrado)
        printf("✅ Vaga alterada e salva com sucesso!\n");
    else
        printf("❌ Nº da vaga não encontrado!\n");

    printf("\n\t>>Tecle <ENTER> para continuar...\n");
    getchar();
}

void exclu_logica_estacionamentos(void) {
    system("clear||cls");

    FILE *arq_estacionamentos;
    Estacionamentos *estacionamento;
    char n_estaci_lida[8];
    int encontrado = 0;

    verifica_diretorio_dados(); // ✅

    printf("\n=====================================================================================\n");
    printf("||                -Módulo Estacionamentos -> Excluir Estacionamento-               ||\n");
    printf("=====================================================================================\n\n");

    estacionamento = (Estacionamentos*)malloc(sizeof(Estacionamentos));
    printf(" >>Digite o Nº da vaga que deseja excluir:\n");
    Ler_Estacionamento(n_estaci_lida);
    printf("\n");

    arq_estacionamentos = fopen("dados/estacionamentos.dat", "r+b");
    if (arq_estacionamentos == NULL) {
        printf("\tErro ao abrir o arquivo de estacionamentos.\n");
        printf("\t>>Tecle <ENTER> para continuar...\n");
        getchar();
        free(estacionamento);
        return;
    }

    while (fread(estacionamento, sizeof(Estacionamentos), 1, arq_estacionamentos)) {
        if ((strcmp(estacionamento->n_estaci, n_estaci_lida) == 0) && (estacionamento->status)) {
            estacionamento->status = False;
            encontrado = 1;
            fseek(arq_estacionamentos, (-1)*sizeof(Estacionamentos), SEEK_CUR);
            fwrite(estacionamento, sizeof(Estacionamentos), 1, arq_estacionamentos);
            break;
        }
    }

    fclose(arq_estacionamentos);
    free(estacionamento);

    if (encontrado)
        printf("✅ Vaga %s excluída e salva no arquivo!\n", n_estaci_lida);
    else
        printf("❌ Nº da vaga não encontrado!\n");

    printf("\n\t>>Tecle <ENTER> para continuar...\n");
    getchar();
}

void recu_registro_estacionamentos(void) {
    system("clear||cls");

    FILE *arq_estacionamentos;
    Estacionamentos *estacionamento;
    char n_estaci_lida[8];
    int encontrado = 0;

    verifica_diretorio_dados(); // ✅

    printf("\n=====================================================================================\n");
    printf("||               -Módulo Estacionamentos -> Recuperar registro-                    ||\n");
    printf("=====================================================================================\n\n");

    estacionamento = (Estacionamentos*)malloc(sizeof(Estacionamentos));
    printf(" >>Digite o Nº da vaga a ser recuperada:\n");
    Ler_Estacionamento(n_estaci_lida);
    printf("\n");

    arq_estacionamentos = fopen("dados/estacionamentos.dat", "r+b");
    if (arq_estacionamentos == NULL) {
        printf("\tErro ao abrir o arquivo de estacionamentos.\n");
        printf("\t>>Tecle <ENTER> para continuar...\n");
        getchar();
        free(estacionamento);
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

    if (encontrado)
        printf("✅ Registro do estacionamento %s recuperado e salvo com sucesso!\n", n_estaci_lida);
    else
        printf("❌ Nº da vaga não encontrado!\n");

    printf("\n\t>>Tecle <ENTER> para continuar...\n");
    getchar();
}
