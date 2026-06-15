/**
 * @file logisticalFlow.h
 * @brief Arquivo contendo a classe LogisticalFlow.
 */

#ifndef LOGISTICALFLOW_H
#define LOGISTICALFLOW_H

#include "../../src/flowImpl.h"

/**
 * @class LogisticalFlow
 * @brief Classe que implementa um fluxo com equação Logística.
 * * Calcula a transferência baseada na população do sistema de destino e sua 
 * capacidade de saturação sustentada.
 */
class LogisticalFlow : public FlowImpl {
protected:
    /** @brief Construtor padrão */
    LogisticalFlow();
    
    /*!
     * @brief This is the parameterized constructor for the LogisticFlow Class.
     * * @param name the name of the LogisticFlow.
     * @param source pointer to the source System.
     * @param target pointer to the target System.
     */
    LogisticalFlow(std::string name, System* source, System* target);
public:
    /** @brief Destrutor virtual */
    virtual ~LogisticalFlow();
    
    /**
     * @brief Executa a equação logística.
     * @return Retorna 0.01 * valor_destino * (1.0 - (valor_destino / 70.0)).
     */
    double execute() override;
    friend class Model;
};

#endif