#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "../include/relatorios.h"
#include "../include/veiculos.h"
#include "../include/dono_veiculo.h"
#include "../include/cadastro_vagas.h"
#include "../include/estacionamentos.h"

// Limpa a tela — funciona em Linux e Windows
static void clear_screen(void) {
    system("clear||cls");
}

//=======================================================
// Menu principal de relatórios
//=======================================================
char relatorio(void) {
    clear_screen();
    char op;
    printf("\n=====================================================================================\n");
    printf("||                                  -SIG-Parking-                                  ||\n");
    printf("=====================================================================================\n");
    printf("|| [1] -> Relatório de Veículos Cadastrados                                        ||\n");
    printf("|| [2] -> Relatório de Estacionamentos                                             ||\n");
    printf("|| [3] -> Relatório de Donos dos Veículos                                          ||\n");
    printf("|| [4] -> Relatório de Cadastro de Vagas                                           ||\n");
    printf("|| [5] -> Relatório de Veículos Estacionados com Dono                              ||\n");
    printf("|| [0] -> Voltar ao Menu Principal                                                 ||\n");
    printf("=====================================================================================\n");
    printf("\t >>Escolha uma opção: ");
    scanf(" %c", &op);
    getchar();
    return op;
}

void switch_relatorio(void) {
    char op;
    do {
        op = relatorio();
        switch (op) {
            case '1': relatorio_veiculos(); break;
            case '2': relatorio_estacionamentos(); break;
            case '3': relatorio_dono_veiculo(); break;
            case '4': relatorio_cadastro_vagas(); break;
            case '5': relatorio_veiculo_dono_vaga(); break;
            default: break;
        }
    } while (op != '0');
}

