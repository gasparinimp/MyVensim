#ifndef MODEL_H
#define MODEL_H

#include <string>
#include "system.h"
#include "flow.h"

class Model {
public:
    virtual ~Model() {};

    // metodos de criar sistema  eo run
    virtual System* criaSistema(std::string nome, double valorInicial) = 0;
    virtual void run(int t_initial, int t_end) = 0;
    
    // get e set de nome
    virtual std::string getName() const = 0;
    virtual void setName(std::string name) = 0;

    // A Factory de Fluxos fica na interface por ser um Template
    template <typename T>
    Flow* criaFluxo(std::string nome, System* origem, System* destino) {
        //Crio um fluxo
        Flow* f = new T(nome);
        //coloco origem e destino
        f->setSource(origem);
        f->setTarget(destino);
        //adiciono o fluxo no meu vetor de fluxos
        add(f);
        return f;
    }

protected:
    virtual void add(Flow* f) = 0;
};

#endif