# Compilador e flags
CC = gcc
CFLAGS = -Wall -Iinclude

# Pastas
SRC_DIR = src
BUILD_DIR = build
DATA_DIR = dados

# Arquivos fonte e objetos
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRC))
BIN = $(BUILD_DIR)/SIG-Parking

# Detecta o OS
UNAME_S := $(shell uname -s)

# Comando de criar pasta
ifeq ($(OS),Windows_NT)
	MKDIR = if not exist $(BUILD_DIR) mkdir $(BUILD_DIR)
	MKDIR_DATA = if not exist $(DATA_DIR) mkdir $(DATA_DIR)
	RM = if exist $(BUILD_DIR) rmdir /s /q $(BUILD_DIR)
	RM_DATA = if exist $(DATA_DIR) rmdir /s /q $(DATA_DIR)
	RUN = $(BIN)
else
	MKDIR = mkdir -p $(BUILD_DIR)
	MKDIR_DATA = mkdir -p $(DATA_DIR)
	RM = rm -rf $(BUILD_DIR)
	RM_DATA = rm -rf $(DATA_DIR)
	RUN = ./$(BIN)
endif

# Regra padrão: compila tudo
all: $(BIN) setup_data

# Gera o executável
$(BIN): $(OBJ)
	@$(MKDIR)
	$(CC) $(OBJ) -o $(BIN)

# Compila cada .c em .o
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@$(MKDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Cria a pasta dados e arquivos .dat vazios, se não existirem
.PHONY: setup_data
setup_data:
	@$(MKDIR_DATA)
	@touch $(DATA_DIR)/veiculos.dat
	@touch $(DATA_DIR)/dono_veiculo.dat
	@touch $(DATA_DIR)/estacionamentos.dat
	@touch $(DATA_DIR)/cadastro_vagas.dat

# Limpa arquivos compilados
clean:
	@$(RM)

# Limpa dados (opcional)
clean_data:
	@$(RM_DATA)

# Executa o programa
run: all
	@$(RUN)