//=======================================================
// RELATÓRIO DE VEÍCULOS
//=======================================================
void relatorio_veiculos(void) {
    clear_screen();

    // ================================
    // NOVO MENU DE FILTRO POR COR
    // ================================
    char op_filtro;
    char cor_filtro[20];
    
    printf("\n===== RELATÓRIO DE VEÍCULOS =====\n");
    printf("[1] Mostrar todos\n");
    printf("[2] Filtrar por cor\n");
    printf("[0] Voltar\n");
    printf("=================================\n");
    printf(" >> Opção: ");
    scanf(" %c", &op_filtro);
    getchar();

    if (op_filtro == '0') return;

    int usar_filtro = 0;
    if(op_filtro == '2'){
        usar_filtro = 1;
        printf("\n >> Digite a cor que deseja filtrar: ");
        fgets(cor_filtro, sizeof(cor_filtro), stdin);
        cor_filtro[strcspn(cor_filtro, "\n")] = 0;
        for(int i=0;i<strlen(cor_filtro);i++) cor_filtro[i] = tolower(cor_filtro[i]);
    }

    FILE *arq = fopen("dados/veiculos.dat", "rb");
    if (!arq) {
        printf("Erro ao abrir o arquivo de veículos.\nTecle ENTER para continuar...");
        getchar();
        return;
    }

    Veiculos v;
    int w_placa = strlen("Placa");
    int w_tipo  = strlen("Tipo");
    int w_modelo= strlen("Modelo");
    int w_cor   = strlen("Cor");
    int w_andar = strlen("Andar");
    int w_vaga  = strlen("Vaga");
    int w_cpf   = strlen("CPF Dono");

    // Primeira varredura para medir largura
    while (fread(&v, sizeof(Veiculos), 1, arq)) {

        if (!v.status) continue;

        // Se estiver filtrando, mas não corresponde, pula
        if(usar_filtro){
            char cor_aux[20];
            strcpy(cor_aux, v.cor);
            for(int i=0;i<strlen(cor_aux);i++) cor_aux[i] = tolower(cor_aux[i]);

            if(!strstr(cor_aux, cor_filtro)) continue;
        }

        if ((int)strlen(v.placa) > w_placa) w_placa = strlen(v.placa);
        if ((int)strlen(v.tipo) > w_tipo) w_tipo = strlen(v.tipo);
        if ((int)strlen(v.model) > w_modelo) w_modelo = strlen(v.model);
        if ((int)strlen(v.cor) > w_cor) w_cor = strlen(v.cor);

        char buf[20];
        snprintf(buf,sizeof(buf),"%d",v.andar);
        if ((int)strlen(buf) > w_andar) w_andar = strlen(buf);
        snprintf(buf,sizeof(buf),"%d",v.vaga);
        if ((int)strlen(buf) > w_vaga) w_vaga = strlen(buf);

        if ((int)strlen(v.cpf) > w_cpf) w_cpf = strlen(v.cpf);
    }

    rewind(arq);

    // ==== Cabeçalho ====
    printf("\n╔");
    for (int i=0;i<w_placa+2;i++) printf("═");
    printf("╦");
    for (int i=0;i<w_tipo+2;i++) printf("═");
    printf("╦");
    for (int i=0;i<w_modelo+2;i++) printf("═");
    printf("╦");
    for (int i=0;i<w_cor+2;i++) printf("═");
    printf("╦");
    for (int i=0;i<w_andar+2;i++) printf("═");
    printf("╦");
    for (int i=0;i<w_vaga+2;i++) printf("═");
    printf("╦");
    for (int i=0;i<w_cpf+2;i++) printf("═");
    printf("╗\n");

    printf("║ %-*s ║ %-*s ║ %-*s ║ %-*s ║ %-*s ║ %-*s ║ %-*s ║\n",
           w_placa,"Placa", w_tipo,"Tipo", w_modelo,"Modelo", w_cor,"Cor",
           w_andar,"Andar", w_vaga,"Vaga", w_cpf,"CPF Dono");

    printf("╠");
    for (int i=0;i<w_placa+2;i++) printf("═");
    printf("╬");
    for (int i=0;i<w_tipo+2;i++) printf("═");
    printf("╬");
    for (int i=0;i<w_modelo+2;i++) printf("═");
    printf("╬");
    for (int i=0;i<w_cor+2;i++) printf("═");
    printf("╬");
    for (int i=0;i<w_andar+2;i++) printf("═");
    printf("╬");
    for (int i=0;i<w_vaga+2;i++) printf("═");
    printf("╬");
    for (int i=0;i<w_cpf+2;i++) printf("═");
    printf("╣\n");

    int count=0;
    while(fread(&v,sizeof(Veiculos),1,arq)) {

        if(!v.status) continue;

        // filtro funcionando
        if(usar_filtro){
            char cor_aux[20];
            strcpy(cor_aux, v.cor);
            for(int i=0;i<strlen(cor_aux);i++) cor_aux[i] = tolower(cor_aux[i]);

            if(!strstr(cor_aux, cor_filtro)) continue;
        }

        count++;

        printf("║ %-*s ║ %-*s ║ %-*s ║ %-*s ║ %-*d ║ %-*d ║ %-*s ║\n",
               w_placa,v.placa,
               w_tipo,v.tipo,
               w_modelo,v.model,
               w_cor,v.cor,
               w_andar,v.andar,
               w_vaga,v.vaga,
               w_cpf,v.cpf);
    }

    if(count==0){
        printf("║ %-*s ║\n",
               w_placa+w_tipo+w_modelo+w_cor+w_andar+w_vaga+w_cpf+18,
               "Nenhum veículo encontrado");
    }

    printf("╚");
    for (int i=0;i<w_placa+2;i++) printf("═");
    printf("╩");
    for (int i=0;i<w_tipo+2;i++) printf("═");
    printf("╩");
    for (int i=0;i<w_modelo+2;i++) printf("═");
    printf("╩");
    for (int i=0;i<w_cor+2;i++) printf("═");
    printf("╩");
    for (int i=0;i<w_andar+2;i++) printf("═");
    printf("╩");
    for (int i=0;i<w_vaga+2;i++) printf("═");
    printf("╩");
    for (int i=0;i<w_cpf+2;i++) printf("═");
    printf("╝\n");

    fclose(arq);
    printf("\n>> Tecle ENTER para continuar...");
    getchar();
}

//=======================================================
// RELATÓRIO DE ESTACIONAMENTOS
//=======================================================
void relatorio_estacionamentos(void) {
    clear_screen();
    FILE *arq = fopen("dados/veiculos.dat","rb");
    if(!arq){
        printf("Erro ao abrir arquivo de veículos.\nTecle ENTER para continuar...");
        getchar();
        return;
    }

    Veiculos v;
    int count = 0;
    printf("╔════════════╦════════════╦════════════╗\n");
    printf("║ Placa      ║ Andar      ║ Vaga       ║\n");
    printf("╠════════════╬════════════╬════════════╣\n");
    while(fread(&v,sizeof(Veiculos),1,arq)){
        if(v.status){
            count++;
            printf("║ %-10s ║ %-10d ║ %-10d ║\n",v.placa,v.andar,v.vaga);
        }
    }
    if(count==0)
        printf("║ %-32s ║\n","Nenhum veículo cadastrado");

    printf("╚════════════╩════════════╩════════════╝\n");
    fclose(arq);
    printf("\n>> Tecle ENTER para continuar...");
    getchar();
}

