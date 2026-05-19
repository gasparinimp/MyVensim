#ifndef FLOW_H
#define FLOW_H

#include <string>
#include "system.h"

class Flow {
protected:
    std::string name;
    System *source;
    System *target;

public:
    // --- FORMA CANÔNICA EM CLASSE ABSTRATA ---
    Flow();
    Flow(const Flow &fl);                 // Construtor de Cópia
    virtual ~Flow();                      // Destrutor Virtual (obrigatório para polimorfismo)
    Flow &operator=(const Flow &fl);      // Operador de Atribuição

    // Construtor com nome
    Flow(std::string name);

    // Getters e Setters dos Relacionamentos
    void setSource(System *s);
    void setTarget(System *t);
    System *getSource() const;
    System *getTarget() const;
    
    std::string getName() const;
    void setName(std::string name);

    // Método Virtual Puro (Contrato para as subclasses)
    virtual double execute() const = 0;
};

#endif