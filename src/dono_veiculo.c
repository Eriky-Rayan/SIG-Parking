#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include "../include/dono_veiculo.h"
#include "../include/validacoes.h"
#include "../include/veiculos.h"

// ==============================
// Função auxiliar - verifica se o veículo existe
// ==============================
int verifica_veiculo_existe(const char *placa) {
    FILE *arq = fopen("dados/veiculos.dat", "rb");
    Veiculos v;

    if (!arq) return 0;

    while (fread(&v, sizeof(Veiculos), 1, arq)) {
        if (strcmp(v.placa, placa) == 0 && v.status == True) {
            fclose(arq);
            return 1;
        }
    }

    fclose(arq);
    return 0;
}

// ==============================
// Menu principal
// ==============================
void switch_dono_veiculo(void) {
    char op;
    do {
        op = dono_veiculo();
        switch (op) {
            case '1': add_dono_veiculo(); break;
            case '2': exib_dono_veiculo(); break;
            case '3': alterar_dono_veiculo(); break;
            case '4': exclu_logica_dono_veiculo(); break;
            case '5': recu_registro_dono_veiculo(); break;
        }
    } while (op != '0');
}

char dono_veiculo(void) {
    system("clear||cls");
    char op;
    printf("\n=====================================================================\n");
    printf("||                       - SIG-Parking -                           ||\n");
    printf("=====================================================================\n");
    printf("||                       Módulo Dono Veículo                       ||\n");
    printf("=====================================================================\n");
    printf("|| [1] -> Cadastrar Dono                                           ||\n");
    printf("|| [2] -> Exibir Dono                                              ||\n");
    printf("|| [3] -> Alterar Dono                                             ||\n");
    printf("|| [4] -> Exclusão lógica                                          ||\n");
    printf("|| [5] -> Recuperar dono                                           ||\n");
    printf("|| [0] -> Voltar                                                   ||\n");
    printf("=====================================================================\n");
    printf(">> Escolha uma opção: ");
    Ler_Opcao_Menu(&op);
    return op;
}

// ==============================
// Cadastrar dono do veículo
// ==============================
void add_dono_veiculo(void) {
    system("clear||cls");
    verifica_diretorio_dados();

    FILE *arq = fopen(ARQ_DONO_VEICULO, "ab");
    DV dono;
    char placa[12];

    if (!arq) {
        printf("\nERRO ao abrir o arquivo de donos!\nTecle ENTER...");
        getchar();
        return;
    }

    printf("\n====================== Cadastro do Dono ======================\n\n");

    Ler_CPF(dono.cpf);
    Ler_Telefone(dono.telefone);
    Ler_Nome(dono.nome, sizeof(dono.nome));

    // Solicitar placa do carro
    printf("\nInforme a PLACA do carro: ");
    Ler_Placa(placa);

    if (!verifica_veiculo_existe(placa)) {
        printf("\n>>> ERRO: Este veículo NÃO existe! Cadastre-o primeiro no módulo Veículos.\n");
        printf("Tecle ENTER para voltar...");
        getchar();
        fclose(arq);
        return;
    }

    strcpy(dono.placa, placa);
    dono.status = True;

    fwrite(&dono, sizeof(DV), 1, arq);
    fclose(arq);

    printf("\nDono cadastrado com sucesso!\n");
    printf("CPF: %s\nNome: %s\nTelefone: %s\nPlaca: %s\n", dono.cpf, dono.nome, dono.telefone, dono.placa);
    printf("\nTecle ENTER para continuar...");
    getchar();
}

