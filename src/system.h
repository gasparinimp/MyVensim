#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>

class System {
private:
    std::string nome;
    double valor;

public:
    System(const std::string& nome, double valorInicial);
    virtual ~System();

    std::string getNome() const;
    double getValor() const;
    void setValor(double v);
};

#endif