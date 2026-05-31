#include <iostream>
#include <cmath>
#include <iomanip>
#include <cassert>
#include "funcional_tests.h"
#include "../../src/modelImpl.h"
#include "../../src/system.h"

//Metodo do teste funcional do exponencial
void exponentialFuncionalTest() { //Funcao para realizar os testes exponenciais
    std::cout << "Executando Teste Exponencial..." << std::endl;

    //Crio o modelo
    Model* mod = new ModelImpl("Modelo Exponencial");
    //Crio os sistemas
    System* pop1 = mod->criaSistema("pop1", 100.0);
    System* pop2 = mod->criaSistema("pop2", 0.0);

    //Crio o fluxo
    Flow* exp = mod->criaFluxo<ExponentialFlow>("Fluxo Exponencial", pop1, pop2);

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
void logisticalFuncionalTest() { //Funcao para realizar os testes logisticos
    std::cout << "Executando Teste Logistico..." << std::endl;

    //Crio o modelo e os sistemas
    Model* mod = new ModelImpl("Modelo Logistico");
    System* p1 = mod->criaSistema("p1", 100.0);
    System* p2 = mod->criaSistema("p2", 10.0);
    //Crio o fluxo
    Flow* log = mod->criaFluxo<LogisticalFlow>("Fluxo Logistico", p1, p2);

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

void complexFuncionalTest() { //Funcao para realizar testes complexos
    std::cout << "Executando Teste Complexo (Sistema Q)..." << std::endl;

    Model* m = new ModelImpl("Complex Model Q");

    //Criação dos 5 sistemas soltos na memória
    System* q1 = m->criaSistema("Q1", 100.0);
    System* q2 = m->criaSistema("Q2", 0.0);
    System* q3 = m->criaSistema("Q3", 100.0);
    System* q4 = m->criaSistema("Q4", 0.0);
    System* q5 = m->criaSistema("Q5", 0.0);

    //Criação e vinculação das 6 engrenagens de fluxos complexos
    Flow* f = m->criaFluxo<ComplexFlow>("f", q1, q2);
    Flow* g = m->criaFluxo<ComplexFlow>("g", q1, q3);
    Flow* r = m->criaFluxo<ComplexFlow>("r", q2, q5);
    Flow* t = m->criaFluxo<ComplexFlow>("t", q2, q3);
    Flow* u = m->criaFluxo<ComplexFlow>("u", q3, q4);
    Flow* v = m->criaFluxo<ComplexFlow>("v", q4, q1);

    //Executando a simulação por 100 iterações
    m->run(0, 100);
          
    //Validação de alta precisao (tive que colocar a funcao round4 para que o codigo pare de falhar quando muda a ultima casa decimal) 
    auto round4 = [](double v) {
        return std::round(v * 10000.0) / 10000.0;
    };

    assert(round4(q1->getValue()) == 31.8513);
    assert(round4(q2->getValue()) == 18.4003);
    assert(round4(q3->getValue()) == 77.1143);
    assert(round4(q4->getValue()) == 56.1728);
    assert(round4(q5->getValue()) == 16.4612);
    
    std::cout << "Teste Complexo Passou!" << std::endl;

    //Limpeza manual da memóriaHeap para evitar vazamentos (Memory Leak)
    delete m;
    delete q1; delete q2; delete q3; delete q4; delete q5;
    delete f; delete g; delete r; delete t; delete u; delete v;
}