#include "funcional_tests.h"

int main() {
    //Chamada os testes
    std::cout <<"INICIANDO TESTES FUNCIONAIS" << std::endl;
    printf("\n");
    exponentialFuncionalTest();
    printf("\n");
    logisticalFuncionalTest();
    printf("\n");
    complexFuncionalTest();
    printf("\n");
    std::cout <<"TODOS OS TESTES PASSARAM!!" << std::endl;
    return 0;
}