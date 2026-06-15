#include "logisticalFlow.h"

LogisticalFlow::LogisticalFlow() : FlowImpl() {}
LogisticalFlow::LogisticalFlow(std::string name, System* source, System* target)
    : FlowImpl(name, source, target){}
LogisticalFlow::~LogisticalFlow() {}

double LogisticalFlow::execute() {
    if (getTarget() != nullptr) {
        double p2 = getTarget()->getValue();
        return 0.01 * p2 * (1.0 - (p2 / 70.0));
    }
    return 0.0;
}