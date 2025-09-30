
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "veiculos.h"
#include "estacionamentos.h"
#include "dono_veiculo.h"
#include "cadastro_vagas.h"
#include "relatorios.h"

//Assinatura das Funções
//Function Signature

char menu_principal(void);
void tela_saida(void);
void op_invalida(void);

void equipe(void);
void sobre(void);

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

    return 0;
}

//Definição das Funções
//Function Definition

char menu_principal(void) {
    system("clear||cls");

    char op;

    printf("\n");
    printf("=====================================================================================\n");
    printf("||                                                                                 ||\n");
    printf("||                                  -SIG-Parking-                                  ||\n");
    printf("||                                                                                 ||\n");
    printf("=====================================================================================\n");
    printf("||                                                                                 ||\n");
    printf("||                                 -Menu Principal-                                ||\n");
    printf("||                                                                                 ||\n");
    printf("=====================================================================================\n");
    printf("||                                                                                 ||\n");
    printf("|| [1] -> Módulo Veículos                                                          ||\n");
    printf("|| [2] -> Módulo Estacionamentos                                                   ||\n");
    printf("|| [3] -> Módulo Donos dos Veículos                                                ||\n");
    printf("|| [4] -> Módulo Cadastro de Vagas                                                 ||\n");
    printf("|| [5] -> Módulo Relatórios                                                        ||\n");
    printf("|| [6] -> Módulo Equipe do Projeto                                                 ||\n");
    printf("|| [7] -> Sobre o Sistema                                                          ||\n");
    printf("|| [0] -> Sair                                                                     ||\n");
    printf("||                                                                                 ||\n");
    printf("=====================================================================================\n");
    printf("\n");
    printf("\t >>Escolha uma opção: ");
    scanf("%c", &op);
    getchar();
    printf("\n");
    return op;
}

//===================
//= Telas Genéricas =
//===================

void equipe(void) {
    system("clear||cls");
    printf("\n");
    printf("=====================================================================================\n");
    printf("||                                                                                 ||\n");
    printf("||                                  -SIG-Parking-                                  ||\n");
    printf("||                                                                                 ||\n");
    printf("=====================================================================================\n");
    printf("||                                                                                 ||\n");
    printf("||                               -Equipe do Projeto-                               ||\n");
    printf("||                                                                                 ||\n");
    printf("=====================================================================================\n");
    printf("||                                                                                 ||\n");
    printf("|| -Eriky Rayan B. De Medeiros                                                     ||\n");
    printf("|| -Email:eriky.medeiros.706@ufrn.edu.br                                           ||\n");
    printf("|| -GitHub:https://github.com/Eriky-Rayan                                          ||\n");
    printf("||                                                                                 ||\n");
    printf("=====================================================================================\n");
    printf("||                                                                                 ||\n");
    printf("|| -Isaac Vilton Ribeiro                                                           ||\n");
    printf("|| -Email:Isaac.ribeiro.018@ufrn.edu.br                                            ||\n");
    printf("|| -GitHub:https://github.com/Isaac-Ribeiro                                        ||\n");
    printf("||                                                                                 ||\n");
    printf("=====================================================================================\n");
    printf("||                                                                                 ||\n");
    printf("|| -Andressa Carla da Silva                                                        ||\n");
    printf("|| -Email:andressa.silva.141@ufrn.edu.br                                           ||\n");
    printf("|| -GitHub:https://github.com/andressa-codes                                       ||\n");
    printf("||                                                                                 ||\n");
    printf("=====================================================================================\n");
    printf("||                                                                                 ||\n");
    printf("|| -GitHub:https://github.com/Eriky-Rayan/SIG-Parking.git                          ||\n");
    printf("||                                                                                 ||\n");
    printf("=====================================================================================\n");
    printf("\n");
    printf("\t >>Tecle <ENTER> para voltar ao Menu Principal: ");
    getchar();
    printf("\n");
}

void sobre(void) {
    system("clear||cls");
    printf("\n");
    printf("=====================================================================================\n");
    printf("||                                                                                 ||\n");
    printf("||                                  -SIG-Parking-                                  ||\n");
    printf("||                                                                                 ||\n");
    printf("=====================================================================================\n");
    printf("||                                                                                 ||\n");
    printf("||                                  -Tela Sobre-                                   ||\n");
    printf("||                                                                                 ||\n");
    printf("=====================================================================================\n");
    printf("||                                                                                 ||\n");
    printf("||-Sistema de Controle de Estacionamentos Para Carros e Motos-                     ||\n");
    printf("|| Motos-                                                                          ||\n");
    printf("||                                                                                 ||\n");
    printf("||-Programa para fins didáticos de ilustração, utilizado como exemplo de           ||\n"); 
    printf("|| codificação de funcionalidades em linguagem C, durante a disciplina             ||\n"); 
    printf("|| DCT1106 - Programação do curso de Bacharelado em Sistemas de Informação da      ||\n");  
    printf("|| Universidade Federal do Rio Grande do Norte. O programa contém os principais    ||\n");  
    printf("|| módulos e funcionalidades que serão exigidos na avaliação dos projetos a serem  ||\n");  
    printf("|| desenvolvidos pelos alunos ao longo da disciplina. Todos os dados e informações ||\n");  
    printf("|| utilizados neste programa são fictícios.                                        ||\n");
    printf("||                                                                                 ||\n");  
    printf("=====================================================================================\n");
    printf("\n");
    printf("\t >>Tecle <ENTER> para voltar ao Menu Principal: ");
    getchar();
    printf("\n");
}

void tela_saida(void) {
    system("clear||cls");
    printf("\n");
    printf("=====================================================================================\n");
    printf("||                                                                                 ||\n");
    printf("||                                  -SIG-Parking-                                  ||\n");
    printf("||                                                                                 ||\n");
    printf("=====================================================================================\n");
    printf("||                                                                                 ||\n");
    printf("||                                                                                 ||\n");
    printf("|| >>Obrigado por utilizar o SIG-Parking! Até a próxima!                           ||\n");
    printf("||                                                                                 ||\n");
    printf("||                                                                                 ||\n");
    printf("=====================================================================================\n");
    printf("\n");
    printf("\t >>Tecle <ENTER> para encerrar programa...\n");
    getchar();
    printf("\n");
}

void op_invalida(void){
    system("clear||cls");
    printf("\n");
    printf("=====================================================================================\n");
    printf("||                                                                                 ||\n");
    printf("||                                 ################                                ||\n");
    printf("||                                 -Opção Invalida-                                ||\n");
    printf("||                                 ################                                ||\n");
    printf("||                                                                                 ||\n");
    printf("=====================================================================================\n");
    printf("\n");
    printf("\t >>Tecle <ENTER> para voltar ao Menu Principal: ");
    getchar();
    printf("\n");
}