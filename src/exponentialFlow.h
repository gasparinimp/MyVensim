#ifndef EXPONENTIALFLOW_H
#define EXPONENTIALFLOW_H

#include "flowImpl.h"

class ExponentialFlow : public FlowImpl {
public:
    ExponentialFlow();
    ExponentialFlow(std::string name);
    virtual ~ExponentialFlow();
    
    // CORREÇÃO: Mantemos o const e o override!
    double execute() const override; 
};

#endif