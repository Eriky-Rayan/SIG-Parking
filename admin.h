//Assinatura das Funções
//Function Signature

void switch_admin(void);
char admin(void);
void exclu_veiculo(void);
void exclu_estacionamentos(void);
void exclu_dono_veiculo(void);
void exclu_cadastro_vagas(void);

struct veiculos {
    char placa[12];
    char tipo[10];
    char model[20];
    char cor [15];
    char n_estaci[8];
    char cpf[15];
    char status;
};

struct estacionamentos
{
    char n_estaci[8];
    char placa[12];
    char status;
};

struct dono_veiculo
{
    char cpf[15];
    char telefone[20];
    char nome[50];
    int quantidade;
    char status;
};

struct cadastro_vagas
{
    int qtd_vagas;
    int num_andar;
    char status;
};

typedef struct veiculos Veiculos;
typedef struct estacionamentos Estacionamentos;
typedef struct dono_veiculo DV;
typedef struct cadastro_vagas CV;