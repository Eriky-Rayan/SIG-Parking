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

    char op_sub;
    printf("=====================================================================================\n");
    printf("||                         RELATÓRIO - VEÍCULOS CADASTRADOS                        ||\n");
    printf("=====================================================================================\n");
    printf("|| [1] -> Mostrar relatório Completo                                               ||\n");
    printf("|| [2] -> Filtrar por Cor do veículo                                               ||\n");
    printf("|| [0] -> Voltar ao Menu Principal                                                 ||\n");
    printf("=====================================================================================\n");
    printf(" >> Escolha uma opção: ");
    scanf(" %c", &op_sub);
    getchar();

    if (op_sub == '0') return;

    else if (op_sub == '1') {

        FILE *arq_veiculos;
        Veiculos *veiculo = malloc(sizeof(Veiculos));
        int count = 0;

        arq_veiculos = fopen("dados/veiculos.dat", "rb");
        if (!arq_veiculos) {
            printf("Erro ao abrir o arquivo de veículos.\n");
            getchar();
            return;
        }

        printf("╔════════════════════════════ RELATÓRIO DE VEÍCULOS ═══════════════════════════╗\n");
        printf("║ %-7s ║ %-8s ║ %-10s ║ %-10s ║ %-15s ║ %-11s ║\n",
               "Placa", "Tipo", "Modelo", "Cor", "Estacionamento", "CPF Dono");
        printf("╠═════════╬══════════╬════════════╬════════════╬═════════════════╬═════════════╣\n");

        while (fread(veiculo, sizeof(Veiculos), 1, arq_veiculos)) {
            if (veiculo->status) {
                count++;
                printf("║ %-7s ║ %-8s ║ %-10s ║ %-10s ║ %-15s ║ %-11s ║\n",
                    veiculo->placa,
                    veiculo->tipo,
                    veiculo->model,
                    veiculo->cor,
                    veiculo->n_estaci,
                    veiculo->cpf
                );
            }
        }

        if (count == 0) {
            printf("Nenhum veículo cadastrado\n");
        }

        printf("╚═════════╩══════════╩════════════╩════════════╩═════════════════╩═════════════╝\n");

        fclose(arq_veiculos);
        free(veiculo);

        printf("\n>> Tecle ENTER para continuar...");
        getchar();
    }
    else if (op_sub == '2') {

        char cor_busca[15];
        FILE *arq_veiculos;
        Veiculos *veiculo = malloc(sizeof(Veiculos));
        int count = 0;

        printf("\n >> Digite a cor do veículo: ");
        fgets(cor_busca, 15, stdin);
        cor_busca[strcspn(cor_busca, "\n")] = '\0';

        arq_veiculos = fopen("dados/veiculos.dat", "rb");
        if (!arq_veiculos) {
            printf("Erro ao abrir o arquivo de veículos.\n");
            getchar();
            return;
        }

        printf("╔════════════════════════════ RELATÓRIO DE VEÍCULOS ═══════════════════════════╗\n");
        printf("║ %-7s ║ %-8s ║ %-10s ║ %-10s ║ %-15s ║ %-11s ║\n",
               "Placa", "Tipo", "Modelo", "Cor", "Estacionamento", "CPF Dono");
        printf("╠═════════╬══════════╬════════════╬════════════╬═════════════════╬═════════════╣\n");

        while (fread(veiculo, sizeof(Veiculos), 1, arq_veiculos)) {
            if (veiculo->status && strstr(veiculo->cor, cor_busca)) {
                count++;
                printf("║ %-7s ║ %-8s ║ %-10s ║ %-10s ║ %-15s ║ %-11s ║\n",
                    veiculo->placa,
                    veiculo->tipo,
                    veiculo->model,
                    veiculo->cor,
                    veiculo->n_estaci,
                    veiculo->cpf
                );
            }
        }

        if (count == 0) {
            printf("Nenhum veículo cadastrado.\n");
        }

        printf("╚═════════╩══════════╩════════════╩════════════╩═════════════════╩═════════════╝\n");

        fclose(arq_veiculos);
        free(veiculo);

        printf("\n>> Tecle ENTER para continuar...");
        getchar();
    }
    else{
        printf("\nOpção inválida!\n");
        printf(">>Tecle <ENTER> para continuar...\n");
        getchar();
    }
}


