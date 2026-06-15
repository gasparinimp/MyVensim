#include "unit_Flow.h"
#include "../../src/flowImpl.h"
#include <assert.h>
#include <iostream>

class SystemMock : public System {
public:
    virtual ~SystemMock() {}
    virtual std::string getName() const override { return ""; }
    virtual void setName(std::string) override {}
    virtual double getValue() const override { return 0.0; }
    virtual void setValue(double) override {}
};

class FlowMock : public FlowImpl {
public:
    using FlowImpl::FlowImpl;
    
    double execute() override {
        return 0.0; 
    }
};

void UnitFlow::unit_Flow_constructor(void) {
    // Teste do construtor vazio
    FlowMock f1;
    assert(f1.name == "");
    assert(f1.source == nullptr);
    assert(f1.target == nullptr);
}

void UnitFlow::unit_Flow_CopyConstructor(){;
    //teste construtor de cópia
    SystemMock s1;
    SystemMock s2;
    FlowMock f;
    f.name = "Flow";
    f.source = &s1;
    f.target = &s2;
    FlowMock f3(f);
    assert(f3.name == "Flow");
    assert(f3.source == &s1);
    assert(f3.target == &s2);
}

void UnitFlow::unit_Flow_Operator(){
    SystemMock s1;
    SystemMock s2;
    FlowMock f;
    f.name = "Fluxo";
    f.source = &s1;
    f.target = &s2;
    FlowMock f2;

    f2 = f;
    assert(f2.name == "Fluxo");
    assert(f2.source == &s1);
    assert(f2.target == &s2);
}

void UnitFlow::unit_Flow_destructor(void) {
    FlowMock* f1 = new FlowMock();
    delete f1;
}

void UnitFlow::unit_Flow_getName(void) {
    FlowMock f;
    f.name = "Fluxo A";
    assert(f.getName() == "Fluxo A");
}

void UnitFlow::unit_Flow_setName(void) {
    FlowMock f1;
    f1.setName("Novo Fluxo");
    assert(f1.name == "Novo Fluxo");
}

void UnitFlow::unit_Flow_getSource(void) {
    FlowMock f1;
    SystemMock s;
    f1.source = &s;
    assert(f1.getSource() == &s);
}

void UnitFlow::unit_Flow_setSource(void) {
    FlowMock f1;
    SystemMock s;
    f1.setSource(&s);
    assert(f1.source == &s);
}

void UnitFlow::unit_Flow_getTarget(void) {
    FlowMock f1;
    SystemMock s;
    f1.target = &s;
    assert(f1.getTarget() == &s);
}

void UnitFlow::unit_Flow_setTarget(void) {
    FlowMock f1;
    SystemMock s;
    f1.setTarget(&s);
    assert(f1.target == &s);
}

void run_unit_tests_Flow(void) {
    UnitFlow::unit_Flow_constructor();
    UnitFlow::unit_Flow_destructor();
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