#include "system.h"

// Construtor
System::System(const std::string& nome, double valorInicial) {
    this->nome = nome;
    this->valor = valorInicial;
}

// Destrutor
System::~System() {}

// Getters e Setters
std::string System::getNome() const {
    return nome;
}

double System::getValor() const {
    return valor;
}

void System::setValor(double v) {
    this->valor = v;
}