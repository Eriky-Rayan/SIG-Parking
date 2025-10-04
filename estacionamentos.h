
//Assinatura das Funções
//Function Signature

void switch_estacionamentos(void);
char estacionamentos(void);
void add_estacionamentos(void);
void exib_estacionamentos(void);
void alterar_estacionamentos(void);
void exclu_estacionamentos(void);

struct estacionamentos
{
    char n_estaci[8];
    char n_estaci_lida[8];
    char placa[12];
};

typedef struct estacionamentos Estacionamentos;