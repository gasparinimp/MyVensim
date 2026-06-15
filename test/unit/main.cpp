#include "unit_System.h"
#include "unit_Flow.h"
#include "unit_Model.h"
#include <iostream>

int main() {
    std::cout << " INICIANDO DE TESTES UNITÁRIOS   " << std::endl;

    // Invoca a verificação da classe System
    run_unit_tests_System();

    // Invoca a verificação da classe Flow
    run_unit_tests_Flow();

    // Invoca a verificação da classe Model
    run_unit_tests_Model();

    std::cout << " TODOS OS TESTES PASSARAM COM SUCESSO! " << std::endl;

    return 0;
}