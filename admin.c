#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "admin.h"
#include "dono_veiculo.h"
#include "cadastro_vagas.h"
#include "estacionamentos.h"
#include "veiculos.h"
#include "validacoes.h"
//==============================
//= Funções de Administrador   =
//==============================

void switch_admin(void){
    
    char op;

    do {
        op = admin();
        switch (op) {
            case '1': 
                exclu_veiculo();
                break;
            case '2': 
                exclu_estacionamentos();
                break;
            case '3': 
                exclu_dono_veiculo();
                break;
            case '4': 
                exclu_cadastro_vagas();
                break;
        }
    } while (op != '0');
}

char admin(void) {
    system("clear||cls");

    char op;

    printf("\n");
    printf("========================================================================================\n");
    printf("||                                                                                    ||\n");
    printf("||                                  -SIG-Parking-                                     ||\n");
    printf("||                                                                                    ||\n");
    printf("========================================================================================\n");
    printf("||                                                                                    ||\n");
    printf("||                             -Funções de Administrador-                             ||\n");
    printf("||                                                                                    ||\n");
    printf("========================================================================================\n");
    printf("||                                                                                    ||\n");
    printf("|| [1] -> Excluir Veículo                                                             ||\n");
    printf("|| [2] -> Excluir Estacionamentos                                                     ||\n");
    printf("|| [3] -> Excluir Dono de Veículo                                                     ||\n");
    printf("|| [4] -> Excluir Cadastro de Vagas                                                   ||\n");
    printf("|| [0] -> Voltar ao Menu Principal                                                    ||\n");
    printf("||                                                                                    ||\n");
    printf("========================================================================================\n");
    printf("\n");
    printf("\t >>Escolha uma opção: ");
    scanf("%c", &op);
    getchar();
    printf("\n");
    return op;
}

