#ifndef FUNCIONAL_TESTS_H
#define FUNCIONAL_TESTS_H

#include "../../src/flow.h"
#include "../../src/system.h"

// Subclasse Exponencial adaptada
class ExponencialFlow : public Flow {
public:
    // Herda os construtores da forma canônica de Flow
    using Flow::Flow;

    double execute() const override {
        if (getSource() != nullptr) {
            return 0.01 * getSource()->getValue(); // getValor() virou getValue()
        }
        return 0.0;
    }
};

// Subclasse Logística adaptada
class LogisticaFlow : public Flow {
public:
    using Flow::Flow;

    double execute() const override {
        if (getTarget() != nullptr) {
            double p2 = getTarget()->getValue();
            return 0.01 * p2 * (1.0 - (p2 / 70.0));
        }
        return 0.0;
    }
};

// Assinaturas das funções de teste
void exponentialFuncionalTest();
void logisticalFuncionalTest();
void complexFuncionalTest();

#endif