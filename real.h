#ifndef REAL_H
#define REAL_H

class Real {
public:
    float value;

    Real(float v) : value(v) {}

    float getValue() {
        return value;
    }
};

#endif
