#ifndef VEICULOS_H
#define VEICULOS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define True 1
#define False 0

// Tamanhos de campos
#define TAM_PLACA 12
#define TAM_TIPO 10
#define TAM_MODELO 20
#define TAM_COR 15
#define TAM_CPF 15

typedef struct veiculos {
    char placa[TAM_PLACA];   // Placa do veículo (Ex: ABC1234)
    char tipo[TAM_TIPO];     // Tipo do veículo: Carro, Moto, etc.
    char model[TAM_MODELO];  // Modelo do veículo
    char cor[TAM_COR];       // Cor do veículo
    int andar;               // Andar onde o veículo será cadastrado
    int vaga;                // Número da vaga nesse andar
    char cpf[TAM_CPF];       // CPF do dono
    int status;              // True = ativo, False = excluído
} Veiculos;

// Funções do módulo Veículos
void switch_veiculos(void);
char veiculos(void);
void add_veiculos(void);
void exib_veiculo(void);
void alterar_veiculo(void);
void exclu_logica_veiculo(void);
void recu_registro_veiculo(void);

#endif // VEICULOS_H
