/**
 * @file flowImpl.h
 * @brief Arquivo contendo a implementacao comum de Flow com Handle-Body.
 */

#ifndef FLOW_IMPL_H
#define FLOW_IMPL_H

#include "flow.h"
#include "handleBody.h"
#include "system.h"
#include <string>

/**
 * @class FlowBody
 * @brief Corpo que armazena os dados reais de Flow.
 *
 * Esta classe guarda o estado comum dos fluxos: nome, sistema de origem e
 * sistema de destino. O FlowImpl funciona como Handle e delega as operacoes
 * para este Body.
 */
class FlowBody : public Body {
private:
    std::string name; /*!< Nome do fluxo */
    System *source;   /*!< Ponteiro para o sistema de origem */
    System *target;   /*!< Ponteiro para o sistema de destino */

public:
    /**
     * @brief Construtor padrao. Inicializa o fluxo sem nome, origem ou destino.
     */
    FlowBody();

    /**
     * @brief Construtor parametrizado.
     * @param name Nome inicial do fluxo.
     * @param source Sistema de origem do fluxo.
     * @param target Sistema de destino do fluxo.
     */
    FlowBody(std::string name, System* source, System* target);

    /**
     * @brief Define o sistema de origem armazenado no Body.
     * @param s Ponteiro para o sistema de origem.
     */
    void setSource(System *s);

    /**
     * @brief Define o sistema de destino armazenado no Body.
     * @param t Ponteiro para o sistema de destino.
     */
    void setTarget(System *t);

    /**
     * @brief Retorna o sistema de origem armazenado no Body.
     * @return Ponteiro para o sistema de origem.
     */
    System *getSource() const;

    /**
     * @brief Retorna o sistema de destino armazenado no Body.
     * @return Ponteiro para o sistema de destino.
     */
    System *getTarget() const;

    /**
     * @brief Retorna o nome armazenado no Body.
     * @return Nome do fluxo.
     */
    std::string getName() const;

    /**
     * @brief Altera o nome armazenado no Body.
     * @param name Novo nome do fluxo.
     */
    void setName(std::string name);
};

/**
 * @class FlowImpl
 * @brief Handle que implementa a parte comum da interface Flow.
 *
 * FlowImpl concentra os metodos comuns a todos os fluxos concretos. As classes
 * filhas continuam implementando apenas execute(), enquanto nome, origem e
 * destino ficam encapsulados no FlowBody.
 */
class FlowImpl : public Flow, public Handle<FlowBody> {
protected:
    /**
     * @brief Construtor padrao. Cria um FlowBody vazio.
     */
    FlowImpl();

    /**
     * @brief Construtor parametrizado. Cria um FlowBody com os dados informados.
     * @param name Nome inicial do fluxo.
     * @param source Sistema de origem.
     * @param target Sistema de destino.
     */
    FlowImpl(std::string name, System* source, System* target);
    
    /**
     * @brief Construtor de cópia.
     * @param fl Referência para o objeto FlowImpl a ser copiado.
     */
    FlowImpl(const FlowImpl &fl); 

    /**
     * @brief Sobrecarga do operador de atribuição.
     * @param fl Referência para o objeto FlowImpl base.
     * @return Referência para o próprio objeto após atribuição.
     */
    FlowImpl &operator=(const FlowImpl &fl); 

public:
    /**
     * @brief Destrutor virtual de FlowImpl.
     */
    virtual ~FlowImpl();   

    /**
     * @brief Define a origem delegando para o FlowBody.
     * @param s Ponteiro para o sistema de origem.
     */
    void setSource(System *s) override;

    /**
     * @brief Define o destino delegando para o FlowBody.
     * @param t Ponteiro para o sistema de destino.
     */
    void setTarget(System *t) override;

    /**
     * @brief Retorna a origem delegando para o FlowBody.
     * @return Ponteiro para o sistema de origem.
     */
    System *getSource() const override;

    /**
     * @brief Retorna o destino delegando para o FlowBody.
     * @return Ponteiro para o sistema de destino.
     */
    System *getTarget() const override;

    /**
     * @brief Retorna o nome delegando para o FlowBody.
     * @return Nome do fluxo.
     */
    std::string getName() const override;

    /**
     * @brief Altera o nome delegando para o FlowBody.
     * @param name Novo nome do fluxo.
     */
    void setName(std::string name) override;

    /**
     * @brief Método virtual puro mantido para as classes filhas sobreescreverem.
     * @return double Valor calculado pela equação do fluxo.
     */
    double execute() override = 0;
    
    friend class UnitFlow;
    friend class Model;
};

#endif
