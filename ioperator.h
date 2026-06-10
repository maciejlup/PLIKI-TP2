#ifndef IOPERATOR_H
#define IOPERATOR_H

#include "real.h"
class IOperator {
public:
    virtual ~IOperator() = default;
    virtual Real calculate(Real, Real)= 0;
};

#endif
