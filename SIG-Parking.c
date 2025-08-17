
#include <stdio.h>
#include <stdlib.h>

void menu_principal(void);
void equipe(void);

int main(void) {
    menu_principal();
    equipe();
    return 0;
}

void menu_principal(void) {
    char op;
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
    printf("⎸ 4 - Módulo Equipe                                   ⎸\n");
    printf("⎸ 5 - Sair                                            ⎸\n");
    printf("⎸=====================================================⎸\n");
    printf("\t\t >>Escolha uma opção: ");
    scanf("%c", &op);
    getchar();
    printf("\n");
    printf("\t\t >>Aperte qualquer tecla para continuar");
    getchar();
}

void equipe (void){
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
    printf("\n");
    printf("\t\t >>Aperte qualquer tecla para continuar");
    getchar();
}

void menu_cad (void){
    system("clear||cls");
    printf("\n");
    printf("⎸=====================================================⎸\n");
    printf("⎸                     SIG-Parking                     ⎸\n");
    printf("⎸=====================================================⎸\n");
    printf("⎸                  Menu de Cadastro                   ⎸\n");
    printf("⎸=====================================================⎸\n");
    printf("⎸ -Cadastrar Usuário(a)                               ⎸\n");
    printf("⎸ -Cadastrar Veículo                                  ⎸\n");
    printf("⎸=====================================================⎸\n");
}
