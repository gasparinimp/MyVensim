#include "unit_Flow.h"
#include "../../src/flowImpl.h"
#include "../../src/systemImpl.h" 
#include <assert.h>
#include <iostream>

class FlowMock : public FlowImpl {
public:
    using FlowImpl::FlowImpl;
    
    double execute() const override {
        return 10.0; 
    }
};

void unit_Flow_constructor(void) {
    // Teste do construtor vazio
    Flow* f1 = new FlowMock();
    assert(f1->getName() == "");
    assert(f1->getSource() == nullptr);
    assert(f1->getTarget() == nullptr);
    delete f1;

    // Teste do construtor com nome
    Flow* f2 = new FlowMock("Fluxo A");
    assert(f2->getName() == "Fluxo A");
    delete f2;
}

void unit_Flow_destructor(void) {
    Flow* f1 = new FlowMock("F1");
    delete f1;
}

void unit_Flow_getName(void) {
    Flow* f1 = new FlowMock("Fluxo B");
    assert(f1->getName() == "Fluxo B");
    delete f1;
}

void unit_Flow_setName(void) {
    Flow* f1 = new FlowMock();
    f1->setName("Novo Fluxo");
    assert(f1->getName() == "Novo Fluxo");
    delete f1;
}

void unit_Flow_getSource(void) {
    System* s1 = new SystemImpl("Origem", 100);
    Flow* f1 = new FlowMock("F1");
    
    f1->setSource(s1);
    assert(f1->getSource() == s1);
    
    delete f1;
    delete s1;
}

void unit_Flow_setSource(void) {
    System* s1 = new SystemImpl("Origem", 100);
    Flow* f1 = new FlowMock("F1");
    
    f1->setSource(s1);
    assert(f1->getSource()->getName() == "Origem");
    
    delete f1;
    delete s1;
}

void unit_Flow_getTarget(void) {
    System* s2 = new SystemImpl("Destino", 50);
    Flow* f1 = new FlowMock("F1");
    
    f1->setTarget(s2);
    assert(f1->getTarget() == s2);
    
    delete f1;
    delete s2;
}

void unit_Flow_setTarget(void) {
    System* s2 = new SystemImpl("Destino", 50);
    Flow* f1 = new FlowMock("F1");
    
    f1->setTarget(s2);
    assert(f1->getTarget()->getName() == "Destino");
    
    delete f1;
    delete s2;
}

void unit_Flow_execute(void) {
    Flow* f1 = new FlowMock();
    // Verifica se o mock está retornando o valor fixo corretamente
    assert(f1->execute() == 10.0);
    delete f1;
}

void run_unit_tests_Flow(void) {
    unit_Flow_constructor();
    unit_Flow_destructor();
    unit_Flow_getName();
    unit_Flow_setName();
    unit_Flow_getSource();
    unit_Flow_setSource();
    unit_Flow_getTarget();
    unit_Flow_setTarget();
    unit_Flow_execute();
    
    std::cout << "OK -> Todos os testes unitarios de Flow passaram!" << std::endl;
}