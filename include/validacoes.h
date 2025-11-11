#ifndef VALIDACOES_H
#define VALIDACOES_H

#include <stdio.h>

// ======== Funções de verificação de diretório ========
void verifica_diretorio_dados(void);

// ======== Funções de validação ========
int Validar_CPF(const char *cpf);
int Validar_Telefone(const char *telefone);
int Validar_Placa(const char *placa);

// ======== Funções de leitura ========
void Ler_CPF(char *cpf);
void Ler_Placa(char *placa);
void Ler_Tipo(char *tipo);
void Ler_Estacionamento(char *destino);
void Ler_Telefone(char *destino);
void Ler_TelefoneSimples(char *destino);
void Ler_Quantidade(int *destino);
void Ler_qtd_vagas(int *destino);
void Ler_num_andar(int *destino);
void Ler_Opcao_Menu(char *destino);
void Ler_Opcao_admin(char *destino);
void Ler_Nome(char *destino, int tamanho);
void Ler_model(char *destino, int tamanho);
void Ler_cor(char *destino, int tamanho);

#endif
