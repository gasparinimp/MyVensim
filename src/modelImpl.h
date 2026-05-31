#ifndef MODEL_IMPL_H
#define MODEL_IMPL_H

#include "model.h"
#include <vector>
#include <string>

//crio a interface
class ModelImpl : public Model {
    //coloco os atributos
protected:
    std::string name;
    std::vector<System*> systems;
    std::vector<Flow*> flows;

public:
    //construtores e sobrecarga
    ModelImpl();
    ModelImpl(std::string name);
    virtual ~ModelImpl();
    ModelImpl(const ModelImpl& mod);
    ModelImpl& operator=(const ModelImpl& mod);

    //sobreescrita dos metodos
    System* criaSistema(std::string nome, double valorInicial) override;
    void run(int t_initial, int t_end) override;
    std::string getName() const override;
    void setName(std::string name) override;

protected:
    void add(Flow* f) override;
};

#endif