
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//Assinatura das Funções
//Function Signature

char menu_principal(void);
void tela_saida(void);

void switch_estacionamentos(void);
char estacionamentos(void);
void add_estacionamentos(void);
void exib_estacionamentos(void);
void alterar_estacionamentos(void);
void exclu_estacionamentos(void);

void switch_relatorio(void);
char relatorio(void);
void relatorio_veiculos(void);
void relatorio_estacionamentos(void);
void relatorio_dono_veiculo(void);
void relatorio_veiculo_estacionamento_dono(void);

void equipe(void);
void sobre(void);
void op_invalida(void);

//código Principal
//main Code

int main(void){

    char op;
    do {
        op = menu_principal();
        switch (op) {
            case '0': 
                tela_saida();
                break;
            case '1': 
                switch_veiculos();
                break;
            case '2': 
                switch_estacionamentos();
                break;
            case '3': 
                switch_dono_veiculo();
                break;
            case '4': 
                switch_cadastro_vagas();
                break;
            case '5': 
                switch_relatorio();
                break;
            case '6': 
                equipe();
                break;
            case '7': 
                sobre();
                break;
            default:
                op_invalida();
                break;
        }
    } while (op != '0');
}

//Definição das Funções
//Function Definition

char menu_principal(void) {
    system("clear||cls");

    char op;

    printf("\n");
    printf("⎸==================================================================================⎸\n");
    printf("⎸                                   SIG-Parking                                    ⎸\n");
    printf("⎸==================================================================================⎸\n");
    printf("⎸                                  Menu Principal                                  ⎸\n");
    printf("⎸==================================================================================⎸\n");
    printf("⎸ 1 - Módulo Veículos                                                              ⎸\n");
    printf("⎸ 2 - Módulo Estacionamentos                                                       ⎸\n");
    printf("⎸ 3 - Módulo Donos dos Veículos                                                    ⎸\n");
    printf("⎸ 4 - Módulo Cadastro de Vagas                                                     ⎸\n");
    printf("⎸ 5 - Módulo Relatórios                                                            ⎸\n");
    printf("⎸ 6 - Módulo Equipe do Projeto                                                     ⎸\n");
    printf("⎸ 7 - Sobre o Sistema                                                              ⎸\n");
    printf("⎸ 0 - Sair                                                                         ⎸\n");
    printf("⎸==================================================================================⎸\n");
    printf("\n");
    printf("\t >>Escolha uma opção: ");
    scanf("%c", &op);
    getchar();
    printf("\n");
    return op;
}

//=========================
//= Módulo Estacionamento =
//=========================

void switch_estacionamentos(void){

    char op;

    do {
        op = estacionamentos();
        switch (op) {
            case '1': 
                add_estacionamentos();
                break;
            case '2': 
                exib_estacionamentos();
                break;
            case '3': 
                alterar_estacionamentos();
                break;
            case '4': 
                exclu_estacionamentos();
                break;
        }
    } while (op != '0');
}

char estacionamentos(void) {
    system("clear||cls");

    char op;

    printf("\n");
    printf("⎸==================================================================================⎸\n");
    printf("⎸                                   SIG-Parking                                    ⎸\n");
    printf("⎸==================================================================================⎸\n");
    printf("⎸                             Módulo Estacionamentos                               ⎸\n");
    printf("⎸==================================================================================⎸\n");
    printf("⎸ 1 - Cadastrar Estacionamento                                                     ⎸\n");
    printf("⎸ 2 - Exibir Dados do Estacionamento                                               ⎸\n");
    printf("⎸ 3 - Alterar Dados do Estacionamento                                              ⎸\n");
    printf("⎸ 4 - Excluir Estacionamento                                                       ⎸\n");
    printf("⎸ 0 - Voltar ao Menu Principal                                                     ⎸\n");
    printf("⎸==================================================================================⎸\n");
    printf("\n");
    printf("\t >>Escolha uma opção: ");
    scanf("%c", &op);
    getchar();
    printf("\n");
    return op;
}

