#ifndef OPERATORS_H
#define OPERATORS_H

#include "ioperator.h"
#include "real.h"
#include <cmath>


class Add : public IOperator {
public:
    Real calculate(Real a, Real b) override {
        return Real(a.value + b.value);
    }
};


class Subtract : public IOperator {
public:
    Real calculate(Real a, Real b) override {
        return Real(a.value - b.value);
    }
};


class Multiply : public IOperator {
public:
    Real calculate(Real a, Real b) override {
        return Real(a.value * b.value);
    }
};


class Divide : public IOperator {
public:
    Real calculate(Real a, Real b) override {
        return Real(a.value / b.value);
    }
};


class Power : public IOperator {
public:
    Real calculate(Real a, Real b) override {
        return Real(std::pow(a.value, b.value));
    }
};

#endif
