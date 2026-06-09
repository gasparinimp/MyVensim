#include <iostream>
#include <cmath>
#include <iomanip>
#include <cassert>
#include "funcional_tests.h"
#include "../../src/modelImpl.h"
#include "../../src/systemImpl.h"
#include "../../src/system.h"

//Metodo do teste funcional do exponencial
void exponentialFuncionalTest() { //Funcao para realizar os testes exponenciais
    std::cout << "Executando Teste Exponencial..." << std::endl;

    //Crio o modelo
    Model* mod = new ModelImpl("Modelo Exponencial");
    //Crio os sistemas
    System* pop1 = new SystemImpl("pop1", 100.0);
    System* pop2 = new SystemImpl("pop2", 0.0);

    //Crio o fluxo
    ExponentialFlow *f = new ExponentialFlow("exponencial");
    f->setSource(pop1);
    f->setTarget(pop2);

    mod->add(pop1);
    mod->add(pop2);
    mod->add(f);

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
    delete f;
}

//Metodo do teste funcional do logistico
void logisticalFuncionalTest() { //Funcao para realizar os testes logisticos
    std::cout << "Executando Teste Logistico..." << std::endl;

    //Crio o modelo e os sistemas
    Model* mod = new ModelImpl("Modelo Logistico");
    System* p1 = new SystemImpl("p1", 100.0);
    System* p2 = new SystemImpl("p2", 10.0);
    //Crio o fluxo
    LogisticalFlow *log = new LogisticalFlow("logistical");

    log->setSource(p1);
    log->setTarget(p2);

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

void complexFuncionalTest() { //Funcao para realizar testes complexos
    std::cout << "Executando Teste Complexo (Sistema Q)..." << std::endl;

    Model* m = new ModelImpl("Complex Model Q");

    //Criação dos 5 sistemas soltos na memória
    System* q1 = new SystemImpl("Q1", 100.0);
    System* q2 = new SystemImpl("Q2", 0.0);
    System* q3 = new SystemImpl("Q3", 100.0);
    System* q4 = new SystemImpl("Q4", 0.0);
    System* q5 = new SystemImpl("Q5", 0.0);

    //Criação e vinculação das 6 engrenagens de fluxos complexos
    ComplexFlow *f = new ComplexFlow("f");
    f->setSource(q1);
    f->setTarget(q2);
    ComplexFlow *g = new ComplexFlow("g");
    g->setSource(q1);
    g->setTarget(q3);
    ComplexFlow *r = new ComplexFlow("r");
    r->setSource(q2);
    r->setTarget(q5);
    ComplexFlow *t = new ComplexFlow("t");
    t->setSource(q2);
    t->setTarget(q3);
    ComplexFlow *u = new ComplexFlow("u");
    u->setSource(q3);
    u->setTarget(q4);
    ComplexFlow *v = new ComplexFlow("v");
    v->setSource(q4);
    v->setTarget(q1);

    //Executando a simulação por 100 iterações
    m->add(q1);
    m->add(q2);
    m->add(q3);
    m->add(q4);
    m->add(q5);
    m->add(f);
    m->add(g);
    m->add(r);
    m->add(t);
    m->add(u);
    m->add(v);
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