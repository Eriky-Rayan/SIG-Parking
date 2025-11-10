#ifndef CADASTRO_VAGAS_H
#define CADASTRO_VAGAS_H

#define True 1
#define False 0

// Assinatura das Funções
void switch_cadastro_vagas(void);
char cadastro_vagas(void);
void add_cadastro_vagas(void);
void exib_cadastro_vagas(void);
void alterar_cadastro_vagas(void);
void exclu_logica_cadastro_vagas(void);
void recu_registro_cadastro_vagas(void);

typedef struct cadastro_vagas {
    int qtd_vagas;
    int num_andar;
    char status;
} CV;

#endif
