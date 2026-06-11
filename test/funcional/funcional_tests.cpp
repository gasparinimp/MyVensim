#include "funcional_tests.h"
#include "../../src/modelImpl.h"
#include "../../src/systemImpl.h"
#include "../../src/exponentialFlow.h"
#include "../../src/logisticalFlow.h"
#include "../../src/complexFlow.h"
#include <assert.h>
#include <iostream>
#include <cmath>

void exponentialFuncionalTest() { 
    std::cout << "Executando Teste Exponencial..." << std::endl;

    // Uso a Fábrica!
    Model* mod = Model::createModel("Modelo Exponencial");
    System* pop1 = mod->createSystem("pop1", 100.0);
    System* pop2 = mod->createSystem("pop2", 0.0);

    // Fábrica de fluxo
    mod->createFlow<ExponentialFlow>("exponencial", pop1, pop2);

    mod->run(0, 100);

    assert(std::fabs(pop1->getValue() - 36.6032) < 0.0001); 
    assert(std::fabs(pop2->getValue() - 63.3968) < 0.0001); 

    std::cout << "Teste Exponencial Passou!" << std::endl;

    Model::deleteModel("Exponencial Model");
}

void logisticalFuncionalTest() { 
    std::cout << "Executando Teste Logistico..." << std::endl;

    Model* mod = Model::createModel("Modelo Logistico");
    System* p1 = mod->createSystem("p1", 100.0);
    System* p2 = mod->createSystem("p2", 10.0);

    mod->createFlow<LogisticalFlow>("Fluxo Logistico", p1, p2);

    mod->run(0, 100);

    assert(std::fabs(p1->getValue() - 88.2167) < 0.0001);
    assert(std::fabs(p2->getValue() - 21.7833) < 0.0001);

    std::cout << "Teste Logistico Passou!" << std::endl;

    Model::deleteModel("Logistical Model");
}

void complexFuncionalTest() { 
    std::cout << "Executando Teste Complexo..." << std::endl;

    Model* mod = Model::createModel("Modelo Complexo");
    System* q1 = mod->createSystem("q1", 100.0);
    System* q2 = mod->createSystem("q2", 0.0);
    System* q3 = mod->createSystem("q3", 100.0);
    System* q4 = mod->createSystem("q4", 0.0);
    System* q5 = mod->createSystem("q5", 0.0);

    mod->createFlow<ComplexFlow>("f", q1, q2);
    mod->createFlow<ComplexFlow>("g", q1, q3);
    mod->createFlow<ComplexFlow>("t", q2, q3);
    mod->createFlow<ComplexFlow>("r", q2, q5);
    mod->createFlow<ComplexFlow>("u", q3, q4);
    mod->createFlow<ComplexFlow>("v", q4, q1);

    mod->run(0, 100);

    assert(std::fabs(q1->getValue() - 31.8513) < 0.0001);
    assert(std::fabs(q2->getValue() - 18.4003) < 0.0001);
    assert(std::fabs(q3->getValue() - 77.1143) < 0.0001);
    assert(std::fabs(q4->getValue() - 56.1728) < 0.0001);
    assert(std::fabs(q5->getValue() - 16.4612) < 0.0001);

    std::cout << "Teste Complexo Passou!" << std::endl;

    delete mod;
}