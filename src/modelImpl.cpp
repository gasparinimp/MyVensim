#include "modelImpl.h"
#include "systemImpl.h"

//Construtor vazio
ModelImpl::ModelImpl() : name("") {}

//Construtor com nome
ModelImpl::ModelImpl(std::string name) : name(name) {}

// Construtor de quando um modelo vai copiar o outro
ModelImpl::ModelImpl(const ModelImpl& mod) {
    this->name = mod.name;
    this->systems = mod.systems;
    this->flows = mod.flows;
} //melhorar contrutor de copia


// Destrutor
ModelImpl::~ModelImpl() {
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