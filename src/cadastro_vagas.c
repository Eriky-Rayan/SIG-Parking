#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "../include/cadastro_vagas.h"
#include "../include/validacoes.h"

// ============================
// Funções de lista dinâmica
// ============================
VagaLista* newVagaList(void) {
    VagaLista* l = (VagaLista*) malloc(sizeof(VagaLista));
    if (!l) {
        fprintf(stderr, "Memoria indisponivel\n");
        exit(EXIT_FAILURE);
    }
    l->prox = NULL;
    return l;
}

void appendVaga(VagaLista *l, VagaArquivo *data) {
    VagaLista* novo = (VagaLista*) malloc(sizeof(VagaLista));
    if (!novo) {
        fprintf(stderr, "Memoria indisponivel\n");
        exit(EXIT_FAILURE);
    }

    novo->dados = *data;  // corrige para usar o struct dentro da lista
    novo->prox = NULL;

    VagaLista* temp = l;
    while (temp->prox != NULL) temp = temp->prox;
    temp->prox = novo;
}

void preencherListaVagas(VagaLista *lista) {
    FILE *arq = fopen(ARQ_VAGAS, "rb");
    if (!arq) return;

    VagaArquivo v;
    while (fread(&v, sizeof(VagaArquivo), 1, arq)) {
        if (v.status == 1) appendVaga(lista, &v);
    }
    fclose(arq);
}

void preencherListaVagas_Tudo(VagaLista *lista) {
    FILE *arq = fopen(ARQ_VAGAS, "rb");
    if (!arq) return;

    VagaArquivo v;
    while (fread(&v, sizeof(VagaArquivo), 1, arq)) {
        appendVaga(lista, &v);
    }
    fclose(arq);
}

void clearVagas(VagaLista* l) {
    VagaLista* temp = l->prox;
    while (temp) {
        VagaLista* next = temp->prox;
        free(temp);
        temp = next;
    }
    l->prox = NULL;
}

void deleteVagas(VagaLista* l) {
    clearVagas(l);
    free(l);
}

int gravarListaVagasEmArquivo(VagaLista* l) {
    FILE *arq = fopen(ARQ_VAGAS, "wb");
    if (!arq) return 0;

    VagaLista* temp = l->prox;
    while (temp) {
        VagaArquivo vWrite = temp->dados;  // agora usamos corretamente o struct
        fwrite(&vWrite, sizeof(VagaArquivo), 1, arq);
        temp = temp->prox;
    }

    fclose(arq);
    return 1;
}

int verifica_andar_existe(int num_andar) {
    VagaLista* lista = newVagaList();
    preencherListaVagas(lista);

    VagaLista* temp = lista->prox;
    while (temp) {
        if (temp->dados.num_andar == num_andar && temp->dados.status == 1) {
            deleteVagas(lista);
            return 1;
        }
        temp = temp->prox;
    }

    deleteVagas(lista);
    return 0;
}

// ============================
// Menu principal
// ============================
char cadastro_vagas(void) {
    system("clear||cls");
    char op;
    printf("\n=====================================================================\n");
    printf("||                       - SIG-Parking -                           ||\n");
    printf("=====================================================================\n");
    printf("||                       Módulo Cadastro de Andares                ||\n");
    printf("=====================================================================\n");
    printf("|| [1] -> Cadastrar Andar                                          ||\n");
    printf("|| [2] -> Exibir Andar                                             ||\n");
    printf("|| [3] -> Alterar Andar                                            ||\n");
    printf("|| [4] -> Exclusão lógica                                          ||\n");
    printf("|| [5] -> Recuperar Andar                                          ||\n");
    printf("|| [0] -> Voltar                                                   ||\n");
    printf("=====================================================================\n");
    printf(">> Escolha uma opção: ");
    Ler_Opcao_Menu(&op);
    return op;
}

void switch_cadastro_vagas(void) {
    char op;
    do {
        op = cadastro_vagas();
        switch (op) {
            case '1': add_cadastro_vagas(); break;
            case '2': exib_cadastro_vagas(); break;
            case '3': alterar_cadastro_vagas(); break;
            case '4': exclu_logica_cadastro_vagas(); break;
            case '5': recu_registro_cadastro_vagas(); break;
        }
    } while (op != '0');
}