//=======================================================
//= RELATÓRIO DE ESTACIONAMENTOS
//=======================================================
void relatorio_estacionamentos(void) {
    system("clear||cls");

    char op_sub;
    printf("=====================================================================================\n");
    printf("||                         RELATÓRIO - ESTACIONAMENTOS                             ||\n");
    printf("=====================================================================================\n");
    printf("|| [1] -> Mostrar relatório Completo                                               ||\n");
    printf("|| [2] -> Filtrar por número de vaga do veículo                                    ||\n");
    printf("|| [0] -> Voltar ao Menu Principal                                                 ||\n");
    printf("=====================================================================================\n");
    printf(" >> Escolha uma opção: ");
    scanf(" %c", &op_sub);
    getchar();

    if (op_sub == '0') return;

    else if(op_sub == '1'){

        FILE *arq_estacionamentos;
        Estacionamentos *estacionamento;
        estacionamento = (Estacionamentos*)malloc(sizeof(Estacionamentos));
        int count = 0;

        arq_estacionamentos = fopen("dados/estacionamentos.dat", "rb");
        if (arq_estacionamentos == NULL) {
            printf("Erro ao abrir o arquivo de estacionamentos.\n");
            printf(">>Tecle <ENTER> para continuar...\n");
            getchar();
            return;
        }

        printf("╔══ RELATÓRIO DE ESTACIONAMENTOS  ═══╗\n");
        printf("║ %-16s ║ %-16s ║\n", "Nº da Vaga", "Placa do Veículo");
        printf("╠═════════════════╬══════════════════╣\n");

        while (fread(estacionamento, sizeof(Estacionamentos), 1, arq_estacionamentos)) {
            if (estacionamento->status) { 
                count++;
                printf("║ %-15s ║ %-16s ║\n",
                    estacionamento->n_estaci,
                    estacionamento->placa);
            }
        }
        printf("╚═════════════════╩══════════════════╝\n");

        if (count == 0) printf("Nenhum estacionamento cadastrado.\n");

        fclose(arq_estacionamentos);
        free(estacionamento);

        printf("\n>>Tecle <ENTER> para continuar...\n");
        getchar();
    }
    else if (op_sub == '2'){

        char vaga_busca[8];
        FILE *arq_estacionamentos;
        Estacionamentos *estacionamento;
        estacionamento = (Estacionamentos*)malloc(sizeof(Estacionamentos));
        int count = 0;

        printf("\n >> Digite o número da vaga: ");
        fgets(vaga_busca, 8, stdin);
        vaga_busca[strcspn(vaga_busca, "\n")] = '\0';

        arq_estacionamentos = fopen("dados/estacionamentos.dat", "rb");
        if (arq_estacionamentos == NULL) {
            printf("Erro ao abrir o arquivo de estacionamentos.\n");
            printf(">>Tecle <ENTER> para continuar...\n");
            getchar();
            return;
        }

        printf("╔══ RELATÓRIO DE ESTACIONAMENTOS  ═══╗\n");
        printf("║ %-16s ║ %-16s ║\n", "Nº da Vaga", "Placa do Veículo");
        printf("╠═════════════════╬══════════════════╣\n");

        while (fread(estacionamento, sizeof(Estacionamentos), 1, arq_estacionamentos)) {
            if (estacionamento->status && strstr(estacionamento->n_estaci, vaga_busca)) { 
                count++;
                printf("║ %-15s ║ %-16s ║\n",
                    estacionamento->n_estaci,
                    estacionamento->placa);
            }
        }
        printf("╚═════════════════╩══════════════════╝\n");

        if (count == 0) printf("Nenhum estacionamento cadastrado.\n");

        fclose(arq_estacionamentos);
        free(estacionamento);

        printf("\n>>Tecle <ENTER> para continuar...\n");
        getchar();
    }
    else{
        printf("\nOpção inválida!\n");
        printf(">>Tecle <ENTER> para continuar...\n");
        getchar();
    }
}

