
#include <stdio.h>
#include <stdlib.h>

void menu_principal(void);
void estacionamentos(void);
void dono_veiculo(void);
void equipe(void);

int main(void) {
    int tela = 5;
    char op;

    while (tela != 0) {
        if (tela == 5) {
            menu_principal();
            scanf(" %c", &op);
            getchar();

            if (op == '1') tela = 1;
            else if (op == '2') tela = 2;
            else if (op == '3') tela = 3;
            else if (op == '4') tela = 4;
            else tela = 0;
        } else if (tela == 1) {
            // Módulo Automóveis
        } else if (tela == 2) {
            estacionamentos();
            scanf(" %c", &op);
            getchar();
            if (op == '0') tela = 5; 
        } else if (tela == 3) {
            dono_veiculo();
            scanf(" %c", &op);
            getchar();
            if (op == '0') tela = 5; 
        } else if (tela == 4) {
            equipe();
            scanf(" %c", &op);
            getchar();
            if (op == '0') tela = 5; 
        }
    }
    return 0;
}

void menu_principal(void) {
    system("clear||cls");
    printf("\n");
    printf("⎸=====================================================⎸\n");
    printf("⎸                     SIG-Parking                     ⎸\n");
    printf("⎸=====================================================⎸\n");
    printf("⎸                   Menu Principal                    ⎸\n");
    printf("⎸=====================================================⎸\n");
    printf("⎸ 1 - Módulo Automóveis                               ⎸\n");
    printf("⎸ 2 - Módulo Estacionamentos                          ⎸\n");
    printf("⎸ 3 - Módulo Donos dos Automóveis                     ⎸\n");
    printf("⎸ 4 - Módulo Equipe do Projeto                        ⎸\n");
    printf("⎸ 0 - Sair                                            ⎸\n");
    printf("⎸=====================================================⎸\n");
    printf("\t >>Escolha uma opção: ");
}

void estacionamentos(void) {
    system("clear||cls");
    printf("\n");
    printf("⎸=====================================================⎸\n");
    printf("⎸                     SIG-Parking                     ⎸\n");
    printf("⎸=====================================================⎸\n");
    printf("⎸                Módulo Estacionamentos               ⎸\n");
    printf("⎸=====================================================⎸\n");
    printf("⎸ 1 - Cadastrar Estacionamento                        ⎸\n");
    printf("⎸ 2 - Exibir dados do Estacionamento                  ⎸\n");
    printf("⎸ 3 - Alterar dados do Estacionamento                 ⎸\n");
    printf("⎸ 4 - Excluir Estacionamento                          ⎸\n");
    printf("⎸ 0 - Voltar ao Menu Principal                        ⎸\n");
    printf("⎸=====================================================⎸\n");
    printf("\t >>Escolha uma opção: ");
}

void dono_veiculo(void) {
    system("clear||cls");
    printf("\n");
    printf("⎸=====================================================⎸\n");
    printf("⎸                     SIG-Parking                     ⎸\n");
    printf("⎸=====================================================⎸\n");
    printf("⎸              Módulo Donos dos Automóveis            ⎸\n");
    printf("⎸=====================================================⎸\n");
    printf("⎸ 1 - Cadastrar Dono de Automóvel                     ⎸\n");
    printf("⎸ 2 - Exibir dados do Dono de Automóvel               ⎸\n");
    printf("⎸ 3 - Alterar dados do Dono de Automóvel              ⎸\n");
    printf("⎸ 4 - Excluir Dono de Automóvel                       ⎸\n");
    printf("⎸ 0 - Voltar ao Menu Principal                        ⎸\n");
    printf("⎸=====================================================⎸\n");
    printf("\t >>Escolha uma opção: ");
}

void equipe (void) {
    system("clear||cls");
    printf("\n");
    printf("⎸=====================================================⎸\n");
    printf("⎸                     SIG-Parking                     ⎸\n");
    printf("⎸=====================================================⎸\n");
    printf("⎸                  Equipe do Projeto                  ⎸\n");
    printf("⎸=====================================================⎸\n");
    printf("⎸ -Eriky Rayan B. De Medeiros                         ⎸\n");
    printf("⎸ -Email:eriky.medeiros.706@ufrn.edu.br               ⎸\n");
    printf("⎸ -GitHub:https://github.com/Eriky-Rayan              ⎸\n");
    printf("⎸=====================================================⎸\n");
    printf("⎸ -Isaac Vilton Ribeiro                               ⎸\n");
    printf("⎸ -Email:Isaac.ribeiro.018@ufrn.edu.br                ⎸\n");
    printf("⎸ -GitHub:https://github.com/Isaac-Ribeiro            ⎸\n");
    printf("⎸=====================================================⎸\n");
    printf("⎸ -Git:https://github.com/Eriky-Rayan/SIG-Parking.git ⎸\n");
    printf("⎸=====================================================⎸\n");
    printf("\t >>Aperte '0' para voltar ao Menu Principal: ");
}
