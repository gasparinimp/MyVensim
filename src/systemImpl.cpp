#include "systemImpl.h"

//Construtor vazio
SystemImpl::SystemImpl() : name(""), value(0.0) {}

// Construtor normal
SystemImpl::SystemImpl(const std::string& name, double value) {
    this->name = name;
    this->value = value;
}

// Destrutor
SystemImpl::~SystemImpl() {}

// Construtor de copia
SystemImpl::SystemImpl(const SystemImpl& other) {
    this->name = other.name;
    this->value = other.value;
}

//Sobrecarga do operador
SystemImpl& SystemImpl::operator=(const SystemImpl& other) {
    if (this == &other) { 
        return *this;
    }
    this->name = other.name;
    this->value = other.value;
    return *this;
}

// Get e set dos atributos
std::string SystemImpl::getName() const {
    return name;
}

double SystemImpl::getValue() const {
    return value;
}

void SystemImpl::setValue(double v) {
    this->value = v;
}

void SystemImpl::setName(std::string n) {
    this->name = n;
}