//=======================================================
// RELATÓRIO DE DONOS DE VEÍCULOS
//=======================================================
void relatorio_dono_veiculo(void) {
    clear_screen();
    char op_sub;
    printf("\n==================== RELATÓRIO - DONOS DOS VEÍCULOS ====================\n");
    printf("1 - Mostrar relatório completo\n");
    printf("2 - Filtrar por nome do dono\n");
    printf("0 - Voltar\n");
    printf("=======================================================================\n");
    printf(" >> Escolha uma opção: ");
    scanf(" %c", &op_sub);
    getchar();
    if(op_sub=='0') return;

    DonoVeiculoLista* lista = newDonoVeiculoList();
    preencherListaDonoVeiculo(lista);

    int w_nome = strlen("Nome");
    int w_cpf = strlen("CPF");
    int w_tel = strlen("Telefone");
    int w_placas = strlen("Placas Vinculadas");

    DonoVeiculoLista* temp = lista->prox;
    char nome_busca[50]; int filtrando=0;
    if(op_sub=='2'){
        printf("\n >> Digite o nome ou parte do nome: ");
        fgets(nome_busca,sizeof(nome_busca),stdin);
        nome_busca[strcspn(nome_busca,"\n")] = 0;
        filtrando = 1;
    }

    // Calcula larguras das colunas
    while(temp){
        if(temp->dados->status && (!filtrando || strstr(temp->dados->nome,nome_busca))){
            if(strlen(temp->dados->nome) > w_nome) w_nome = strlen(temp->dados->nome);
            if(strlen(temp->dados->cpf) > w_cpf) w_cpf = strlen(temp->dados->cpf);
            if(strlen(temp->dados->telefone) > w_tel) w_tel = strlen(temp->dados->telefone);

            FILE *arq_v = fopen("dados/veiculos.dat","rb");
            if(arq_v){
                Veiculos v; char placas_temp[256]="";
                while(fread(&v,sizeof(Veiculos),1,arq_v)){
                    if(v.status && strcmp(v.cpf,temp->dados->cpf)==0){
                        if(strlen(placas_temp)>0) strncat(placas_temp,", ",sizeof(placas_temp)-strlen(placas_temp)-1);
                        strncat(placas_temp,v.placa,sizeof(placas_temp)-strlen(placas_temp)-1);
                    }
                }
                fclose(arq_v);
                if(strlen(placas_temp) > w_placas) w_placas = strlen(placas_temp);
            }
        }
        temp = temp->prox;
    }

    // Cabeçalho
    printf("\n╔"); for(int i=0;i<w_nome+2;i++) printf("═");
    printf("╦"); for(int i=0;i<w_cpf+2;i++) printf("═");
    printf("╦"); for(int i=0;i<w_tel+2;i++) printf("═");
    printf("╦"); for(int i=0;i<w_placas+2;i++) printf("═");
    printf("╗\n");

    printf("║ %-*s ║ %-*s ║ %-*s ║ %-*s ║\n", w_nome,"Nome", w_cpf,"CPF", w_tel,"Telefone", w_placas,"Placas Vinculadas");

    printf("╠"); for(int i=0;i<w_nome+2;i++) printf("═");
    printf("╬"); for(int i=0;i<w_cpf+2;i++) printf("═");
    printf("╬"); for(int i=0;i<w_tel+2;i++) printf("═");
    printf("╬"); for(int i=0;i<w_placas+2;i++) printf("═");
    printf("╣\n");

    // Preenche linhas
    temp = lista->prox; int encontrou=0;
    while(temp){
        if(temp->dados->status && (!filtrando || strstr(temp->dados->nome,nome_busca))){
            encontrou=1;
            FILE *arq_v = fopen("dados/veiculos.dat","rb");
            Veiculos v; char placas[256]="";
            if(arq_v){
                while(fread(&v,sizeof(Veiculos),1,arq_v)){
                    if(v.status && strcmp(v.cpf,temp->dados->cpf)==0){
                        if(strlen(placas)>0) strncat(placas,", ",sizeof(placas)-strlen(placas)-1);
                        strncat(placas,v.placa,sizeof(placas)-strlen(placas)-1);
                    }
                }
                fclose(arq_v);
            }
            if(strlen(placas)==0) strcpy(placas,"-");
            printf("║ %-*s ║ %-*s ║ %-*s ║ %-*s ║\n",
                   w_nome,temp->dados->nome,
                   w_cpf,temp->dados->cpf,
                   w_tel,temp->dados->telefone,
                   w_placas,placas);
        }
        temp = temp->prox;
    }

    if(!encontrou)
        printf("║ %-*s ║\n",w_nome+w_cpf+w_tel+w_placas+9,"Nenhum dono encontrado");

    printf("╚"); for(int i=0;i<w_nome+2;i++) printf("═");
    printf("╩"); for(int i=0;i<w_cpf+2;i++) printf("═");
    printf("╩"); for(int i=0;i<w_tel+2;i++) printf("═");
    printf("╩"); for(int i=0;i<w_placas+2;i++) printf("═");
    printf("╝\n");

    deleteDonoVeiculo(lista);
    printf("\n>> Tecle ENTER para continuar...");
    getchar();
}