// ==============================
// Exibir dono
// ==============================
void exib_dono_veiculo(void) {
    system("clear||cls");

    FILE *arq = fopen(ARQ_DONO_VEICULO, "rb");
    DV dono;
    char cpf_busca[15];
    int achou = 0;

    if (!arq) {
        printf("\nNenhum dono cadastrado ainda.\nTecle ENTER...");
        getchar();
        return;
    }

    printf("\nDigite o CPF para buscar: ");
    Ler_CPF(cpf_busca);

    while (fread(&dono, sizeof(DV), 1, arq)) {
        if (strcmp(dono.cpf, cpf_busca) == 0 && dono.status == True) {
            achou = 1;
            printf("\n=== Dono Encontrado ===\n");
            printf("CPF: %s\nNome: %s\nTelefone: %s\nPlaca: %s\n", dono.cpf, dono.nome, dono.telefone, dono.placa);
            break;
        }
    }

    fclose(arq);

    if (!achou)
        printf("\nCPF não encontrado!\n");

    printf("Tecle ENTER...");
    getchar();
}

// ==============================
// Alterar dono
// ==============================
void alterar_dono_veiculo(void) {
    system("clear||cls");
    FILE *arq = fopen(ARQ_DONO_VEICULO, "r+b");
    DV dono;
    char cpf_busca[15];
    int achou = 0;

    if (!arq) {
        printf("\nErro ao abrir arquivo!\nTecle ENTER...");
        getchar();
        return;
    }

    printf("\nCPF para alterar: ");
    Ler_CPF(cpf_busca);

    while (fread(&dono, sizeof(DV), 1, arq)) {
        if (strcmp(dono.cpf, cpf_busca) == 0 && dono.status == True) {
            achou = 1;

            Ler_Telefone(dono.telefone);
            Ler_Nome(dono.nome, sizeof(dono.nome));

            fseek(arq, -sizeof(DV), SEEK_CUR);
            fwrite(&dono, sizeof(DV), 1, arq);
            break;
        }
    }

    fclose(arq);

    if (achou)
        printf("\nDados alterados com sucesso!\n");
    else
        printf("\nCPF não encontrado!\n");

    printf("Tecle ENTER...");
}

// ==============================
// Exclusão lógica
// ==============================
void exclu_logica_dono_veiculo(void) {
    system("clear||cls");

    FILE *arq = fopen(ARQ_DONO_VEICULO, "r+b");
    DV dono;
    char cpf_busca[15];
    int achou = 0;

    if (!arq) {
        printf("\nErro ao abrir arquivo!\nTecle ENTER...");
        getchar();
        return;
    }

    printf("\nCPF para excluir: ");
    Ler_CPF(cpf_busca);

    while (fread(&dono, sizeof(DV), 1, arq)) {
        if (strcmp(dono.cpf, cpf_busca) == 0 && dono.status == True) {
            dono.status = False;
            achou = 1;
            fseek(arq, -sizeof(DV), SEEK_CUR);
            fwrite(&dono, sizeof(DV), 1, arq);
            break;
        }
    }

    fclose(arq);

    if (achou)
        printf("\nExclusão lógica feita.\n");
    else
        printf("\nCPF não encontrado!\n");

    printf("Tecle ENTER...");
}

// ==============================
// Recuperar registro
// ==============================
void recu_registro_dono_veiculo(void) {
    system("clear||cls");

    FILE *arq = fopen(ARQ_DONO_VEICULO, "r+b");
    DV dono;
    char cpf_busca[15];
    int achou = 0;

    if (!arq) {
        printf("\nErro ao abrir arquivo!\nTecle ENTER...");
        getchar();
        return;
    }

    printf("\nCPF para recuperar: ");
    Ler_CPF(cpf_busca);

    while (fread(&dono, sizeof(DV), 1, arq)) {
        if (strcmp(dono.cpf, cpf_busca) == 0 && dono.status == False) {
            dono.status = True;
            achou = 1;
            fseek(arq, -sizeof(DV), SEEK_CUR);
            fwrite(&dono, sizeof(DV), 1, arq);
            break;
        }
    }

    fclose(arq);

    if (achou)
        printf("\nRegistro recuperado!\n");
    else
        printf("\nCPF não encontrado!\n");

    printf("Tecle ENTER...");
}
