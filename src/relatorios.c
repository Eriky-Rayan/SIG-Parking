#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/relatorios.h"
#include "../include/dono_veiculo.h"
#include "../include/cadastro_vagas.h"
#include "../include/veiculos.h"

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

    FILE *arq_veiculos = fopen("dados/veiculos.dat", "rb");
    if (!arq_veiculos) {
        printf("Erro ao abrir o arquivo de veículos.\n");
        getchar();
        return;
    }

    Veiculos *veiculo = malloc(sizeof(Veiculos));
    int count = 0;

    // Cabeçalho da tabela
    printf("\n╔════════════╦════════════╦══════════════╦════════════╦════════╦═══════╦═════════════╗\n");
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
//= RELATÓRIO DE DONOS DE VEÍCULOS (corrigido)
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

    DonoVeiculoLista* lista = newDonoVeiculoList();
    preencherListaDonoVeiculo(lista);

    DonoVeiculoLista* temp = lista->prox;
    char nome_busca[50];
    int filtrando = 0;

    if (op_sub == '2') {
        printf("\n >> Digite o nome ou parte do nome: ");
        fgets(nome_busca, sizeof(nome_busca), stdin);
        nome_busca[strcspn(nome_busca, "\n")] = '\0';
        filtrando = 1;
    }

    printf("\n╔══════════════════════╦═════════════╦══════════════╦═════════╦══════════╦════════════╦════════════╦══════╦═════╗\n");
    printf("║ Nome                 ║ CPF         ║ Telefone     ║ Placa   ║ Tipo     ║ Modelo     ║ Cor        ║ Andar║ Vaga║\n");
    printf("╠══════════════════════╬═════════════╬══════════════╬═════════╬══════════╬════════════╬════════════╬══════╬═════╣\n");

    int encontrou = 0;
    while (temp != NULL) {
        if (temp->status && (!filtrando || strstr(temp->nome, nome_busca))) {
            encontrou = 1;

            FILE* arq_veiculos = fopen("dados/veiculos.dat", "rb");
            Veiculos veiculo;
            int achou_veiculo = 0;

            if (arq_veiculos) {
                while (fread(&veiculo, sizeof(Veiculos), 1, arq_veiculos)) {
                    if (veiculo.status && strcmp(veiculo.cpf, temp->cpf) == 0) {
                        achou_veiculo = 1;
                        printf("║ %-20s ║ %-11s ║ %-12s ║ %-7s ║ %-8s ║ %-10s ║ %-10s ║ %-4d ║ %-3d ║\n",
                               temp->nome, temp->cpf, temp->telefone,
                               veiculo.placa, veiculo.tipo, veiculo.model,
                               veiculo.cor, veiculo.andar, veiculo.vaga);
                    }
                }
                fclose(arq_veiculos);
            }

            if (!achou_veiculo) {
                printf("║ %-20s ║ %-11s ║ %-12s ║ %-7s ║ %-8s ║ %-10s ║ %-10s ║ %-4s ║ %-3s ║\n",
                       temp->nome, temp->cpf, temp->telefone,
                       "-", "-", "-", "-", "-", "-");
            }
        }
        temp = temp->prox;
    }

    if (!encontrou) {
        printf("║                       Nenhum dono encontrado                                               ║\n");
    }

    printf("╚══════════════════════╩═════════════╩══════════════╩═════════╩══════════╩════════════╩════════════╩══════╩═════╝\n");

    deleteDonoVeiculo(lista);
    printf("\n>> Tecle ENTER para continuar...");
    getchar();
}


void relatorio_estacionamentos(void) {
    system("clear||cls");
    FILE *arq_veiculos = fopen("dados/veiculos.dat", "rb");
    if (!arq_veiculos) {
        printf("Erro ao abrir o arquivo de veículos.\n");
        getchar();
        return;
    }

    Veiculos veiculo;
    int count = 0;

    printf("\n╔════════════╦════════════╦════════════╗\n");
    printf("║ Placa      ║ Andar      ║ Vaga       ║\n");
    printf("╠════════════╬════════════╬════════════╣\n");

    while (fread(&veiculo, sizeof(Veiculos), 1, arq_veiculos)) {
        if (veiculo.status) {
            count++;
            printf("║ %-10s ║ %-10d ║ %-10d ║\n",
                   veiculo.placa, veiculo.andar, veiculo.vaga);
        }
    }

    if (count == 0)
        printf("║        Nenhum veículo cadastrado                                               ║\n");

    printf("╚════════════╩════════════╩════════════╝\n");

    fclose(arq_veiculos);
    printf("\n>> Tecle ENTER para continuar...");
    getchar();
}

//=======================================================
//= RELATÓRIO DE CADASTRO DE VAGAS
//=======================================================
void relatorio_cadastro_vagas(void) {
    system("clear||cls");
    FILE *arq_vagas = fopen("dados/cadastro_vagas.dat", "rb");
    if (!arq_vagas) {
        printf("Erro ao abrir o arquivo de vagas.\n");
        getchar();
        return;
    }

    CV vagas;
    Veiculos veiculo;
    FILE *arq_veiculos;

    while (fread(&vagas, sizeof(CV), 1, arq_vagas)) {
        if (vagas.status) {
            printf("\n╔══════════════════════════════════════╗\n");
            printf("║ ANDAR %2d | TOTAL DE VAGAS: %2d       ║\n", vagas.num_andar, vagas.total_vagas);
            printf("╠═════════╦════════════╦═══════╦════════╗\n");
            printf("║ Placa   ║ Tipo       ║ Vaga  ║ CPF    ║\n");
            printf("╠═════════╬════════════╬═══════╬════════╣\n");

            arq_veiculos = fopen("dados/veiculos.dat", "rb");
            if (arq_veiculos) {
                int encontrou = 0;
                while (fread(&veiculo, sizeof(Veiculos), 1, arq_veiculos)) {
                    if (veiculo.status && veiculo.andar == vagas.num_andar) {
                        encontrou = 1;
                        printf("║ %-7s ║ %-10s ║ %-5d ║ %-7s ║\n",
                               veiculo.placa, veiculo.tipo, veiculo.vaga, veiculo.cpf);
                    }
                }
                if (!encontrou)
                    printf("║       Nenhum veículo nessa vaga       ║\n");

                fclose(arq_veiculos);
            }

            printf("╚═════════╩════════════╩═══════╩════════╝\n");
        }
    }

    fclose(arq_vagas);
    printf("\n>> Tecle ENTER para continuar...");
    getchar();
}