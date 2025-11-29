#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "../include/admin.h"
#include "../include/dono_veiculo.h"
#include "../include/cadastro_vagas.h"
#include "../include/estacionamentos.h"
#include "../include/veiculos.h"
#include "../include/validacoes.h"

//==============================
//= Funções de Administrador   =
//==============================

void switch_admin(void) {
    char op;
    do {
        op = admin();
        switch (op) {
            case '1': exclu_veiculo(); break;
            case '2': exclu_estacionamentos(); break;
            case '3': exclu_dono_veiculo(); break;
            case '4': exclu_cadastro_vagas(); break;
        }
    } while (op != '0');
}

char admin(void) {
    system("clear||cls");
    char op;

    printf("\n");
    printf("========================================================================================\n");
    printf("||                                  -SIG-Parking-                                     ||\n");
    printf("||                             -Funções de Administrador-                             ||\n");
    printf("========================================================================================\n");
    printf("|| [1] -> Excluir Veículo                                                             ||\n");
    printf("|| [2] -> Excluir Estacionamentos                                                     ||\n");
    printf("|| [3] -> Excluir Dono de Veículo                                                     ||\n");
    printf("|| [4] -> Excluir Cadastro de Vagas                                                   ||\n");
    printf("|| [0] -> Voltar ao Menu Principal                                                    ||\n");
    printf("========================================================================================\n");
    printf("\t >>Escolha uma opção: ");
    Ler_Opcao_admin(&op);
    printf("\n");
    return op;
}

//==============================
//= Excluir Veículo
//==============================
void exclu_veiculo(void) {
    system("clear||cls");

    FILE *arq_veiculo;
    FILE *arq_veiculo_temp;
    Veiculos *veiculo = (Veiculos*)malloc(sizeof(Veiculos));
    char placa_lida[12];
    int encontrado = 0;

    printf("\n>> Digite a placa do veículo a ser excluído: ");
    Ler_Placa(placa_lida);

    arq_veiculo = fopen("dados/veiculos.dat", "rb");
    arq_veiculo_temp = fopen("dados/veiculos_temp.dat", "wb");

    if (arq_veiculo == NULL) {
        printf("\nErro ao abrir arquivo de veículos.\nTecle <ENTER> para continuar...");
        getchar();
        free(veiculo);
        return;
    }

    while (fread(veiculo, sizeof(Veiculos), 1, arq_veiculo)) {
        if (strcmp(veiculo->placa, placa_lida) != 0) {
            fwrite(veiculo, sizeof(Veiculos), 1, arq_veiculo_temp);
        } else {
            encontrado = 1;
        }
    }

    fclose(arq_veiculo);
    fclose(arq_veiculo_temp);
    free(veiculo);

    remove("dados/veiculos.dat");
    rename("dados/veiculos_temp.dat", "dados/veiculos.dat");

    if (encontrado)
        printf("\nVeículo com placa %s excluído fisicamente!\n", placa_lida);
    else
        printf("\nPlaca não encontrada!\n");

    printf("Tecle <ENTER> para continuar...");
    getchar();
}

//==============================
//= Excluir Estacionamento
//==============================
void exclu_estacionamentos(void) {
    system("clear||cls");

    FILE *arq_estacionamentos;
    FILE *arq_estacionamentos_temp;
    Estacionamentos *estacionamento = (Estacionamentos*)malloc(sizeof(Estacionamentos));
    char n_estaci_lido[8];
    int encontrado = 0;

    printf("\n>> Digite o número do estacionamento a ser excluído: ");
    Ler_Estacionamento(n_estaci_lido);

    arq_estacionamentos = fopen("dados/estacionamentos.dat", "rb");
    arq_estacionamentos_temp = fopen("dados/estacionamentos_temp.dat", "wb");

    if (arq_estacionamentos == NULL) {
        printf("\nErro ao abrir arquivo de estacionamentos.\nTecle <ENTER> para continuar...");
        getchar();
        free(estacionamento);
        return;
    }

    while (fread(estacionamento, sizeof(Estacionamentos), 1, arq_estacionamentos)) {
        if (strcmp(estacionamento->n_estaci, n_estaci_lido) != 0) {
            fwrite(estacionamento, sizeof(Estacionamentos), 1, arq_estacionamentos_temp);
        } else {
            encontrado = 1;
        }
    }

    fclose(arq_estacionamentos);
    fclose(arq_estacionamentos_temp);
    free(estacionamento);

    remove("dados/estacionamentos.dat");
    rename("dados/estacionamentos_temp.dat", "dados/estacionamentos.dat");

    if (encontrado)
        printf("\nEstacionamento %s excluído fisicamente!\n", n_estaci_lido);
    else
        printf("\nNúmero do estacionamento não encontrado!\n");

    printf("Tecle <ENTER> para continuar...");
    getchar();
}

