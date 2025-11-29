#ifndef DONO_VEICULO_H
#define DONO_VEICULO_H

//=====================================
//= Definições e Estruturas            =
//=====================================

// Definições booleanas simples
#define TRUE 1
#define FALSE 0

//=====================================
//= Caminhos dos Arquivos              =
//=====================================
#define ARQ_DONO_VEICULO "dados/dono_veiculo.dat"
#define TEMP_DONO_VEICULO "dados/temp_dono_veiculo.dat"

//=====================================
//= Estrutura do Dono de Veículo       =
//=====================================
typedef struct dono_veiculo {
    char cpf[15];
    char telefone[20];
    char nome[50];
    char placa[12];  // placa do veículo cadastrado
    int status;      // TRUE = ativo, FALSE = inativo
} DonoVeiculo;

// Estrutura da lista encadeada
typedef struct dono_veiculo_lista {
    char cpf[15];
    char telefone[20];
    char nome[50];
    char placa[12];
    int status;
    struct dono_veiculo_lista *prox;
} DonoVeiculoLista;

//=====================================
//= Assinaturas das Funções            =
//=====================================
void switch_dono_veiculo(void);
char dono_veiculo(void);

void add_dono_veiculo(void);
void exib_dono_veiculo(void);
void alterar_dono_veiculo(void);
void exclu_logica_dono_veiculo(void);
void recu_registro_dono_veiculo(void);

// Funções auxiliares de lista
DonoVeiculoLista* newDonoVeiculoList(void);
void appendDonoVeiculo(DonoVeiculoLista *l, DonoVeiculo *data);
void preencherListaDonoVeiculo(DonoVeiculoLista *lista);
void preencherListaDonoVeiculo_Tudo(DonoVeiculoLista *lista);
void clearDonoVeiculo(DonoVeiculoLista* l);
void deleteDonoVeiculo(DonoVeiculoLista* l);
int gravarListaDonoVeiculoEmArquivo(DonoVeiculoLista* l);
int verifica_veiculo_existe(const char *placa);

#endif // DONO_VEICULO_H