void add_estacionamentos(void) {
    system("clear||cls");

    char n_estaci[8];
    char tipo[10];
    char placa[12];

    printf("\n");
    printf("⎸==================================================================================⎸\n");
    printf("⎸                                   SIG-Parking                                    ⎸\n");
    printf("⎸==================================================================================⎸\n");
    printf("⎸                 Módulo Estacionamentos - Cadastrar Estacionamento                ⎸\n");
    printf("⎸==================================================================================⎸\n");
    printf("\n");
    printf(" >>Digite o Nº da vaga onde o veículo será cadastrado: ");
    scanf("%s", n_estaci);
    getchar();
    printf("\n");
    printf(" >>Tipo de Veículo no estacionamento (Carro/Moto): ");
    scanf("%s", tipo);
    getchar();
    printf("\n");
    printf(" >>Digite a placa do veículo: ");
    scanf("%s", placa);
    getchar();
    printf("\n");

    printf("Veículo cadastrado no estacionamento com sucesso!\n");
    printf("\nNº do estacionamento: %s", n_estaci);
    printf("\nTipo do veículo: %s", tipo);
    printf("\nPlaca: %s", placa);
    printf("\n");
    printf("\t >>Tecle <ENTER> para continuar...\n");
}

void exib_estacionamentos(void) {
    system("clear||cls");

    char n_estaci[8];

    printf("\n");
    printf("⎸==================================================================================⎸\n");
    printf("⎸                                   SIG-Parking                                    ⎸\n");
    printf("⎸==================================================================================⎸\n");
    printf("⎸                 Módulo Estacionamentos - Exibir Estacionamento                   ⎸\n");
    printf("⎸==================================================================================⎸\n");
    printf("\n");
    printf(" >>Digite Nº da vaga que deseja ver: ");
    scanf("%s", n_estaci);
    getchar();
    printf("\n");
    printf("O veículo na seguinte vaga foi exibido: %s\n", n_estaci);
    printf("\n");
    printf("\t >>Tecle <ENTER> para continuar...\n");
}

void alterar_estacionamentos(void) {
    system("clear||cls");

    char n_estaci[8];
    char tipo[10];
    char placa[12];

    printf("\n");
    printf("⎸==================================================================================⎸\n");
    printf("⎸                                   SIG-Parking                                    ⎸\n");
    printf("⎸==================================================================================⎸\n");
    printf("⎸                 Módulo Estacionamentos - Alterar Estacionamento                  ⎸\n");
    printf("⎸==================================================================================⎸\n");
    printf("\n");
    printf(" -Digite os novos dados do estacionamento-");
    printf("\n");
    printf(" >>Digite o Nº da vaga que deseja alterar: ");
    scanf("%s", n_estaci);
    getchar();
    printf("\n");
    printf(" >>Tipo de Veículo no estacionamento (Carro/Moto): ");
    scanf("%s", tipo);
    getchar();
    printf("\n");
    printf(" >>Digite a placa do veículo: ");
    scanf("%s", placa);
    getchar();
    printf("\n");

    printf("Vaga de estacionamento alterada com sucesso!\n");
    printf("\nNº do estacionamento: %s", n_estaci);
    printf("\nTipo do veículo: %s", tipo);
    printf("\nPlaca: %s", placa);
    printf("\n");
    printf("\t >>Tecle <ENTER> para continuar...\n");
}

void exclu_estacionamentos(void) {
    system("clear||cls");

    char n_estaci[8];

    printf("\n");
    printf("⎸==================================================================================⎸\n");
    printf("⎸                                   SIG-Parking                                    ⎸\n");
    printf("⎸==================================================================================⎸\n");
    printf("⎸                 Módulo Estacionamentos - Excluir Estacionamento                   ⎸\n");
    printf("⎸==================================================================================⎸\n");
    printf("\n");
    printf(" >>Digite o Nº da vaga que deseja excluir: ");
    scanf("%s", n_estaci);
    getchar();
    printf("\n");

    printf("O veículo na vaga %s excluído com sucesso!\n", n_estaci);
    printf("\n");
    printf("\t >>Tecle <ENTER> para continuar...\n");
}

//=====================
//= Módulo Relatórios =
//=====================

