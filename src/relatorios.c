#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "../include/relatorios.h"
#include "../include/dono_veiculo.h"
#include "../include/cadastro_vagas.h"
#include "../include/estacionamentos.h"
#include "../include/veiculos.h"

//===============================
//= Funções do Módulo Relatório =
//===============================

void switch_relatorio(void) {
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
    printf("||                                  -SIG-Parking-                                  ||\n");
    printf("=====================================================================================\n");
    printf("|| [1] -> Relatório de Veículos Cadastrados                                        ||\n");
    printf("|| [2] -> Relatório de Estacionamentos                                             ||\n");
    printf("|| [3] -> Relatório de Donos dos Veículos                                          ||\n");
    printf("|| [4] -> Relatório de Cadastro de Vagas                                           ||\n");
    printf("|| [0] -> Voltar ao Menu Principal                                                 ||\n");
    printf("=====================================================================================\n");
    printf("\t >>Escolha uma opção: ");
    scanf(" %c", &op);
    getchar();
    return op;
}

//=======================================================
//= RELATÓRIO DE VEÍCULOS CADASTRADOS
//=======================================================
void relatorio_veiculos(void) {
    system("clear||cls");

    FILE *arq_veiculos;
    Veiculos *veiculo;
    int count = 0;

    printf("\n====================== RELATÓRIO DE VEÍCULOS ======================\n\n");

    veiculo = (Veiculos*)malloc(sizeof(Veiculos));
    arq_veiculos = fopen("veiculos.dat", "rb");

    if (arq_veiculos == NULL) {
        printf("Erro ao abrir o arquivo de veículos.\n");
        printf(">>Tecle <ENTER> para continuar...\n");
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

    if (count == 0) printf("Nenhum veículo cadastrado.\n");

    fclose(arq_veiculos);
    free(veiculo);

    printf("\n>>Tecle <ENTER> para continuar...\n");
    getchar();
}

//=======================================================
//= RELATÓRIO DE ESTACIONAMENTOS
//=======================================================
void relatorio_estacionamentos(void) {
    system("clear||cls");

    FILE *arq_estacionamentos;
    Estacionamentos *estacionamento;
    int count = 0;

    printf("\n=================== RELATÓRIO DE ESTACIONAMENTOS ==================\n\n");

    estacionamento = (Estacionamentos*)malloc(sizeof(Estacionamentos));
    arq_estacionamentos = fopen("estacionamentos.dat", "rb");

    if (arq_estacionamentos == NULL) {
        printf("Erro ao abrir o arquivo de estacionamentos.\n");
        printf(">>Tecle <ENTER> para continuar...\n");
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

    if (count == 0) printf("Nenhum estacionamento cadastrado.\n");

    fclose(arq_estacionamentos);
    free(estacionamento);

    printf("\n>>Tecle <ENTER> para continuar...\n");
    getchar();
}

//=======================================================
//= RELATÓRIO DE DONOS DE VEÍCULOS
//=======================================================
void relatorio_dono_veiculo(void) {
    system("clear||cls");

    FILE *arq_dono;
    DV *dono;
    int count = 0;

    printf("\n=================== RELATÓRIO DE DONOS DE VEÍCULOS ==================\n\n");

    dono = (DV*)malloc(sizeof(DV));
    arq_dono = fopen("dono_veiculo.dat", "rb");

    if (arq_dono == NULL) {
        printf("Erro ao abrir o arquivo de donos dos veículos.\n");
        printf(">>Tecle <ENTER> para continuar...\n");
        getchar();
        return;
    }

    while (fread(dono, sizeof(DV), 1, arq_dono)) {
        if (dono->status) {
            count++;
            printf("Dono nº %d\n", count);
            printf("Nome: %s\n", dono->nome);
            printf("CPF: %s\n", dono->cpf);
            printf("Telefone: %s\n", dono->telefone);
            printf("Quantidade de veículos: %d\n", dono->quantidade);
            printf("-----------------------------------------------------------\n");
        }
    }

    if (count == 0) printf("Nenhum dono de veículo cadastrado.\n");

    fclose(arq_dono);
    free(dono);

    printf("\n>>Tecle <ENTER> para continuar...\n");
    getchar();
}

//=======================================================
//= RELATÓRIO DE CADASTRO DE VAGAS
//=======================================================
void relatorio_cadastro_vagas(void) {
    system("clear||cls");

    FILE *arq_vagas;
    CV *vagas;
    int count = 0;

    printf("\n=================== RELATÓRIO DE CADASTRO DE VAGAS ==================\n\n");

    vagas = (CV*)malloc(sizeof(CV));
    arq_vagas = fopen("cadastro_vagas.dat", "rb");

    if (arq_vagas == NULL) {
        printf("Erro ao abrir o arquivo de cadastro de vagas.\n");
        printf(">>Tecle <ENTER> para continuar...\n");
        getchar();
        return;
    }

    while (fread(vagas, sizeof(CV), 1, arq_vagas)) {
        if (vagas->status) {
            count++;
            printf("Andar nº %d\n", vagas->num_andar);
            printf("Quantidade de vagas: %d\n", vagas->qtd_vagas);
            printf("-----------------------------------------------------------\n");
        }
    }

    if (count == 0) printf("Nenhuma vaga cadastrada.\n");

    fclose(arq_vagas);
    free(vagas);

    printf("\n>>Tecle <ENTER> para continuar...\n");
    getchar();
}
