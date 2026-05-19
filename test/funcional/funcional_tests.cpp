#include <iostream>
#include <cmath>
#include <cassert>
#include "funcional_tests.h"
#include "../../src/model.h"
#include "../../src/system.h"

//Metodo do teste funcional do exponencial
void exponentialFuncionalTest() {
    std::cout << "Executando Teste Exponencial..." << std::endl;

    //Crio o modelo
    Model* mod = new Model("Modelo Exponencial");
    //Crio os sistemas
    System* pop1 = new System("pop1", 100.0);
    System* pop2 = new System("pop2", 0.0);
    //Crio o fluxo
    ExponencialFlow* exp = new ExponencialFlow("Fluxo Exponencial");

    //Defino o destino e origem
    exp->setSource(pop1);
    exp->setTarget(pop2);

    //Adiciono os sistemas e fluxo no modelo
    mod->add(pop1);
    mod->add(pop2);
    mod->add(exp);

    //Executo a simulação
    mod->run(0, 100);

    //Validação com assert
    //Faço com que a diferença seja menor que 0.0001 para dar certo
    assert(std::fabs(pop1->getValue() - 36.6032) < 0.0001); 
    assert(std::fabs(pop2->getValue() - 63.3968) < 0.0001); 

    std::cout << "Teste Exponencial Passou!" << std::endl;

    //Limpo os ponteiros
    delete mod;
    delete pop1;
    delete pop2;
    delete exp;
}

//Metodo do teste funcional do logistico
void logisticalFuncionalTest() {
    std::cout << "Executando Teste Logistico..." << std::endl;

    //Crio o modelo e os sistemas
    Model* mod = new Model("Modelo Logistico");
    System* p1 = new System("p1", 100.0);
    System* p2 = new System("p2", 10.0);
    //Crio o fluxo
    LogisticaFlow* log = new LogisticaFlow("Fluxo Logistico");

    //Defino o destino e origem
    log->setSource(p1);
    log->setTarget(p2);

    //Adiciono sistemas e fluxo no modelo
    mod->add(p1);
    mod->add(p2);
    mod->add(log);

    //Executo a simulacao
    mod->run(0, 100);

    //Validação com assert
    //Faço com que a diferença seja menor que 0.0001 para dar certo
    assert(std::fabs(p1->getValue() - 88.2167) < 0.0001);
    assert(std::fabs(p2->getValue() - 21.7833) < 0.0001);

    std::cout << "Teste Logistico Passou!" << std::endl;

    //Deleto os ponteiros
    delete mod;
    delete p1;
    delete p2;
    delete log;
}
