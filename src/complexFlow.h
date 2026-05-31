#ifndef COMPLEXFLOW_H
#define COMPLEXFLOW_H

#include "flowImpl.h"

class ComplexFlow : public FlowImpl {
public:
    ComplexFlow();
    ComplexFlow(std::string name);
    virtual ~ComplexFlow();
    
    double execute() const override;
};

#endif