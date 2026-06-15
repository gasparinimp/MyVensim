/**
 * @file complexFlow.h
 * @brief Arquivo contendo a classe ComplexFlow para sistemas complexos.
 */

#ifndef COMPLEXFLOW_H
#define COMPLEXFLOW_H

#include "../../src/flowImpl.h"

/**
 * @class ComplexFlow
 * @brief Classe que implementa um fluxo genérico para o Teste Complexo.
 * * Semelhante ao exponencial, calcula a transferência baseada em uma fração 
 * (0.01) do valor do sistema de origem. Usado para malhas de sistemas.
 */
class ComplexFlow : public FlowImpl {
protected:
    /** @brief Construtor padrão */
    ComplexFlow();
    
    /*!
     * @brief This is the parameterized constructor for the ComplexFlow Class.
     * @param name the name of the ComplexFlow.
     * @param source a pointer to the source System.
     * @param target a pointer to the target System.
     */
    ComplexFlow(std::string name, System* source, System* target);
public:
    /** @brief Destrutor virtual */
    virtual ~ComplexFlow();

    /**
     * @brief Executa a equação do fluxo complexo.
     * @return Retorna 0.01 * valor_da_origem.
     */
    virtual double execute() override;
    
    friend class Model;
};

#endif