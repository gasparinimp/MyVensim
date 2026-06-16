/**
 * @file systemImpl.h
 * @brief Arquivo contendo a implementacao concreta de System com Handle-Body.
 */

#ifndef SYSTEM_IMPL_H
#define SYSTEM_IMPL_H

#include "handleBody.h"
#include "system.h"
#include <string>

/**
 * @class SystemBody
 * @brief Corpo que armazena os dados reais de System.
 *
 * Esta classe representa o Body do padrao Handle-Body. Ela nao e usada
 * diretamente pelo usuario da biblioteca; quem acessa seus dados e o
 * SystemImpl, que funciona como Handle.
 */
class SystemBody : public Body {
private:
    std::string name; /*!< Nome do sistema */
    double value;     /*!< Valor acumulado no sistema */

public:
    /**
     * @brief Construtor padrao. Inicializa nome vazio e valor zero.
     */
    SystemBody();

    /**
     * @brief Construtor parametrizado.
     * @param name Nome inicial do sistema.
     * @param value Valor inicial armazenado no sistema.
     */
    SystemBody(const std::string& name, double value);

    /**
     * @brief Retorna o nome armazenado no Body.
     * @return Nome do sistema.
     */
    std::string getName() const;

    /**
     * @brief Retorna o valor armazenado no Body.
     * @return Valor atual do sistema.
     */
    double getValue() const;

    /**
     * @brief Altera o valor armazenado no Body.
     * @param value Novo valor do sistema.
     */
    void setValue(double value);

    /**
     * @brief Altera o nome armazenado no Body.
     * @param name Novo nome do sistema.
     */
    void setName(std::string name);
};

/**
 * @class SystemImpl
 * @brief Handle concreto que implementa a interface System.
 *
 * O SystemImpl nao guarda diretamente nome e valor. Esses dados ficam em
 * SystemBody, e os metodos publicos apenas delegam as chamadas para o Body.
 */
class SystemImpl : public System, public Handle<SystemBody> {
protected:
    /**
     * @brief Construtor padrao. Cria um SystemBody vazio.
     */
    SystemImpl();

    /**
     * @brief Construtor parametrizado. Cria um SystemBody com nome e valor.
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
     * @brief Destrutor virtual. Libera a referencia ao SystemBody.
     */
    virtual ~SystemImpl();             

    /**
     * @brief Retorna o nome do sistema delegando para o SystemBody.
     * @return Nome do sistema.
     */
    std::string getName() const override;

    /**
     * @brief Retorna o valor do sistema delegando para o SystemBody.
     * @return Valor atual do sistema.
     */
    double getValue() const override;

    /**
     * @brief Altera o valor do sistema delegando para o SystemBody.
     * @param value Novo valor do sistema.
     */
    void setValue(double value) override;

    /**
     * @brief Altera o nome do sistema delegando para o SystemBody.
     * @param name Novo nome do sistema.
     */
    void setName(std::string name) override;
    
    friend class UnitSystem;
    friend class ModelImpl;
    friend class ModelBody;
};

#endif
