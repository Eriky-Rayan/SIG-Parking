#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include "../include/veiculos.h"
#include "../include/validacoes.h"

// ========================================
// Menu principal de veículos
// ========================================
void switch_veiculos(void) {
    char op;
    do {
        op = veiculos();
        switch (op) {
            case '1': add_veiculos(); break;
            case '2': exib_veiculo(); break;
            case '3': alterar_veiculo(); break;
            case '4': exclu_logica_veiculo(); break;
            case '5': recu_registro_veiculo(); break;
        }
    } while (op != '0');
}

char veiculos(void) {
    system("clear||cls");
    char op;

    printf("\n");
    printf("=============================================================\n");
    printf("||                    - SIG-Parking -                      ||\n");
    printf("=============================================================\n");
    printf("|| [1] -> Cadastrar Veículo                                ||\n");
    printf("|| [2] -> Exibir Dados do Veículo                          ||\n");
    printf("|| [3] -> Alterar Dados do Veículo                         ||\n");
    printf("|| [4] -> Excluir Veículo                                  ||\n");
    printf("|| [5] -> Recuperar Registro de Veículo                    ||\n");
    printf("|| [0] -> Voltar ao Menu Principal                         ||\n");
    printf("=============================================================\n");
    printf("\t>> Escolha uma opção: ");
    Ler_Opcao_Menu(&op);
    return op;
}

// ========================================
// Função: Cadastrar Veículo
// ========================================
void add_veiculos(void) {
    system("clear||cls");
    verifica_diretorio_dados();

    FILE *arq_veiculos;
    Veiculos veiculo;

    printf("\n=========== Cadastro de Veículo ===========\n");
    Ler_Placa(veiculo.placa);
    Ler_Tipo(veiculo.tipo);
    Ler_model(veiculo.model, sizeof(veiculo.model));
    Ler_cor(veiculo.cor, sizeof(veiculo.cor));
    Ler_Estacionamento(veiculo.n_estaci);
    Ler_CPF(veiculo.cpf);
    veiculo.status = True;

    arq_veiculos = fopen("dados/veiculos.dat", "ab");
    if (!arq_veiculos) {
        perror("Erro ao abrir o arquivo de veículos");
        printf("\t>>Tecle <ENTER> para continuar...");
        getchar();
        return;
    }

    fwrite(&veiculo, sizeof(Veiculos), 1, arq_veiculos);
    fclose(arq_veiculos);

    printf("\nVeículo cadastrado com sucesso!\n");
    printf("Placa: %s | Tipo: %s | Modelo: %s | Cor: %s | Estac.: %s | CPF: %s\n",
           veiculo.placa, veiculo.tipo, veiculo.model,
           veiculo.cor, veiculo.n_estaci, veiculo.cpf);

    printf("\n\t>>Tecle <ENTER> para continuar...");
    getchar();
}

// ========================================
// Função: Exibir Veículo
// ========================================
void exib_veiculo(void) {
    system("clear||cls");

    FILE *arq_veiculos;
    Veiculos veiculo;
    char placa_lida[12];
    int encontrado = 0;

    printf("\n=========== Exibir Veículo ===========\n");
    Ler_Placa(placa_lida);

    arq_veiculos = fopen("dados/veiculos.dat", "rb");
    if (!arq_veiculos) {
        printf("\tNenhum veículo cadastrado ainda.\n");
        printf("\t>>Tecle <ENTER> para continuar...");
        getchar();
        return;
    }

    while (fread(&veiculo, sizeof(Veiculos), 1, arq_veiculos)) {
        if ((strcmp(veiculo.placa, placa_lida) == 0) && (veiculo.status)) {
            encontrado = 1;
            printf("\n<<< Veículo encontrado >>>\n");
            printf("Placa: %s\nTipo: %s\nModelo: %s\nCor: %s\nEstac.: %s\nCPF: %s\n",
                   veiculo.placa, veiculo.tipo, veiculo.model,
                   veiculo.cor, veiculo.n_estaci, veiculo.cpf);
            break;
        }
    }

    fclose(arq_veiculos);
    if (!encontrado)
        printf("\nPlaca não encontrada!\n");

    printf("\n\t>>Tecle <ENTER> para continuar...");
    getchar();
}

