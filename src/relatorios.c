#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/relatorios.h"
#include "../include/dono_veiculo.h"
#include "../include/cadastro_vagas.h"
#include "../include/veiculos.h"
#include "../include/estacionamentos.h"

//===============================
//= Funções do Módulo Relatório =
//===============================

void switch_relatorio(void) {
    char op;
    do {
        op = relatorio();
        switch (op) {
            case '1': relatorio_veiculos(); break;
            case '2': relatorio_estacionamentos(); break;
            case '3': relatorio_dono_veiculo(); break;
            case '4': relatorio_cadastro_vagas(); break;
            case '5': relatorio_veiculo_dono_vaga();break;
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
    printf("|| [5] -> Relatório de veículos estacionados                                       ||\n");
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
    printf("|| [3] -> Veículos estacionados                                                    ||\n");
    printf("|| [0] -> Voltar ao Menu Principal                                                 ||\n");
    printf("=====================================================================================\n");
    printf(" >> Escolha uma opção: ");
    scanf(" %c", &op_sub);
    getchar();

    if (op_sub == '0') return;

    FILE *arq_veiculos = fopen("dados/veiculos.dat", "rb");
    if (!arq_veiculos) {
        printf("Erro ao abrir o arquivo de veículos.\n");
        getchar();
        return;
    }

    Veiculos *veiculo = malloc(sizeof(Veiculos));
    int count = 0;

    // Cabeçalho da tabela
    printf("╔════════════╦════════════╦══════════════╦════════════╦════════╦═══════╦═════════════╗\n");
    printf("║ Placa      ║ Tipo       ║ Modelo       ║ Cor        ║ Andar  ║ Vaga  ║ CPF Dono    ║\n");
    printf("╠════════════╬════════════╬══════════════╬════════════╬════════╬═══════╬═════════════╣\n");

    if (op_sub == '1') {
        while (fread(veiculo, sizeof(Veiculos), 1, arq_veiculos)) {
            if (veiculo->status) {
                count++;
                printf("║ %-10s ║ %-10s ║ %-12s ║ %-10s ║ %-6d ║ %-5d ║ %-11s ║\n",
                       veiculo->placa, veiculo->tipo, veiculo->model,
                       veiculo->cor, veiculo->andar, veiculo->vaga, veiculo->cpf);
            }
        }
        if (count == 0)
            printf("║ %-76s ║\n", "Nenhum veículo cadastrado");
    } 
    else if (op_sub == '2') {
        char cor_busca[15];
        printf("\n >> Digite a cor do veículo: ");
        fgets(cor_busca, sizeof(cor_busca), stdin);
        cor_busca[strcspn(cor_busca, "\n")] = '\0';

        while (fread(veiculo, sizeof(Veiculos), 1, arq_veiculos)) {
            if (veiculo->status && strstr(veiculo->cor, cor_busca)) {
                count++;
                printf("║ %-10s ║ %-10s ║ %-12s ║ %-10s ║ %-6d ║ %-5d ║ %-11s ║\n",
                       veiculo->placa, veiculo->tipo, veiculo->model,
                       veiculo->cor, veiculo->andar, veiculo->vaga, veiculo->cpf);
            }
        }
        if (count == 0)
            printf("║ %-76s ║\n", "Nenhum veículo cadastrado com essa cor");
    } 
    else {
        printf("\nOpção inválida!\n");
    }

    // Rodapé da tabela
    printf("╚════════════╩════════════╩══════════════╩════════════╩════════╩═══════╩═════════════╝\n");

    fclose(arq_veiculos);
    free(veiculo);
    printf("\n>> Tecle ENTER para continuar...");
    getchar();
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
    printf("|| [2] -> Filtrar por vaga do veículo                                             ||\n");
    printf("|| [0] -> Voltar ao Menu Principal                                                 ||\n");
    printf("=====================================================================================\n");
    printf(" >> Escolha uma opção: ");
    scanf(" %c", &op_sub);
    getchar();

    FILE *arq_veiculos = fopen("dados/veiculos.dat", "rb");
    if (!arq_veiculos) {
        printf("Erro ao abrir o arquivo de veículos.\n");
        getchar();
        return;
    }

    Veiculos *veiculo = malloc(sizeof(Veiculos));
    int count = 0;

    printf("╔════════════╦════════════╦════════════╗\n");
    printf("║ Placa      ║ Andar      ║ Vaga       ║\n");
    printf("╠════════════╬════════════╬════════════╣\n");

    if (op_sub == '1') {
        while (fread(veiculo, sizeof(Veiculos), 1, arq_veiculos)) {
            if (veiculo->status) {
                count++;
                printf("║ %-10s ║ %-10d ║ %-10d ║\n",
                       veiculo->placa, veiculo->andar, veiculo->vaga);
            }
        }
        if (count == 0)
            printf("║        Nenhum veículo cadastrado                                               ║\n");
    } 
    else if (op_sub == '2') {
        int vaga_busca;
        printf("\n >> Digite o número da vaga: ");
        scanf("%d", &vaga_busca);
        getchar();

        while (fread(veiculo, sizeof(Veiculos), 1, arq_veiculos)) {
            if (veiculo->status && veiculo->vaga == vaga_busca) {
                count++;
                printf("║ %-10s ║ %-10d ║ %-10d ║\n",
                       veiculo->placa, veiculo->andar, veiculo->vaga);
            }
        }
        if (count == 0)
            printf("║     Nenhum veículo encontrado nessa vaga                                       ║\n");
    } 
    else {
        printf("\nOpção inválida!\n");
    }

    printf("╚════════════╩════════════╩════════════╝\n");

    fclose(arq_veiculos);
    free(veiculo);
    printf("\n>> Tecle ENTER para continuar...");
    getchar();
}

//=======================================================
//= RELATÓRIO DE DONOS DE VEÍCULOS
//=======================================================
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

    FILE *arq_dono;
    DV *dono = malloc(sizeof(DV));
    Veiculos veiculo;
    FILE *arq_veiculos;

    if (op_sub == '1' || op_sub == '2') {
        char nome_busca[50];
        int filtrando = 0;
        if (op_sub == '2') {
            printf("\n >> Digite o nome ou parte do nome: ");
            fgets(nome_busca, 50, stdin);
            nome_busca[strcspn(nome_busca, "\n")] = '\0';
            filtrando = 1;
        }

        arq_dono = fopen("dados/dono_veiculo.dat", "rb");
        if (!arq_dono) {
            printf("Erro ao abrir o arquivo de donos.\n");
            free(dono);
            getchar();
            return;
        }

        printf("\n╔══════════════════════╦═════════════╦══════════════╦═════════╦══════════╦════════════╦════════════╦══════╦═════╗\n");
        printf("║ Nome                 ║ CPF         ║ Telefone     ║ Placa   ║ Tipo     ║ Modelo     ║ Cor        ║ Andar║ Vaga║\n");
        printf("╠══════════════════════╬═════════════╬══════════════╬═════════╬══════════╬════════════╬════════════╬══════╬═════╣\n");

        int encontrou_dono = 0;
        while (fread(dono, sizeof(DV), 1, arq_dono)) {
            if (dono->status && (!filtrando || strstr(dono->nome, nome_busca))) {
                encontrou_dono = 1;

                arq_veiculos = fopen("dados/veiculos.dat", "rb");
                int encontrou_veiculo = 0;

                if (arq_veiculos) {
                    while (fread(&veiculo, sizeof(Veiculos), 1, arq_veiculos)) {
                        if (veiculo.status && strcmp(veiculo.cpf, dono->cpf) == 0) {
                            encontrou_veiculo = 1;
                            printf("║ %-20s ║ %-11s ║ %-12s ║ %-7s ║ %-8s ║ %-10s ║ %-10s ║ %-4d ║ %-3d ║\n",
                                   dono->nome, dono->cpf, dono->telefone,
                                   veiculo.placa, veiculo.tipo, veiculo.model,
                                   veiculo.cor, veiculo.andar, veiculo.vaga);
                        }
                    }
                    fclose(arq_veiculos);
                }

                if (!encontrou_veiculo) {
                    printf("║ %-20s ║ %-11s ║ %-12s ║ %-7s ║ %-8s ║ %-10s ║ %-10s ║ %-4s ║ %-3s ║\n",
                           dono->nome, dono->cpf, dono->telefone,
                           "-", "-", "-", "-", "-", "-");
                }
            }
        }

        if (!encontrou_dono)
            printf("║                       Nenhum dono encontrado                                               ║\n");

        printf("╚══════════════════════╩═════════════╩══════════════╩═════════╩══════════╩════════════╩════════════╩══════╩═════╝\n");

        fclose(arq_dono);
        free(dono);
        printf("\n>> Tecle ENTER para continuar...");
        getchar();
        return;
    }

    printf("\nOpção inválida!\n");
    free(dono);
    getchar();
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

    int andar_busca = 0;
    if (op_sub == '2') {
        printf("\n >> Digite o número do andar: ");
        scanf("%d", &andar_busca);
        getchar();
    }

    FILE *arq_vagas = fopen("dados/cadastro_vagas.dat", "rb");
    if (!arq_vagas) {
        printf("Erro ao abrir o arquivo de vagas.\n");
        getchar();
        return;
    }

    CV *vagas = malloc(sizeof(CV));
    Veiculos veiculo;
    FILE *arq_veiculos;
    int encontrou;

    rewind(arq_vagas);
    while (fread(vagas, sizeof(CV), 1, arq_vagas)) {
        if (vagas->status && (op_sub == '1' || (op_sub == '2' && vagas->num_andar == andar_busca))) {
            printf("\n╔═══════════════════════════════════════════════════════════════════╗\n");
            printf("║                   ANDAR %2d | TOTAL DE VAGAS: %2d                   ║\n", vagas->num_andar, vagas->total_vagas);
            printf("╠═════════╦══════════╦════════════╦════════════╦══════╦═════════════╣\n");
            printf("║ Placa   ║ Tipo     ║ Modelo     ║ Cor        ║ Vaga ║ CPF Dono    ║\n");
            printf("╠═════════╬══════════╬════════════╬════════════╬══════╬═════════════╣\n");

            arq_veiculos = fopen("dados/veiculos.dat", "rb");
            if (arq_veiculos) {
                encontrou = 0;
                while (fread(&veiculo, sizeof(Veiculos), 1, arq_veiculos)) {
                    if (veiculo.status && veiculo.andar == vagas->num_andar) {
                        encontrou = 1;
                        printf("║ %-7s ║ %-8s ║ %-10s ║ %-10s ║ %-4d ║ %-11s ║\n",
                               veiculo.placa, veiculo.tipo, veiculo.model,
                               veiculo.cor, veiculo.vaga, veiculo.cpf);
                    }
                }
                if (!encontrou)
                    printf("║                      Nenhum veículo nessa vaga                            ║\n");
                fclose(arq_veiculos);
            }

            printf("╚═════════╩══════════╩════════════╩════════════╩══════╩═════════════╝\n\n");
        }
    }

    free(vagas);
    fclose(arq_vagas);
    printf("\n>> Tecle ENTER para continuar...");
    getchar();
}
void relatorio_veiculo_dono_vaga(void){
    system("clear||cls");
    
    FILE *arq_estacionamentos, *arq_veiculos, *arq_dono;

    Estacionamentos *estacionamento = malloc(sizeof(Estacionamentos));
    Veiculos *veiculo = malloc(sizeof(Veiculos));
    DV *dono = malloc(sizeof(DV));

    arq_estacionamentos = fopen("dados/estacionamentos.dat", "rb");
    if (!arq_estacionamentos) {
        printf("Erro ao abrir estacionamentos.\n");
        getchar();
        free(estacionamento);
        free(veiculo);
        free(dono);
        return;
    }

    printf("╔═════════════════════════════════════════════════════════════════╗\n");
    printf("║                RELATÓRIO — VEÍCULOS ESTACIONADOS                ║\n");
    printf("╠════════════════════════╦════════════════════════╦═══════════════╣\n");
    printf("║ %-22s ║ %-22s ║ %-13s ║\n", "Veiculo", "Dono", "Vaga");
    printf("╠════════════════════════╬════════════════════════╬═══════════════╣\n");

    while (fread(estacionamento, sizeof(Estacionamentos), 1, arq_estacionamentos)) {

        if (estacionamento->status) {

            // ---- BUSCA VEÍCULO ----
            arq_veiculos = fopen("dados/veiculos.dat", "rb");
            int achouVeic = 0;

            if (arq_veiculos) {
                while (fread(veiculo, sizeof(Veiculos), 1, arq_veiculos)) {
                    if (veiculo->status && strcmp(veiculo->placa, estacionamento->placa) == 0) {
                        achouVeic = 1;
                        break;
                    }
                }
                fclose(arq_veiculos);
            }

            if (achouVeic) {

                // ---- BUSCA DONO ----
                arq_dono = fopen("dados/dono_veiculo.dat", "rb");
                int achouDono = 0;

                if (arq_dono) {
                    while (fread(dono, sizeof(DV), 1, arq_dono)) {
                        if (dono->status && strcmp(dono->cpf, veiculo->cpf) == 0) {
                            achouDono = 1;
                            break;
                        }
                    }
                    fclose(arq_dono);
                }

                if (achouDono) {
                    printf("║ %-22s ║ %-22s ║ %-13s ║\n",
                        veiculo->model,
                        dono->nome,
                        estacionamento->n_estaci);
                }
            }
        }
    }

    printf("╚════════════════════════╩════════════════════════╩═══════════════╝\n");
    printf("\n>> Tecle ENTER para continuar...");
    getchar();

    fclose(arq_estacionamentos);
    free(estacionamento);
    free(veiculo);
    free(dono);
}
