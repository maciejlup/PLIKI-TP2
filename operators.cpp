#include "operators.h"
#include <cmath>

Real Add::calculate(Real a, Real b) {
    return Real(a.value + b.value);
}

Real Subtract::calculate(Real a, Real b) {
    return Real(a.value - b.value);
}

Real Multiply::calculate(Real a, Real b) {
    return Real(a.value * b.value);
}

Real Divide::calculate(Real a, Real b) {
    return Real(a.value / b.value);
}

Real Power::calculate(Real a, Real b) {
    return Real(std::pow(a.value, b.value));
}
