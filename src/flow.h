#ifndef FLOW_H
#define FLOW_H

#include <string>
#include "system.h"

class Flow {
public:
    //Destrutor                
    virtual ~Flow() {};   

    //Get e set de origem, destino e nome
    virtual void setSource(System *s) = 0;
    virtual void setTarget(System *t) = 0;
    virtual System *getSource() const = 0;
    virtual System *getTarget() const = 0;
    virtual std::string getName() const = 0;
    virtual void setName(std::string name) = 0;
    virtual double execute() const = 0;
};

#endif