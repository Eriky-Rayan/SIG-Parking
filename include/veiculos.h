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

// ============================
// Struct principal do arquivo
// ============================
typedef struct veiculos {
    char placa[TAM_PLACA];   
    char tipo[TAM_TIPO];     
    char model[TAM_MODELO];  
    char cor[TAM_COR];       
    int andar;               
    int vaga;                
    char cpf[TAM_CPF];       
    int status;              // 1 = ativo, 0 = excluído
} Veiculos;

// ============================
// Lista Dinâmica Direta
// ============================
typedef struct VeiculoLista {
    Veiculos dados;          
    struct VeiculoLista *prox;
} VeiculoLista;

// Funções da lista dinâmica
VeiculoLista* newVeiculoList(void);
void appendVeiculo(VeiculoLista *l, Veiculos *data);
void preencherListaVeiculos(VeiculoLista *lista);
void preencherListaVeiculos_Tudo(VeiculoLista *lista);
void clearVeiculos(VeiculoLista* l);
void deleteVeiculos(VeiculoLista* l);
int gravarListaVeiculosEmArquivo(VeiculoLista* l);

// Caminho do arquivo
#define ARQ_VEICULOS "dados/veiculos.dat"

// ============================
// Menu principal
// ============================
void switch_veiculos(void);
char veiculos(void);

// ============================
// CRUD
// ============================
void add_veiculos(void);
void exib_veiculo(void);
void alterar_veiculo(void);
void exclu_logica_veiculo(void);
void recu_registro_veiculo(void);

#endif // VEICULOS_H
