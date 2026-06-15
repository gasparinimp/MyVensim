/**
 * @file exponentialFlow.h
 * @brief Arquivo contendo a classe ExponentialFlow.
 */

#ifndef EXPONENTIALFLOW_H
#define EXPONENTIALFLOW_H

#include  "../../src/flowImpl.h"

/**
 * @class ExponentialFlow
 * @brief Classe que implementa um fluxo com equação Exponencial.
 * * Herda de FlowImpl e calcula a transferência baseada em 1% (0.01) do valor 
 * armazenado no sistema de origem.
 */
class ExponentialFlow : public FlowImpl {
protected:
    /** @brief Construtor padrão */
    ExponentialFlow();
    
    /*!
     * @brief This is the parameterized constructor for the ExponentialFlow Class.
     * * @param name the name of the ExponentialFlow.
     * @param source a pointer to the source System.
     * @param target a pointer to the target System.
     */
    ExponentialFlow(std::string name, System* source, System* target);
public:
    /** @brief Destrutor virtual */
    virtual ~ExponentialFlow();
    
    /**
     * @brief Executa a equação exponencial.
     * @return Retorna 0.01 * valor_da_origem.
     */
    double execute() override; 
    friend class Model;
};

#endif