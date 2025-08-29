
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//Assinatura das Funções
//Function Signature

void menu_principal(void);
void tela_saida(void);

void modulo_veiculos(void);
char veiculos(void);
void add_veiculos(void);
void exib_veiculo(void);
void alterar_veiculo(void);
void exclu_veiculo(void);

void estacionamentos(void);
void add_estacionamentos(void);
void exib_estacionamentos(void);
void alterar_estacionamentos(void);
void exclu_estacionamentos(void);

void dono_veiculo(void);
void add_dono_veiculo(void);
void exib_dono_veiculo(void);
void alterar_dono_veiculo(void);
void exclu_dono_veiculo(void);

void cadastro_vagas(void);
void add_cadastro_vagas(void);
void exib_cadastro_vagas(void);
void alterar_cadastro_vagas(void);
void exclu_cadastro_vagas(void);

void relatorio(void);

void equipe(void);
void sobre(void);
void op_invalida(void);

//código Principal
//main Code

//int main(void) {
//    int tela = 8;
//   char op;
//
//    while (tela != 0) {
//        if (tela == 8) {
//            menu_principal();
//            scanf(" %c", &op);
//            getchar();
//
//            if (op == '1') tela = 1;
//            else if (op == '2') tela = 2;
//            else if (op == '3') tela = 3;
//            else if (op == '4') tela = 4;
//            else if (op == '5') tela = 5;
//            else if (op == '6') tela = 6;
//            else if (op == '7') tela = 7;
//            else tela = 0;
//            printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
//            getchar();
//        } else if (tela == 1) {
//            veiculos();
//            scanf(" %c", &op);
//            getchar();
//            if (op == '1') {
//                printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
//                getchar();
//                add_veiculos();
//                getchar();
//                tela = 1;
//            }
//            else if (op == '2') {
//                printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
//                getchar();
//                exib_veiculo();
//                getchar();
//                tela = 1;
//            }
//            else if (op == '3') {
//                printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
//                getchar();
//                alterar_veiculo();
//                getchar();
//                tela = 1;
//            }
//            else if (op == '4') {
//                printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
//                getchar();
//                exclu_veiculo();
//                getchar();
//                tela = 1;
//            }
//            else if (op == '0') tela = 8;
//        } else if (tela == 2) {
//            estacionamentos();
//            scanf(" %c", &op);
//            getchar();
//            if (op == '1') {
//                printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
//                getchar();
//                add_estacionamentos();
//                getchar();
//                tela = 2;
//            }
//            else if (op == '2') {
//                printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
//                getchar();
//                exib_estacionamentos();
//                getchar();
//                tela = 2;
//            }
//            else if (op == '3') {
//                printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
//                getchar();
//                alterar_estacionamentos();
//                getchar();
//                tela = 2;
//            }
//            else if (op == '4') {
//                printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
//                getchar();
//                exclu_estacionamentos();
//                getchar();
//                tela = 2;
//            }
//            else if (op == '0') tela = 8; 
//        } else if (tela == 3) {
//            dono_veiculo();
//            scanf(" %c", &op);
//            getchar();
//            if (op == '1') {
//                printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
//                getchar();
//                add_dono_veiculo();
//                getchar();
//                tela = 3;
//            }
//            else if (op == '2') {
//                printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
//                getchar();
//                exib_dono_veiculo();
//                getchar();
//                tela = 3;
//            }
//            else if (op == '3') {
//                printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
//                getchar();
//                alterar_dono_veiculo();
//                getchar();
//                tela = 3;
//            }
//            else if (op == '4') {
//                printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
//                getchar();
//                exclu_dono_veiculo();
//                getchar();
//                tela = 3;
//            }
//            if (op == '0') tela = 8; 
//        } else if (tela == 4) {
//            cadastro_vagas();
//            scanf(" %c", &op);
//            getchar();
//            if (op == '1') {
//                printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
//                getchar();
//                add_cadastro_vagas();
//                getchar();
//                tela = 4;
//            }
//            else if (op == '2') {
//                printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
//                getchar();
//                exib_cadastro_vagas();
//                getchar();
//                tela = 4;
//            }
//            else if (op == '3') {
//                printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
//                getchar();
//                alterar_cadastro_vagas();
//                getchar();
//                tela = 4;
//            }
//            else if (op == '4') {
//                printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
//                getchar();
//                exclu_cadastro_vagas();
//                getchar();
//                tela = 4;
//            }
//            if (op == '0') tela = 8;
//        } else if (tela == 5) {
//            relatorio();
//            scanf(" %c", &op);
//            getchar();
//            if (op == '0') tela = 8;
//        } else if (tela == 6) {
//            equipe();
//            scanf(" %c", &op);
//            getchar();
//            if (op == '0') tela = 8; 
//        } else if (tela == 7) {
//            sobre();
//            scanf(" %c", &op);
//            getchar();
//            if (op == '0') tela = 8;
//        }
//    }
//    tela_saida();
//    return 0;
//}

