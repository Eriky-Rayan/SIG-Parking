#ifndef RELATORIOS_H
#define RELATORIOS_H

//======================================
//= Assinatura das Funções (Headers)   =
//======================================

// Controla o menu de relatórios
void switch_relatorio(void);

// Exibe o menu principal do módulo Relatórios
char relatorio(void);

// Relatórios específicos
void relatorio_veiculos(void);
void relatorio_estacionamentos(void);
void relatorio_dono_veiculo(void);
void relatorio_cadastro_vagas(void);
void relatorio_veiculo_dono_vaga(void);

#endif // RELATORIOS_H