//=======================================================
// RELATÓRIO DE CADASTRO DE VAGAS
//=======================================================
void relatorio_cadastro_vagas(void) {
    clear_screen();
    int num_andar;
    printf("\n=== Exibir Andar ===\n");
    Ler_num_andar(&num_andar);

    VagaLista* lista = newVagaList();
    preencherListaVagas(lista);

    VagaLista* temp = lista->prox;
    int achou = 0;

    while(temp){
        if(temp->dados.num_andar==num_andar && temp->dados.status==1){
            achou=1;

            FILE* arq_veic = fopen("dados/veiculos.dat","rb");
            if(arq_veic){
                Veiculos v;
                while(fread(&v,sizeof(Veiculos),1,arq_veic)){
                    if(v.status && v.andar==num_andar){
                        int idx = v.vaga-1;
                        if(idx>=0 && idx<MAX_VAGAS){
                            temp->dados.ocupado[idx]=1;
                            strcpy(temp->dados.placa[idx],v.placa);
                        }
                    }
                }
                fclose(arq_veic);
            }

            int w_andar = strlen("Andar");
            int w_total = strlen("Total Vagas");
            int w_status = strlen("Status");
            int w_placas = strlen("Vagas Ocupadas (Placas)");

            char placas[256]=""; int primeira=1;
            for(int i=0;i<temp->dados.total_vagas;i++){
                if(temp->dados.ocupado[i]){
                    if(!primeira) strncat(placas,", ",sizeof(placas)-strlen(placas)-1);
                    strncat(placas,temp->dados.placa[i],sizeof(placas)-strlen(placas)-1);
                    primeira=0;
                }
            }
            if(strlen(placas)==0) strcpy(placas,"-");

            printf("\n╔"); for(int i=0;i<w_andar+2;i++) printf("═");
            printf("╦"); for(int i=0;i<w_total+2;i++) printf("═");
            printf("╦"); for(int i=0;i<w_status+2;i++) printf("═");
            printf("╦"); for(int i=0;i<w_placas+2;i++) printf("═");
            printf("╗\n");

            printf("║ %-*s ║ %-*s ║ %-*s ║ %-*s ║\n",
                   w_andar,"Andar", w_total,"Total Vagas", w_status,"Status", w_placas,"Vagas Ocupadas (Placas)");

            printf("╠"); for(int i=0;i<w_andar+2;i++) printf("═");
            printf("╬"); for(int i=0;i<w_total+2;i++) printf("═");
            printf("╬"); for(int i=0;i<w_status+2;i++) printf("═");
            printf("╬"); for(int i=0;i<w_placas+2;i++) printf("═");
            printf("╣\n");

            printf("║ %-*d ║ %-*d ║ %-*s ║ %-*s ║\n",
                   w_andar,temp->dados.num_andar,
                   w_total,temp->dados.total_vagas,
                   w_status,"Ativo",
                   w_placas,placas);

            printf("╚"); for(int i=0;i<w_andar+2;i++) printf("═");
            printf("╩"); for(int i=0;i<w_total+2;i++) printf("═");
            printf("╩"); for(int i=0;i<w_status+2;i++) printf("═");
            printf("╩"); for(int i=0;i<w_placas+2;i++) printf("═");
            printf("╝\n");

            break;
        }
        temp=temp->prox;
    }

    if(!achou) printf("\nAndar não encontrado!\n");

    deleteVagas(lista);
    printf("\n>> Tecle ENTER para continuar...");
    getchar();
}

