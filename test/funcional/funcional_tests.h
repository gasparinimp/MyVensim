#ifndef FUNCIONAL_TESTS_H
#define FUNCIONAL_TESTS_H

#include "../../src/flow.h"

class ExponencialFlow : public Flow {
public:
    double executa() override {
        if (getSource() != nullptr) {
            return 0.01 * getSource()->getValor();
        }
        return 0.0;
    }
};

class LogisticaFlow : public Flow {
public:
    double executa() override {
        if (getTarget() != nullptr) {
            double p2 = getTarget()->getValor();
            return 0.01 * p2 * (1.0 - (p2 / 70.0));
        }
        return 0.0;
    }
};

// Assinaturas das funções exigidas pelo roteiro
void exponentialFuncionalTest();
void logisticalFuncionalTest();
void complexFuncionalTest();

#endif