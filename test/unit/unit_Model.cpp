#include "unit_Model.h"
#include "../../src/modelImpl.h"
#include "../../src/systemImpl.h"
#include "../../src/flowImpl.h"
#include "../../src/exponentialFlow.h"
#include <assert.h>
#include <iostream>
#include <cmath>

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
    ModelImpl* m1 = new ModelImpl("M1");
    SystemImpl* s1 = new SystemImpl("Sistema", 50.0);
    m1->systems.push_back(s1);
    
    // O próprio destrutor de m1 vai liberar s1 de forma segura.
    delete m1;
}

void UnitModel::unit_Model_CopyConstructor() {
    // Para testar cópia rasa sem estourar o destrutor duplo ao fechar o escopo,
    // alocamos o modelo dinamicamente e limpamos seu vetor antes do descarte.
    ModelImpl* m = new ModelImpl("Modelo");
    SystemImpl* s1 = new SystemImpl("Sistema", 50.0);
    ExponentialFlow* f1 = new ExponentialFlow("Flow");
    m->add(s1);
    m->add(f1);
    
    ModelImpl m1(*m);
    assert(m1.name == "Modelo");
    assert(m1.systems.size() == 1);
    assert(m1.flows.size() == 1);
    assert(m1.systems[0] == s1);
    assert(m1.flows[0] == f1);

    // Esvaziamos uma das instâncias para que os destrutores não tentem apagar o mesmo ponteiro
    m1.systems.clear();
    m1.flows.clear();

    delete m; // deleta s1 e f1 de forma controlada
}

void UnitModel::unit_Model_Operator() {
    ModelImpl* m1 = new ModelImpl("Modelo");
    SystemImpl* s1 = new SystemImpl("Sistema", 50.0);
    ExponentialFlow* f1 = new ExponentialFlow("Flow");
    m1->add(s1);
    m1->add(f1);

    ModelImpl m2;
    m2 = *m1;
    assert(m2.name == "Modelo");
    assert(m2.systems.size() == 1);
    assert(m2.flows.size() == 1);
    assert(m2.systems[0] == s1);
    assert(m2.flows[0] == f1);

    m2.systems.clear();
    m2.flows.clear();

    delete m1;
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
    SystemImpl* s = new SystemImpl("Sistema", 50.0); 
    m.add(s);
    assert(m.systems.size() == 1);
    assert(m.systems[0] == s);
    // Sem delete s manual. O destrutor de m limpa ao sair do escopo.
}

void UnitModel::unit_Model_addFlow() {
    ModelImpl m;
    ExponentialFlow* f = new ExponentialFlow("Flow"); 
    m.add(f);
    assert(m.flows.size() == 1);
    assert(m.flows[0] == f);
    // Sem delete f manual.
}

void UnitModel::unit_Model_createModel() {
    size_t pastSize = ModelImpl::models.size();
    Model* m = Model::createModel("Factory Model");
    
    assert(m->getName() == "Factory Model");
    assert(ModelImpl::models.size() == pastSize + 1); 
    
    Model::deleteModel("Factory Model"); 
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
    ModelImpl m("Teste");
    SystemImpl s1("s1", 10);
    SystemImpl s2("s2", 20);
    
    Flow* f = m.createFlow<ExponentialFlow>("FlowExp", &s1, &s2);
    
    assert(f->getName() == "FlowExp");
    assert(f->getSource() == &s1);
    assert(f->getTarget() == &s2);
    assert(m.flows.size() == 1);
    assert(m.flows[0] == f); 
    m.deleteFlow(f);
}

void UnitModel::unit_Model_deleteModel() {
    Model::createModel("Modelo");
    size_t pastSize = ModelImpl::models.size();
    
    bool deletado = Model::deleteModel("Modelo");
    
    assert(deletado == true);
    assert(ModelImpl::models.size() == pastSize - 1);
}

void UnitModel::unit_Model_deleteSystem() {
    ModelImpl m("Teste");
    System* s = m.createSystem("Sistema", 50.0);
    
    bool deletado = m.deleteSystem(s);
    
    assert(deletado == true);
    assert(m.systems.empty()); 
}

void UnitModel::unit_Model_deleteFlow() {
    ModelImpl m("Teste");
    Flow* f = m.createFlow<ExponentialFlow>("FlowExp", nullptr, nullptr);
    
    bool deletado = m.deleteFlow(f);
    
    assert(deletado == true);
    assert(m.flows.empty()); 
}

void UnitModel::unit_Model_run() {
    ModelImpl m("Teste");
    SystemImpl* s1 = new SystemImpl("Source", 100.0);
    SystemImpl* s2 = new SystemImpl("Target", 0.0);
    ExponentialFlow* f = new ExponentialFlow("Flow");

    f->source = s1;
    f->target = s2;
    
    m.add(s1);
    m.add(s2);
    m.add(f);

    m.run(0, 1); 

    assert(s1->value == 99.0);
    assert(s2->value == 1.0);
    // Sem deletes locais manuais aqui, o destrutor de 'm' cuidará do ciclo de descarte da heap.
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
    UnitModel::unit_Model_createModel();
    UnitModel::unit_Model_createSystem();
    UnitModel::unit_Model_createFlow();
    UnitModel::unit_Model_deleteModel();
    UnitModel::unit_Model_deleteSystem();
    UnitModel::unit_Model_deleteFlow();
    UnitModel::unit_Model_run();
    
    std::cout << "OK -> Todos os testes unitarios de Model passaram!" << std::endl;
}
