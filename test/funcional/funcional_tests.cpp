#include <iostream>
#include <cmath>
#include <cassert>
#include "funcional_tests.h"
#include "../../src/model.h"
#include "../../src/system.h"

void exponentialFuncionalTest() {
    Model* mod = new Model();
    System* pop1 = mod->criaSistema("pop1", 100.0);
    System* pop2 = mod->criaSistema("pop2", 0.0);
    
    mod->criaFluxo<ExponencialFlow>(pop1, pop2);
    mod->run(0, 100);

    // Substitua pelo valor de ponto flutuante exato do Vensim na hora de rodar
    // assert(fabs(pop1->getValor() - VALOR_VENSIM_POP1) < 0.0001); 
    
    std::cout << "Teste Exponencial Passou!" << std::endl;
    delete mod;
}

void logisticalFuncionalTest() {
    Model* mod = new Model();
    System* p1 = mod->criaSistema("p1", 100.0);
    System* p2 = mod->criaSistema("p2", 10.0);
    
    mod->criaFluxo<LogisticaFlow>(p1, p2);
    mod->run(0, 100);

    std::cout << "Teste Logístico Passou!" << std::endl;
    delete mod;
}

void complexFuncionalTest() {
    // Aqui você vai montar a rede do Sistema Q na Sprint 2
    std::cout << "Teste Complexo Pronto para ser Implementado!" << std::endl;
}