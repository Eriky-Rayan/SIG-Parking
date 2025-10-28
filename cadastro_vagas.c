#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "cadastro_vagas.h"
#include "validacoes.h"

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
                exclu_logica_cadastro_vagas();
                break;               
            case '5':
                recu_registro_cadastro_vagas();
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
    printf("|| [4] -> Excluir Vagas logicamente                                                ||\n");
    printf("|| [5] -> Recuperar registro das Vagas                                             ||\n");
    printf("|| [0] -> Voltar ao Menu Principal                                                 ||\n");
    printf("||                                                                                 ||\n");
    printf("=====================================================================================\n");
    printf("\n");
    printf("\t >>Escolha uma opção: ");
    Ler_Opcao_Menu(&op);
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
    Ler_qtd_vagas(&vagas->qtd_vagas);
    getchar();
    printf("\n");
    printf(" >>Digite o número do andar: ");
    Ler_num_andar(&vagas->num_andar);
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

    free(vagas);
}

void exib_cadastro_vagas(void) {
    system("clear||cls");

    FILE *arq_cadastro_vagas;
    CV *vagas;
    int num_andar_lido;
    int encontrado = 0;

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
    vagas = (CV*)malloc(sizeof(CV));
    printf(" >>Digite o número do andar: ");
    Ler_num_andar(&num_andar_lido);
    getchar();
    printf("\n");

    arq_cadastro_vagas = fopen("cadastro_vagas.dat", "rb");
    if (arq_cadastro_vagas == NULL) {
        printf("\t Erro ao abrir o arquivo de cadastro das vagas.\n");
        printf("\t >>Tecle <ENTER> para continuar...\n");
        getchar();
        return;
    }
    while (fread(vagas, sizeof(CV), 1, arq_cadastro_vagas)) {
        if ((vagas->num_andar == num_andar_lido) && (vagas->status)){
            encontrado = 1;
            printf("<<<Vaga encontrada>>\n");
            printf("Número do andar: %d\n", vagas->num_andar);
            printf("Quantidade de vagas: %d\n", vagas->qtd_vagas);
            break;
        }
    }

    fclose(arq_cadastro_vagas);
    free(vagas);

    if (encontrado) {
        printf("A quantidade de vagas do seguinte andar foi exibida: %d\n", num_andar_lido);
    }
    else{
        printf("\nAndar não encontrado!\n");
    }

    printf("\n");
    printf("\t >>Tecle <ENTER> para continuar...\n");
    getchar();
    printf("\n");
}

void alterar_cadastro_vagas(void) {
    system("clear||cls");

    FILE *arq_cadastro_vagas;
    CV *vagas;
    int num_andar_lido;
    int encontrado = 0;

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
    vagas = (CV*)malloc(sizeof(CV));
    printf(" -Digite os novos dados das vagas-");
    printf("\n");
    printf(" >>Digite o número do andar: ");
    Ler_num_andar(&num_andar_lido);
    getchar();
    printf("\n");

    arq_cadastro_vagas = fopen("cadastro_vagas.dat", "r+b");
    if (arq_cadastro_vagas == NULL) {
        printf("\t Erro ao abrir o arquivo do cadastro das vagas.\n");
        printf("\t >>Tecle <ENTER> para continuar...\n");
        return;
    }

    while (fread(vagas, sizeof(CV), 1, arq_cadastro_vagas)) {
        if ((vagas->num_andar == num_andar_lido) && (vagas->status)) {
            encontrado = 1;
            printf(" >>Digite a nova quantidade de vagas: ");
            Ler_qtd_vagas(&vagas->qtd_vagas);
            getchar();
            printf("\n");

            fseek(arq_cadastro_vagas, (-1)*sizeof(CV), SEEK_CUR);
            fwrite(vagas, sizeof(CV), 1, arq_cadastro_vagas);
            break;
        }
    }

    fclose(arq_cadastro_vagas);
    free(vagas);

    if (encontrado) {
        printf("\nDados das vagas alterados com sucesso!\n");
    } else {
        printf("\nAndar não encontrado!\n");
    }

    printf("\t >>Tecle <ENTER> para continuar...\n");
    getchar();
    printf("\n");
}

