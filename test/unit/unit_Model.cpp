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

void UnitModel::unit_Model_constructor(void) {
    ModelImpl m1;
    assert(m1.name == "");
    assert(m1.systems.empty());
    assert(m1.flows.empty());
}

void UnitModel::unit_Model_ParameterizedConstructor() {
    ModelImpl m2("M2");
    assert(m2.name == "M2");
}

void UnitModel::unit_Model_destructor(void) {
    ModelImpl* m1 = new ModelImpl("M1");
    m1->systems.push_back(new SystemImpl("Sistema", 50.0));
    delete m1;
}

void UnitModel::unit_Model_CopyConstructor() {
    ModelImpl m1("Modelo");
    SystemImpl* s1 = new SystemImpl("Sistema", 50.0);
    FlowMockModel* f1 = new FlowMockModel("Flow");
    m1.add(s1);
    m1.add(f1);
    
    ModelImpl m2(m1);
    assert(m2.name == "Modelo");
    assert(m2.systems.size() == 1);
    assert(m2.flows.size() == 1);
    assert(m2.systems[0] == s1);
    assert(m2.flows[0] == f1);

    m2.systems.clear();
    m2.flows.clear();
}

void UnitModel::unit_Model_Operator() {
    ModelImpl m1("Modelo");
    SystemImpl* s1 = new SystemImpl("Sistema", 50.0);
    FlowMockModel* f1 = new FlowMockModel("Flow");
    m1.add(s1);
    m1.add(f1);

    ModelImpl m2;
    m2 = m1;
    assert(m2.name == "Modelo");
    assert(m2.systems.size() == 1);
    assert(m2.flows.size() == 1);
    assert(m2.systems[0] == s1);
    assert(m2.flows[0] == f1);

    m2.systems.clear();
    m2.flows.clear();
}

void UnitModel::unit_Model_getName(void) {
    ModelImpl m1("M2");
    assert(m1.getName() == "M2");
}

void UnitModel::unit_Model_setName(void) {
    ModelImpl m1;
    m1.setName("M2");
    assert(m1.name == "M2");
}

void UnitModel::unit_Model_criaSistema(void) {
    ModelImpl m1;
    SystemImpl* s1 = new SystemImpl("SisA", 100.0);
    
    m1.add(s1);
    // Verifica se a fábrica construiu corretamente
    assert(m1.systems.size() == 1);
    assert(m1.systems[0] == s1);
}

void UnitModel::unit_Model_criaFluxo(void) {
    ModelImpl m1;
    FlowMockModel* f1 = new FlowMockModel("Flow");
    m1.add(f1);
    assert(m1.flows.size() == 1);
    assert(m1.flows[0] == f1);
}

void UnitModel::unit_Model_run(void) {
    ModelImpl m1;
    SystemImpl s1("Origem", 100.0);
    SystemImpl s2("Destino", 0.0);
    FlowMockModel* f1 = new FlowMockModel("Flow"); 
    f1->setSource(&s1);
    f1->setTarget(&s2);

    m1.add(&s1);
    m1.add(&s2);
    m1.add(f1);

    m1.run(0,1);
    
    // Origem deve perder 10 (100 - 10 = 90)
    assert(std::fabs(s1.getValue() - 90.0) < 0.0001);
    // Destino deve ganhar 10 (0 + 10 = 10)
    assert(std::fabs(s2.getValue() - 10.0) < 0.0001);
}


void run_unit_tests_Model(void) {
    UnitModel::unit_Model_constructor();
    UnitModel::unit_Model_destructor();
    UnitModel::unit_Model_ParameterizedConstructor();
    UnitModel::unit_Model_CopyConstructor();
    UnitModel::unit_Model_Operator();
    UnitModel::unit_Model_getName();
    UnitModel::unit_Model_setName();
    UnitModel::unit_Model_criaSistema();
    UnitModel::unit_Model_criaFluxo();
    UnitModel::unit_Model_run();
    
    std::cout << "OK -> Todos os testes unitarios de Model passaram!" << std::endl;
}