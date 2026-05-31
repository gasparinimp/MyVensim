#ifndef LOGISTICALFLOW_H
#define LOGISTICALFLOW_H

#include "flowImpl.h"

class LogisticalFlow : public FlowImpl {
public:
    LogisticalFlow();
    LogisticalFlow(std::string name);
    virtual ~LogisticalFlow();
    
    double execute() const override;
};

#endif