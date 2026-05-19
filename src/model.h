#ifndef MODEL_H
#define MODEL_H

#include <string>
#include <vector>
#include "system.h"
#include "flow.h"

class Model {
private:
    std::string name;
    std::vector<System*> systems;
    std::vector<Flow*> flows;

public:
    // --- FORMA CANÔNICA ORTODOXA ---
    Model();                          
    Model(const Model& mod);         
    virtual ~Model();                 
    Model& operator=(const Model& mod); 

    // Construtor com nome
    Model(std::string name);

    // Métodos de Gerenciamento (Agregação)
    void add(System* s);
    void add(Flow* f);

    // Motor de Simulação
    void run(int t_initial, int t_end);

    // Getters e Setters
    std::string getName() const;
    void setName(std::string name);
};

#endif