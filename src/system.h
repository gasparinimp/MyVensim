/**
 * @file system.h
 * @brief Arquivo contendo a interface System.
 * * Define o contrato para os Sistemas dentro do simulador, que representam 
 * os estoques ou nós onde a energia/massa se acumula.
 */

#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>

/**
 * @class System
 * @brief Interface que representa um Sistema no simulador.
 * * Na interface, a classe não possui atributos, apenas métodos virtuais puros 
 * e o destrutor virtual, servindo como base para as classes concretas.
 */
class System {
public:
    /**
     * @brief Destrutor virtual da interface System.
     */
    virtual ~System() {};              

    /**
     * @brief Obtém o nome do sistema.
     * @return std::string contendo o nome do sistema.
     */
    virtual std::string getName() const = 0;

    /**
     * @brief Obtém o valor atual armazenado no sistema.
     * @return double representando o valor atual do sistema.
     */
    virtual double getValue() const = 0;

    /**
     * @brief Define um novo valor para o sistema.
     * @param value Novo valor (double) a ser armazenado.
     */
    virtual void setValue(double value) = 0;

    /**
     * @brief Define um novo nome para o sistema.
     * @param name Novo nome (std::string) do sistema.
     */
    virtual void setName(std::string name) = 0;
};

#endif