#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "validacoes.h"

// Valida CPF (apenas números, pontos e hífen, 11 dígitos)
int validarCPF(char cpf[]) {
    int i, digitos = 0;
    for (i = 0; cpf[i] != '\0'; i++) {
        if (isdigit(cpf[i])) digitos++;
        else if (cpf[i] != '.' && cpf[i] != '-') return 0;
    }
    return (digitos == 11);
}

// Valida placa (ABC-1234)
int validarPlaca(char placa[]) {
    if (strlen(placa) != 8) return 0;
    for (int i = 0; i < 3; i++) if (!isalpha(placa[i])) return 0;
    if (placa[3] != '-') return 0;
    for (int i = 4; i < 8; i++) if (!isdigit(placa[i])) return 0;
    return 1;
}

// Valida tipo (Carro ou Moto)
int validarTipo(char tipo[]) {
    return (strcasecmp(tipo, "Carro") == 0 || strcasecmp(tipo, "Moto") == 0);
}

// Ler string não vazia
void lerString(char *entrada, int tamanho) {
    char c;
    while (1) {
        if (scanf("%s", entrada) != 1) {
            while ((c = getchar()) != '\n' && c != EOF);
            printf("Entrada inválida! Tente novamente.\n");
            continue;
        }
        while ((c = getchar()) != '\n' && c != EOF);
        if (strlen(entrada) == 0) printf("Entrada não pode ser vazia! Tente novamente.\n");
        else break;
    }
}

// Ler CPF com validação
void lerCPF(char *cpf) {
    char c;
    while (1) {
        if (scanf("%s", cpf) != 1) {
            while ((c = getchar()) != '\n' && c != EOF);
            printf("Entrada inválida!\n");
            continue;
        }
        while ((c = getchar()) != '\n' && c != EOF);
        if (validarCPF(cpf)) break;
        else printf("CPF inválido! Deve conter 11 números. Tente novamente.\n");
    }
}

// Ler placa com validação
void lerPlaca(char *placa) {
    char c;
    while (1) {
        if (scanf("%s", placa) != 1) {
            while ((c = getchar()) != '\n' && c != EOF);
            printf("Entrada inválida!\n");
            continue;
        }
        while ((c = getchar()) != '\n' && c != EOF);
        if (validarPlaca(placa)) break;
        else printf("Placa inválida! Formato correto: ABC-1234\n");
    }
}

// Ler tipo com validação
void lerTipo(char *tipo) {
    char c;
    while (1) {
        if (scanf("%s", tipo) != 1) {
            while ((c = getchar()) != '\n' && c != EOF);
            printf("Entrada inválida!\n");
            continue;
        }
        while ((c = getchar()) != '\n' && c != EOF);
        if (validarTipo(tipo)) break;
        else printf("Tipo inválido! Digite 'Carro' ou 'Moto'.\n");
    }
}