// ========================================
// Função: Alterar Veículo
// ========================================
void alterar_veiculo(void) {
    system("clear||cls");

    FILE *arq_veiculos;
    Veiculos veiculo;
    char placa_lida[12];
    int encontrado = 0;

    printf("\n=========== Alterar Veículo ===========\n");
    Ler_Placa(placa_lida);

    arq_veiculos = fopen("dados/veiculos.dat", "r+b");
    if (!arq_veiculos) {
        printf("\tErro ao abrir o arquivo de veículos.\n");
        printf("\t>>Tecle <ENTER> para continuar...");
        getchar();
        return;
    }

    while (fread(&veiculo, sizeof(Veiculos), 1, arq_veiculos)) {
        if ((strcmp(veiculo.placa, placa_lida) == 0) && veiculo.status) {
            encontrado = 1;
            printf("\n--- Informe os novos dados ---\n");
            Ler_Tipo(veiculo.tipo);
            Ler_model(veiculo.model, sizeof(veiculo.model));
            Ler_cor(veiculo.cor, sizeof(veiculo.cor));
            Ler_Estacionamento(veiculo.n_estaci);
            Ler_CPF(veiculo.cpf);

            fseek(arq_veiculos, -sizeof(Veiculos), SEEK_CUR);
            fwrite(&veiculo, sizeof(Veiculos), 1, arq_veiculos);
            break;
        }
    }

    fclose(arq_veiculos);

    if (encontrado)
        printf("\nDados do veículo alterados com sucesso!\n");
    else
        printf("\nPlaca não encontrada!\n");

    printf("\t>>Tecle <ENTER> para continuar...");
    getchar();
}

// ========================================
// Função: Exclusão lógica de veículo
// ========================================
void exclu_logica_veiculo(void) {
    system("clear||cls");

    FILE *arq_veiculos;
    Veiculos veiculo;
    char placa_lida[12];
    int encontrado = 0;

    printf("\n=========== Excluir Veículo ===========\n");
    Ler_Placa(placa_lida);

    arq_veiculos = fopen("dados/veiculos.dat", "r+b");
    if (!arq_veiculos) {
        printf("\tErro ao abrir o arquivo de veículos.\n");
        printf("\t>>Tecle <ENTER> para continuar...");
        getchar();
        return;
    }

    while (fread(&veiculo, sizeof(Veiculos), 1, arq_veiculos)) {
        if ((strcmp(veiculo.placa, placa_lida) == 0) && veiculo.status) {
            veiculo.status = False;
            fseek(arq_veiculos, -sizeof(Veiculos), SEEK_CUR);
            fwrite(&veiculo, sizeof(Veiculos), 1, arq_veiculos);
            encontrado = 1;
            break;
        }
    }

    fclose(arq_veiculos);

    if (encontrado)
        printf("\nVeículo excluído logicamente.\n");
    else
        printf("\nPlaca não encontrada!\n");

    printf("\t>>Tecle <ENTER> para continuar...");
    getchar();
}

// ========================================
// Função: Recuperar Veículo
// ========================================
void recu_registro_veiculo(void) {
    system("clear||cls");

    FILE *arq_veiculos;
    Veiculos veiculo;
    char placa_lida[12];
    int encontrado = 0;

    printf("\n=========== Recuperar Veículo ===========\n");
    Ler_Placa(placa_lida);

    arq_veiculos = fopen("dados/veiculos.dat", "r+b");
    if (!arq_veiculos) {
        printf("\tErro ao abrir o arquivo de veículos.\n");
        printf("\t>>Tecle <ENTER> para continuar...");
        getchar();
        return;
    }

    while (fread(&veiculo, sizeof(Veiculos), 1, arq_veiculos)) {
        if ((strcmp(veiculo.placa, placa_lida) == 0) && !veiculo.status) {
            veiculo.status = True;
            fseek(arq_veiculos, -sizeof(Veiculos), SEEK_CUR);
            fwrite(&veiculo, sizeof(Veiculos), 1, arq_veiculos);
            encontrado = 1;
            break;
        }
    }

    fclose(arq_veiculos);

    if (encontrado)
        printf("\nVeículo recuperado com sucesso!\n");
    else
        printf("\nPlaca não encontrada!\n");

    printf("\t>>Tecle <ENTER> para continuar...");
    getchar();
}
