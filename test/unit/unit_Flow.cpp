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

void UnitFlow::unit_Flow_constructor(void) {
    // Teste do construtor vazio
    FlowMock f1;
    assert(f1.name == "");
    assert(f1.source == nullptr);
    assert(f1.target == nullptr);
}

void UnitFlow::unit_Flow_ParameterizedConstructor() {
    //teste construtor parametrizado
    FlowMock f2("Test Flow");
    assert(f2.name == "Test Flow");
    assert(f2.source == nullptr);
    assert(f2.target == nullptr);
}

void UnitFlow::unit_Flow_CopyConstructor(){
    FlowMock f2("Test Flow");
    //teste construtor de cópia
    SystemImpl s1("Source", 10.0);
    SystemImpl s2("Target", 20.0);
    f2.setSource(&s1);
    f2.setTarget(&s2);
    FlowMock f3(f2);
    assert(f3.name == "Test Flow");
    assert(f3.source == &s1);
    assert(f3.target == &s2);
}

void UnitFlow::unit_Flow_Operator(){
    FlowMock f2("Test Flow");
    SystemImpl s1("Source", 10.0);
    SystemImpl s2("Target", 20.0);
    f2.setSource(&s1);
    f2.setTarget(&s2);

    //teste operador de atribuição
    FlowMock f4;
    f4 = f2;
    assert(f4.name == "Test Flow");
    assert(f4.source == &s1);
    assert(f4.target == &s2);
}

void UnitFlow::unit_Flow_destructor(void) {
    FlowMock* f1 = new FlowMock("F1");
    delete f1;
}

void UnitFlow::unit_Flow_getName(void) {
    FlowMock f1("Fluxo B");
    assert(f1.name == "Fluxo B");
}

void UnitFlow::unit_Flow_setName(void) {
    FlowMock f1;
    f1.setName("Novo Fluxo");
    assert(f1.name == "Novo Fluxo");
}

void UnitFlow::unit_Flow_getSource(void) {
    FlowMock f1;
    SystemImpl s("Sistema", 50.0);
    f1.source = &s;
    assert(f1.getSource() == &s);
}

void UnitFlow::unit_Flow_setSource(void) {
    FlowMock f1;
    SystemImpl s("Sistema", 50.0);
    f1.setSource(&s);
    assert(f1.source == &s);
}

void UnitFlow::unit_Flow_getTarget(void) {
    FlowMock f1;
    SystemImpl s("Sistema", 50.0);
    f1.target = &s;
    assert(f1.getTarget() == &s);
}

void UnitFlow::unit_Flow_setTarget(void) {
    FlowMock f1;
    SystemImpl s("Sistema", 50.0);
    f1.setTarget(&s);
    assert(f1.target == &s);
}

void run_unit_tests_Flow(void) {
    UnitFlow::unit_Flow_constructor();
    UnitFlow::unit_Flow_destructor();
    UnitFlow::unit_Flow_ParameterizedConstructor();
    UnitFlow::unit_Flow_CopyConstructor();
    UnitFlow::unit_Flow_Operator();
    UnitFlow::unit_Flow_getName();
    UnitFlow::unit_Flow_setName();
    UnitFlow::unit_Flow_getSource();
    UnitFlow::unit_Flow_setSource();
    UnitFlow::unit_Flow_getTarget();
    UnitFlow::unit_Flow_setTarget();
    
    std::cout << "OK -> Todos os testes unitarios de Flow passaram!" << std::endl;
}