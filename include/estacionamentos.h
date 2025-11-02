#define True 1;
#define False 0;
//Assinatura das Funções
//Function Signature

void switch_estacionamentos(void);
char estacionamentos(void);
void add_estacionamentos(void);
void exib_estacionamentos(void);
void alterar_estacionamentos(void);
void exclu_logica_estacionamentos(void);
void recu_registro_estacionamentos(void);

struct estacionamentos
{
    char n_estaci[8];
    char placa[12];
    char status;
};

typedef struct estacionamentos Estacionamentos;