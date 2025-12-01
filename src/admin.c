#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "../include/admin.h"
#include "../include/cadastro_vagas.h"

//==============================
// Funções de Administrador
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

//====================================
// Função genérica de exclusão física
//====================================
int excluir_fisicamente(const char *arquivo, const char *arquivo_temp, void *registro, size_t tamanho,
                        int (*comparar)(void *, void *), void *param) {
    FILE *arq = fopen(arquivo, "rb");
    FILE *arq_temp = fopen(arquivo_temp, "wb");
    int encontrado = 0;

    if (!arq || !arq_temp) {
        if (arq) fclose(arq);
        if (arq_temp) fclose(arq_temp);
        return -1;
    }

    while (fread(registro, tamanho, 1, arq)) {
        if (!comparar(registro, param)) {
            fwrite(registro, tamanho, 1, arq_temp);
        } else {
            encontrado = 1;
        }
    }

    fclose(arq);
    fclose(arq_temp);

    remove(arquivo);
    rename(arquivo_temp, arquivo);

    return encontrado;
}

//==============================
// Funções de comparação
//==============================
int comparar_veiculo(void *v, void *param) {
    Veiculos *veic = (Veiculos*)v;
    char *placa = (char*)param;
    return strcmp(veic->placa, placa) == 0;
}

int comparar_estacionamento(void *e, void *param) {
    Estacionamentos *est = (Estacionamentos*)e;
    char *n_estaci = (char*)param;
    return strcmp(est->n_estaci, n_estaci) == 0;
}

int comparar_dono(void *d, void *param) {
    DonoVeiculo *dv = (DonoVeiculo*)d;
    char *cpf = (char*)param;
    return strcmp(dv->cpf, cpf) == 0;
}

//==============================
// Excluir Veículo
//==============================
void exclu_veiculo(void) {
    system("clear||cls");
    Veiculos veiculo;
    char placa_lida[12];

    printf("\n>> Digite a placa do veículo a ser excluído: ");
    Ler_Placa(placa_lida);

    int resultado = excluir_fisicamente(ARQ_VEICULO, TEMP_VEICULO, &veiculo, sizeof(Veiculos),
                                        comparar_veiculo, placa_lida);

    if (resultado == 1)
        printf("\nVeículo com placa %s excluído fisicamente!\n", placa_lida);
    else if (resultado == 0)
        printf("\nPlaca não encontrada!\n");
    else
        printf("\nErro ao abrir arquivo de veículos.\n");

    printf("Tecle <ENTER> para continuar...");
    getchar();
}

//==============================
// Excluir Estacionamento
//==============================
void exclu_estacionamentos(void) {
    system("clear||cls");
    Estacionamentos estacionamento;
    char n_estaci_lido[8];

    printf("\n>> Digite o número do estacionamento a ser excluído: ");
    Ler_Estacionamento(n_estaci_lido);

    int resultado = excluir_fisicamente(ARQ_ESTACIONAMENTO, TEMP_ESTACIONAMENTO, &estacionamento,
                                        sizeof(Estacionamentos), comparar_estacionamento, n_estaci_lido);

    if (resultado == 1)
        printf("\nEstacionamento %s excluído fisicamente!\n", n_estaci_lido);
    else if (resultado == 0)
        printf("\nNúmero do estacionamento não encontrado!\n");
    else
        printf("\nErro ao abrir arquivo de estacionamentos.\n");

    printf("Tecle <ENTER> para continuar...");
    getchar();
}

//==============================
// Excluir Dono de Veículo
//==============================
void exclu_dono_veiculo(void) {
    system("clear||cls");
    DonoVeiculo dono;
    char cpf_lido[15];

    printf("\n>> Digite o CPF do dono a ser excluído: ");
    Ler_CPF(cpf_lido);

    int resultado = excluir_fisicamente(ARQ_DONO, TEMP_DONO, &dono, sizeof(DonoVeiculo),
                                        comparar_dono, cpf_lido);

    if (resultado == 1)
        printf("\nDono com CPF %s excluído fisicamente!\n", cpf_lido);
    else if (resultado == 0)
        printf("\nCPF não encontrado!\n");
    else
        printf("\nErro ao abrir arquivo de donos.\n");

    printf("Tecle <ENTER> para continuar...");
    getchar();
}

//============================================
// Excluir Cadastro de Vagas (listas diretas)
//============================================
void exclu_cadastro_vagas(void) {
    system("clear||cls");
    int num_andar_lido;

    printf("\n>> Digite o número do andar a excluir: ");
    Ler_num_andar(&num_andar_lido);

    // Carregar todos os registros ativos e inativos
    VagaLista *lista = newVagaList();
    preencherListaVagas_Tudo(lista);

    VagaLista *temp = lista->prox;
    int encontrado = 0;

    while (temp != NULL) {
        
        if (temp->dados.num_andar == num_andar_lido && temp->dados.status == 1) {
            temp->dados.status = 0; // exclusão lógica
            encontrado = 1;
            break;
        }
        temp = temp->prox;
    }

    if (encontrado) {
        if (gravarListaVagasEmArquivo(lista))
            printf("\nVagas do andar %d excluídas logicamente!\n", num_andar_lido);
        else
            printf("\nErro ao gravar arquivo de vagas.\n");
    } else {
        printf("\nAndar não encontrado!\n");
    }

    deleteVagas(lista);
    printf("Tecle <ENTER> para continuar...");
    getchar();
}