/**
 * @file complexFlow.h
 * @brief Arquivo contendo a classe ComplexFlow para sistemas complexos.
 */

#ifndef COMPLEXFLOW_H
#define COMPLEXFLOW_H

#include "flowImpl.h"

/**
 * @class ComplexFlow
 * @brief Classe que implementa um fluxo genérico para o Teste Complexo.
 * * Semelhante ao exponencial, calcula a transferência baseada em uma fração 
 * (0.01) do valor do sistema de origem. Usado para malhas de sistemas.
 */
class ComplexFlow : public FlowImpl {
public:
    /** @brief Construtor padrão */
    ComplexFlow();
    
    /** @brief Construtor parametrizado com nome */
    ComplexFlow(std::string name);
    
    /** @brief Destrutor virtual */
    virtual ~ComplexFlow();
    
    /**
     * @brief Executa a equação do fluxo complexo.
     * @return Retorna 0.01 * valor_da_origem.
     */
    double execute() const override;
};

#endif