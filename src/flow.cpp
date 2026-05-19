#include "flow.h"

// Construtor Padrão
Flow::Flow() : name(""), source(nullptr), target(nullptr) {}

// Construtor com Nome
Flow::Flow(std::string name) : name(name), source(nullptr), target(nullptr) {}

// Construtor de Cópia
Flow::Flow(const Flow &fl) {
    this->name = fl.name;
    this->source = fl.source; // Copia o ponteiro de origem
    this->target = fl.target; // Copia o ponteiro de destino
}

// Destrutor
// Como o Flow não é dono dos sistemas (ele apenas aponta para eles), 
// o destrutor NÃO deve dar delete em source ou target. Deixe vazio.
Flow::~Flow() {}

// Operador de Atribuição
Flow &Flow::operator=(const Flow &fl) {
    if (this == &fl) {
        return *this;
    }
    this->name = fl.name;
    this->source = fl.source;
    this->target = fl.target;
    return *this;
}

// ---- GETTERS E SETTERS ----
void Flow::setSource(System *s) {
    source = s;
}

void Flow::setTarget(System *t) {
    target = t;
}

void Flow::setName(std::string n) {
    name = n;
}

System *Flow::getSource() const {
    return source;
}

System *Flow::getTarget() const {
    return target;
}

std::string Flow::getName() const {
    return name;
}