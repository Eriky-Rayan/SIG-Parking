#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "../include/validacoes.h"

// ==========================================================
// Função: verifica_diretorio_dados()
// Garante que a pasta "dados" exista antes de salvar arquivos
// ==========================================================
void verifica_diretorio_dados(void) {
    struct stat st = {0};
    if (stat("dados", &st) == -1) {
        mkdir("dados", 0700);
    }
}

// ==========================================================
// Funções de Validação
// ==========================================================

// ---- CPF ----
int Validar_CPF(const char *cpf) {
    int i, j, digito1 = 0, digito2 = 0, valido = 1;
    int num[11];

    // Remove caracteres não numéricos
    int k = 0;
    for (i = 0; i < strlen(cpf); i++) {
        if (isdigit(cpf[i])) {
            num[k++] = cpf[i] - '0';
        }
    }
    if (k != 11)
        return 0;

    // Verifica se todos os dígitos são iguais
    for (i = 1; i < 11; i++) {
        if (num[i] != num[0]) {
            valido = 0;
            break;
        }
    }
    if (valido)
        return 0;

    // Calcula dígitos verificadores
    for (i = 0, j = 10; i < 9; i++, j--)
        digito1 += num[i] * j;
    digito1 = 11 - (digito1 % 11);
    if (digito1 >= 10)
        digito1 = 0;

    for (i = 0, j = 11; i < 10; i++, j--)
        digito2 += num[i] * j;
    digito2 = 11 - (digito2 % 11);
    if (digito2 >= 10)
        digito2 = 0;

    return (num[9] == digito1 && num[10] == digito2);
}

// ---- Telefone ----
int Validar_Telefone(const char *telefone) {
    int digitos = 0;
    for (int i = 0; i < strlen(telefone); i++) {
        if (isdigit(telefone[i]))
            digitos++;
        else if (telefone[i] != '+' && telefone[i] != '(' &&
                 telefone[i] != ')' && telefone[i] != '-' &&
                 telefone[i] != ' ')
            return 0; // caractere inválido
    }
    return (digitos >= 10 && digitos <= 13);
}

// ---- Placa ----
int Validar_Placa(const char *placa) {
    if (strlen(placa) != 7)
        return 0;
    for (int i = 0; i < 3; i++) {
        if (!isalpha(placa[i]))
            return 0;
    }
    for (int i = 3; i < 7; i++) {
        if (!isdigit(placa[i]))
            return 0;
    }
    return 1;
}

// ==========================================================
// Funções de Leitura com validação e repetição segura
// ==========================================================

void Ler_CPF(char *cpf) {
    do {
        printf(" >>Digite o CPF (somente números ou com pontuação): ");
        scanf("%s", cpf);
        getchar();
        if (!Validar_CPF(cpf)) {
            printf("CPF inválido! Tente novamente.\n\n");
        }
    } while (!Validar_CPF(cpf));
}

void Ler_Telefone(char *destino) {
    do {
        printf(" >>Telefone (Ex: (11)91234-5678 ou +55 11 91234-5678): ");
        scanf("%[^\n]", destino);
        getchar();

        if (!Validar_Telefone(destino)) {
            printf("\nTelefone inválido! Use apenas números e caracteres válidos (+, -, (, ), espaço).\n\n");
        }
    } while (!Validar_Telefone(destino));
}

void Ler_Placa(char *placa) {
    do {
        printf(" >>Digite a placa (formato ABC1234): ");
        scanf("%s", placa);
        getchar();
        if (!Validar_Placa(placa)) {
            printf("Placa inválida! Use 3 letras seguidas de 4 números.\n\n");
        }
    } while (!Validar_Placa(placa));
}

void Ler_Tipo(char *tipo) {
    printf(" >>Digite o tipo do veículo (Ex: Carro, Moto): ");
    scanf("%[^\n]", tipo);
    getchar();
}

void Ler_Estacionamento(char *destino) {
    printf(" >>Digite o número do estacionamento: ");
    scanf("%[^\n]", destino);
    getchar();
}

void Ler_TelefoneSimples(char *destino) {
    printf(" >>Digite o telefone: ");
    scanf("%[^\n]", destino);
    getchar();
}

void Ler_Quantidade(int *destino) {
    printf(" >>Digite a quantidade: ");
    scanf("%d", destino);
    getchar();
}

void Ler_qtd_vagas(int *destino) {
    printf(" >>Digite a quantidade de vagas: ");
    scanf("%d", destino);
    getchar();
}

void Ler_num_andar(int *destino) {
    printf(" >>Digite o número do andar: ");
    scanf("%d", destino);
    getchar();
}

void Ler_Opcao_Menu(char *destino) {
    printf("\n >>Escolha uma opção: ");
    scanf(" %c", destino);
    getchar();
}

void Ler_Opcao_admin(char *destino) {
    printf("\n >>Escolha uma opção do menu admin: ");
    scanf(" %c", destino);
    getchar();
}

void Ler_Nome(char *destino, int tamanho) {
    printf(" >>Digite o nome: ");
    fgets(destino, tamanho, stdin);
    destino[strcspn(destino, "\n")] = '\0';
}

void Ler_model(char *destino, int tamanho) {
    printf(" >>Digite o modelo: ");
    fgets(destino, tamanho, stdin);
    destino[strcspn(destino, "\n")] = '\0';
}

void Ler_cor(char *destino, int tamanho) {
    printf(" >>Digite a cor: ");
    fgets(destino, tamanho, stdin);
    destino[strcspn(destino, "\n")] = '\0';
}
