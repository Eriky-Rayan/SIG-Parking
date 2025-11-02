#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "validacoes.h"

// Validação de valores de entrada da placa do veículo:
int Validar_Placa(char placa[]) {
    if (strlen(placa) != 8) return 0;
    for (int i = 0; i < 3; i++) if (!isalpha(placa[i])) return 0;
    if (placa[3] != '-') return 0;
    for (int i = 4; i < 8; i++) if (!isdigit(placa[i])) return 0;
    return 1;
}

void Ler_Placa(char *placa) {
    char c;
    while (1) {
        printf(" >>Placa do Veículo (ABC-1234): ");
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


// Validação de valores dde entrada do tipo do veículo:
int Validar_Tipo(char tipo[]) {
    return (strcasecmp(tipo, "Carro") == 0 || strcasecmp(tipo, "Moto") == 0);
}

void Ler_Tipo(char *tipo) {
    char c;
    while (1) {
        printf(" >>Tipo de Veículo (Carro/Moto): ");
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


int Validar_model(const char *model) {
    if (strlen(model) == 0)
        return 0;

    for (int i = 0; i < strlen(model); i++) {
        if (!isalpha(model[i]) &&      // não é letra
            !isdigit(model[i]) &&      // não é número
            model[i] != ' ' &&         // não é espaço
            model[i] != '.' &&         // não é ponto
            model[i] != '-') {         // não é hífen
            return 0; // caractere inválido
        }
    }
    return 1; // válido
}

void Ler_model(char *destino, int tamanho) {
    do {
        printf(" >>Modelo do veículo: ");
        fgets(destino, tamanho, stdin);

        destino[strcspn(destino, "\n")] = '\0';

        if (!Validar_model(destino)) {
            printf("Modelo inválido! Use apenas letras, números, espaços, ponto e hífen.\n\n");
        }
    } while (!Validar_model(destino));
}


// Validação de valores de entrada da cor do veículo:
int Validar_cor(const char *cor) {
    if (strlen(cor) == 0)
        return 0;

    for (int i = 0; i < strlen(cor); i++) {
        if (!isalpha(cor[i]) && cor[i] != ' ') {
            return 0; // encontrou caractere inválido
        }
    }
    return 1; // válido
}

void Ler_cor(char *destino, int tamanho) {
    do {
        printf(" >>Cor do Veículo: ");
        fgets(destino, tamanho, stdin);

        destino[strcspn(destino, "\n")] = '\0';

        if (!Validar_cor(destino)) {
            printf("Cor inválida! Digite apenas letras e espaços.\n\n");
        }
    } while (!Validar_cor(destino));
}


// Validação de valores de entrada do CPF:
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

void Ler_CPF(char *cpf) {
    char c;
    while (1) {
        printf(" >>CPF do Dono do Veículo: ");
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

// Validação de valores de entrada do número do estacionamento:
int Validar_Estacionamento(const char *entrada) {
    if (strlen(entrada) == 0)
        return 0;

    for (int i = 0; i < strlen(entrada); i++) {
        if (!isdigit(entrada[i])) {
            return 0; // encontrou algo que não é número
        }
    }

    return 1; // válido
}

void Ler_Estacionamento(char *destino) {
    do {
        printf(" >>Nº do estacionamento: ");
        scanf("%s", destino);
        getchar();

        if (!Validar_Estacionamento(destino)) {
            printf("Entrada inválida! Digite apenas números inteiros.\n\n");
        }
    } while (!Validar_Estacionamento(destino));
}

int Validar_Telefone(const char *telefone) {
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

void Ler_Telefone(char *destino) {
    do {
        printf(" >>Telefone: ");
        scanf("%s", destino);
        getchar(); 

        if (!Validar_Telefone(destino)) {
            printf("Telefone inválido! Digite apenas números e caracteres válidos (+, -, (, )).\n\n");
        }
    } while (!Validar_Telefone(destino));
}


// Validação de valores de entrada do nome:
int Validar_Nome(const char *nome) {
    if (strlen(nome) == 0)
        return 0;

    for (int i = 0; i < strlen(nome); i++) {
        if (!isalpha(nome[i]) && nome[i] != ' ') {
            return 0; // encontrou caractere inválido
        }
    }
    return 1; // válido
}

void Ler_Nome(char *destino, int tamanho) {
    do {
        printf(" >>Nome: ");
        fgets(destino, tamanho, stdin);

        destino[strcspn(destino, "\n")] = '\0';

        if (!Validar_Nome(destino)) {
            printf("Nome inválido! Digite apenas letras e espaços.\n\n");
        }
    } while (!Validar_Nome(destino));
}


// Validação de valores de entrada da quantidade de veículos:
int Validar_Quantidade(const char *entrada) {
    if (strlen(entrada) == 0)
        return 0;

    for (int i = 0; i < strlen(entrada); i++) {
        if (!isdigit(entrada[i])) {
            return 0;
        }
    }

    int valor = atoi(entrada);
    if (valor <= 0)
        return 0;

    return 1;
}

void Ler_Quantidade(int *destino) {
    char buffer[20];

    do {
        printf(" >>Quantidade de veículos: ");
        scanf("%s", buffer);

        if (!Validar_Quantidade(buffer)) {
            printf("Quantidade inválida! Digite um número inteiro positivo.\n\n");
        }
    } while (!Validar_Quantidade(buffer));

    *destino = atoi(buffer);
}


// Validação de valores de entrada da quantidade de vagas:
int Validar_qtd_vagas(const char *entrada) {
    if (strlen(entrada) == 0)
        return 0;

    for (int i = 0; i < strlen(entrada); i++) {
        if (!isdigit(entrada[i])) {
            return 0;
        }
    }

    int valor = atoi(entrada);
    if (valor <= 0)
        return 0;

    return 1;
}

void Ler_qtd_vagas(int *destino) {
    char buffer[20];

    do {
        printf(" >>Quantidade de vagas: ");
        scanf("%s", buffer);

        if (!Validar_qtd_vagas(buffer)) {
            printf("Quantidade inválida! Digite um número inteiro positivo.\n\n");
        }
    } while (!Validar_qtd_vagas(buffer));

    *destino = atoi(buffer);
}


// Validação de valores de entrada do número do andar:
int Validar_num_andar(const char *entrada) {
    if (strlen(entrada) == 0)
        return 0;

    for (int i = 0; i < strlen(entrada); i++) {
        if (!isdigit(entrada[i])) {
            return 0;
        }
    }

    int valor = atoi(entrada);
    if (valor <= 0)
        return 0;

    return 1;
}

void Ler_num_andar(int *destino) {
    char buffer[20];

    do {
        printf(" >>Número do andar: ");
        scanf("%s", buffer);

        if (!Validar_num_andar(buffer)) {
            printf("Número inválido! Digite um número inteiro positivo.\n\n");
        }
    } while (!Validar_num_andar(buffer));

    *destino = atoi(buffer); // converte string válida para inteiro
}

// Valida se a opção do menu é um número entre 0 e 5
int Validacao_Opcao_Menu(const char *entrada) {
    if (strlen(entrada) == 0)
        return 0;

    // verifica se há apenas dígitos
    for (int i = 0; i < strlen(entrada); i++) {
        if (!isdigit(entrada[i])) {
            return 0; // caractere inválido
        }
    }

    // converte para número e verifica o intervalo
    int valor = atoi(entrada);
    if (valor < 0 || valor > 5)
        return 0;

    return 1;
}

// Lê a opção do menu com validação
void Ler_Opcao_Menu(char *destino) {
    char buffer[10];

    do {
        scanf("%s", buffer); // lê como string

        if (!Validacao_Opcao_Menu(buffer)) {
            printf("\nOpção inválida! Digite um número entre 0 e 5.\n\n");
        }
    } while (!Validacao_Opcao_Menu(buffer));

    *destino = buffer[0]; // guarda a opção
}

// Valida se a opção do menu é um número entre 0 e 4
int Validacao_Opcao_admin(const char *entrada) {
    if (strlen(entrada) == 0)
        return 0;

    // verifica se há apenas dígitos
    for (int i = 0; i < strlen(entrada); i++) {
        if (!isdigit(entrada[i])) {
            return 0; // caractere inválido
        }
    }

    // converte para número e verifica o intervalo
    int valor = atoi(entrada);
    if (valor < 0 || valor > 4)
        return 0;

    return 1;
}

// Lê a opção do menu com validação
void Ler_Opcao_admin(char *destino) {
    char buffer[10];

    do {
        scanf("%s", buffer); // lê como string

        if (!Validacao_Opcao_admin(buffer)) {
            printf("\nOpção inválida! Digite um número entre 0 e 4.\n\n");
        }
    } while (!Validacao_Opcao_admin(buffer));

    *destino = buffer[0]; // guarda a opção
}

