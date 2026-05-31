#include "logisticalFlow.h"

LogisticalFlow::LogisticalFlow() : FlowImpl() {}
LogisticalFlow::LogisticalFlow(std::string name) : FlowImpl(name) {}
LogisticalFlow::~LogisticalFlow() {}

double LogisticalFlow::execute() const {
    if (getTarget() != nullptr) {
        double p2 = getTarget()->getValue();
        return 0.01 * p2 * (1.0 - (p2 / 70.0));
    }
    return 0.0;
}