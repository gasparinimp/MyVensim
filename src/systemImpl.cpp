#include "systemImpl.h"

SystemBody::SystemBody() : name(""), value(0.0) {}

SystemBody::SystemBody(const std::string& name, double value) {
    this->name = name;
    this->value = value;
}

std::string SystemBody::getName() const {
    return name;
}

double SystemBody::getValue() const {
    return value;
}

void SystemBody::setValue(double v) {
    this->value = v;
}

void SystemBody::setName(std::string n) {
    this->name = n;
}

//Construtor vazio
SystemImpl::SystemImpl() : Handle<SystemBody>(new SystemBody()) {}

// Construtor normal
SystemImpl::SystemImpl(const std::string& name, double value)
    : Handle<SystemBody>(new SystemBody(name, value)) {}

// Destrutor
SystemImpl::~SystemImpl() {}

// Construtor de copia
SystemImpl::SystemImpl(const SystemImpl& other) : Handle<SystemBody>(other) {}

//Sobrecarga do operador
SystemImpl& SystemImpl::operator=(const SystemImpl& other) {
    Handle<SystemBody>::operator=(other);
    return *this;
}

// Get e set dos atributos
std::string SystemImpl::getName() const {
    return pImpl->getName();
}

double SystemImpl::getValue() const {
    return pImpl->getValue();
}

void SystemImpl::setValue(double v) {
    pImpl->setValue(v);
}

void SystemImpl::setName(std::string n) {
    pImpl->setName(n);
}
