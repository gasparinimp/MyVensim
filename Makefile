# Variáveis de compilação
CC = g++
CFLAGS = -Wall -std=c++17

# Diretórios
SRC_DIR = src
TEST_DIR = test/funcional
BIN_DIR = bin

# Arquivos fonte e objetos do produto principal
SRC_SOURCES = $(SRC_DIR)/system.cpp $(SRC_DIR)/flow.cpp $(SRC_DIR)/model.cpp
SRC_OBJECTS = $(BIN_DIR)/system.o $(BIN_DIR)/flow.o $(BIN_DIR)/model.o

# Alvo principal (Compila e roda os testes funcionais)
all: funcional

# Cria os arquivos .o na pasta bin antes de gerar o executável
$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Regra para compilar o executável de testes funcionais
funcional: $(SRC_OBJECTS)
	$(CC) $(CFLAGS) $(TEST_DIR)/main.cpp $(TEST_DIR)/funcional_tests.cpp $(SRC_OBJECTS) -o $(BIN_DIR)/funcional_tests

# Regra para rodar os testes
run_funcional: funcional
	./$(BIN_DIR)/funcional_tests

# Limpa os arquivos gerados pela compilação para deixar o repositório limpo
clean:
	rm -rf $(BIN_DIR)/*
