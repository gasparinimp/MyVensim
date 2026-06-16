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
    assert(f1.getName() == "");
    assert(f1.getSource() == nullptr);
    assert(f1.getTarget() == nullptr);
    assert(f1.pImpl->getRefCount() == 1);
}

void UnitFlow::unit_Flow_CopyConstructor(){;
    //teste construtor de cópia
    SystemMock s1;
    SystemMock s2;
    FlowMock f;
    f.setName("Flow");
    f.setSource(&s1);
    f.setTarget(&s2);
    FlowMock f3(f);
    assert(f3.getName() == "Flow");
    assert(f3.getSource() == &s1);
    assert(f3.getTarget() == &s2);
    assert(f.pImpl == f3.pImpl);
    assert(f.pImpl->getRefCount() == 2);
}

void UnitFlow::unit_Flow_Operator(){
    SystemMock s1;
    SystemMock s2;
    FlowMock f;
    f.setName("Fluxo");
    f.setSource(&s1);
    f.setTarget(&s2);
    FlowMock f2;

    f2 = f;
    assert(f2.getName() == "Fluxo");
    assert(f2.getSource() == &s1);
    assert(f2.getTarget() == &s2);
    assert(f.pImpl == f2.pImpl);
    assert(f.pImpl->getRefCount() == 2);
}

void UnitFlow::unit_Flow_destructor(void) {
    FlowMock* f1 = new FlowMock();
    delete f1;
}

void UnitFlow::unit_Flow_getName(void) {
    FlowMock f;
    f.setName("Fluxo A");
    assert(f.getName() == "Fluxo A");
}

void UnitFlow::unit_Flow_setName(void) {
    FlowMock f1;
    f1.setName("Novo Fluxo");
    assert(f1.getName() == "Novo Fluxo");
}

void UnitFlow::unit_Flow_getSource(void) {
    FlowMock f1;
    SystemMock s;
    f1.setSource(&s);
    assert(f1.getSource() == &s);
}

void UnitFlow::unit_Flow_setSource(void) {
    FlowMock f1;
    SystemMock s;
    f1.setSource(&s);
    assert(f1.getSource() == &s);
}

void UnitFlow::unit_Flow_getTarget(void) {
    FlowMock f1;
    SystemMock s;
    f1.setTarget(&s);
    assert(f1.getTarget() == &s);
}

void UnitFlow::unit_Flow_setTarget(void) {
    FlowMock f1;
    SystemMock s;
    f1.setTarget(&s);
    assert(f1.getTarget() == &s);
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
