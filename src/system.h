#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>

class System {
private:
    std::string name;
    double value;

public:
    // --- FORMA CANÔNICA ORTODOXA ---
    System();                                       // Construtor Padrão
    System(const std::string& name, double value);  // Construtor com Parâmetros
    virtual ~System();                              // Destrutor
    System(const System& other);                    // Construtor de Cópia
    System& operator=(const System& other);         // Operador de Atribuição

    // Getters e Setters (Alinhados em Inglês)
    std::string getName() const;
    double getValue() const;
    void setValue(double value);
    void setName(std::string name);
};

#endif