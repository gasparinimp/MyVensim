#Pega todos os arquivos .cpp da pasta src/ automaticamente
SRC_FILES = $(wildcard src/*.cpp)

all:
	mkdir -p bin
	g++ -Wall -std=c++17 -fPIC -shared $(SRC_FILES) -o bin/libmyvensim.so
	
	g++ -Wall -std=c++17 test/funcional/*.cpp -Lbin -lmyvensim -Wl,-rpath,bin -o bin/funcional_tests
	
	g++ -Wall -std=c++17 test/unit/*.cpp -Lbin -lmyvensim -Wl,-rpath,bin -o bin/unit_tests

run_funcional: all
	./bin/funcional_tests

run_unit: all
	./bin/unit_tests

clean:
	rm -rf bin