//Definição das Funções
//Function Definition

void menu_principal(void) {
    system("clear||cls");
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
    printf("\n");
}

//===================
//= Módulo Veículos =
//===================

void modulo_veiculos(void){
    
    char op;

    do {
        op = veiculos();
        switch (op) {
            case '1': add_veiculos();
                      break;
            case '2': exib_veiculo();
                      break;
            case '3': alterar_veiculo();
                      break;
            case '4': exclu_veiculo();
                      break;
        }
    } while (op != '0');
}

char veiculos(void) {
    system("clear||cls");

    char op;

    printf("\n");
    printf("⎸==================================================================================⎸\n");
    printf("⎸                                   SIG-Parking                                    ⎸\n");
    printf("⎸==================================================================================⎸\n");
    printf("⎸                                 Módulo Veículos                                  ⎸\n");
    printf("⎸==================================================================================⎸\n");
    printf("⎸ 1 - Cadastrar Veículo                                                            ⎸\n");
    printf("⎸ 2 - Exibir Dados do Veículo                                                      ⎸\n");
    printf("⎸ 3 - Alterar Dados do Veículo                                                     ⎸\n");
    printf("⎸ 4 - Excluir Veículo                                                              ⎸\n");
    printf("⎸ 0 - Voltar ao Menu Principal                                                     ⎸\n");
    printf("⎸==================================================================================⎸\n");
    printf("\n");
    printf("\t >>Escolha uma opção: ");
    scanf("%c", &op);
    getchar();
    printf("\n");
    return op;
}

void add_veiculos(void) {
    system("clear||cls");

    char placa[12];
    char tipo[10];
    char model[20];
    char cor [15];
    char n_estaci[8];
    char cpf[15];

    printf("\n");
    printf("⎸==================================================================================⎸\n");
    printf("⎸                                   SIG-Parking                                    ⎸\n");
    printf("⎸==================================================================================⎸\n");
    printf("⎸                        Módulo Veículos - Cadastrar veículo                       ⎸\n");
    printf("⎸==================================================================================⎸\n");
    printf("\n");
    printf(" >>Digite a placa do veículo a ser cadastrado: ");
    scanf("%s", placa);
    getchar();
    printf("\n");
    printf(" >>Tipo de Veículo (Carro/Moto): ");
    scanf("%s", tipo);
    getchar();
    printf("\n");
    printf(" >>Modelo do veículo: ");
    scanf("%s", model);
    getchar();
    printf("\n");
    printf(" >>Cor do Veículo: ");
    scanf("%s", cor);
    getchar();
    printf("\n");
    printf(" >>Nº do estacionamento: ");
    scanf("%s", n_estaci);
    getchar();
    printf("\n");
    printf(" >>CPF do Dono do Veículo: ");
    scanf("%s", cpf);
    getchar();
    printf("\n");

    printf("Veículo cadastrado com sucesso!\n");
    printf("\nPlaca: %s", placa);
    printf("\nTipo: %s", tipo);
    printf("\nModelo: %s", model);
    printf("\nCor: %s", cor);
    printf("\nNº do estacionamento: %s", n_estaci);
    printf("\nCPF: %s", cpf);
    printf("\n");
    printf("\t >>Tecle <ENTER> para continuar...\n");
}

void exib_veiculo(void) {
    system("clear||cls");

    char placa[12];

    printf("\n");
    printf("⎸==================================================================================⎸\n");
    printf("⎸                                   SIG-Parking                                    ⎸\n");
    printf("⎸==================================================================================⎸\n");
    printf("⎸                        Módulo Veículos - Exibir veículo                          ⎸\n");
    printf("⎸==================================================================================⎸\n");
    printf("\n");
    printf(" >>Digite a placa do veículo a ser exibido:  \n");
    scanf("%s", placa);
    getchar();
    printf("\n");
    printf("O veículo com a seguinte placa foi exibido: %s\n", placa);
    printf("\n");
    printf("\t >>Tecle <ENTER> para continuar...\n");
}

