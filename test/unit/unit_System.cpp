#include "unit_System.h"
#include "../../src/systemImpl.h" // Incluimos a implementacao para poder instanciar
#include <assert.h>
#include <iostream>

//teste dos construtores
void UnitSystem::unit_System_constructor(void) {
    // Teste do construtor vazio
    SystemImpl s1;
    assert(s1.getName() == "");
    assert(s1.getValue() == 0.0);
    assert(s1.pImpl->getRefCount() == 1);
}

void UnitSystem::unit_System_ParameterizedConstructor() {
    SystemImpl s1("Sistema", 50.0);
    assert(s1.getName() == "Sistema");
    assert(s1.getValue() == 50.0);
}

void UnitSystem::unit_System_CopyConstructor() {
    SystemImpl s1("Sistema", 50.0);
    SystemImpl s2(s1);
    assert(s2.getName() == "Sistema");
    assert(s2.getValue() == 50.0);
    assert(s1.pImpl == s2.pImpl);
    assert(s1.pImpl->getRefCount() == 2);

    s1.setName("Sistema Alterado");
    assert(s2.getName() == "Sistema Alterado");
}

void UnitSystem::unit_System_Operator() {
    SystemImpl s1("Sistema", 50.0);
    SystemImpl s2;
    s2 = s1;
    assert(s2.getName() == "Sistema");
    assert(s2.getValue() == 50.0);
    assert(s1.pImpl == s2.pImpl);
    assert(s1.pImpl->getRefCount() == 2);
}

//teste do destrutor
void UnitSystem::unit_System_destructor(void) {
    System* s1 = new SystemImpl("S1", 0.0);
    delete s1;
}

//teste do get e set nome
void UnitSystem::unit_System_getName(void) {
    SystemImpl s1("Sistema A", 100.0);
    assert(s1.getName() == "Sistema A");
}

void UnitSystem::unit_System_setName(void) {
    SystemImpl s1;
    s1.setName("Novo Nome");
    assert(s1.getName() == "Novo Nome");
}

//teste do get e set value
void UnitSystem::unit_System_getValue(void) {
    SystemImpl s1("Sistema B", 55.5);
    assert(s1.getValue() == 55.5);
}

void UnitSystem::unit_System_setValue(void) {
    SystemImpl s1;
    s1.setValue(20.0);
    assert(s1.getValue() == 20.0);
}

void UnitSystem::unit_System_HandleBody(void) {
    SystemImpl s3("tiago", 7.0);
    SystemImpl s4("antonio", 8.0);

    assert(s3.pImpl != s4.pImpl);

    s3 = s4;

    assert(s3.pImpl == s4.pImpl);
    assert(s3.pImpl->getRefCount() == 2);
    assert(s3.getName() == "antonio");
    assert(s3.getValue() == 8.0);

    s3 = s3;

    assert(s3.pImpl == s4.pImpl);
    assert(s3.pImpl->getRefCount() == 2);
}

//roda todos os testes do system
void run_unit_tests_System(void) {
    UnitSystem::unit_System_constructor();
    UnitSystem::unit_System_ParameterizedConstructor();
    UnitSystem::unit_System_CopyConstructor();
    UnitSystem::unit_System_Operator();
    UnitSystem::unit_System_destructor();
    UnitSystem::unit_System_getName();
    UnitSystem::unit_System_setName();
    UnitSystem::unit_System_getValue();
    UnitSystem::unit_System_setValue();
    UnitSystem::unit_System_HandleBody();
    std::cout << "OK -> Todos os testes unitarios de System passaram!" << std::endl;
}