void exclu_logica_cadastro_vagas(void) {
    system("clear||cls");

    FILE *arq_cadastro_vagas;
    CV *vagas;
    int num_andar_lido;
    int encontrado = 0;

    printf("\n");
    printf("=====================================================================================\n");
    printf("||                                                                                 ||\n");
    printf("||                                  -SIG-Parking-                                  ||\n");
    printf("||                                                                                 ||\n");
    printf("=====================================================================================\n");
    printf("||                                                                                 ||\n");
    printf("||                -Módulo Cadastro de Vagas -> Excluir vagas logicamente -         ||\n");
    printf("||                                                                                 ||\n");
    printf("=====================================================================================\n");
    printf("\n");
    vagas = (CV*)malloc(sizeof(CV));
    printf(" >>Digite o número do andar que deseja excluir logicamente: ");
    Ler_num_andar(&num_andar_lido);
    getchar();
    printf("\n");

    arq_cadastro_vagas = fopen("cadastro_vagas.dat", "r+b");
    if (arq_cadastro_vagas == NULL) {
        printf("\t Erro ao abrir o arquivo do cadastro das vagas.\n");
        printf("\t >>Tecle <ENTER> para continuar...\n");
        getchar();
        return;
    }

    while (fread(vagas, sizeof(CV), 1, arq_cadastro_vagas)) {
        if ((vagas->num_andar == num_andar_lido) && (vagas->status)) {
            vagas->status = False;
            encontrado = 1;
            fseek(arq_cadastro_vagas, (-1)*sizeof(CV), SEEK_CUR);
            fwrite(vagas, sizeof(CV), 1, arq_cadastro_vagas);
            break;
        }
    }

    fclose(arq_cadastro_vagas);
    free(vagas);

    if (encontrado) {
        printf("Vagas do andar %d excluídas logicamente com sucesso!\n", num_andar_lido);
    } else {
        printf("\nAndar não encontrado!\n");
    }

    printf("\n");
    printf("\t >>Tecle <ENTER> para continuar...\n");
    getchar();
    printf("\n");
}

void recu_registro_cadastro_vagas(void) {
    system("clear||cls");

    FILE *arq_cadastro_vagas;
    CV *vagas;
    int num_andar_lido;
    int encontrado = 0;

    printf("\n");
    printf("=====================================================================================\n");
    printf("||                                                                                 ||\n");
    printf("||                                  -SIG-Parking-                                  ||\n");
    printf("||                                                                                 ||\n");
    printf("=====================================================================================\n");
    printf("||                                                                                 ||\n");
    printf("||                -Módulo Cadastro de Vagas -> Recuperar registro -                ||\n");
    printf("||                                                                                 ||\n");
    printf("=====================================================================================\n");
    printf("\n");
    vagas = (CV*)malloc(sizeof(CV));
    printf(" >>Digite o número do andar que deseja recuperar: ");
    Ler_num_andar(&num_andar_lido);
    getchar();
    printf("\n");

    arq_cadastro_vagas = fopen("cadastro_vagas.dat", "r+b");
    if (arq_cadastro_vagas == NULL) {
        printf("\t Erro ao abrir o arquivo do cadastro das vagas.\n");
        printf("\t >>Tecle <ENTER> para continuar...\n");
        getchar();
        return;
    }

    while (fread(vagas, sizeof(CV), 1, arq_cadastro_vagas)) {
        if ((vagas->num_andar == num_andar_lido) && (!vagas->status)) {
            vagas->status = True;
            encontrado = 1;
            fseek(arq_cadastro_vagas, (-1)*sizeof(CV), SEEK_CUR);
            fwrite(vagas, sizeof(CV), 1, arq_cadastro_vagas);
            break;
        }
    }

    fclose(arq_cadastro_vagas);
    free(vagas);

    if (encontrado) {
        printf("Registro de Vagas do andar %d recuperadas logicamente com sucesso!\n", num_andar_lido);
    } else {
        printf("\nAndar não encontrado!\n");
    }

    printf("\n");
    printf("\t >>Tecle <ENTER> para continuar...\n");
    getchar();
    printf("\n");
}