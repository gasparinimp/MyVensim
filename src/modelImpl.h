/**
 * @file modelImpl.h
 * @brief Arquivo contendo a implementação concreta da interface Model.
 */

#ifndef MODEL_IMPL_H
#define MODEL_IMPL_H

#include "model.h"
#include <vector>
#include <string>

/**
 * @class ModelImpl
 * @brief Classe concreta que implementa a interface Model.
 * * Atua como o orquestrador da simulação, gerenciando as coleções (vetores)
 * de sistemas e fluxos que compõem o modelo.
 */
class ModelImpl : public Model {
protected:
    std::string name;                 /*!< Nome do modelo */
    std::vector<System*> systems;     /*!< Vetor contendo os ponteiros para os Sistemas */
    std::vector<Flow*> flows;         /*!< Vetor contendo os ponteiros para os Fluxos */

public:
    /**
     * @brief Construtor padrão. Inicializa um modelo vazio.
     */
    ModelImpl();

    /**
     * @brief Construtor parametrizado.
     * @param name Nome do modelo.
     */
    ModelImpl(std::string name);

    /**
     * @brief Destrutor virtual. Limpa os vetores de agregação.
     */
    virtual ~ModelImpl();

    /**
     * @brief Construtor de cópia.
     * @param mod Referência para o objeto ModelImpl a ser copiado.
     */
    ModelImpl(const ModelImpl& mod);

    /**
     * @brief Sobrecarga do operador de atribuição.
     * @param mod Referência para o objeto ModelImpl base.
     * @return Referência para o próprio objeto.
     */
    ModelImpl& operator=(const ModelImpl& mod);

    void add(System *s) override;
    void add(Flow *f) override;
    void run(int t_initial, int t_end) override;
    std::string getName() const override;
    void setName(std::string name) override;
    
    friend class UnitModel;
};

#endif