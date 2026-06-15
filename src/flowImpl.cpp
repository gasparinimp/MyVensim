#include "flowImpl.h"

// Construtor padrão em que inicializa tudo "vazio"
FlowImpl::FlowImpl() : name(""), source(nullptr), target(nullptr) {}

// Construtor apenas com o nome
FlowImpl::FlowImpl(std::string name, System* source, System* target): name(name), 
    source(source), target(target){}

// Construtor de quando um fluxo vai copiar o outro
FlowImpl::FlowImpl(const FlowImpl &fl) {
    this->name = fl.name;
    this->source = fl.source; 
    this->target = fl.target;
}

// Destrutor
//Como nada é criado nele, fica vazio
FlowImpl::~FlowImpl() {}

// Sobrecarga do operador igual, para permitir recebimento direto
FlowImpl &FlowImpl::operator=(const FlowImpl &fl) {
    //Se o objeto for o mesmo que o atual, so retorna ele mesmo
    if (this == &fl) {
        return *this;
    }
    //Se for diferente, faço a atribuição
    this->name = fl.name;
    this->source = fl.source;
    this->target = fl.target;
    return *this;
}

//Get e set de origem, destino e nome
void FlowImpl::setSource(System *s) {
    source = s;
}

void FlowImpl::setTarget(System *t) {
    target = t;
}

void FlowImpl::setName(std::string n) {
    name = n;
}

System *FlowImpl::getSource() const {
    return source;
}

System *FlowImpl::getTarget() const {
    return target;
}

std::string FlowImpl::getName() const {
    return name;
}