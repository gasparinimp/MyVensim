#ifndef SYSTEM_IMPL_H
#define SYSTEM_IMPL_H
#include "system.h"
#include <string>

class SystemImpl : public System {
protected:
    std::string name;
    double value;
public:
    //Construtor vazio
    SystemImpl();    
    //Construtor normal  
    SystemImpl(const std::string& name, double value); 
    //Destrutor
    virtual ~SystemImpl();      
    //Construtor de copia
    SystemImpl(const SystemImpl& other); 
    //Sobrecarga 
    SystemImpl& operator=(const SystemImpl& other);         

    // Sobrescrita (override) dos métodos da interface
    std::string getName() const override;
    double getValue() const override;
    void setValue(double value) override;
    void setName(std::string name) override;
};


#endif