//=======================================================
// RELATÓRIO DE VEÍCULOS COM DONO E VAGA
//=======================================================
void relatorio_veiculo_dono_vaga(void) {
    clear_screen();

    printf("\n==================== RELATÓRIO - VEÍCULO + DONO + VAGA ====================\n");
    printf("1 - Mostrar relatório completo\n");
    printf("2 - Filtrar por nome do dono\n");
    printf("0 - Voltar\n");
    printf("==========================================================================\n");
    printf(" >> Escolha uma opção: ");

    char op_sub;
    scanf(" %c", &op_sub);
    getchar();

    if (op_sub == '0') return;

    char nome_busca[50];
    int filtrando = 0;

    if (op_sub == '2') {
        printf("\n >> Digite o nome do dono: ");
        fgets(nome_busca, sizeof(nome_busca), stdin);
        nome_busca[strcspn(nome_busca, "\n")] = 0;
        filtrando = 1;
    }

    DonoVeiculoLista* lista = newDonoVeiculoList();
    preencherListaDonoVeiculo(lista);

    int w_veiculo = strlen("Veículo");
    int w_dono = strlen("Dono");
    int w_vaga = strlen("Vaga");

    DonoVeiculoLista* temp = lista->prox;
    Veiculos v;

    FILE *arq_veiculos = fopen("dados/veiculos.dat","rb");
    if(!arq_veiculos){
        printf("Erro ao abrir arquivo de veículos.\n");
        deleteDonoVeiculo(lista);
        getchar();
        return;
    }

    // PRIMEIRO PASSO: Calcular larguras
    while(temp){
        if(temp->dados->status && (!filtrando || strstr(temp->dados->nome, nome_busca))) {
            rewind(arq_veiculos);
            while(fread(&v,sizeof(Veiculos),1,arq_veiculos)){
                if(v.status && strcmp(v.cpf,temp->dados->cpf)==0){
                    if(strlen(v.model) > w_veiculo) w_veiculo = strlen(v.model);
                    if(strlen(temp->dados->nome) > w_dono) w_dono = strlen(temp->dados->nome);

                    char buf[10];
                    snprintf(buf,sizeof(buf),"%d",v.vaga);
                    if(strlen(buf) > w_vaga) w_vaga = strlen(buf);
                }
            }
        }
        temp = temp->prox;
    }
    rewind(arq_veiculos);

    // CABEÇALHO
    printf("\n╔"); for(int i=0;i<w_veiculo+2;i++) printf("═");
    printf("╦"); for(int i=0;i<w_dono+2;i++) printf("═");
    printf("╦"); for(int i=0;i<w_vaga+2;i++) printf("═");
    printf("╗\n");

    printf("║ %-*s ║ %-*s ║ %-*s ║\n",
           w_veiculo,"Veículo", w_dono,"Dono", w_vaga,"Vaga");

    printf("╠"); for(int i=0;i<w_veiculo+2;i++) printf("═");
    printf("╬"); for(int i=0;i<w_dono+2;i++) printf("═");
    printf("╬"); for(int i=0;i<w_vaga+2;i++) printf("═");
    printf("╣\n");

    // LINHAS
    temp = lista->prox;
    int encontrou = 0;

    while(temp){
        if(temp->dados->status && (!filtrando || strstr(temp->dados->nome, nome_busca))) {

            rewind(arq_veiculos);
            int achouVeic = 0;

            while(fread(&v,sizeof(Veiculos),1,arq_veiculos)){
                if(v.status && strcmp(v.cpf,temp->dados->cpf)==0){
                    achouVeic = 1;
                    encontrou = 1;

                    printf("║ %-*s ║ %-*s ║ %-*d ║\n",
                           w_veiculo, v.model,
                           w_dono, temp->dados->nome,
                           w_vaga, v.vaga);
                }
            }

            if(!achouVeic) {
                encontrou = 1;
                printf("║ %-*s ║ %-*s ║ %-*s ║\n",
                       w_veiculo,"-",
                       w_dono,temp->dados->nome,
                       w_vaga,"-");
            }
        }
        temp = temp->prox;
    }

    if(!encontrou)
        printf("║ %-*s ║\n", w_veiculo+w_dono+w_vaga+6,"Nenhum registro encontrado");

    // RODAPÉ
    printf("╚"); for(int i=0;i<w_veiculo+2;i++) printf("═");
    printf("╩"); for(int i=0;i<w_dono+2;i++) printf("═");
    printf("╩"); for(int i=0;i<w_vaga+2;i++) printf("═");
    printf("╝\n");

    fclose(arq_veiculos);
    deleteDonoVeiculo(lista);

    printf("\n>> Tecle ENTER para continuar...");
    getchar();
}