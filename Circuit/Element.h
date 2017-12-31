#ifndef ELECTRICAL_CIRCUIT_SIMULATOR_ELEMENT_H
#define ELECTRICAL_CIRCUIT_SIMULATOR_ELEMENT_H

#include "Matrix.h"
#include <Circuit.h>

class Circuit;

class Element {
protected:
    uint32_t node1;
    uint32_t  node2;
    double value;

public:
    Element(uint32_t node1, uint32_t node2, double value);
    virtual void modifyCircuit(Circuit *circuit) = 0;
};


#endif //ELECTRICAL_CIRCUIT_SIMULATOR_ELEMENT_H
