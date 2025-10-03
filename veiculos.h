
//Assinatura das Funções
//Function Signature

void switch_veiculos(void);
char veiculos(void);
void add_veiculos(void);
void exib_veiculo(void);
void alterar_veiculo(void);
void exclu_veiculo(void);

struct veiculos {
    char placa[12];
    char placa_lida[12];
    char tipo[10];
    char model[20];
    char cor [15];
    char n_estaci[8];
    char cpf[15];
};

typedef struct veiculos Veiculos;