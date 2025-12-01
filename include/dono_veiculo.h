#ifndef DONO_VEICULO_H
#define DONO_VEICULO_H

//=====================================
//= Definições e Estruturas
//=====================================

// Definições booleanas simples
#define TRUE 1
#define FALSE 0

//=====================================
//= Caminhos dos Arquivos
//=====================================
#define ARQ_DONO_VEICULO "dados/dono_veiculo.dat"
#define TEMP_DONO_VEICULO "dados/temp_dono_veiculo.dat"

//=====================================
//= Estrutura do Dono de Veículo
//=====================================
typedef struct dono_veiculo {
    char cpf[15];
    char telefone[20];
    char nome[50];
    char placa[12];   // placa vinculada no cadastro
    int status;       // TRUE = ativo, FALSE = inativo
} DonoVeiculo;

//=====================================
//= Estrutura da Lista Encadeada
//=====================================
typedef struct dono_veiculo_lista {
    DonoVeiculo *dados;
    struct dono_veiculo_lista *prox;
} DonoVeiculoLista;

//=====================================
//= Assinaturas das Funções
//=====================================

// Menu principal
void switch_dono_veiculo(void);
char dono_veiculo(void);

// CRUD básico
void add_dono_veiculo(void);
void exib_dono_veiculo(void);
void alterar_dono_veiculo(void);
void exclu_logica_dono_veiculo(void);
void recu_registro_dono_veiculo(void);

// Lista dinâmica
DonoVeiculoLista* newDonoVeiculoList(void);
void appendDonoVeiculo(DonoVeiculoLista *l, DonoVeiculo *data);
void preencherListaDonoVeiculo(DonoVeiculoLista *lista);          // Apenas ativos
void preencherListaDonoVeiculo_Tudo(DonoVeiculoLista *lista);     // Todos, mesmo inativos
void clearDonoVeiculo(DonoVeiculoLista* l);
void deleteDonoVeiculo(DonoVeiculoLista* l);

// Gravar novamente no arquivo (opcional)
int gravarListaDonoVeiculoEmArquivo(DonoVeiculoLista* l);

// Verificar vínculo com veículos
int verifica_veiculo_existe(const char *placa);

// 🔥 FUNÇÃO DE ORDENAÇÃO USADA PELO RELATÓRIO
void ordenarListaDono(DonoVeiculoLista *lista);

#endif // DONO_VEICULO_H
