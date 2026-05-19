#include "model.h"

// Construtor Padrão
Model::Model() : name("") {}

// Construtor com Nome
Model::Model(std::string name) : name(name) {}

// Construtor de Cópia (Cópia Rasa das estruturas dos seus colegas)
Model::Model(const Model& mod) {
    this->name = mod.name;
    this->systems = mod.systems;
    this->flows = mod.flows;
}

// Destrutor
// Como o modelo atual de vocês usa agregação (.add), os objetos são criados fora.
// Se o professor exigir que o Model limpe a memória, você adicionaria os 'delete' aqui.
Model::~Model() {}

// Operador de Atribuição
Model& Model::operator=(const Model& mod) {
    if (this == &mod) {
        return *this;
    }
    this->name = mod.name;
    this->systems = mod.systems;
    this->flows = mod.flows;
    return *this;
}

// Getters e Setters
std::string Model::getName() const { 
    return name; 
}

void Model::setName(std::string n) { 
    name = n; 
}

// Métodos para adicionar elementos ao modelo
void Model::add(System* s) {
    systems.push_back(s);
}

void Model::add(Flow* f) {
    flows.push_back(f);
}

// Função Run integrada com os métodos em inglês (getValue, setValue, execute)
void Model::run(int t_initial, int t_end) {
    for (int tempo = t_initial; tempo < t_end; ++tempo) {
        std::vector<double> results;
        
        // CORREÇÃO AQUI: Trocamos o iterador por um loop indexado comum
        for (size_t i = 0; i < flows.size(); ++i) {
            results.push_back(flows[i]->execute());
        }
        
        // O resto do seu código continua exatamente igual:
        for (size_t i = 0; i < flows.size(); ++i) {
            System* origem = flows[i]->getSource();
            System* destino = flows[i]->getTarget();
            if (origem != nullptr) {
                origem->setValue(origem->getValue() - results[i]);
            }
            if (destino != nullptr) {
                destino->setValue(destino->getValue() + results[i]);
            }
        }
    }
}