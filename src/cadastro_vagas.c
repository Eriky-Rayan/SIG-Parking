#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#include "../include/cadastro_vagas.h"
#include "../include/validacoes.h"

// Estrutura para facilitar
typedef struct cadastro_vagas CV;

// ============================
// MENU PRINCIPAL
// ============================
void switch_cadastro_vagas(void) {
    char op;
    do {
        op = cadastro_vagas();
        switch (op) {
            case '1': add_cadastro_vagas(); break;
            case '2': exib_cadastro_vagas(); break;
            case '3': alterar_cadastro_vagas(); break;
            case '4': exclu_logica_cadastro_vagas(); break;
            case '5': recu_registro_cadastro_vagas(); break;
        }
    } while (op != '0');
}

char cadastro_vagas(void) {
    system("clear||cls");
    char op;

    printf("\n");
    printf("=====================================================================================\n");
    printf("||                                  - SIG-Parking -                                 ||\n");
    printf("=====================================================================================\n");
    printf("||                          Módulo Cadastro de Andares                              ||\n");
    printf("=====================================================================================\n");
    printf("|| [1] -> Cadastrar Andar                                                          ||\n");
    printf("|| [2] -> Exibir Andar                                                             ||\n");
    printf("|| [3] -> Alterar Andar                                                            ||\n");
    printf("|| [4] -> Excluir Andar (lógico)                                                  ||\n");
    printf("|| [5] -> Recuperar Andar                                                          ||\n");
    printf("|| [0] -> Voltar ao Menu Principal                                                ||\n");
    printf("=====================================================================================\n");

    Ler_Opcao_Menu(&op);
    return op;
}

// ============================
// CADASTRAR ANDAR
// ============================
void add_cadastro_vagas(void) {
    system("clear||cls");
    verifica_diretorio_dados();

    FILE *arq = fopen(ARQ_VAGAS, "ab");
    if (!arq) {
        printf("\nErro ao abrir arquivo de vagas!\nPressione ENTER...\n");
        getchar();
        return;
    }

    CV *andar = malloc(sizeof(CV));
    if (!andar) {
        printf("\nErro de memória!\nPressione ENTER...\n");
        fclose(arq);
        return;
    }

    printf("\n=====================================================================================\n");
    printf("||                   - Cadastro de Andar -> Nova Entrada -                          ||\n");
    printf("=====================================================================================\n");

    Ler_num_andar(&andar->num_andar);
    Ler_num_vaga(&andar->total_vagas);
    andar->status = True;

    fwrite(andar, sizeof(CV), 1, arq);
    fclose(arq);

    printf("\nAndar cadastrado com sucesso!\nNúmero do andar: %d | Total de vagas: %d\n",
           andar->num_andar, andar->total_vagas);
    printf("Pressione ENTER...\n");
    getchar();

    free(andar);
}

// ============================
// EXIBIR ANDAR
// ============================
void exib_cadastro_vagas(void) {
    system("clear||cls");
    verifica_diretorio_dados();

    FILE *arq = fopen(ARQ_VAGAS, "rb");
    if (!arq) {
        printf("\nNenhum andar cadastrado!\nPressione ENTER...\n");
        getchar();
        return;
    }

    CV *andar = malloc(sizeof(CV));
    int num_lido, encontrado = 0;

    printf("\n=====================================================================================\n");
    printf("||               - Cadastro de Andar -> Exibir Dados -                              ||\n");
    printf("=====================================================================================\n");

    Ler_num_andar(&num_lido);

    while (fread(andar, sizeof(CV), 1, arq)) {
        if ((andar->num_andar == num_lido) && andar->status) {
            encontrado = 1;
            printf("\n<<< Andar Encontrado >>>\n");
            printf("Número do andar: %d | Total de vagas: %d\n", andar->num_andar, andar->total_vagas);
            break;
        }
    }

    if (!encontrado)
        printf("\nAndar não encontrado!\n");

    printf("Pressione ENTER...\n");
    getchar();
    free(andar);
    fclose(arq);
}

