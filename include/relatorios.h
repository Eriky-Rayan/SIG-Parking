#ifndef RELATORIOS_H
#define RELATORIOS_H

//======================================
//= Assinatura das Funções (Headers)   =
//======================================

// Controla o menu principal de relatórios
void switch_relatorio(void);

// Exibe o menu do módulo Relatórios e retorna a opção escolhida
char relatorio(void);

// Relatórios específicos
void relatorio_veiculos(void);          // Exibe relatório completo ou filtrado de veículos (inclui andar e vaga)
void relatorio_estacionamentos(void);   // Exibe relatório de veículos por estacionamento/andars/vagas
void relatorio_dono_veiculo(void);      // Exibe relatório dos donos dos veículos
void relatorio_cadastro_vagas(void);    // Exibe relatório de vagas cadastradas (por andar ou completo)

// NOVA FUNÇÃO ADICIONADA
void relatorio_veiculo_dono_vaga(void); // Exibe relatório cruzando veículo, dono e vaga

#endif // RELATORIOS_H
