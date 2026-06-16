/**
 * @file modelImpl.h
 * @brief Arquivo contendo a implementacao concreta da interface Model com Handle-Body.
 */

#ifndef MODEL_IMPL_H
#define MODEL_IMPL_H

#include "handleBody.h"
#include "model.h"
#include "system.h"
#include "flow.h"
#include <vector>
#include <string>
#include <algorithm>

/**
 * @class ModelBody
 * @brief Corpo que armazena os dados reais de Model.
 *
 * Esta classe guarda o estado do modelo: nome, sistemas e fluxos. O ModelImpl
 * e o Handle responsavel por expor a interface publica e delegar as chamadas
 * para este Body.
 */
class ModelBody : public Body {
private:
    std::string name;                 /*!< Nome do modelo */
    std::vector<System*> systems;     /*!< Vetor contendo os ponteiros para os Sistemas */
    std::vector<Flow*> flows;         /*!< Vetor contendo os ponteiros para os Fluxos */

public:
    /**
     * @brief Construtor padrao. Inicializa o modelo sem nome.
     */
    ModelBody();

    /**
     * @brief Construtor parametrizado.
     * @param name Nome inicial do modelo.
     */
    ModelBody(std::string name);

    /**
     * @brief Destrutor. Libera os sistemas e fluxos armazenados no modelo.
     */
    virtual ~ModelBody();

    /**
     * @brief Adiciona um sistema ao vetor interno do Body.
     * @param s Ponteiro para o sistema que sera armazenado.
     */
    void add(System *s);

    /**
     * @brief Adiciona um fluxo ao vetor interno do Body.
     * @param f Ponteiro para o fluxo que sera armazenado.
     */
    void add(Flow *f);

    /**
     * @brief Executa a simulacao entre dois instantes.
     * @param t_initial Tempo inicial da simulacao.
     * @param t_end Tempo final da simulacao.
     */
    void run(int t_initial, int t_end);

    /**
     * @brief Retorna o nome armazenado no Body.
     * @return Nome do modelo.
     */
    std::string getName() const;

    /**
     * @brief Altera o nome armazenado no Body.
     * @param name Novo nome do modelo.
     */
    void setName(std::string name);

    /**
     * @brief Cria um sistema e o adiciona ao modelo.
     * @param name Nome do sistema.
     * @param value Valor inicial do sistema.
     * @return Ponteiro para o sistema criado.
     */
    System* createSystem(std::string name, double value);

    /**
     * @brief Remove um sistema do vetor interno.
     * @param s Ponteiro para o sistema que sera removido.
     */
    void deleteSystem(System* s);

    /**
     * @brief Remove um fluxo do vetor interno.
     * @param f Ponteiro para o fluxo que sera removido.
     */
    void deleteFlow(Flow* f);

    friend class UnitModel;
};

/**
 * @class ModelImpl
 * @brief Handle concreto que implementa a interface Model.
 *
 * ModelImpl nao guarda diretamente os vetores de sistemas e fluxos. Ele herda
 * de Handle<ModelBody> e delega as operacoes para o ModelBody associado.
 */
class ModelImpl : public Model, public Handle<ModelBody> {
protected:
    static std::vector<Model*> models; 

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

public:
    /**
     * @brief Destrutor virtual. Libera a referencia ao ModelBody.
     */
    virtual ~ModelImpl();

    
    /**
     * @brief Adiciona um sistema delegando para o ModelBody.
     * @param s Ponteiro para o sistema que sera armazenado.
     */
    void add(System *s) override;

    /**
     * @brief Adiciona um fluxo delegando para o ModelBody.
     * @param f Ponteiro para o fluxo que sera armazenado.
     */
    void add(Flow *f) override;

    /**
     * @brief Executa a simulacao delegando para o ModelBody.
     * @param t_initial Tempo inicial da simulacao.
     * @param t_end Tempo final da simulacao.
     */
    void run(int t_initial, int t_end) override;

    /**
     * @brief Retorna o nome do modelo delegando para o ModelBody.
     * @return Nome do modelo.
     */
    std::string getName() const override;

    /**
     * @brief Altera o nome do modelo delegando para o ModelBody.
     * @param name Novo nome do modelo.
     */
    void setName(std::string name) override;

    /**
     * @brief Cria um sistema delegando para o ModelBody.
     * @param name Nome do sistema.
     * @param value Valor inicial do sistema.
     * @return Ponteiro para o sistema criado.
     */
    System* createSystem(std::string name, double value) override;

    /**
     * @brief Remove um sistema delegando para o ModelBody.
     * @param s Ponteiro para o sistema que sera removido.
     */
    void deleteSystem(System* s) override;

    /**
     * @brief Remove um fluxo delegando para o ModelBody.
     * @param f Ponteiro para o fluxo que sera removido.
     */
    void deleteFlow(Flow* f) override;
    
    friend class Model;
    friend class UnitModel;
};

#endif
