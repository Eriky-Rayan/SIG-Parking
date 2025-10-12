#define True 1;
#define False 0;
//Assinatura das Funções
//Function Signature

void switch_dono_veiculo(void);
char dono_veiculo(void);
void add_dono_veiculo(void);
void exib_dono_veiculo(void);
void alterar_dono_veiculo(void);
void exclu_dono_veiculo(void);

struct dono_veiculo
{
    char cpf[15];
    char cpf_lido[15];
    char telefone[20];
    char nome[50];
    int quantidade;
    char status;
};

typedef struct dono_veiculo DV;
