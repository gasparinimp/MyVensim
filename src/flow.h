#ifndef FLOW_H
#define FLOW_H

#include <string>
#include "system.h"

class Flow {
private:
    std::string nome;
    System* source;
    System* target;

public:
    Flow(const std::string& nome = "");
    virtual ~Flow();

    System* getSource() const;
    System* getTarget() const;
    void setSource(System* s);
    void setTarget(System* t);
    
    // Método virtual puro - Espaço em branco para o usuário preencher
    virtual double executa() = 0; 
};

#endif