// ============================
// ALTERAR ANDAR
// ============================
void alterar_cadastro_vagas(void) {
    system("clear||cls");
    verifica_diretorio_dados();

    FILE *arq = fopen(ARQ_VAGAS, "r+b");
    if (!arq) {
        printf("\nErro ao abrir arquivo de vagas!\nPressione ENTER...\n");
        getchar();
        return;
    }

    CV *andar = malloc(sizeof(CV));
    int andar_lido, encontrado = 0;

    printf("\n=====================================================================================\n");
    printf("||               - Cadastro de Andar -> Alterar Dados -                              ||\n");
    printf("=====================================================================================\n");

    Ler_num_andar(&andar_lido);

    while (fread(andar, sizeof(CV), 1, arq)) {
        if ((andar->num_andar == andar_lido) && andar->status) {
            encontrado = 1;

            printf("\nInforme os novos dados do andar:\n");
            Ler_num_andar(&andar->num_andar);
            Ler_num_vaga(&andar->total_vagas);

            fseek(arq, -sizeof(CV), SEEK_CUR);
            fwrite(andar, sizeof(CV), 1, arq);
            break;
        }
    }

    if (encontrado)
        printf("\nDados do andar alterados com sucesso!\n");
    else
        printf("\nAndar não encontrado!\n");

    printf("Pressione ENTER...\n");
    getchar();
    free(andar);
    fclose(arq);
}

// ============================
// EXCLUSÃO LÓGICA
// ============================
void exclu_logica_cadastro_vagas(void) {
    system("clear||cls");
    verifica_diretorio_dados();

    FILE *arq = fopen(ARQ_VAGAS, "r+b");
    if (!arq) {
        printf("\nErro ao abrir arquivo de vagas!\nPressione ENTER...\n");
        getchar();
        return;
    }

    CV *andar = malloc(sizeof(CV));
    int andar_lido, encontrado = 0;

    printf("\n=====================================================================================\n");
    printf("||               - Cadastro de Andar -> Exclusão Lógica -                            ||\n");
    printf("=====================================================================================\n");

    Ler_num_andar(&andar_lido);

    while (fread(andar, sizeof(CV), 1, arq)) {
        if ((andar->num_andar == andar_lido) && andar->status) {
            encontrado = 1;
            andar->status = False;

            fseek(arq, -sizeof(CV), SEEK_CUR);
            fwrite(andar, sizeof(CV), 1, arq);
            break;
        }
    }

    if (encontrado)
        printf("\nAndar marcado como excluído!\n");
    else
        printf("\nAndar não encontrado!\n");

    printf("Pressione ENTER...\n");
    getchar();
    free(andar);
    fclose(arq);
}

// ============================
// RECUPERAR ANDAR
// ============================
void recu_registro_cadastro_vagas(void) {
    system("clear||cls");
    verifica_diretorio_dados();

    FILE *arq = fopen(ARQ_VAGAS, "r+b");
    if (!arq) {
        printf("\nErro ao abrir arquivo de vagas!\nPressione ENTER...\n");
        getchar();
        return;
    }

    CV *andar = malloc(sizeof(CV));
    int andar_lido, encontrado = 0;

    printf("\n=====================================================================================\n");
    printf("||               - Cadastro de Andar -> Recuperar Registro -                         ||\n");
    printf("=====================================================================================\n");

    Ler_num_andar(&andar_lido);

    while (fread(andar, sizeof(CV), 1, arq)) {
        if ((andar->num_andar == andar_lido) && !andar->status) {
            encontrado = 1;
            andar->status = True;

            fseek(arq, -sizeof(CV), SEEK_CUR);
            fwrite(andar, sizeof(CV), 1, arq);
            break;
        }
    }

    if (encontrado)
        printf("\nAndar recuperado com sucesso!\n");
    else
        printf("\nAndar não encontrado!\n");

    printf("Pressione ENTER...\n");
    getchar();
    free(andar);
    fclose(arq);
}
