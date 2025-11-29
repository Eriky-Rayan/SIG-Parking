#ifndef RELATORIOS_H
#define RELATORIOS_H

#include "veiculos.h"
#include "dono_veiculo.h"
#include "cadastro_vagas.h"
#include "estacionamentos.h"

// Controla o menu de relatórios
// Exibe o menu principal do módulo Relatórios
void switch_relatorio(void);
char relatorio(void);

// Relatórios específicos
void relatorio_veiculos(void);
void relatorio_estacionamentos(void);
void relatorio_dono_veiculo(void);
void relatorio_cadastro_vagas(void);
void relatorio_veiculo_dono_vaga(void);

#endif // RELATORIOS_H
