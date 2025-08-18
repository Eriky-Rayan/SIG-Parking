
#include <stdio.h>
#include <stdlib.h>

//Assinatura das Funções
//Function Signature

void menu_principal(void);

void veiculos(void);
void add_veiculos(void);

void estacionamentos(void);
void add_estacionamentos(void);

void dono_veiculo(void);
void add_dono_veiculo(void);

void equipe(void);
void sobre(void);

//código Principal
//main Code

int main(void) {
    int tela = 6;
    char op;

    while (tela != 0) {
        if (tela == 6) {
            menu_principal();
            scanf(" %c", &op);
            getchar();

            if (op == '1') tela = 1;
            else if (op == '2') tela = 2;
            else if (op == '3') tela = 3;
            else if (op == '4') tela = 4;
            else if (op == '5') tela = 5;
            else tela = 0;
        } else if (tela == 1) {
            veiculos();
            scanf(" %c", &op);
            getchar();
            if (op == '1') {
                add_veiculos();
                getchar();
                tela = 1;
            }
            else if (op == '0') tela = 6;
        } else if (tela == 2) {
            estacionamentos();
            scanf(" %c", &op);
            getchar();
            if (op == '1') {
                add_estacionamentos();
                getchar();
                tela = 2;
            }
            if (op == '0') tela = 6; 
        } else if (tela == 3) {
            dono_veiculo();
            scanf(" %c", &op);
            getchar();
            if (op == '1') {
                add_dono_veiculo();
                getchar();
                tela = 3;
            }
            if (op == '0') tela = 6; 
        } else if (tela == 4) {
            equipe();
            scanf(" %c", &op);
            getchar();
            if (op == '0') tela = 6; 
        } else if (tela == 5) {
            sobre();
            scanf(" %c", &op);
            getchar();
            if (op == '0') tela = 6;
        }
    }
    return 0;
}

//Definição das Funções
//Function Definition

void menu_principal(void) {
    system("clear||cls");
    printf("\n");
    printf("⎸=====================================================⎸\n");
    printf("⎸                     SIG-Parking                     ⎸\n");
    printf("⎸=====================================================⎸\n");
    printf("⎸                   Menu Principal                    ⎸\n");
    printf("⎸=====================================================⎸\n");
    printf("⎸ 1 - Módulo Veículos                                 ⎸\n");
    printf("⎸ 2 - Módulo Estacionamentos                          ⎸\n");
    printf("⎸ 3 - Módulo Donos dos Veículos                       ⎸\n");
    printf("⎸ 4 - Módulo Equipe do Projeto                        ⎸\n");
    printf("⎸ 5 - Sobre o Sistema                                 ⎸\n");
    printf("⎸ 0 - Sair                                            ⎸\n");
    printf("⎸=====================================================⎸\n");
    printf("\n");
    printf("\t >>Escolha uma opção: ");
}

void veiculos(void){
    system("clear||cls");
    printf("\n");
    printf("⎸=====================================================⎸\n");
    printf("⎸                     SIG-Parking                     ⎸\n");
    printf("⎸=====================================================⎸\n");
    printf("⎸                   Módulo Veículos                   ⎸\n");
    printf("⎸=====================================================⎸\n");
    printf("⎸ 1 - Cadastrar Veículo                               ⎸\n");
    printf("⎸ 2 - Exibir Dados do Veículo                         ⎸\n");
    printf("⎸ 3 - Alterar Dados do Veículo                        ⎸\n");
    printf("⎸ 4 - Excluir Veículo                                 ⎸\n");
    printf("⎸ 0 - Voltar ao Menu Principal                        ⎸\n");
    printf("⎸=====================================================⎸\n");
    printf("\n");
    printf("\t >>Escolha uma opção: ");
}

void add_veiculos(void){
    system("clear||cls");
    printf("\n");
    printf("⎸=====================================================⎸\n");
    printf("⎸                     SIG-Parking                     ⎸\n");
    printf("⎸=====================================================⎸\n");
    printf("⎸         Módulo Veículos - Cadastrar veículo         ⎸\n");
    printf("⎸=====================================================⎸\n");
    printf("  Digite os dados do veículo a ser cadastrado:         \n");
    printf("\n");
    printf(" >>Tipo de Veículo (Carro/Moto): ");
    printf("\n");
    printf(" >>Placa do Veículo: ");
    printf("\n");
    printf(" >>Nome do Veículo: ");
    printf("\n");
    printf(" >>Cor do Veículo: ");
    printf("\n");
    printf(" >>Nº do estacionamento: ");
    printf("\n");
    printf(" >>CPF do Dono do Veículo: ");
    printf("\n");
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
    printf("\n");
    printf("\t >>Escolha uma opção: ");
}

void add_estacionamentos(void){
    system("clear||cls");
    printf("\n");
    printf("⎸=====================================================⎸\n");
    printf("⎸                     SIG-Parking                     ⎸\n");
    printf("⎸=====================================================⎸\n");
    printf("⎸ Módulo Estacionamentos - Cadastrar Estacionamento   ⎸\n");
    printf("⎸=====================================================⎸\n");
    printf("  Digite os dados do estacionamento a ser cadastrado:  \n");
    printf("\n");
    printf(" >>Tipo do Estacionamento (Carro/Moto): ");
    printf("\n");
    printf(" >>Número do Estacionamento: ");
    printf("\n");
}

void dono_veiculo(void) {
    system("clear||cls");
    printf("\n");
    printf("⎸=====================================================⎸\n");
    printf("⎸                     SIG-Parking                     ⎸\n");
    printf("⎸=====================================================⎸\n");
    printf("⎸              Módulo Donos dos Veículos              ⎸\n");
    printf("⎸=====================================================⎸\n");
    printf("⎸ 1 - Cadastrar Dono de Veículo                       ⎸\n");
    printf("⎸ 2 - Exibir dados do Dono de Veículo                 ⎸\n");
    printf("⎸ 3 - Alterar dados do Dono de Veículo                ⎸\n");
    printf("⎸ 4 - Excluir Dono de Veículo                         ⎸\n");
    printf("⎸ 0 - Voltar ao Menu Principal                        ⎸\n");
    printf("⎸=====================================================⎸\n");
    printf("\n");
    printf("\t >>Escolha uma opção: ");
}

void add_dono_veiculo(void) {
    system("clear||cls");
    printf("\n");
    printf("⎸=====================================================⎸\n");
    printf("⎸                     SIG-Parking                     ⎸\n");
    printf("⎸=====================================================⎸\n");
    printf("⎸      Módulo Donos dos Veículos - Cadastrar Dono     ⎸\n");
    printf("⎸=====================================================⎸\n");
    printf(" Digite os dados do dono do veículo a ser cadastrado:  \n");
    printf("\n");
    printf(" >>Nome do Dono: ");
    printf("\n");
    printf(" >>CPF do Dono: ");
    printf("\n");
    printf(" >>Telefone do Dono: ");
    printf("\n");
}

void equipe(void) {
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
    printf("\t >>Aperte '0' para voltar ao Menu Principal: ");
}

void sobre(void){
    system("clear||cls");
    printf("\n");
    printf("⎸=====================================================⎸\n");
    printf("⎸                     SIG-Parking                     ⎸\n");
    printf("⎸=====================================================⎸\n");
    printf("⎸                     Tela Sobre                      ⎸\n");
    printf("⎸=====================================================⎸\n");
    printf("⎸-Sistema de Controle de Estacionamentos Para Carros e⎸\n");
    printf("⎸ Motos-                                              ⎸\n");
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
    printf("\t >>Aperte '0' para voltar ao Menu Principal: ");
}