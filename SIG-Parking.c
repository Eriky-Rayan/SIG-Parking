
#include <stdio.h>
#include <stdlib.h>

//você encontrará as seguintes funções ao decorrer desse código.
//you will find the following functions throughout this code.
void menu_principal(void);
void estacionamentos(void);
void dono_veiculo(void);
void equipe(void);
void sobre(void);

int main(void) {
    menu_principal();
    estacionamentos();
    dono_veiculo();
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
    printf("⎸ 5 - Módulo Equipe do Projeto                        ⎸\n");
    printf("⎸ 6 - Sair                                            ⎸\n");
    printf("⎸=====================================================⎸\n");
    printf("\t\t >>Escolha uma opção: ");
    scanf("%c", &op);
    getchar();
    printf("\n");
    printf("\t\t >>Aperte qualquer tecla para continuar");
    getchar();
}

void estacionamentos(void) {
    char op;
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
    printf("\t\t >>Escolha uma opção: ");
    scanf("%c", &op);
    getchar();
    printf("\n");
    printf("\t\t >>Aperte qualquer tecla para continuar");
    getchar();
}

void dono_veiculo(void) {
    char op;
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
    printf("\t\t >>Escolha uma opção: ");
    scanf("%c", &op);
    getchar();
    printf("\n");
    printf("\t\t >>Aperte qualquer tecla para continuar");
    getchar();
}

void equipe (void) {
    char op;
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
    printf("\t\t >>Escolha uma opção: ");
    scanf("%c", &op);
    getchar();
    printf("\n");
    printf("\t\t >>Aperte qualquer tecla para continuar");
    getchar();
}

void sobre (void){
    char op;
    system("clear||cls");
    printf("\n");
    printf("⎸=====================================================⎸\n");
    printf("⎸                     SIG-Parking                     ⎸\n");
    printf("⎸=====================================================⎸\n");
    printf("⎸                     Tela Sobre                      ⎸\n");
    printf("⎸=====================================================⎸\n");
    printf("⎸Sistema de Controle de Estacionamentos Para Carros e ⎸\n");
    printf("⎸Motos                                                ⎸\n");
    printf("⎸                                                     ⎸\n");
    printf("⎸-Programa para fins didáticos de ilustração,         ⎸\n"); 
    printf("⎸utilizado como exemplo de codificação de             ⎸\n"); 
    printf("⎸funcionalidades em linguagem C, durante a disciplina ⎸\n");  
    printf("⎸DCT1106 - Programação                                ⎸\n");  
    printf("⎸do curso de Bacharelado em Sistemas de Informação da ⎸\n");  
    printf("⎸Universidade Federal do Rio Grande do Norte.         ⎸\n");  
    printf("⎸O programa contém os principais módulos e            ⎸\n");  
    printf("⎸funcionalidades que serão exigidos na avaliação dos  ⎸\n");  
    printf("⎸projetos a serem desenvolvidos pelos alunos ao longo ⎸\n"); 
    printf("⎸da disciplina. Todos os dados e informações          ⎸\n");  
    printf("⎸utilizados neste programa são fictícios.             ⎸\n");
    printf("⎸=====================================================⎸\n");
    printf("\n");
    printf("\t\t >>Aperte qualquer tecla para continuar");
    getchar();
}