#include "unit_System.h"
#include "../../src/systemImpl.h" // Incluimos a implementacao para poder instanciar
#include <assert.h>
#include <iostream>

//teste dos construtores
void unit_System_constructor(void) {
    // Teste do construtor vazio
    System* s1 = new SystemImpl();
    assert(s1->getName() == "");
    assert(s1->getValue() == 0.0);
    delete s1;

    // Teste do construtor com parametros
    System* s2 = new SystemImpl("S2", 10.5);
    assert(s2->getName() == "S2");
    assert(s2->getValue() == 10.5);
    delete s2;
}

//teste do destrutor
void unit_System_destructor(void) {
    System* s1 = new SystemImpl("S1", 0.0);
    delete s1;
}

//teste do get e set nome
void unit_System_getName(void) {
    System* s1 = new SystemImpl("Sistema A", 100.0);
    assert(s1->getName() == "Sistema A");
    delete s1;
}

void unit_System_setName(void) {
    System* s1 = new SystemImpl();
    s1->setName("Novo Nome");
    assert(s1->getName() == "Novo Nome");
    delete s1;
}

//teste do get e set value
void unit_System_getValue(void) {
    System* s1 = new SystemImpl("Sistema B", 55.5);
    assert(s1->getValue() == 55.5);
    delete s1;
}

void unit_System_setValue(void) {
    System* s1 = new SystemImpl();
    s1->setValue(20.0);
    assert(s1->getValue() == 20.0);
    delete s1;
}

//roda todos os testes do system
void run_unit_tests_System(void) {
    unit_System_constructor();
    unit_System_destructor();
    unit_System_getName();
    unit_System_setName();
    unit_System_getValue();
    unit_System_setValue();
    std::cout << "OK -> Todos os testes unitarios de System passaram!" << std::endl;
}