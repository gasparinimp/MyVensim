#include "unit_Model.h"
#include "../../src/modelImpl.h"
#include <assert.h>
#include <iostream>
#include <cmath>

namespace {
class SystemMock : public System {
private:
    std::string name;
    double value;
public:
    SystemMock() {
        this->name = "";
        this->value = 0.0;
    }
    SystemMock(std::string name, double value) : name(name), value(value){}
    virtual ~SystemMock() {}
    
    virtual std::string getName() const override { return this->name; }
    virtual void setName(std::string n) override { this->name = n; }
    virtual double getValue() const override { return this->value; }
    virtual void setValue(double v) override { this->value = v; }
};

class FlowMock : public Flow {
private:
    std::string name;
    System* source;
    System* target;
public:
    FlowMock(){
        this->name= "";
        this->source= nullptr;
        this->target= nullptr;
    }

    FlowMock(std::string name, System* source, System* target) 
        : name(name), source(source), target(target) {}
        
    virtual ~FlowMock() {}
    
    virtual std::string getName() const override { return this->name; }
    virtual void setName(std::string n) override { this->name = n; }
    
    // Calcula 1% do valor da origem a cada iteração!
    double execute() override {
        if (this->source != nullptr) {
            return 0.01 * this->source->getValue();
        }
        return 0.0; 
    }
    
    virtual System* getSource() const override{ return this->source; }
    virtual void setSource(System* s) override{ this->source = s; }
    virtual System* getTarget() const override{ return this->target; }
    virtual void setTarget(System* t) override{ this->target = t; }
};
}
void UnitModel::unit_Model_constructor(void) {
    ModelImpl m;
    assert(m.name == "");
    assert(m.systems.empty());
    assert(m.flows.empty());
}

void UnitModel::unit_Model_ParameterizedConstructor() {
    ModelImpl m("M2");
    assert(m.name == "M2");
}

void UnitModel::unit_Model_destructor(void) {
    ModelImpl* m1 = new ModelImpl();
    System* s1 = new SystemMock();
    m1->systems.push_back(s1);
}

void UnitModel::unit_Model_CopyConstructor() {
    ModelImpl m;
    m.name = "Modelo";
    System* s = new SystemMock("S1", 0.0);

    m.systems.push_back(s);

    // Invoca o construtor de cópia
    ModelImpl m1(m);
    assert(m1.name == "Modelo");
    assert(m1.systems.size() == 1); 
    assert(m1.systems[0] == s);

    //liberar memoria
    m.systems.clear();
}

void UnitModel::unit_Model_Operator() {
    ModelImpl m;
    m.name = "Modelo";
    
    ModelImpl m1;
    m1.name = "Modelo 2";

    m1 = m;
    assert(m1.name == "Modelo");
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

void UnitModel::unit_Model_addSystem() {
    ModelImpl m;
    System* s = new SystemMock("Sistema", 50.0); 
    m.add(s);
    assert(m.systems.size() == 1);
    assert(m.systems[0] == s);
}

void UnitModel::unit_Model_addFlow() {
    ModelImpl m;
    Flow* f = new FlowMock("Flow", nullptr, nullptr); 
    m.add(f);
    assert(m.flows.size() == 1);
    assert(m.flows[0] == f);
}

void UnitModel::unit_Model_createSystem() {
    ModelImpl m("Teste");
    System* s = m.createSystem("Sistema", 50.0);
    
    assert(s->getName() == "Sistema");
    assert(s->getValue() == 50.0);
    assert(m.systems.size() == 1);
    assert(m.systems[0] == s); 
    m.deleteSystem(s);
}

void UnitModel::unit_Model_createFlow() {
    ModelImpl m;
    Flow* f = new FlowMock("F1", nullptr, nullptr);

    m.add(f);
    assert(m.flows.size() == 1);
    assert(m.flows[0] == f);
}

void UnitModel::unit_Model_deleteSystem() {
    ModelImpl m("Teste");
    System* s = new SystemMock("Sistema", 50.0);
    
    m.systems.push_back(s);

    m.deleteSystem(s);
    
    assert(m.systems.empty());
}

void UnitModel::unit_Model_deleteFlow() {
    ModelImpl mod;
    Flow* f = new FlowMock("F1", nullptr, nullptr);
    
    mod.flows.push_back(f);

    mod.deleteFlow(f);
    assert(mod.flows.empty()); 
}

void UnitModel::unit_Model_run() {
    ModelImpl mod;
    System* s1 = new SystemMock("Origem", 100.0);
    System* s2 = new SystemMock("Destino", 0.0);

    Flow* f = new FlowMock("Fluxo", s1, s2);

    mod.add(s1);
    mod.add(s2);
    mod.add(f);

    mod.run(0, 2);

    assert(std::fabs(s1->getValue() - 98.01) < 0.0001);
    assert(std::fabs(s2->getValue() - 1.99) < 0.0001);

}

void run_unit_tests_Model(void) {
    UnitModel::unit_Model_constructor();
    UnitModel::unit_Model_destructor();
    UnitModel::unit_Model_ParameterizedConstructor();
    UnitModel::unit_Model_CopyConstructor();
    UnitModel::unit_Model_Operator();
    UnitModel::unit_Model_getName();
    UnitModel::unit_Model_setName();
    UnitModel::unit_Model_addSystem();
    UnitModel::unit_Model_addFlow();
    UnitModel::unit_Model_createSystem();
    UnitModel::unit_Model_createFlow();
    UnitModel::unit_Model_deleteSystem();
    UnitModel::unit_Model_deleteFlow();
    UnitModel::unit_Model_run();
    
    std::cout << "OK -> Todos os testes unitarios de Model passaram!" << std::endl;
}
