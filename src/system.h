#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>

//Em interfaces, a classe não tem atributos, apenas metodos virtuais puro e o destrutor
class System {
public:
    //Destrutor
    virtual ~System() {};              

    //Get e set dos atributos
    virtual std::string getName() const = 0;
    virtual double getValue() const = 0;
    virtual void setValue(double value) = 0;
    virtual void setName(std::string name) = 0;
};

#endif