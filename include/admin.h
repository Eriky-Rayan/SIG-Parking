#ifndef ADMIN_H
#define ADMIN_H

#include "veiculos.h"
#include "estacionamentos.h"
#include "dono_veiculo.h"
#include "cadastro_vagas.h"
#include "validacoes.h"

//=====================================================
// Assinatura das Funções do Administrador
//=====================================================

void switch_admin(void);            // Menu principal do administrador
char admin(void);                   // Exibe menu e lê opção do usuário

// Funções de exclusão física
void exclu_veiculo(void);           // Excluir veículo fisicamente
void exclu_estacionamentos(void);   // Excluir estacionamento fisicamente
void exclu_dono_veiculo(void);      // Excluir dono de veículo fisicamente
void exclu_cadastro_vagas(void);    // Excluir cadastro de vagas fisicamente

#endif // ADMIN_H