void alterar_veiculo(void) {
    system("clear||cls");

    char placa[12];
    char tipo[10];
    char model[20];
    char cor [15];
    char n_estaci[8];
    char cpf[15];

    printf("\n");
    printf("⎸==================================================================================⎸\n");
    printf("⎸                                   SIG-Parking                                    ⎸\n");
    printf("⎸==================================================================================⎸\n");
    printf("⎸                        Módulo Veículos - Alterar Dados                           ⎸\n");
    printf("⎸==================================================================================⎸\n");
    printf("\n");
    printf(" -Digite os novos dados do veículo-");
    printf("\n");
    printf(" >>Digite a placa do veículo a ser alterado: \n");
    scanf("%s", placa);
    getchar();
    printf("\n");
    printf(" >>Tipo de Veículo (Carro/Moto): ");
    scanf("%s", tipo);
    getchar();
    printf("\n");
    printf(" >>Modelo do veículo: ");
    scanf("%s", model);
    getchar();
    printf("\n");
    printf(" >>Cor do Veículo: ");
    scanf("%s", cor);
    getchar();
    printf("\n");
    printf(" >>Nº do estacionamento: ");
    scanf("%s", n_estaci);
    getchar();
    printf("\n");
    printf(" >>CPF do Dono do Veículo: ");
    scanf("%s", cpf);
    getchar();
    printf("\n");

    printf("Dados do veículo alterados com sucesso!\n");
    printf("\nPlaca: %s", placa);
    printf("\nTipo: %s", tipo);
    printf("\nModelo: %s", model);
    printf("\nCor: %s", cor);
    printf("\nNº do estacionamento: %s", n_estaci);
    printf("\nCPF: %s", cpf);
    printf("\n");
    printf("\t >>Tecle <ENTER> para continuar...\n");
}

void exclu_veiculo(void) {
    system("clear||cls");

    char placa[12];

    printf("\n");
    printf("⎸==================================================================================⎸\n");
    printf("⎸                                   SIG-Parking                                    ⎸\n");
    printf("⎸==================================================================================⎸\n");
    printf("⎸                         Módulo Veículos - Excluir Dados                          ⎸\n");
    printf("⎸==================================================================================⎸\n");
    printf("\n");
    printf(" >>Digite a placa do veículo a ser excluido: ");
    scanf("%s", placa);
    getchar();
    printf("\n");

    printf("Veículo com placa %s excluído com sucesso!\n", placa);
    printf("\n");
    printf("\t >>Tecle <ENTER> para continuar...\n");
}

//=========================
//= Módulo Estacionamento =
//=========================

