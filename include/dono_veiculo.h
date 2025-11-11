#ifndef DONO_VEICULO_H
#define DONO_VEICULO_H

//=====================================
//= Definições e Estruturas            =
//=====================================

// Definições booleanas simples
#define True 1
#define False 0

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
    int quantidade;
    int status; // 1 = ativo (True), 0 = inativo (False)
} DV;

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

#endif // DONO_VEICULO_H
