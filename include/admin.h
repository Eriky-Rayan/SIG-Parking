#ifndef ADMIN_H
#define ADMIN_H

#include "veiculos.h"
#include "estacionamentos.h"
#include "dono_veiculo.h"
#include "cadastro_vagas.h"
#include "validacoes.h"

//=====================================================
// Caminhos dos arquivos
//=====================================================

// Arquivos permanentes
#ifndef ARQ_VEICULO
#define ARQ_VEICULO "dados/veiculos.dat"
#endif

#ifndef ARQ_ESTACIONAMENTO
#define ARQ_ESTACIONAMENTO "dados/estacionamentos.dat"
#endif

#ifndef ARQ_DONO
#define ARQ_DONO "dados/dono_veiculo.dat"
#endif

#ifndef ARQ_VAGAS
#define ARQ_VAGAS "dados/cadastro_vagas.dat"
#endif

// Arquivos temporários
#ifndef TEMP_VEICULO
#define TEMP_VEICULO "dados/veiculos_temp.dat"
#endif

#ifndef TEMP_ESTACIONAMENTO
#define TEMP_ESTACIONAMENTO "dados/estacionamentos_temp.dat"
#endif

#ifndef TEMP_DONO
#define TEMP_DONO "dados/dono_veiculo_temp.dat"
#endif

#ifndef TEMP_VAGAS
#define TEMP_VAGAS "dados/cadastro_vagas_temp.dat"
#endif

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

// Função genérica de exclusão física
// 'comparar' recebe o registro e um parâmetro auxiliar (ex: placa, CPF ou número do andar)
int excluir_fisicamente(const char *arquivo, const char *arquivo_temp, void *registro, size_t tamanho,
                        int (*comparar)(void*, void*), void *param);

#endif // ADMIN_H
