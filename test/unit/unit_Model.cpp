#include "unit_Model.h"
#include "../../src/modelImpl.h"
#include "../../src/systemImpl.h"
#include "../../src/flowImpl.h"
#include <assert.h>
#include <iostream>
#include <cmath>

class FlowMockModel : public FlowImpl {
public:
    using FlowImpl::FlowImpl;
    double execute() const override {
        return 10.0;
    }
};

void unit_Model_constructor(void) {
    Model* m1 = new ModelImpl();
    assert(m1->getName() == "");
    delete m1;

    Model* m2 = new ModelImpl("Modelo de Teste");
    assert(m2->getName() == "Modelo de Teste");
    delete m2;
}

void unit_Model_destructor(void) {
    Model* m1 = new ModelImpl("M1");
    // Em agregação, apenas deletar o modelo não deve causar falhas
    delete m1;
}

void unit_Model_getName(void) {
    Model* m1 = new ModelImpl("Meu Modelo");
    assert(m1->getName() == "Meu Modelo");
    delete m1;
}

void unit_Model_setName(void) {
    Model* m1 = new ModelImpl();
    m1->setName("Novo Nome do Modelo");
    assert(m1->getName() == "Novo Nome do Modelo");
    delete m1;
}

void unit_Model_criaSistema(void) {
    Model* m1 = new ModelImpl();
    System* s1 = m1->criaSistema("SisA", 100.0);
    
    // Verifica se a fábrica construiu corretamente
    assert(s1 != nullptr);
    assert(s1->getName() == "SisA");
    assert(s1->getValue() == 100.0);
    
    delete m1;
    delete s1; // Limpeza manual por causa da Agregação
}

void unit_Model_criaFluxo(void) {
    Model* m1 = new ModelImpl();
    System* s1 = m1->criaSistema("SisA", 100.0);
    System* s2 = m1->criaSistema("SisB", 0.0);
    
    // Fabrica o fluxo Mock passando a origem e destino
    Flow* f1 = m1->criaFluxo<FlowMockModel>("FluxoMock", s1, s2);
    
    assert(f1 != nullptr);
    assert(f1->getName() == "FluxoMock");
    assert(f1->getSource() == s1);
    assert(f1->getTarget() == s2);
    
    delete m1;
    delete s1; delete s2; delete f1;
}

void unit_Model_run(void) {
    Model* m1 = new ModelImpl();
    System* s1 = m1->criaSistema("Origem", 100.0);
    System* s2 = m1->criaSistema("Destino", 0.0);
    Flow* f1 = m1->criaFluxo<FlowMockModel>("Fluxo", s1, s2);
    
    // O mock retorna sempre 10. Vamos rodar de t=0 até t=1 (1 iteração)
    m1->run(0, 1);
    
    // Origem deve perder 10 (100 - 10 = 90)
    assert(std::fabs(s1->getValue() - 90.0) < 0.0001);
    // Destino deve ganhar 10 (0 + 10 = 10)
    assert(std::fabs(s2->getValue() - 10.0) < 0.0001);
    
    delete m1;
    delete s1; delete s2; delete f1;
}


void run_unit_tests_Model(void) {
    unit_Model_constructor();
    unit_Model_destructor();
    unit_Model_getName();
    unit_Model_setName();
    unit_Model_criaSistema();
    unit_Model_criaFluxo();
    unit_Model_run();
    
    std::cout << "OK -> Todos os testes unitarios de Model passaram!" << std::endl;
}