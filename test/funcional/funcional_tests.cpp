#include <iostream>
#include <cmath>
#include <cassert>
#include "funcional_tests.h"
#include "../../src/model.h"
#include "../../src/system.h"

void exponentialFuncionalTest() {
    std::cout << "Executando Teste Exponencial..." << std::endl;

    // 1. Criamos os elementos soltos na memória
    Model* mod = new Model("Modelo Exponencial");
    System* pop1 = new System("pop1", 100.0);
    System* pop2 = new System("pop2", 0.0);
    ExponencialFlow* exp = new ExponencialFlow("Fluxo Exponencial");

    // 2. Vinculamos o fluxo aos sistemas de origem e destino
    exp->setSource(pop1);
    exp->setTarget(pop2);

    // 3. Adicionamos todos ao modelo via agregação (.add)
    mod->add(pop1);
    mod->add(pop2);
    mod->add(exp);

    // 4. Executamos a simulação
    mod->run(0, 100);

    // 5. Verificação matemática exata com assert (Delta de tolerância: 0.0001)
    assert(std::fabs(pop1->getValue() - 36.6032) < 0.0001); 
    assert(std::fabs(pop2->getValue() - 63.3968) < 0.0001); 

    std::cout << "Teste Exponencial Passou!" << std::endl;

    // 6. Limpeza manual e segura da memória para evitar Memory Leak
    delete mod;
    delete pop1;
    delete pop2;
    delete exp;
}

void logisticalFuncionalTest() {
    std::cout << "Executando Teste Logistico..." << std::endl;

    Model* mod = new Model("Modelo Logistico");
    System* p1 = new System("p1", 100.0);
    System* p2 = new System("p2", 10.0);
    LogisticaFlow* log = new LogisticaFlow("Fluxo Logistico");

    log->setSource(p1);
    log->setTarget(p2);

    mod->add(p1);
    mod->add(p2);
    mod->add(log);

    mod->run(0, 100);

    // Verificação matemática para o modelo logístico
    assert(std::fabs(p1->getValue() - 88.2167) < 0.0001);
    assert(std::fabs(p2->getValue() - 21.7833) < 0.0001);

    std::cout << "Teste Logistico Passou!" << std::endl;

    delete mod;
    delete p1;
    delete p2;
    delete log;
}

void complexFuncionalTest() {
    // Mantendo seu aviso limpo para a Sprint 1, deixando o gancho para a Sprint 2
    std::cout << "Teste Complexo Pronto para ser Implementado na Sprint 2!" << std::endl;
}