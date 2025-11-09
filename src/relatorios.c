#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../include/relatorios.h"
#include "../include/dono_veiculo.h"
#include "../include/cadastro_vagas.h"
#include "../include/estacionamentos.h"
#include "../include/veiculos.h"

//===============================
//= Funções do Módulo Relatorio =
//===============================

void switch_relatorio(void){

    char op;

    do {
        op = relatorio();
        switch (op) {
            case '1': 
                relatorio_veiculos();
                break;
            case '2': 
                relatorio_estacionamentos();
                break;
            case '3': 
                relatorio_dono_veiculo();
                break;
            case '4': 
                relatorio_cadastro_vagas();
                break;
        }
    } while (op != '0');
}

char relatorio(void) {
    system("clear||cls");

    char op;

    printf("\n");
    printf("=====================================================================================\n");
    printf("||                                                                                 ||\n");
    printf("||                                  -SIG-Parking-                                  ||\n");
    printf("||                                                                                 ||\n");
    printf("=====================================================================================\n");
    printf("||                                                                                 ||\n");
    printf("||                                -Módulo Relatórios-                              ||\n");
    printf("||                                                                                 ||\n");
    printf("=====================================================================================\n");
    printf("||                                                                                 ||\n");
    printf("|| [1] -> Relatório de Veículos Cadastrados                                        ||\n");
    printf("|| [2] -> Relatório de Estacionamentos                                             ||\n");
    printf("|| [3] -> Relatório de Donos dos Veículos                                          ||\n");
    printf("|| [4] -> Relatório de Cadastro de Vagas                                           ||\n");
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

void relatorio_veiculos(void) {
    system("clear||cls");

    FILE *arq_veiculos;
    Veiculos *veiculo;
    int count = 0;

    printf("\n");
    printf("=====================================================================================\n");
    printf("||                                                                                 ||\n");
    printf("||                                  -SIG-Parking-                                  ||\n");
    printf("||                                                                                 ||\n");
    printf("=====================================================================================\n");
    printf("||                                                                                 ||\n");
    printf("||                     -Módulo Relatórios -> Veículos Cadastrados-                 ||\n");
    printf("||                                                                                 ||\n");
    printf("=====================================================================================\n");
    printf("\n");
    veiculo = (Veiculos*)malloc(sizeof(Veiculos));

    arq_veiculos = fopen("veiculos.dat", "rb");
    if (arq_veiculos == NULL) {
        printf("\tErro ao abrir o arquivo de veículos.\n");
        printf("\t>>Tecle <ENTER> para continuar...\n");
        getchar();
        return;
    }

    while (fread(veiculo, sizeof(Veiculos), 1, arq_veiculos)) {
        if (veiculo->status) { 
            count++;
            printf("Veículo nº %d\n", count);
            printf("Placa: %s\n", veiculo->placa);
            printf("Tipo: %s\n", veiculo->tipo);
            printf("Modelo: %s\n", veiculo->model);
            printf("Cor: %s\n", veiculo->cor);
            printf("Nº do Estacionamento: %s\n", veiculo->n_estaci);
            printf("CPF do Dono: %s\n", veiculo->cpf);
            printf("-----------------------------------------------------------\n");
        }
    }

    if (count == 0) {
        printf("Nenhum veículo cadastrado.\n");
    }
    else{
        printf("Relatório de veículos cadastrados gerado com sucesso!\n");
    }

    fclose(arq_veiculos);
    free(veiculo);

    printf("\n");
    printf("\t >>Tecle <ENTER> para continuar...\n");
    getchar();
}

void relatorio_estacionamentos(void) {
    system("clear||cls");

    FILE *arq_estacionamentos;
    Estacionamentos *estacionamento;
    int count = 0;

    printf("\n");
    printf("=====================================================================================\n");
    printf("||                                                                                 ||\n");
    printf("||                                  -SIG-Parking-                                  ||\n");
    printf("||                                                                                 ||\n");
    printf("=====================================================================================\n");
    printf("||                                                                                 ||\n");
    printf("||                     -Módulo Relatórios -> Estacionamentos-                      ||\n");
    printf("||                                                                                 ||\n");
    printf("=====================================================================================\n");
    printf("\n");
    estacionamento = (Estacionamentos*)malloc(sizeof(Estacionamentos));

    arq_estacionamentos = fopen("estacionamentos.dat", "rb");
    if (arq_estacionamentos == NULL) {
        printf("\t Erro ao abrir o arquivo de dono_veiculo.\n");
        printf("\t >>Tecle <ENTER> para continuar...\n");
        getchar();
        return;
    }

    while (fread(estacionamento, sizeof(Estacionamentos), 1, arq_estacionamentos)) {
        if (estacionamento->status) { 
            count++;
            printf("Estacionamento nº %d\n", count);
            printf("Nº da Vaga: %s\n", estacionamento->n_estaci);
            printf("Placa do Veículo: %s\n", estacionamento->placa);
            printf("-----------------------------------------------------------\n");
        }
    }

    if (count == 0) {
        printf("Nenhum estacionamento cadastrado.\n");
    }
    else{
        printf("Relatório de estacionamentos gerado com sucesso!\n");
    }

    fclose(arq_estacionamentos);
    free(estacionamento);

    printf("\n");
    printf("\t >>Tecle <ENTER> para continuar...\n");
    getchar();
}

void relatorio_dono_veiculo(void) {
    system("clear||cls");

    printf("\n");
    printf("=====================================================================================\n");
    printf("||                                                                                 ||\n");
    printf("||                                  -SIG-Parking-                                  ||\n");
    printf("||                                                                                 ||\n");
    printf("=====================================================================================\n");
    printf("||                                                                                 ||\n");
    printf("||                    -Módulo Relatórios -> Donos dos Veículos-                    ||\n");
    printf("||                                                                                 ||\n");
    printf("=====================================================================================\n");
    printf("\n");
    printf("Relatório de donos dos veículos gerado com sucesso!\n");
    printf("\n");
    printf("\t >>Tecle <ENTER> para continuar...\n");
    getchar();
}

void relatorio_cadastro_vagas(void) {
    system("clear||cls");

    printf("\n");
    printf("=====================================================================================\n");
    printf("||                                                                                 ||\n");
    printf("||                                  -SIG-Parking-                                  ||\n");
    printf("||                                                                                 ||\n");
    printf("=====================================================================================\n");
    printf("||                                                                                 ||\n");
    printf("||                -Módulo Relatórios -> Cadastro de vagas-                         ||\n");
    printf("||                                                                                 ||\n");
    printf("=====================================================================================\n");
    printf("\n");
    printf("Relatório de cadastro de vagas gerado com sucesso!\n");
    printf("\n");
    printf("\t >>Tecle <ENTER> para continuar...\n");
    getchar();
}