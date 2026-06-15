#include "complexFlow.h"

ComplexFlow::ComplexFlow() : FlowImpl() {}
ComplexFlow::ComplexFlow(std::string name, System* source, System* target) 
    : FlowImpl(name, source, target) {}
ComplexFlow::~ComplexFlow() {}

double ComplexFlow::execute() {
    if (this->getSource() != nullptr) {
        return 0.01 * this->getSource()->getValue(); 
    }
    return 0.0;
}