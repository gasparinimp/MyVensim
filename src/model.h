#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include <string>
#include "system.h"
#include "flow.h"

class Model {
private:
    int tempo;
    std::vector<System*> sistemas;
    std::vector<Flow*> fluxos;

public:
    Model();
    virtual ~Model();

    System* criaSistema(const std::string& nome, double valorInicial);
    
    // Factory usando templates para instanciar qualquer subclasse de Flow
    template <typename T>
    Flow* criaFluxo(System* source, System* target) {
        Flow* f = new T();
        f->setSource(source);
        f->setTarget(target);
        fluxos.push_back(f);
        return f;
    }

    void run(int t_inicial, int t_final);
};

#endif