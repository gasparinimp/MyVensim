#include "flowImpl.h"

FlowBody::FlowBody() : name(""), source(nullptr), target(nullptr) {}

FlowBody::FlowBody(std::string name, System* source, System* target): name(name), 
    source(source), target(target){}

//Get e set de origem, destino e nome
void FlowBody::setSource(System *s) {
    source = s;
}

void FlowBody::setTarget(System *t) {
    target = t;
}

void FlowBody::setName(std::string n) {
    name = n;
}

System *FlowBody::getSource() const {
    return source;
}

System *FlowBody::getTarget() const {
    return target;
}

std::string FlowBody::getName() const {
    return name;
}

// Construtor padrão em que inicializa tudo "vazio"
FlowImpl::FlowImpl() : Handle<FlowBody>(new FlowBody()) {}

// Construtor apenas com o nome
FlowImpl::FlowImpl(std::string name, System* source, System* target)
    : Handle<FlowBody>(new FlowBody(name, source, target)) {}

// Construtor de quando um fluxo vai copiar o outro
FlowImpl::FlowImpl(const FlowImpl &fl) : Handle<FlowBody>(fl) {}

// Destrutor
FlowImpl::~FlowImpl() {}

// Sobrecarga do operador igual, para permitir recebimento direto
FlowImpl &FlowImpl::operator=(const FlowImpl &fl) {
    Handle<FlowBody>::operator=(fl);
    return *this;
}

void FlowImpl::setSource(System *s) {
    pImpl->setSource(s);
}

void FlowImpl::setTarget(System *t) {
    pImpl->setTarget(t);
}

void FlowImpl::setName(std::string n) {
    pImpl->setName(n);
}

System *FlowImpl::getSource() const {
    return pImpl->getSource();
}

System *FlowImpl::getTarget() const {
    return pImpl->getTarget();
}

std::string FlowImpl::getName() const {
    return pImpl->getName();
}
