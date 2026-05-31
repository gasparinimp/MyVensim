#include "exponentialFlow.h"

ExponentialFlow::ExponentialFlow() : FlowImpl() {}
ExponentialFlow::ExponentialFlow(std::string name) : FlowImpl(name) {}
ExponentialFlow::~ExponentialFlow() {}

double ExponentialFlow::execute() const {
    if (getSource() != nullptr) {
        return getSource()->getValue() * 0.01;
    }
    return 0.0;
}