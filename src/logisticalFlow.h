/**
 * @file logisticalFlow.h
 * @brief Arquivo contendo a classe LogisticalFlow.
 */

#ifndef LOGISTICALFLOW_H
#define LOGISTICALFLOW_H

#include "flowImpl.h"

/**
 * @class LogisticalFlow
 * @brief Classe que implementa um fluxo com equação Logística.
 * * Calcula a transferência baseada na população do sistema de destino e sua 
 * capacidade de saturação sustentada.
 */
class LogisticalFlow : public FlowImpl {
public:
    /** @brief Construtor padrão */
    LogisticalFlow();
    
    /** @brief Construtor parametrizado com nome */
    LogisticalFlow(std::string name);
    
    /** @brief Destrutor virtual */
    virtual ~LogisticalFlow();
    
    /**
     * @brief Executa a equação logística.
     * @return Retorna 0.01 * valor_destino * (1.0 - (valor_destino / 70.0)).
     */
    double execute() const override;
};

#endif