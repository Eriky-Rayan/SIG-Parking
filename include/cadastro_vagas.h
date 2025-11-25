#ifndef CADASTRO_VAGAS_H
#define CADASTRO_VAGAS_H

// ==============================
// Definições booleanas simples
// ==============================
#define True 1
#define False 0

// ==============================
// Caminhos dos arquivos
// ==============================
#define ARQ_VAGAS "dados/cadastro_vagas.dat"
#define TEMP_VAGAS "dados/temp_cadastro_vagas.dat"

// ==============================
// Estrutura de Dados
// ==============================
typedef struct cadastro_vagas {
    int num_andar;    // Número do andar
    int total_vagas;  // Quantidade de vagas nesse andar
    int status;       // 1 = ativo, 0 = inativo
} CV;

// ==============================
// Assinaturas das funções
// ==============================
void switch_cadastro_vagas(void);
char cadastro_vagas(void);
void add_cadastro_vagas(void);
void exib_cadastro_vagas(void);
void alterar_cadastro_vagas(void);
void exclu_logica_cadastro_vagas(void);
void recu_registro_cadastro_vagas(void);
void verifica_diretorio_dados(void);

// ==============================
// Funções de leitura específicas
// ==============================
void Ler_num_andar(int *destino);
void Ler_num_vaga(int *destino);

#endif // CADASTRO_VAGAS_H