//==============================
//= Excluir Dono de Veículo
//==============================
void exclu_dono_veiculo(void) {
    system("clear||cls");

    FILE *arq_dono;
    FILE *arq_dono_temp;
    DonoVeiculo *dono = (DonoVeiculo*)malloc(sizeof(DonoVeiculo));
    char cpf_lido[15];
    int encontrado = 0;

    printf("\n>> Digite o CPF do dono a ser excluído: ");
    Ler_CPF(cpf_lido);

    arq_dono = fopen("dados/dono_veiculo.dat", "rb");
    arq_dono_temp = fopen("dados/dono_veiculo_temp.dat", "wb");

    if (arq_dono == NULL) {
        printf("\nErro ao abrir arquivo de donos.\nTecle <ENTER> para continuar...");
        getchar();
        free(dono);
        return;
    }

    while (fread(dono, sizeof(DonoVeiculo), 1, arq_dono)) {
        if (strcmp(dono->cpf, cpf_lido) != 0) {
            fwrite(dono, sizeof(DonoVeiculo), 1, arq_dono_temp);
        } else {
            encontrado = 1;
        }
    }

    fclose(arq_dono);
    fclose(arq_dono_temp);
    free(dono);

    remove("dados/dono_veiculo.dat");
    rename("dados/dono_veiculo_temp.dat", "dados/dono_veiculo.dat");

    if (encontrado)
        printf("\nDono com CPF %s excluído fisicamente!\n", cpf_lido);
    else
        printf("\nCPF não encontrado!\n");

    printf("Tecle <ENTER> para continuar...");
    getchar();
}

//==============================
//= Excluir Cadastro de Vagas
//==============================
void exclu_cadastro_vagas(void) {
    system("clear||cls");

    FILE *arq_vagas;
    FILE *arq_vagas_temp;
    CV *vagas = (CV*)malloc(sizeof(CV));
    int num_andar_lido;
    int encontrado = 0;

    printf("\n>> Digite o número do andar a excluir: ");
    Ler_num_andar(&num_andar_lido);

    arq_vagas = fopen("dados/cadastro_vagas.dat", "rb");
    arq_vagas_temp = fopen("dados/cadastro_vagas_temp.dat", "wb");

    if (arq_vagas == NULL) {
        printf("\nErro ao abrir arquivo de vagas.\nTecle <ENTER> para continuar...");
        getchar();
        free(vagas);
        return;
    }

    while (fread(vagas, sizeof(CV), 1, arq_vagas)) {
        if (vagas->num_andar != num_andar_lido) {
            fwrite(vagas, sizeof(CV), 1, arq_vagas_temp);
        } else {
            encontrado = 1;
        }
    }

    fclose(arq_vagas);
    fclose(arq_vagas_temp);
    free(vagas);

    remove("dados/cadastro_vagas.dat");
    rename("dados/cadastro_vagas_temp.dat", "dados/cadastro_vagas.dat");

    if (encontrado)
        printf("\nVagas do andar %d excluídas fisicamente!\n", num_andar_lido);
    else
        printf("\nAndar não encontrado!\n");

    printf("Tecle <ENTER> para continuar...");
    getchar();
}