void exclu_veiculo(void) {
    system("clear||cls");

    FILE *arq_veiculo;
    FILE *arq_veiculo_temp;
    Veiculos *veiculo;
    char placa_lida[12];
    int encontrado = 0;

    printf("\n");
    printf("======================================================================================\n");
    printf("||                                                                                  ||\n");
    printf("||                                  -SIG-Parking-                                   ||\n");
    printf("||                                                                                  ||\n");
    printf("======================================================================================\n");
    printf("||                                                                                  ||\n");
    printf("||                   -Módulo Veículos -> Excluir Dados Fisicamente-                 ||\n");
    printf("||                                                                                  ||\n");
    printf("======================================================================================\n");
    printf("\n");
    veiculo = (Veiculos*)malloc(sizeof(Veiculos));
    printf(" >>Digite a placa do veículo a ser excluido. \n");
    Ler_Placa_Lida(placa_lida);
    printf("\n");

    arq_veiculo = fopen("veiculos.dat", "rb");
    arq_veiculo_temp = fopen("veiculos_temp.dat", "wb");
    if (arq_veiculo == NULL) {
        printf("\t Erro ao abrir o arquivo de veículos.\n");
        printf("\t >>Tecle <ENTER> para continuar...\n");
        getchar();
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

    remove("veiculos.dat");
    rename("veiculos_temp.dat", "veiculos.dat");

    if (encontrado) {
        printf("Veículo com placa %s excluído fisicamente com sucesso!\n", placa_lida);
    } else {
        printf("Placa não encontrada!\n");
    }

    printf("\n");
    printf("\t >>Tecle <ENTER> para continuar...\n");
    getchar();
    printf("\n");
}

void exclu_estacionamentos(void) {
    system("clear||cls");

    FILE *arq_estacionamentos;
    FILE *arq_estacionamentos_temp;
    Estacionamentos *estacionamento;
    char n_estaci_lido[8];
    int encontrado = 0;

    printf("\n");
    printf("======================================================================================\n");
    printf("||                                                                                  ||\n");
    printf("||                                  -SIG-Parking-                                   ||\n");
    printf("||                                                                                  ||\n");
    printf("======================================================================================\n");
    printf("||                                                                                  ||\n");
    printf("||               -Módulo Estacionamentos -> Excluir Dados Fisicamente-              ||\n");
    printf("||                                                                                  ||\n");
    printf("======================================================================================\n");
    printf("\n");
    estacionamento = (Estacionamentos*)malloc(sizeof(Estacionamentos));
    printf(" >>Digite o número do estacionamento a ser excluido. \n");
    Ler_Estacionamento_Lida(n_estaci_lido);
    printf("\n");

    arq_estacionamentos = fopen("estacionamentos.dat", "rb");
    arq_estacionamentos_temp = fopen("estacionamentos_temp.dat", "wb");
    if (arq_estacionamentos == NULL) {
        printf("\t Erro ao abrir o arquivo de estacionamentos.\n");
        printf("\t >>Tecle <ENTER> para continuar...\n");
        getchar();
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

    remove("estacionamentos.dat");
    rename("estacionamentos_temp.dat", "estacionamentos.dat");

    if (encontrado) {
        printf("Estacionamento com número %s excluído fisicamente com sucesso!\n", n_estaci_lido);
    } else {
        printf("Número do estacionamento não encontrado!\n");
    }

    printf("\n");
    printf("\t >>Tecle <ENTER> para continuar...\n");
    getchar();
    printf("\n");
}

void exclu_dono_veiculo(void) {
    system("clear||cls");

    FILE *arq_dono_veiculo;
    FILE *arq_dono_veiculo_temp;
    DV *dono;
    char cpf_lido[12];
    int encontrado = 0;

    printf("\n");
    printf("======================================================================================\n");
    printf("||                                                                                  ||\n");
    printf("||                                  -SIG-Parking-                                   ||\n");
    printf("||                                                                                  ||\n");
    printf("======================================================================================\n");
    printf("||                                                                                  ||\n");
    printf("||                  -Módulo Donos dos Veículos -> Excluir Dados Fisicamente-        ||\n");
    printf("||                                                                                  ||\n");
    printf("======================================================================================\n");
    printf("\n");
    dono = (DV*)malloc(sizeof(DV));
    printf(" >>Digite o CPF do dono a ser excluido. \n");
    Ler_CPF_Lido(cpf_lido);
    printf("\n");

    arq_dono_veiculo = fopen("dono_veiculo.dat", "rb");
    arq_dono_veiculo_temp = fopen("dono_veiculo_temp.dat", "wb");
    if (arq_dono_veiculo == NULL) {
        printf("\t Erro ao abrir o arquivo de dono_veiculo.\n");
        printf("\t >>Tecle <ENTER> para continuar...\n");
        getchar();
        return;
    }

    while (fread(dono, sizeof(DV), 1, arq_dono_veiculo)) {
        if (strcmp(dono->cpf, cpf_lido) != 0) {
            fwrite(dono, sizeof(DV), 1, arq_dono_veiculo_temp);
        } else {
            encontrado = 1;
        }
    }

    fclose(arq_dono_veiculo);
    fclose(arq_dono_veiculo_temp);
    free(dono); 

    remove("dono_veiculo.dat");
    rename("dono_veiculo_temp.dat", "dono_veiculo.dat");

    if (encontrado) {
        printf("Dono do veículo com CPF %s excluído fisicamente com sucesso!\n", cpf_lido);
    } else {
        printf("CPF não encontrado!\n");
    }

    printf("\n");
    printf("\t >>Tecle <ENTER> para continuar...\n");
    getchar();
    printf("\n");
}

void exclu_cadastro_vagas(void) {
    system("clear||cls");

    FILE *arq_cadastro_vagas;
    FILE *arq_cadastro_vagas_temp;
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
    printf("||                -Módulo Cadastro de Vagas -> Excluir Vagas fisicamenente -       ||\n");
    printf("||                                                                                 ||\n");
    printf("=====================================================================================\n");
    printf("\n");
    vagas = (CV*)malloc(sizeof(CV));
    printf(" >>Digite o número do andar que deseja excluir. \n");
    Ler_num_andar(&num_andar_lido);
    printf("\n");

    arq_cadastro_vagas = fopen("cadastro_vagas.dat", "rb");
    arq_cadastro_vagas_temp = fopen("cadastro_vagas_temp.dat", "wb");
    if (arq_cadastro_vagas == NULL) {
        printf("\t Erro ao abrir o arquivo do cadastro das vagas.\n");
        printf("\t >>Tecle <ENTER> para continuar...\n");
        getchar();
        return;
    }
    while (fread(vagas, sizeof(CV), 1, arq_cadastro_vagas)) {
        if (vagas->num_andar != num_andar_lido) {
            fwrite(vagas, sizeof(CV), 1, arq_cadastro_vagas_temp); 
        } else {
            encontrado = 1; 
        }
    }

    fclose(arq_cadastro_vagas);
    fclose(arq_cadastro_vagas_temp);
    free(vagas); 

    remove("cadastro_vagas.dat");
    rename("cadastro_vagas_temp.dat", "cadastro_vagas.dat");

    if (encontrado) {
        printf("Vagas do andar %d excluídas fisicamente com sucesso!\n", num_andar_lido);
    } else {
        printf("\nAndar não encontrado!\n");
    }

    printf("\n");
    printf("\t >>Tecle <ENTER> para continuar...\n");
    getchar();
    printf("\n");
}
