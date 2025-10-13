#define True 1;
#define False 0;
//Assinatura das Funções
//Function Signature

void switch_cadastro_vagas(void);
char cadastro_vagas(void);
void add_cadastro_vagas(void);
void exib_cadastro_vagas(void);
void alterar_cadastro_vagas(void);
void exclu_cadastro_vagas(void);

struct cadastro_vagas
{
    int qtd_vagas;
    int num_andar;
    char status;
};

typedef struct cadastro_vagas CV;