void switch_relatorio(void){

    char op;

    do {
        op = relatorio();
        switch (op) {
            case '1': 
                relatorio_veiculos();
                break;
            case '2': 
                relatorio_estacionamentos();
                break;
            case '3': 
                relatorio_dono_veiculo();
                break;
            case '4': 
                relatorio_veiculo_estacionamento_dono();
                break;
        }
    } while (op != '0');
}

char relatorio(void) {
    system("clear||cls");

    char op;

    printf("\n");
    printf("⎸==================================================================================⎸\n");
    printf("⎸                                   SIG-Parking                                    ⎸\n");
    printf("⎸==================================================================================⎸\n");
    printf("⎸                                 Módulo Relatórios                                ⎸\n");
    printf("⎸==================================================================================⎸\n");
    printf("⎸ 1 - Relatório de Veículos Cadastrados                                            ⎸\n");
    printf("⎸ 2 - Relatório de Estacionamentos                                                 ⎸\n");
    printf("⎸ 3 - Relatório de Donos dos Veículos                                              ⎸\n");
    printf("⎸ 4 - Relatório de Veículo/Estacionamento/Dono                                     ⎸\n");
    printf("⎸ 0 - Voltar ao Menu Principal                                                     ⎸\n");
    printf("⎸==================================================================================⎸\n");
    printf("\n");
    printf("\t >>Escolha uma opção: ");
    scanf("%c", &op);
    getchar();
    printf("\n");
    return op;
}

void relatorio_veiculos(void) {
    system("clear||cls");

    printf("\n");
    printf("⎸==================================================================================⎸\n");
    printf("⎸                                   SIG-Parking                                    ⎸\n");
    printf("⎸==================================================================================⎸\n");
    printf("⎸                      Módulo Relatórios - Veículos Cadastrados                    ⎸\n");
    printf("⎸==================================================================================⎸\n");
    printf("\n");
    printf("Relatório de veículos cadastrados gerado com sucesso!\n");
    printf("\n");
    printf("\t >>Tecle <ENTER> para continuar...\n");
    getchar();
}

void relatorio_estacionamentos(void) {
    system("clear||cls");

    printf("\n");
    printf("⎸==================================================================================⎸\n");
    printf("⎸                                   SIG-Parking                                    ⎸\n");
    printf("⎸==================================================================================⎸\n");
    printf("⎸                      Módulo Relatórios - Estacionamentos                        ⎸\n");
    printf("⎸==================================================================================⎸\n");
    printf("\n");
    printf("Relatório de estacionamentos gerado com sucesso!\n");
    printf("\n");
    printf("\t >>Tecle <ENTER> para continuar...\n");
    getchar();
}

void relatorio_dono_veiculo(void) {
    system("clear||cls");

    printf("\n");
    printf("⎸==================================================================================⎸\n");
    printf("⎸                                   SIG-Parking                                    ⎸\n");
    printf("⎸==================================================================================⎸\n");
    printf("⎸                   Módulo Relatórios - Donos dos Veículos                         ⎸\n");
    printf("⎸==================================================================================⎸\n");
    printf("\n");
    printf("Relatório de donos dos veículos gerado com sucesso!\n");
    printf("\n");
    printf("\t >>Tecle <ENTER> para continuar...\n");
    getchar();
}

void relatorio_veiculo_estacionamento_dono(void) {
    system("clear||cls");

    printf("\n");
    printf("⎸==================================================================================⎸\n");
    printf("⎸                                   SIG-Parking                                    ⎸\n");
    printf("⎸==================================================================================⎸\n");
    printf("⎸            Módulo Relatórios - Veículo/Estacionamento/Dono                      ⎸\n");
    printf("⎸==================================================================================⎸\n");
    printf("\n");
    printf("Relatório de veículo/estacionamento/dono gerado com sucesso!\n");
    printf("\n");
    printf("\t >>Tecle <ENTER> para continuar...\n");
    getchar();
}

//===================
//= Telas Genéricas =
//===================

