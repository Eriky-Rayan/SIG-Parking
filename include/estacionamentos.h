#ifndef ESTACIONAMENTO_H
#define ESTACIONAMENTO_H

#define True 1
#define False 0

// ====================
// Assinatura das Funções
// ====================
void switch_estacionamentos(void);
char estacionamentos(void);
void add_estacionamentos(void);
void exib_estacionamentos(void);
void alterar_estacionamentos(void);
void exclu_logica_estacionamentos(void);
void recu_registro_estacionamentos(void);

// ====================
// Estrutura Principal
// ====================
struct estacionamentos
{
    char n_estaci[8];
    char placa[12];
    char status;
};

typedef struct estacionamentos Estacionamentos;

// ====================
// Persistência
// ====================
void salvar_estacionamentos(void);
void carregar_estacionamentos(void);

#endif
