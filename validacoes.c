#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "validacoes.h"

// Valida placa (ABC-1234)
int Validar_Placa(char placa[]) {
    if (strlen(placa) != 8) return 0;
    for (int i = 0; i < 3; i++) if (!isalpha(placa[i])) return 0;
    if (placa[3] != '-') return 0;
    for (int i = 4; i < 8; i++) if (!isdigit(placa[i])) return 0;
    return 1;
}

// Ler placa com validação
void Ler_Placa(char *placa) {
    char c;
    while (1) {
        if (scanf("%s", placa) != 1) {
            while ((c = getchar()) != '\n' && c != EOF);
            printf("Entrada inválida!\n");
            continue;
        }
        while ((c = getchar()) != '\n' && c != EOF);
        if (Validar_Placa(placa)) break;
        else printf("Placa inválida! Formato correto: ABC-1234\n");
    }
}

int Validar_Placa_Lida(char placa_lida[]) {
    if (strlen(placa_lida) != 8) return 0;
    for (int i = 0; i < 3; i++) if (!isalpha(placa_lida[i])) return 0;
    if (placa_lida[3] != '-') return 0;
    for (int i = 4; i < 8; i++) if (!isdigit(placa_lida[i])) return 0;
    return 1;
}

// Ler placa com validação
void Ler_Placa_Lida(char *placa_lida) {
    char c;
    while (1) {
        if (scanf("%s", placa_lida) != 1) {
            while ((c = getchar()) != '\n' && c != EOF);
            printf("Entrada inválida!\n");
            continue;
        }
        while ((c = getchar()) != '\n' && c != EOF);
        if (Validar_Placa(placa_lida)) break;
        else printf("Placa inválida! Formato correto: ABC-1234\n");
    }
}

// Valida tipo de veículo (Carro ou Moto)
int Validar_Tipo(char tipo[]) {
    return (strcasecmp(tipo, "Carro") == 0 || strcasecmp(tipo, "Moto") == 0);
}

// Ler tipo com validação
void Ler_Tipo(char *tipo) {
    char c;
    while (1) {
        if (scanf("%s", tipo) != 1) {
            while ((c = getchar()) != '\n' && c != EOF);
            printf("Entrada inválida!\n");
            continue;
        }
        while ((c = getchar()) != '\n' && c != EOF);
        if (Validar_Tipo(tipo)) break;
        else printf("Tipo inválido! Digite 'Carro' ou 'Moto'.\n");
    }
}

// Valida CPF (XXX.XXX.XXX-XX)
int Validar_CPF(char cpf[]) {
    if (strlen(cpf) != 14) return 0;
    for (int i = 0; i < 14; i++) {
        if (i == 3 || i == 7) {
            if (cpf[i] != '.') return 0;
        } else if (i == 11) {
            if (cpf[i] != '-') return 0;
        } else {
            if (!isdigit(cpf[i])) return 0;
        }
    }
    return 1;
}

// Ler CPF com validação
void Ler_CPF(char *cpf) {
    char c;
    while (1) {
        if (scanf("%s", cpf) != 1) {
            while ((c = getchar()) != '\n' && c != EOF);
            printf("Entrada inválida!\n");
            continue;
        }
        while ((c = getchar()) != '\n' && c != EOF);
        if (Validar_CPF(cpf)) break;
        else printf("CPF inválido! Formato correto: XXX.XXX.XXX-XX\n");
    }
}

int Validar_Estacionamento(const char *entrada) {
        // se estiver vazio, já é inválido
    if (strlen(entrada) == 0)
        return 0;

    // percorre cada caractere
    for (int i = 0; i < strlen(entrada); i++) {
        if (!isdigit(entrada[i])) {
            return 0; // encontrou algo que não é número
        }
    }

    return 1; // válido
}

// 🔹 Lê o número do estacionamento e valida
void Ler_Estacionamento(char *destino) {
    do {
        printf(" >>Nº do estacionamento: ");
        scanf("%s", destino);
        getchar(); // limpa o buffer

        if (!Validar_Estacionamento(destino)) {
            printf("Entrada inválida! Digite apenas números inteiros.\n\n");
        }
    } while (!Validar_Estacionamento(destino));
}

int Validar_Estacionamento_Lida(const char *entrada) {
        // se estiver vazio, já é inválido
    if (strlen(entrada) == 0)
        return 0;

    // percorre cada caractere
    for (int i = 0; i < strlen(entrada); i++) {
        if (!isdigit(entrada[i])) {
            return 0; // encontrou algo que não é número
        }
    }

    return 1; // válido
}

void Ler_Estacionamento_Lida(char *destino) {
    do {
        printf(" >>Nº do estacionamento: ");
        scanf("%s", destino);
        getchar(); // limpa o buffer

        if (!Validar_Estacionamento_Lida(destino)) {
            printf("Entrada inválida! Digite apenas números inteiros.\n\n");
        }
    } while (!Validar_Estacionamento_Lida(destino));
}