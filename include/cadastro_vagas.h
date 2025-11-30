#ifndef CADASTRO_VAGAS_H
#define CADASTRO_VAGAS_H

#include <stdio.h>

#define True 1
#define False 0

#define ARQ_VAGAS "dados/cadastro_vagas.dat"
#define MAX_VAGAS 50    // Número máximo de vagas por andar
#define PLACA_LEN 8     // 7 caracteres da placa + '\0'

//=====================================================
// Estrutura do registro de vagas no arquivo
//=====================================================
typedef struct {
    int num_andar;
    int total_vagas;
    int status;               // 1 = ativo, 0 = inativo
    int ocupado[MAX_VAGAS];   // 1 = ocupado, 0 = livre
    char placa[MAX_VAGAS][PLACA_LEN]; // placas armazenadas
} VagaArquivo;

//=====================================================
// Estrutura da lista de vagas (encadeada)
//=====================================================
typedef struct VagaLista {
    VagaArquivo dados;        // registro completo do andar
    struct VagaLista *prox;   // próximo nó da lista
} VagaLista;

//=====================================================
// Funções públicas do módulo de cadastro de vagas
//=====================================================
void switch_cadastro_vagas(void);
char cadastro_vagas(void);
void add_cadastro_vagas(void);
void exib_cadastro_vagas(void);
void alterar_cadastro_vagas(void);
void exclu_logica_cadastro_vagas(void);
void recu_registro_cadastro_vagas(void);
void verifica_diretorio_dados(void);

//=====================================================
// Funções de leitura
//=====================================================
void Ler_num_andar(int *destino);
void Ler_num_vaga(int *destino);

//=====================================================
// Funções auxiliares de lista
//=====================================================
VagaLista* newVagaList(void);
void appendVaga(VagaLista *l, VagaArquivo *data);
void preencherListaVagas(VagaLista *lista);       // Carrega apenas ativos
void preencherListaVagas_Tudo(VagaLista *lista);  // Carrega todos
void clearVagas(VagaLista* l);
void deleteVagas(VagaLista* l);
int gravarListaVagasEmArquivo(VagaLista* l);
int verifica_andar_existe(int num_andar);

#endif // CADASTRO_VAGAS_H
