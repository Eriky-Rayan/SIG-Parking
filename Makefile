CC = gcc
CFLAGS = -Wall -Iinclude
SRC = $(wildcard src/*.c)
OBJ = $(SRC:src/%.c=build/%.o)
BIN = build/SIG-Parking

# Compila tudo
all: $(BIN)

# Gera o executável
$(BIN): $(OBJ)
	$(CC) $(OBJ) -o $(BIN)

# Compila os .c em .o
build/%.o: src/%.c
	@mkdir -p build
	$(CC) $(CFLAGS) -c $< -o $@

# Limpa arquivos temporários
clean:
	rm -rf build

# Executa o programa
run: all
	./$(BIN)