//=======================================================
//= RELATÓRIO DE DONOS DE VEÍCULOS
//=======================================================
#define CENTER "                    "   // 20 espaços
#define WIDTH 76                       // largura exata da tabela

void relatorio_dono_veiculo(void) {
    system("clear||cls");

    char op_sub;
    printf("\n==================== RELATÓRIO - DONOS DOS VEÍCULOS ====================\n");
    printf("1 - Mostrar relatório completo\n");
    printf("2 - Filtrar por nome do dono\n");
    printf("0 - Voltar\n");
    printf("=======================================================================\n");
    printf(" >> Escolha uma opção: ");
    scanf(" %c", &op_sub);
    getchar();

    if (op_sub == '0') return;

    //-----------------------------------------------------------
    // OPÇÃO 1 → RELATÓRIO COMPLETO (SEU RELATÓRIO ORIGINAL)
    //-----------------------------------------------------------
    if (op_sub == '1') {

        FILE *arq_dono;
        DV *dono;
        int count = 0;

        printf(CENTER "**************************************************************************\n");
        printf(CENTER "***                      RELATÓRIO DE DONOS DE VEÍCULOS               ***\n");
        printf(CENTER "**************************************************************************\n");
        printf(CENTER "| %-20s | %-14s | %-13s | %-4s |\n",
            "Nome", "CPF", "Telefone", "Qtde");
        printf(CENTER "--------------------------------------------------------------------------\n");

        dono = (DV*)malloc(sizeof(DV));
        arq_dono = fopen("dados/dono_veiculo.dat", "rb");

        if (arq_dono == NULL) {
            printf("Erro ao abrir o arquivo de donos dos veículos.\n");
            printf(">>Tecle <ENTER> para continuar...\n");
            getchar();
            return;
        }

        while (fread(dono, sizeof(DV), 1, arq_dono)) {
            if (dono->status) {
                count++;
                printf(CENTER "| %-20s | %-14s | %-13s | %-4d |\n",
                    dono->nome,
                    dono->cpf,
                    dono->telefone,
                    dono->quantidade
                );
            }
        }

        if (count == 0)
            printf(CENTER "Nenhum dono cadastrado.\n");

        printf(CENTER "--------------------------------------------------------------------------\n");
        printf(CENTER "Fim da Lista!\n");

        fclose(arq_dono);
        free(dono);

        printf("\n>>Tecle <ENTER> para continuar...\n");
        getchar();
        return;
    }

    //-----------------------------------------------------------
    // OPÇÃO 2 → FILTRAR DONOS PELO NOME
    //-----------------------------------------------------------
    else if (op_sub == '2') {

        char nome_busca[50];
        FILE *arq_dono;
        DV *dono;
        int encontrou = 0;

        printf("\n >> Digite o nome ou parte do nome: ");
        fgets(nome_busca, 50, stdin);
        nome_busca[strcspn(nome_busca, "\n")] = '\0';

        dono = malloc(sizeof(DV));
        arq_dono = fopen("dados/dono_veiculo.dat", "rb");

        if (arq_dono == NULL) {
            printf("Erro ao abrir o arquivo de donos dos veículos.\n");
            printf(">>Tecle <ENTER> para continuar...\n");
            getchar();
            free(dono);
            return;
        }

        system("clear||cls");
        printf("\n==================== RESULTADO DA PESQUISA ====================\n\n");

        while (fread(dono, sizeof(DV), 1, arq_dono)) {
            if (dono->status && strstr(dono->nome, nome_busca)) {

                encontrou = 1;

                printf("Nome: %s\n", dono->nome);
                printf("CPF: %s\n", dono->cpf);
                printf("Telefone: %s\n", dono->telefone);
                printf("Quantidade de veículos: %d\n", dono->quantidade);
                printf("---------------------------------------------------------\n");
            }
        }

        if (!encontrou)
            printf("Nenhum dono encontrado com esse nome.\n");

        fclose(arq_dono);
        free(dono);

        printf("\n>>Tecle <ENTER> para continuar...\n");
        getchar();
        return;
    }

    //-----------------------------------------------------------
    // OPÇÃO INVÁLIDA
    //-----------------------------------------------------------
    else {
        printf("\nOpção inválida!\n");
        printf(">>Tecle <ENTER> para continuar...\n");
        getchar();
    }
}


