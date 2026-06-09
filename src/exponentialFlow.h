/**
 * @file exponentialFlow.h
 * @brief Arquivo contendo a classe ExponentialFlow.
 */

#ifndef EXPONENTIALFLOW_H
#define EXPONENTIALFLOW_H

#include "flowImpl.h"

/**
 * @class ExponentialFlow
 * @brief Classe que implementa um fluxo com equação Exponencial.
 * * Herda de FlowImpl e calcula a transferência baseada em 1% (0.01) do valor 
 * armazenado no sistema de origem.
 */
class ExponentialFlow : public FlowImpl {
public:
    /** @brief Construtor padrão */
    ExponentialFlow();
    
    /** @brief Construtor parametrizado que recebe o nome do fluxo */
    ExponentialFlow(std::string name);
    
    /** @brief Destrutor virtual */
    virtual ~ExponentialFlow();
    
    /**
     * @brief Executa a equação exponencial.
     * @return Retorna 0.01 * valor_da_origem.
     */
    double execute() const override; 
};

#endif