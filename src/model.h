/**
 * @file model.h
 * @brief Arquivo contendo a interface Model.
 * * Define o contrato para o Modelo, que atua como o orquestrador principal,
 * armazenando e gerenciando todos os Sistemas e Fluxos da simulação.
 */

#ifndef MODEL_H
#define MODEL_H

#include <string>
#include "system.h"
#include "flow.h"

/**
 * @class Model
 * @brief Interface que representa o Modelo de simulação.
 */
class Model {
public:
    /**
     * @brief Destrutor virtual da interface Model.
     */
    virtual ~Model() {};

    /**
     * @brief Adiciona um Sistema ao modelo.
     * @param s Ponteiro para o sistema (System*) a ser adicionado.
     */
    virtual void add(System *s) = 0;

    /**
     * @brief Adiciona um Fluxo ao modelo.
     * @param f Ponteiro para o fluxo (Flow*) a ser adicionado.
     */
    virtual void add(Flow *f) = 0;

    /**
     * @brief Executa a simulação do modelo dentro de um intervalo de tempo.
     * @param t_initial Tempo inicial da simulação.
     * @param t_end Tempo final da simulação.
     */
    virtual void run(int t_initial, int t_end) = 0;
    
    /**
     * @brief Obtém o nome do modelo.
     * @return std::string contendo o nome do modelo.
     */
    virtual std::string getName() const = 0;

    /**
     * @brief Define um novo nome para o modelo.
     * @param name Novo nome (std::string) do modelo.
     */
    virtual void setName(std::string name) = 0;
};

#endif