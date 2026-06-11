#include "modelImpl.h"
#include "systemImpl.h"

std::vector<Model*> ModelImpl::models;

//Construtor vazio
ModelImpl::ModelImpl() : name("") {}

//Construtor com nome
ModelImpl::ModelImpl(std::string name) : name(name) {}

// Construtor de quando um modelo vai copiar o outro
ModelImpl::ModelImpl(const ModelImpl& mod) {
    this->name = mod.name;
    this->systems = mod.systems;
    this->flows = mod.flows;
}


// Destrutor
ModelImpl::~ModelImpl() {
    for (std::vector<System*>::iterator it = systems.begin(); it != systems.end(); ++it) {
        delete *it; 
    }
    for (std::vector<Flow*>::iterator it = flows.begin(); it != flows.end(); ++it) {
        delete *it;
    }
    systems.clear();
    flows.clear();
}

//Sobre carga do operador
ModelImpl& ModelImpl::operator=(const ModelImpl& mod) {
    if (this == &mod) {
        return *this;
    }
    this->name = mod.name;
    this->systems = mod.systems;
    this->flows = mod.flows;
    return *this;
}

// Get e set de nome
std::string ModelImpl::getName() const { 
    return name; 
}

void ModelImpl::setName(std::string n) { 
    name = n; 
}

//Metodo para adicionar sistema ao vetor de sistemas

void ModelImpl::add(System *s){
    systems.push_back(s);
}

//Metodo para adicionar fluxos do vetor de fluxos
void ModelImpl::add(Flow *f){
    flows.push_back(f);
}

//Função run assincrona
void ModelImpl::run(int t_initial, int t_end) {
    //Enquanto o tempo nao acabar
    for (int tempo = t_initial; tempo < t_end; ++tempo) {
        //Crio um vetor de resultados
        std::vector<double> results;
        
        //Executo os fluxos e coloco o resultado no vetor de resultados
        for (size_t i = 0; i < flows.size(); ++i) {
            results.push_back(flows[i]->execute());
        }
        
        //Pego os sistemas de origem e destino dos fluxos
        for (size_t i = 0; i < flows.size(); ++i) {
            System* origem = flows[i]->getSource();
            System* destino = flows[i]->getTarget();
            //Se não forem nulos, atualizo os valores ao mesmo tempo para não ter inconsistência
            if (origem != nullptr) {
                origem->setValue(origem->getValue() - results[i]);
            }
            if (destino != nullptr) {
                destino->setValue(destino->getValue() + results[i]);
            }
        }
    }
}

Model* Model::createModel(std::string name) {
    Model* m = new ModelImpl(name);
    ModelImpl::models.push_back(m);
    return m;
}

// A FÁBRICA DE SISTEMAS
System* ModelImpl::createSystem(std::string name, double value) {
    System* s = new SystemImpl(name, value);
    this->add(s);
    return s;
}

bool Model::deleteModel(std::string name) {
    for (auto it = ModelImpl::models.begin(); it != ModelImpl::models.end(); ++it) {
        if ((*it)->getName() == name) {
            Model* m = *it;
            ModelImpl::models.erase(it);
            delete m; 
            return true;
        }
    }
    return false;
}

bool ModelImpl::deleteSystem(System* s) {
    for (auto it = systems.begin(); it != systems.end(); ++it) {
        if (*it == s) {
            systems.erase(it);
            delete s;
            return true;
        }
    }
    return false;
}

bool ModelImpl::deleteFlow(Flow* f) {
    for (auto it = flows.begin(); it != flows.end(); ++it) {
        if (*it == f) {
            flows.erase(it);
            delete f;
            return true;
        }
    }
    return false;
}