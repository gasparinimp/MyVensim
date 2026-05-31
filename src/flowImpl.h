#ifndef FLOW_IMPL_H
#define FLOW_IMPL_H

#include "flow.h"
#include <string>

//criando a interface
class FlowImpl : public Flow {
//a interface que possui os atributos 
protected:
    std::string name;
    System *source;
    System *target;

public:
    //construtor vazio
    FlowImpl();
    //construtor de copia
    FlowImpl(const FlowImpl &fl); 
    //construtor com nome
    FlowImpl(std::string name);
    //destrutor
    virtual ~FlowImpl();  
    //sobrecarga
    FlowImpl &operator=(const FlowImpl &fl);  

    //metodos que vão ser sobreescritos
    void setSource(System *s) override;
    void setTarget(System *t) override;
    System *getSource() const override;
    System *getTarget() const override;
    std::string getName() const override;
    void setName(std::string name) override;
    //continua sendo puro pois ele vai ser sobreescrito 
    virtual double execute() const override = 0;
};

#endif