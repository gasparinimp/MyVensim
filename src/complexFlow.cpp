#include "complexFlow.h"

ComplexFlow::ComplexFlow() : FlowImpl() {}
ComplexFlow::ComplexFlow(std::string name) : FlowImpl(name) {}
ComplexFlow::~ComplexFlow() {}

double ComplexFlow::execute() const {
    if (getSource() != nullptr) {
        return getSource()->getValue() * 0.01; 
    }
    return 0.0;
}