#ifndef DONO_VEICULO_H
#define DONO_VEICULO_H

//=====================================================
//  Definições Simples
//=====================================================
#define True 1
#define False 0

//=====================================================
//  Caminho do Arquivo de Donos
//=====================================================
#define ARQ_DONO_VEICULO "dados/dono_veiculo.dat"

//=====================================================
//  Estrutura do Dono de Veículo (igual estilo amigo)
//=====================================================
typedef struct donoVeiculo {
    char cpf[15];
    char telefone[20];
    char nome[50];
    char placa[12];
    int status;             // 1 ativo, 0 inativo
} DonoVeiculo;

//=====================================================
//  Lista Dinâmica (estilo do seu amigo)
//=====================================================
typedef struct donoVeiculoLista {
    char cpf[15];
    char telefone[20];
    char nome[50];
    char placa[12];
    int status;
    struct donoVeiculoLista *prox;
} DonoVeiculoLista;

//=====================================================
//  Funções de lista (estilo iniciante)
//=====================================================
DonoVeiculoLista* newDonoVeiculoList(void);
void appendDonoVeiculo(DonoVeiculoLista *l, DonoVeiculo *data);
void preencherListaDonoVeiculo(DonoVeiculoLista *lista);
void clearDonoVeiculo(DonoVeiculoLista* l);
void deleteDonoVeiculo(DonoVeiculoLista* l);
int gravarListaDonoVeiculoEmArquivo(DonoVeiculoLista* l);

//=====================================================
//  Menu
//=====================================================
void switch_dono_veiculo(void);
char dono_veiculo(void);

//=====================================================
//  Ações principais
//=====================================================
void add_dono_veiculo(void);
void exib_dono_veiculo(void);
void alterar_dono_veiculo(void);
void exclu_logica_dono_veiculo(void);
void recu_registro_dono_veiculo(void);

//=====================================================
//  Função auxiliar
//=====================================================
int verifica_veiculo_existe(const char *placa);

#endif