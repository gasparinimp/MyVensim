/**
 * @file flowImpl.h
 * @brief Arquivo contendo a implementação concreta da interface Flow.
 */

#ifndef FLOW_IMPL_H
#define FLOW_IMPL_H

#include "flow.h"
#include <string>

/**
 * @class FlowImpl
 * @brief Classe concreta que implementa a interface Flow.
 * * Armazena as propriedades do fluxo, como o nome, e os ponteiros para
 * os sistemas de origem e destino.
 */
class FlowImpl : public Flow {
protected:
    std::string name; /*!< Nome do fluxo */
    System *source;   /*!< Ponteiro para o sistema de origem */
    System *target;   /*!< Ponteiro para o sistema de destino */

public:
    /**
     * @brief Construtor padrão. Inicializa o fluxo vazio.
     */
    FlowImpl();

    /**
     * @brief Construtor de cópia.
     * @param fl Referência para o objeto FlowImpl a ser copiado.
     */
    FlowImpl(const FlowImpl &fl); 

    /**
     * @brief Construtor parametrizado.
     * @param name Nome do fluxo.
     */
    FlowImpl(std::string name);

    /**
     * @brief Destrutor virtual de FlowImpl.
     */
    virtual ~FlowImpl();  

    /**
     * @brief Sobrecarga do operador de atribuição.
     * @param fl Referência para o objeto FlowImpl base.
     * @return Referência para o próprio objeto após atribuição.
     */
    FlowImpl &operator=(const FlowImpl &fl);  

    void setSource(System *s) override;
    void setTarget(System *t) override;
    System *getSource() const override;
    System *getTarget() const override;
    std::string getName() const override;
    void setName(std::string name) override;

    /**
     * @brief Método virtual puro mantido para as classes filhas sobreescreverem.
     * @return double Valor calculado pela equação do fluxo.
     */
    virtual double execute() const override = 0;
    
    friend class UnitFlow;
    friend class UnitModel;
};

#endif