void estacionamentos(void) {
    system("clear||cls");
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
    printf("\n");
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

//==========================
//= Módulo Dono de Veículo =
//==========================

void dono_veiculo(void) {
    system("clear||cls");
    printf("\n");
    printf("⎸==================================================================================⎸\n");
    printf("⎸                                   SIG-Parking                                    ⎸\n");
    printf("⎸==================================================================================⎸\n");
    printf("⎸                            Módulo Donos dos Veículos                             ⎸\n");
    printf("⎸==================================================================================⎸\n");
    printf("⎸ 1 - Cadastrar Dono de Veículo                                                    ⎸\n");
    printf("⎸ 2 - Exibir Dados do Dono de Veículo                                              ⎸\n");
    printf("⎸ 3 - Alterar Dados do Dono de Veículo                                             ⎸\n");
    printf("⎸ 4 - Excluir Dono de Veículo                                                      ⎸\n");
    printf("⎸ 0 - Voltar ao Menu Principal                                                     ⎸\n");
    printf("⎸==================================================================================⎸\n");
    printf("\n");
    printf("\t >>Escolha uma opção: ");
    printf("\n");
}

void add_dono_veiculo(void) {
    system("clear||cls");

    char cpf[15];
    char telefone[20];
    char nome[50];
    int quantidade;

    printf("\n");
    printf("⎸==================================================================================⎸\n");
    printf("⎸                                   SIG-Parking                                    ⎸\n");
    printf("⎸==================================================================================⎸\n");
    printf("⎸                  Módulo Donos dos Veículos - Cadastrar Dono                      ⎸\n");
    printf("⎸==================================================================================⎸\n");
    printf("\n");
    printf(" >>Digite o CPF do dono do veículo a ser cadastrado:  ");
    scanf("%s", cpf);
    getchar();
    printf("\n");
    printf(" >>Telefone do dono: ");
    scanf("%s", telefone);
    getchar();
    printf("\n");
    printf(" >>Nome do dono: ");
    scanf("%s", nome);
    getchar();
    printf("\n");
    printf(" >>Quantidade de veículos: ");
    scanf("%d", &quantidade);
    getchar();
    printf("\n");

    printf("\nDono do veículo cadastrado com sucesso!\n");
    printf("\nCPF: %s", cpf);
    printf("\nTelefone: %s", telefone);
    printf("\nNome: %s", nome);
    printf("\nQuantidade de veículos: %d\n", quantidade);
    printf("\n");
    printf("\t >>Tecle <ENTER> para continuar...\n");
}

void exib_dono_veiculo(void) {
    system("clear||cls");

    char cpf[15];

    printf("\n");
    printf("⎸==================================================================================⎸\n");
    printf("⎸                                   SIG-Parking                                    ⎸\n");
    printf("⎸==================================================================================⎸\n");
    printf("⎸                     Módulo Donos dos Veículos - Exibir Dados                     ⎸\n");
    printf("⎸==================================================================================⎸\n");
    printf("\n");
    printf(" >>Digite o CPF do dono a ser exibido: ");
    scanf("%s", cpf);
    getchar();
    printf("\n");
    printf("O seguinte CPF foi exibido: %s\n", cpf);
    printf("\n");
    printf("\t >>Tecle <ENTER> para continuar...\n");
}

void alterar_dono_veiculo(void) {
    system("clear||cls");

    char cpf[15];
    char telefone[20];
    char nome[50];
    int quantidade;

    printf("\n");
    printf("⎸==================================================================================⎸\n");
    printf("⎸                                   SIG-Parking                                    ⎸\n");
    printf("⎸==================================================================================⎸\n");
    printf("⎸                   Módulo Donos dos Veículos - Alterar Dados                      ⎸\n");
    printf("⎸==================================================================================⎸\n");
    printf("\n");
    printf(" -Digite os novos dados do dono do veículo-");
    printf("\n");
    printf(" >>Digite o CPF do dono do veículo a ser alterado: ");
    scanf("%s", cpf);
    getchar();
    printf("\n");
    printf(" >>Telefone do dono: ");
    scanf("%s", telefone);
    getchar();
    printf("\n");
    printf(" >>Nome do dono: ");
    scanf("%s", nome);
    getchar();
    printf("\n");
    printf(" >>Quantidade de veículos cadastrados: ");
    scanf("%d", &quantidade);
    getchar();
    printf("\n");

    printf("Dados do dono do veículo alterados com sucesso!\n");
    printf("\nCPF: %s", cpf);
    printf("\nTelefone: %s", telefone);
    printf("\nNome: %s", nome);
    printf("\nQuantidade de veículos: %d\n", quantidade);
    printf("\n");
    printf("\t >>Tecle <ENTER> para continuar...\n");
}

void exclu_dono_veiculo(void) {
    system("clear||cls");

    char cpf[15];

    printf("\n");
    printf("⎸==================================================================================⎸\n");
    printf("⎸                                   SIG-Parking                                    ⎸\n");
    printf("⎸==================================================================================⎸\n");
    printf("⎸                   Módulo Donos dos Veículos - Excluir Dados                      ⎸\n");
    printf("⎸==================================================================================⎸\n");
    printf("\n");
    printf(" >>Digite o CPF do dono a ser excluido: ");
    scanf("%s", cpf);
    getchar();
    printf("\n");

    printf("Dono do veículo com CPF %s excluído com sucesso!\n", cpf);
    printf("\n");
    printf("\t >>Tecle <ENTER> para continuar...\n");
}

//=====================
//= Módulo Cad. Vagas =
//=====================

void cadastro_vagas(void) {
    system("clear||cls");
    printf("\n");
    printf("⎸==================================================================================⎸\n");
    printf("⎸                                   SIG-Parking                                    ⎸\n");
    printf("⎸==================================================================================⎸\n");
    printf("⎸                            Módulo Cadastro de Vagas                              ⎸\n");
    printf("⎸==================================================================================⎸\n");
    printf("⎸ 1 - Cadastrar Vagas                                                              ⎸\n");
    printf("⎸ 2 - Exibir Dados das Vagas                                                       ⎸\n");
    printf("⎸ 3 - Alterar Dados das Vagas                                                      ⎸\n");
    printf("⎸ 4 - Excluir Dados das Vagas                                                      ⎸\n");
    printf("⎸ 0 - Voltar ao Menu Principal                                                     ⎸\n");
    printf("⎸==================================================================================⎸\n");
    printf("\n");
    printf("\t >>Tecle '0' para voltar ao Menu Principal: ");
    printf("\n");
}

void add_cadastro_vagas(void) {
    system("clear||cls");

    int qtd_vagas;
    int num_andar;

    printf("\n");
    printf("⎸==================================================================================⎸\n");
    printf("⎸                                   SIG-Parking                                    ⎸\n");
    printf("⎸==================================================================================⎸\n");
    printf("⎸                   Módulo Cadastro de Vagas - Cadastrar Vagas                     ⎸\n");
    printf("⎸==================================================================================⎸\n");
    printf("\n");
    printf(" >>Digite a quantidade de vagas a ser cadastrada: ");
    scanf("%d", qtd_vagas);
    getchar();
    printf("\n");
    printf(" >>Digite o número do andar: ");
    scanf("%d", num_andar);
    getchar();
    printf("\n");

    printf("Vaga cadastrada com sucesso!\n");
    printf("\nQuantidade de vagas no andar: %d", qtd_vagas);
    printf("\nTNúmero do andar: %d", num_andar);
    printf("\n");
    printf("\t >>Tecle <ENTER> para continuar...\n");
}

void exib_cadastro_vagas(void) {
    system("clear||cls");

    int qtd_vagas;
    int num_andar;

    printf("\n");
    printf("⎸==================================================================================⎸\n");
    printf("⎸                                   SIG-Parking                                    ⎸\n");
    printf("⎸==================================================================================⎸\n");
    printf("⎸                  Módulo Cadastro de Vagas - Exibir Dados das Vagas               ⎸\n");
    printf("⎸==================================================================================⎸\n");
    printf("\n");
    printf(" >>Digite o número do andar: ");
    scanf("%d", num_andar);
    getchar();
    printf("\n");
    printf("Será exibido a quantidade de vagas do seguinte andar: %d\n", num_andar);
    printf("\n");
    printf("\t >>Tecle <ENTER> para continuar...\n");
}

void alterar_cadastro_vagas(void) {
    system("clear||cls");

    int qtd_vagas;
    int num_andar;

    printf("\n");
    printf("⎸==================================================================================⎸\n");
    printf("⎸                                   SIG-Parking                                    ⎸\n");
    printf("⎸==================================================================================⎸\n");
    printf("⎸                 Módulo Cadastro de Vagas - Alterar Dados das Vagas              ⎸\n");
    printf("⎸==================================================================================⎸\n");
    printf("\n");
    printf(" -Digite os novos dados das vagas-");
    printf("\n");
    printf(" >>Digite o número do andar: ");
    scanf("%d", num_andar);
    getchar();
    printf("\n");
    printf(" >>Digite a quantidade de vagas a ser cadastrada: ");
    scanf("%d", qtd_vagas);
    getchar();
    printf("\n");

    printf("Dados das vagas alterados com sucesso!\n");
    printf("\nQuantidade de vagas no andar: %d", qtd_vagas);
    printf("\nTNúmero do andar: %d", num_andar);
    printf("\n");
    printf("\t >>Tecle <ENTER> para continuar...\n");
}

void exclu_cadastro_vagas(void) {
    system("clear||cls");

    int num_andar;

    printf("\n");
    printf("⎸==================================================================================⎸\n");
    printf("⎸                                   SIG-Parking                                    ⎸\n");
    printf("⎸==================================================================================⎸\n");
    printf("⎸                 Módulo Cadastro de Vagas - Excluir Dados das Vagas               ⎸\n");
    printf("⎸==================================================================================⎸\n");
    printf("\n");
    printf(" >>Digite o número do andar que deseja excluir: ");
    scanf("%d", num_andar);
    getchar();
    printf("\n");

    printf("Vagas do andar %d excluídas com sucesso!\n", num_andar);
    printf("\n");
    printf("\t >>Tecle <ENTER> para continuar...\n");
}

//=====================
//= Módulo Relatórios =
//=====================

void relatorio(void) {
    system("clear||cls");
    printf("\n");
    printf("⎸==================================================================================⎸\n");
    printf("⎸                                   SIG-Parking                                    ⎸\n");
    printf("⎸==================================================================================⎸\n");
    printf("⎸                                 Módulo Relatórios                                ⎸\n");
    printf("⎸==================================================================================⎸\n");
    printf("⎸ 1 - Relatório de Veículos Cadastrados                                            ⎸\n");
    printf("⎸ 2 - Relatório de Estacionamentos                                                 ⎸\n");
    printf("⎸ 3 - Relatório de Donos dos Veículos                                              ⎸\n");
    printf("⎸ 0 - Voltar ao Menu Principal                                                     ⎸\n");
    printf("⎸==================================================================================⎸\n");
    printf("\n");
    printf("\t >>Escolha uma opção: ");
    printf("\n");
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
    printf("\t >>Tecle '0' para voltar ao Menu Principal: ");
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
    printf("\t >>Tecle '0' para voltar ao Menu Principal: ");
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
    printf("\t >>Tecle <ENTER> para voltar ao Menu Principal: ");
    getchar();
}