//=======================================================
//= RELATÓRIO DE CADASTRO DE VAGAS
//=======================================================
void relatorio_cadastro_vagas(void) {
    system("clear||cls");

    char op_sub;
    printf("\n==================== RELATÓRIO - CADASTRO DE VAGAS ====================\n");
    printf("1 - Mostrar relatório completo\n");
    printf("2 - Filtrar por andar\n");
    printf("0 - Voltar\n");
    printf("=======================================================================\n");
    printf(" >> Escolha uma opção: ");
    scanf(" %c", &op_sub);
    getchar();

    if (op_sub == '0') return;

    //===========================================================
    // OPÇÃO 1 → RELATÓRIO COMPLETO (SEU RELATÓRIO ORIGINAL)
    //===========================================================
    if (op_sub == '1') {

        FILE *arq_vagas;
        CV *vagas = NULL;  
        int count = 0;

        printf(CENTER "************************************************************************\n");
        printf(CENTER "***                  RELATÓRIO DE CADASTRO DE VAGAS                  ***\n");
        printf(CENTER "************************************************************************\n");
        printf(CENTER "| %-10s | %-20s |\n", "Andar", "Quantidade de Vagas");
        printf(CENTER "------------------------------------------------------------------------\n");

        vagas = malloc(sizeof(CV));
        arq_vagas = fopen("dados/cadastro_vagas.dat", "rb");

        if (arq_vagas == NULL) {
            printf("Erro ao abrir o arquivo de cadastro de vagas.\n");
            printf(">>Tecle <ENTER> para continuar...\n");
            getchar();
            free(vagas);
            return;
        }

        while (fread(vagas, sizeof(CV), 1, arq_vagas)) {
            if (vagas->status) {
                count++;
                printf(CENTER "| %-10d | %-20d |\n",
                       vagas->num_andar,
                       vagas->qtd_vagas
                );
            }
        }

        if (count == 0)
            printf(CENTER "Nenhuma vaga cadastrada.\n");

        printf(CENTER "------------------------------------------------------------------------\n");
        printf(CENTER "Fim da Lista!\n");

        fclose(arq_vagas);
        free(vagas);

        printf("\n>>Tecle <ENTER> para continuar...\n");
        getchar();
        return;
    }

    //===========================================================
    // OPÇÃO 2 → FILTRAR POR ANDAR
    //===========================================================
    else if (op_sub == '2') {

        int andar_busca;
        int encontrou = 0;

        printf("\n >> Digite o número do andar: ");
        scanf("%d", &andar_busca);
        getchar();

        FILE *arq_vagas = fopen("dados/cadastro_vagas.dat", "rb");
        CV *vagas = malloc(sizeof(CV));

        if (arq_vagas == NULL) {
            printf("Erro ao abrir o arquivo de cadastro de vagas.\n");
            printf(">>Tecle <ENTER> para continuar...\n");
            getchar();
            free(vagas);
            return;
        }

        system("clear||cls");
        printf("\n==================== VAGAS DO ANDAR %d ====================\n\n", andar_busca);

        while (fread(vagas, sizeof(CV), 1, arq_vagas)) {
            if (vagas->status && vagas->num_andar == andar_busca) {
                encontrou = 1;
                printf("Andar: %d\n", vagas->num_andar);
                printf("Quantidade de vagas: %d\n", vagas->qtd_vagas);
                printf("--------------------------------------------------------\n");
            }
        }

        if (!encontrou)
            printf("Nenhuma vaga encontrada nesse andar.\n");

        fclose(arq_vagas);
        free(vagas);

        printf("\n>>Tecle <ENTER> para continuar...\n");
        getchar();
        return;
    }

    //===========================================================
    // OPÇÃO INVÁLIDA
    //===========================================================
    else {
        printf("\nOpção inválida!\n");
        printf(">>Tecle <ENTER> para continuar...\n");
        getchar();
    }
}
