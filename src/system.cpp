#include "system.h"

// Construtor Padrão
System::System() : name(""), value(0.0) {}

// Construtor com Parâmetros
System::System(const std::string& name, double value) {
    this->name = name;
    this->value = value;
}

// Destrutor
System::~System() {}

// Construtor de Cópia
System::System(const System& other) {
    this->name = other.name;
    this->value = other.value;
}

// Operador de Atribuição
System& System::operator=(const System& other) {
    if (this == &other) { 
        return *this;
    }
    this->name = other.name;
    this->value = other.value;
    return *this;
}

// Getters e Setters (Implementação correspondente em Inglês)
std::string System::getName() const {
    return name;
}

double System::getValue() const {
    return value;
}

void System::setValue(double v) {
    this->value = v;
}

void System::setName(std::string n) {
    this->name = n;
}