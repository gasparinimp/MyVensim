#include "modelImpl.h"
#include "systemImpl.h"
std::vector<Model*> ModelImpl::models;
//Construtor vazio
ModelBody::ModelBody() : name("") {}

//Construtor com nome
ModelBody::ModelBody(std::string name) : name(name) {}


// Destrutor
ModelBody::~ModelBody() {
    for (std::vector<System*>::iterator it = systems.begin(); it != systems.end(); ++it) {
        delete *it; 
    }
    for (std::vector<Flow*>::iterator it = flows.begin(); it != flows.end(); ++it) {
        delete *it;
    }
    systems.clear();
    flows.clear();
}

// Get e set de nome
std::string ModelBody::getName() const { 
    return name; 
}

void ModelBody::setName(std::string n) { 
    name = n; 
}

//Metodo para adicionar sistema ao vetor de sistemas

void ModelBody::add(System *s){
    systems.push_back(s);
}

//Metodo para adicionar fluxos do vetor de fluxos
void ModelBody::add(Flow *f){
    flows.push_back(f);
}

//Função run assincrona
void ModelBody::run(int t_initial, int t_end) {
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

// A FÁBRICA DE SISTEMAS
System* ModelBody::createSystem(std::string name, double value) {
    System* s = new SystemImpl(name, value);
    this->add(s);
    return s;
}

void ModelBody::deleteSystem(System* s) {
    auto it = std::find(systems.begin(), systems.end(), s);
    if (it != systems.end()) {
        systems.erase(it); //remove  o sistema do vetor.
    }
}

void ModelBody::deleteFlow(Flow* f) {
    auto it = std::find(flows.begin(), flows.end(), f);
    if (it != flows.end()) {
        flows.erase(it);
    }
}

ModelImpl::ModelImpl() : Handle<ModelBody>(new ModelBody()) {}

ModelImpl::ModelImpl(std::string name) : Handle<ModelBody>(new ModelBody(name)) {}

// Construtor de quando um modelo vai copiar o outro
ModelImpl::ModelImpl(const ModelImpl& mod) : Handle<ModelBody>(mod) {}

// Destrutor
ModelImpl::~ModelImpl() {}

//Sobre carga do operador
ModelImpl& ModelImpl::operator=(const ModelImpl& mod) {
    Handle<ModelBody>::operator=(mod);
    return *this;
}

std::string ModelImpl::getName() const { 
    return pImpl->getName(); 
}

void ModelImpl::setName(std::string n) { 
    pImpl->setName(n); 
}

void ModelImpl::add(System *s){
    pImpl->add(s);
}

void ModelImpl::add(Flow *f){
    pImpl->add(f);
}

void ModelImpl::run(int t_initial, int t_end) {
    pImpl->run(t_initial, t_end);
}

Model* Model::createModel(std::string name) {
    Model* m = new ModelImpl(name);
    ModelImpl::models.push_back(m);
    return m;
}

System* ModelImpl::createSystem(std::string name, double value) {
    return pImpl->createSystem(name, value);
}

void ModelImpl::deleteSystem(System* s) {
    pImpl->deleteSystem(s);
}

void ModelImpl::deleteFlow(Flow* f) {
    pImpl->deleteFlow(f);
}
