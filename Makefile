all: funcional unit

funcional:
	mkdir -p bin
	g++ -Wall -std=c++17 src/systemImpl.cpp src/flowImpl.cpp src/modelImpl.cpp src/exponentialFlow.cpp src/logisticalFlow.cpp src/complexFlow.cpp test/funcional/main.cpp test/funcional/funcional_tests.cpp -o bin/funcional_tests

unit:
	mkdir -p bin
	g++ -Wall -std=c++17 src/systemImpl.cpp src/flowImpl.cpp src/modelImpl.cpp test/unit/main.cpp test/unit/unit_tests.cpp test/unit/unit_System.cpp test/unit/unit_Flow.cpp test/unit/unit_Model.cpp -o bin/unit_tests

run_funcional: funcional
	./bin/funcional_tests

run_unit: unit
	./bin/unit_tests

clean:
	rm -rf bin