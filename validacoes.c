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

int Validar_CPF_Lido(char cpf_lido[]) {
    if (strlen(cpf_lido) != 14) return 0;
    for (int i = 0; i < 14; i++) {
        if (i == 3 || i == 7) {
            if (cpf_lido[i] != '.') return 0;
        } else if (i == 11) {
            if (cpf_lido[i] != '-') return 0;
        } else {
            if (!isdigit(cpf_lido[i])) return 0;
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

void Ler_CPF_Lido(char *cpf_lido) {
    char c;
    while (1) {
        if (scanf("%s", cpf_lido) != 1) {
            while ((c = getchar()) != '\n' && c != EOF);
            printf("Entrada inválida!\n");
            continue;
        }
        while ((c = getchar()) != '\n' && c != EOF);
        if (Validar_CPF(cpf_lido)) break;
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

void Ler_Estacionamento(char *destino) {
    do {
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
        scanf("%s", destino);
        getchar(); // limpa o buffer

        if (!Validar_Estacionamento_Lida(destino)) {
            printf("Entrada inválida! Digite apenas números inteiros.\n\n");
        }
    } while (!Validar_Estacionamento_Lida(destino));
}


// 🔹 Validação do telefone: retorna 1 se válido, 0 se inválido
int Validacao_Telefone(const char *telefone) {
    if (strlen(telefone) == 0)
        return 0;

    for (int i = 0; i < strlen(telefone); i++) {
        if (!isdigit(telefone[i]) && telefone[i] != '+' &&
            telefone[i] != '(' && telefone[i] != ')' &&
            telefone[i] != '-' && telefone[i] != ' ') {
            return 0; // caractere inválido
        }
    }
    return 1; // telefone válido
}
// 🔹 Leitura e validação do telefone
void Ler_Telefone(char *destino) {
    do {
        scanf("%s", destino); // você pode trocar por fgets() se quiser aceitar espaços
        getchar(); 

        if (!Validacao_Telefone(destino)) {
            printf("Telefone inválido! Digite apenas números e caracteres válidos (+, -, (, )).\n\n");
        }
    } while (!Validacao_Telefone(destino));
}


// 🔹 Valida se o nome contém apenas letras e espaços
int Validacao_Nome(const char *nome) {
    if (strlen(nome) == 0)
        return 0;

    for (int i = 0; i < strlen(nome); i++) {
        if (!isalpha(nome[i]) && nome[i] != ' ') {
            return 0; // encontrou caractere inválido
        }
    }
    return 1; // válido
}
// 🔹 Lê o nome do dono e valida
void Ler_Nome(char *destino, int tamanho) {
    do {
        fgets(destino, tamanho, stdin);

        // remove o \n do final, se houver
        destino[strcspn(destino, "\n")] = '\0';

        if (!Validacao_Nome(destino)) {
            printf("Nome inválido! Digite apenas letras e espaços.\n\n");
        }
    } while (!Validacao_Nome(destino));
}


// 🔹 Validação: retorna 1 se a entrada contém apenas dígitos e é maior que 0
int Validacao_Quantidade(const char *entrada) {
    if (strlen(entrada) == 0)
        return 0;

    for (int i = 0; i < strlen(entrada); i++) {
        if (!isdigit(entrada[i])) {
            return 0; // caractere inválido
        }
    }

    // Verifica se é maior que 0
    int valor = atoi(entrada);
    if (valor <= 0)
        return 0;

    return 1;
}
// 🔹 Leitura e validação da quantidade
void Ler_Quantidade(int *destino) {
    char buffer[20];

    do {
        scanf("%s", buffer); // lê como string para validar
        // getchar(); // não necessário se usar scanf("%s")

        if (!Validacao_Quantidade(buffer)) {
            printf("Quantidade inválida! Digite um número inteiro positivo.\n\n");
        }
    } while (!Validacao_Quantidade(buffer));

    *destino = atoi(buffer); // converte string válida para inteiro
}

// 🔹 Validação: retorna 1 se a entrada contém apenas dígitos e é maior que 0
int Validacao_qtd_vagas(const char *entrada) {
    if (strlen(entrada) == 0)
        return 0;

    for (int i = 0; i < strlen(entrada); i++) {
        if (!isdigit(entrada[i])) {
            return 0; // caractere inválido
        }
    }

    // Verifica se é maior que 0
    int valor = atoi(entrada);
    if (valor <= 0)
        return 0;

    return 1;
}

// 🔹 Leitura e validação da quantidade
void Ler_qtd_vagas(int *destino) {
    char buffer[20];

    do {
        scanf("%s", buffer);

        if (!Validacao_qtd_vagas(buffer)) {
            printf("Quantidade inválida! Digite um número inteiro positivo.\n\n");
        }
    } while (!Validacao_qtd_vagas(buffer));

    *destino = atoi(buffer); // converte string válida para inteiro
}

// 🔹 Validação: retorna 1 se a entrada contém apenas dígitos e é maior que 0
int Validacao_num_andar(const char *entrada) {
    if (strlen(entrada) == 0)
        return 0;

    for (int i = 0; i < strlen(entrada); i++) {
        if (!isdigit(entrada[i])) {
            return 0; // caractere inválido
        }
    }

    // Verifica se é maior que 0
    int valor = atoi(entrada);
    if (valor <= 0)
        return 0;

    return 1;
}

// 🔹 Leitura e validação do número do andar
void Ler_num_andar(int *destino) {
    char buffer[20];

    do {
        scanf("%s", buffer);

        if (!Validacao_num_andar(buffer)) {
            printf("Número inválido! Digite um número inteiro positivo.\n\n");
        }
    } while (!Validacao_num_andar(buffer));

    *destino = atoi(buffer); // converte string válida para inteiro
}

