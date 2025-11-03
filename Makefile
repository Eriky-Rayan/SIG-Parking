# Compilador e flags
CC = gcc
CFLAGS = -Wall -Iinclude

# Pastas
SRC_DIR = src
BUILD_DIR = build

# Arquivos fonte e objetos
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRC))
BIN = $(BUILD_DIR)/SIG-Parking

# Detecta o OS
UNAME_S := $(shell uname -s)

# Comando de criar pasta
ifeq ($(OS),Windows_NT)
	MKDIR = if not exist $(BUILD_DIR) mkdir $(BUILD_DIR)
	RM = if exist $(BUILD_DIR) rmdir /s /q $(BUILD_DIR)
	RUN = $(BIN)
else
	MKDIR = mkdir -p $(BUILD_DIR)
	RM = rm -rf $(BUILD_DIR)
	RUN = ./$(BIN)
endif

# Regra padrão: compila tudo
all: $(BIN)

# Gera o executável
$(BIN): $(OBJ)
	@$(MKDIR)
	$(CC) $(OBJ) -o $(BIN)

# Compila cada .c em .o
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@$(MKDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Limpa arquivos compilados
clean:
	@$(RM)

# Executa o programa
run: all
	@$(RUN)
