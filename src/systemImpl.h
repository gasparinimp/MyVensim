/**
 * @file systemImpl.h
 * @brief Arquivo contendo a implementação concreta de System.
 */

#ifndef SYSTEM_IMPL_H
#define SYSTEM_IMPL_H

#include "system.h"
#include <string>

/**
 * @class SystemImpl
 * @brief Classe concreta que implementa a interface System.
 * * Armazena as propriedades reais do sistema, como o nome e o valor.
 */
class SystemImpl : public System {
protected:
    std::string name; /*!< Nome do sistema */
    double value;     /*!< Valor acumulado no sistema */

    /**
     * @brief Construtor padrão. Inicializa com valores vazios.
     */
    SystemImpl();    

    /**
     * @brief Construtor parametrizado.
     * @param name Nome inicial do sistema.
     * @param value Valor inicial do sistema.
     */
    SystemImpl(const std::string& name, double value); 
    /**
     * @brief Construtor de cópia.
     * @param other Referência para o objeto a ser copiado.
     */
    SystemImpl(const SystemImpl& other); 

    /**
     * @brief Sobrecarga do operador de atribuição.
     * @param other Referência para o objeto base da atribuição.
     * @return Referência para o próprio objeto após a atribuição.
     */
    SystemImpl& operator=(const SystemImpl& other);  
public:

    /**
     * @brief Destrutor virtual de SystemImpl.
     */
    virtual ~SystemImpl();             

    std::string getName() const override;
    double getValue() const override;
    void setValue(double value) override;
    void setName(std::string name) override;
    
    friend class UnitSystem;
    friend class ModelImpl;
};

#endif