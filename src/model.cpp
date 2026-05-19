#include "model.h"

Model::Model() {
    tempo = 0;
}

Model::~Model() {
    // Desaloca todos os sistemas criados pela fábrica
    for (size_t i = 0; i < sistemas.size(); ++i) {
        delete sistemas[i];
    }
    sistemas.clear();

    // Desaloca todos os fluxos criados pela fábrica
    for (size_t i = 0; i < fluxos.size(); ++i) {
        delete fluxos[i];
    }
    fluxos.clear();
}

// Método Factory (Fábrica) para encapsular a criação de Sistemas
System* Model::criaSistema(const std::string& nome, double valorInicial) {
    System* s = new System(nome, valorInicial);
    sistemas.push_back(s); // Guarda o ponteiro na coleção interna do modelo
    return s;
}

// O MOTOR DO SIMULADOR: O algoritmo do loop síncrono em dois passos
void Model::run(int t_inicial, int t_final) {
    for (tempo = t_inicial; tempo < t_final; ++tempo) {
        
        // PASSO 1: Fase de Cálculo (Leitura síncrona de todos os fluxos)
        std::vector<double> resultados_temporarios;
        for (size_t i = 0; i < fluxos.size(); ++i) {
            resultados_temporarios.push_back(fluxos[i]->executa());
        }
        
        // PASSO 2: Fase de Atualização (Escrita nos estoques de origem e destino)
        for (size_t i = 0; i < fluxos.size(); ++i) {
            System* src = fluxos[i]->getSource();
            System* tgt = fluxos[i]->getTarget();
            
            if (src != nullptr) {
                src->setValor(src->getValor() - resultados_temporarios[i]);
            }
            if (tgt != nullptr) {
                tgt->setValor(tgt->getValor() + resultados_temporarios[i]);
            }
        }
    }
}