void equipe(void) {
    system("clear||cls");
    printf("\n");
    printf("⎸==================================================================================⎸\n");
    printf("⎸                                   SIG-Parking                                    ⎸\n");
    printf("⎸==================================================================================⎸\n");
    printf("⎸                                Equipe do Projeto                                 ⎸\n");
    printf("⎸==================================================================================⎸\n");
    printf("⎸ -Eriky Rayan B. De Medeiros                                                      ⎸\n");
    printf("⎸ -Email:eriky.medeiros.706@ufrn.edu.br                                            ⎸\n");
    printf("⎸ -GitHub:https://github.com/Eriky-Rayan                                           ⎸\n");
    printf("⎸==================================================================================⎸\n");
    printf("⎸ -Isaac Vilton Ribeiro                                                            ⎸\n");
    printf("⎸ -Email:Isaac.ribeiro.018@ufrn.edu.br                                             ⎸\n");
    printf("⎸ -GitHub:https://github.com/Isaac-Ribeiro                                         ⎸\n");
    printf("⎸==================================================================================⎸\n");
    printf("⎸ -Git:https://github.com/Eriky-Rayan/SIG-Parking.git                              ⎸\n");
    printf("⎸==================================================================================⎸\n");
    printf("\n");
    printf("\t >>Tecle <ENTER> para voltar ao Menu Principal: ");
    getchar();
    printf("\n");
}

void sobre(void) {
    system("clear||cls");
    printf("\n");
    printf("⎸==================================================================================⎸\n");
    printf("⎸                                   SIG-Parking                                    ⎸\n");
    printf("⎸==================================================================================⎸\n");
    printf("⎸                                   Tela Sobre                                     ⎸\n");
    printf("⎸==================================================================================⎸\n");
    printf("⎸-Sistema de Controle de Estacionamentos Para Carros e                             ⎸\n");
    printf("⎸ Motos-                                                                           ⎸\n");
    printf("⎸                                                                                  ⎸\n");
    printf("⎸-Programa para fins didáticos de ilustração, utilizado como exemplo de            ⎸\n"); 
    printf("⎸ codificação de funcionalidades em linguagem C, durante a disciplina              ⎸\n"); 
    printf("⎸ DCT1106 - Programação do curso de Bacharelado em Sistemas de Informação da       ⎸\n");  
    printf("⎸ Universidade Federal do Rio Grande do Norte. O programa contém os principais     ⎸\n");  
    printf("⎸ módulos e funcionalidades que serão exigidos na avaliação dos projetos a serem   ⎸\n");  
    printf("⎸ desenvolvidos pelos alunos ao longo da disciplina. Todos os dados e informações  ⎸\n");  
    printf("⎸ utilizados neste programa são fictícios.                                         ⎸\n");  
    printf("⎸==================================================================================⎸\n");
    printf("\n");
    printf("\t >>Tecle <ENTER> para voltar ao Menu Principal: ");
    getchar();
    printf("\n");
}

void tela_saida(void) {
    system("clear||cls");
    printf("\n");
    printf("⎸==================================================================================⎸\n");
    printf("⎸                                   SIG-Parking                                    ⎸\n");
    printf("⎸==================================================================================⎸\n");
    printf("⎸                                                                                  ⎸\n");
    printf("⎸                                                                                  ⎸\n");
    printf("⎸ >>Obrigado por utilizar o SIG-Parking! Até a próxima!                            ⎸\n");
    printf("⎸                                                                                  ⎸\n");
    printf("⎸                                                                                  ⎸\n");
    printf("⎸==================================================================================⎸\n");
    printf("\n");
    printf("\t >>Tecle <ENTER> para encerrar programa...\n");
    getchar();
}

void op_invalida(void){
    system("clear||cls");
    printf("\n");
    printf("⎸==================================================================================⎸\n");
    printf("⎸                                ******************                                ⎸\n");
    printf("⎸                                * Opção Invalida *                                ⎸\n");
    printf("⎸                                ******************                                ⎸\n");
    printf("⎸==================================================================================⎸\n");
    printf("\n");
    printf("\t >>Tecle <ENTER> para voltar ao Menu Principal: ");
    getchar();
}