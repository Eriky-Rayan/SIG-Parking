# SIG-Parking (*EM DESENVOLVIMENTO*)
Um Sistema de Controle de Estacionamentos de Carros e Motos

Universidade Federal do Rio Grande do Norte
Centro de Ensino Superior do Seridó
Departamento de Computação e Tecnologia
Bacharelado em Sistemas de Informação

Disciplina DCT1106 - Programação

Programa para fins didáticos de ilustração, utilizado como exemplo de codificação de funcionalidades em linguagem C, durante a disciplina DCT1106 - Programação do curso de Bacharelado em Sistemas de Informação da Universidade Federal do Rio Grande do Norte. O programa contém os principais módulos e funcionalidades que serão exigidos na avaliação dos projetos a serem desenvolvidos pelos alunos ao longo da disciplina. Todos os dados e informações utilizados neste programa são fictícios.

Atenção: este NÃO é um programa comercial. O autor não se responsabiliza por quaisquer danos, sejam pessoais, materiais ou imateriais, decorrentes da utilização deste código-fonte ou de trechos do mesmo, assim como, não garante o seu funcionamento correto em situações reais.
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

# ■ O Programa possui os seguintes módulos:

-Módulo Veículos

-Módulo Estacionamentos

-Módulo Donos dos Veículos

-Módulo Cadastro de Vagas

-Módulo Relatórios

-Módulo Equipe do Projeto

-Sobre o Sistema

---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

# ■ Como utilizar

Baixe o arquivo pelo GitHub, extraia os arquivos e em seguida utilize os comandos no terminal nessa ordem: gcc -c -Wall *.h ׀ gcc -c -Wall *.c ׀ gcc -o SIG-Parking *.o ׀ ./SIG-Parking

O programa possui a capacidade de cadastro para motos e carros, seus respectivos donos e capacidade de gerenciamento de vagas estacionamentos.

Para utilizar o programa basta inserir as informações necessarias sobre os veículos, donos e cadastrar a quantidade de vagas e andares do estacionamento, após isso basta manter o gerenciamento dessas informações.

---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

# ■ Caso possua o Make

Utilize os seguintes comandos no terminal (Make) para compilar o código, (Make run) para executar o programa e (Make clean) para limpar os arquivos residuais após o uso.

# ■ Explicação rasa sobre os módulos

# ▶ Veículos
-Cadastrar veículos utilizando a placa como chave do dicionario e tipo, modelo, cor, id da vaga onde está estacionado e o cpf do dono como informações de cadastro.

# ▶ Estacionamentos
-Cadastrar um veículo em uma vaga usando o id da vaga como chave do dicionario e tipo da vaga (carro ou moto) e placa do veículo como informações de cadastro.

# ▶ Donos dos Veículos
Cadastrar os donos dos veículos usando o cpf como chave do dicionario e telefone, nome e quantidade de veículos cadastrados como informações de cadastro.

# ▶ Cadastro de Vagas
-Cadastra a quantidade de vagas em um andar que estarão sendo disponibilizadas para uso.

# ▶ Relatorios
-Exibe relatorios diversos utilizando informações cadastradas no sistema.

# ▶ Equipe do Projeto
-Exibe informações sobre os menbros da equipe que participou do desenvolvimento desse projeto.

# ▶ Sobre o Sistema
-Exibe uma breve introdução ao sistema

---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

# Equipe do Projeto:

-Eriky Rayan B. de Medeiros (https://github.com/Eriky-Rayan)

-Isaac Vilton Ribeiro (https://github.com/Isaac-Ribeiro)

-Andressa Carla da Silva (https://github.com/andressa-codes)

---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

# Orientador:

-Flavius Da Luz e Gorgonio (https://github.com/FlaviusGorgonio)

---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
