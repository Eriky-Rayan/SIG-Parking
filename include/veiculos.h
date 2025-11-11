#ifndef VEICULOS_H
#define VEICULOS_H

// ========================================
// Bibliotecas necessárias
// ========================================
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ========================================
// Definições globais
// ========================================
#define True 1
#define False 0

// ========================================
// Estrutura principal
// ========================================
typedef struct veiculos {
    char placa[12];      // Ex: "ABC-1234"
    char tipo[10];       // Ex: "Carro" ou "Moto"
    char model[20];      // Ex: "Civic", "CG 160", etc.
    char cor[15];        // Ex: "Preto", "Vermelho"
    char n_estaci[8];    // Número do estacionamento
    char cpf[15];        // CPF do dono do veículo
    char status;         // Ativo (True) ou excluído (False)
} Veiculos;

// ========================================
// Assinaturas das funções principais
// ========================================

// Controlador de menu
void switch_veiculos(void);

// Exibe o menu e retorna opção
char veiculos(void);

// CRUD de veículos
void add_veiculos(void);
void exib_veiculo(void);
void alterar_veiculo(void);
void exclu_logica_veiculo(void);
void recu_registro_veiculo(void);


void salvar_veiculos(void);
void carregar_veiculos(void);

#endif
