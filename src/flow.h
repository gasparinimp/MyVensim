/**
 * @file flow.h
 * @brief Arquivo contendo a interface Flow.
 * * Define o contrato para os Fluxos dentro do simulador, responsáveis por 
 * transferir valores de um Sistema (Origem) para outro (Destino).
 */

#ifndef FLOW_H
#define FLOW_H

#include <string>
class System;

/**
 * @class Flow
 * @brief Interface que representa um Fluxo de transferência no simulador.
 */
class Flow {
public:
    /**
     * @brief Destrutor virtual da interface Flow.
     */
    virtual ~Flow() {};   

    /**
     * @brief Define o sistema de origem do fluxo.
     * @param s Ponteiro para o sistema de origem (System*).
     */
    virtual void setSource(System *s) = 0;

    /**
     * @brief Define o sistema de destino do fluxo.
     * @param t Ponteiro para o sistema de destino (System*).
     */
    virtual void setTarget(System *t) = 0;

    /**
     * @brief Obtém o sistema de origem atual.
     * @return Ponteiro para o sistema de origem (System*).
     */
    virtual System *getSource() const = 0;

    /**
     * @brief Obtém o sistema de destino atual.
     * @return Ponteiro para o sistema de destino (System*).
     */
    virtual System *getTarget() const = 0;

    /**
     * @brief Obtém o nome do fluxo.
     * @return std::string contendo o nome do fluxo.
     */
    virtual std::string getName() const = 0;

    /**
     * @brief Define um novo nome para o fluxo.
     * @param name Novo nome (std::string) do fluxo.
     */
    virtual void setName(std::string name) = 0;

    /**
     * @brief Método virtual puro que executa a equação matemática do fluxo.
     * @return double correspondente ao valor calculado a ser transferido.
     */
    virtual double execute() = 0;
};

#endif