// ============================
// CRUD
// ============================
void add_cadastro_vagas(void) {
    system("clear||cls");
    verifica_diretorio_dados();

    int num_andar, total_vagas;
    printf("\n=== Cadastro de Andar ===\n");
    Ler_num_andar(&num_andar);
    Ler_num_vaga(&total_vagas);

    if (verifica_andar_existe(num_andar)) {
        printf("\nErro: Andar já cadastrado ativo!\nTecle ENTER...");
        getchar();
        return;
    }

    VagaArquivo vNew;
    vNew.num_andar = num_andar;
    vNew.total_vagas = total_vagas;
    vNew.status = 1;
    for (int i = 0; i < MAX_VAGAS; i++) {
        vNew.ocupado[i] = 0;
        vNew.placa[i][0] = '\0';
    }

    VagaLista* lista = newVagaList();
    preencherListaVagas(lista);
    appendVaga(lista, &vNew);

    if (gravarListaVagasEmArquivo(lista))
        printf("\nAndar cadastrado com sucesso!\n");
    else
        printf("\nErro ao gravar arquivo!\n");

    deleteVagas(lista);
    printf("Tecle ENTER...");
    getchar();
}

void exib_cadastro_vagas(void) {
    system("clear||cls");
    int num_andar;
    printf("\n=== Exibir Andar ===\n");
    Ler_num_andar(&num_andar);

    VagaLista* lista = newVagaList();
    preencherListaVagas(lista);

    VagaLista* temp = lista->prox;
    int achou = 0;
    while (temp) {
        if (temp->dados.num_andar == num_andar && temp->dados.status == 1) {
            achou = 1;
            printf("\nAndar: %d | Total de vagas: %d\n", temp->dados.num_andar, temp->dados.total_vagas);
            break;
        }
        temp = temp->prox;
    }

    if (!achou) printf("\nAndar não encontrado!\n");
    deleteVagas(lista);
    printf("Tecle ENTER...");
    getchar();
}

// As demais funções (`alterar_cadastro_vagas`, `exclu_logica_cadastro_vagas`, `recu_registro_cadastro_vagas`) 
// devem ter a mesma correção: usar temp->dados.num_andar, temp->dados.total_vagas e temp->dados.status.
void alterar_cadastro_vagas(void) {
    system("clear||cls");
    int num_andar;
    printf("\n=== Alterar Andar ===\n");
    Ler_num_andar(&num_andar);

    VagaLista* lista = newVagaList();
    preencherListaVagas(lista);

    VagaLista* temp = lista->prox;
    int achou = 0;
    while (temp) {
        if (temp->dados.num_andar == num_andar && temp->dados.status == 1) {
            achou = 1;
            int novo_total_vagas;
            printf("Total de vagas atual: %d\n", temp->dados.total_vagas);
            Ler_num_vaga(&novo_total_vagas);
            temp->dados.total_vagas = novo_total_vagas;
            break;
        }
        temp = temp->prox;
    }

    if (achou) {
        if (gravarListaVagasEmArquivo(lista))
            printf("\nAndar alterado com sucesso!\n");
        else
            printf("\nErro ao gravar arquivo!\n");
    } else {
        printf("\nAndar não encontrado!\n");
    }

    deleteVagas(lista);
    printf("Tecle ENTER...");
    getchar();
}

void exclu_logica_cadastro_vagas(void) {
    system("clear||cls");
    int num_andar;
    printf("\n=== Exclusão Lógica ===\n");
    Ler_num_andar(&num_andar);

    VagaLista* lista = newVagaList();
    preencherListaVagas(lista);

    VagaLista* temp = lista->prox;
    int achou = 0;
    while (temp) {
        if (temp->dados.num_andar == num_andar && temp->dados.status == 1) {
            temp->dados.status = 0;
            achou = 1;
            break;
        }
        temp = temp->prox;
    }

    if (achou) {
        if (gravarListaVagasEmArquivo(lista))
            printf("\nAndar excluído logicamente!\n");
        else
            printf("\nErro ao gravar arquivo!\n");
    } else {
        printf("\nAndar não encontrado!\n");
    }

    deleteVagas(lista);
    printf("Tecle ENTER...");
    getchar();
}

void recu_registro_cadastro_vagas(void) {
    system("clear||cls");
    int num_andar;
    printf("\n=== Recuperar Andar ===\n");
    Ler_num_andar(&num_andar);

    VagaLista* lista = newVagaList();
    preencherListaVagas_Tudo(lista);

    VagaLista* temp = lista->prox;
    int achou = 0;
    while (temp) {
        if (temp->dados.num_andar == num_andar && temp->dados.status == 0) {
            temp->dados.status = 1;
            achou = 1;
            break;
        }
        temp = temp->prox;
    }

    if (achou) {
        if (gravarListaVagasEmArquivo(lista))
            printf("\nAndar recuperado com sucesso!\n");
        else
            printf("\nErro ao gravar arquivo!\n");
    } else {
        printf("\nAndar não encontrado ou já ativo!\n");
    }

    deleteVagas(lista);
    printf("Tecle ENTER...");
    getchar();
}