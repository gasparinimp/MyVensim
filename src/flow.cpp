#include "flow.h"

// Construtor padrão da classe Flow
Flow::Flow(const std::string& nome) {
    this->nome = nome;
    this->source = nullptr;
    this->target = nullptr;
}

// Destrutor
Flow::~Flow() {}

// Getters e Setters dos Relacionamentos (source e target)
System* Flow::getSource() const {
    return source;
}

System* Flow::getTarget() const {
    return target;
}

void Flow::setSource(System* s) {
    this->source = s;
}

void Flow::setTarget(System* t) {
    this->target = t;
}