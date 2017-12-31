#ifndef ELECTRICAL_CIRCUIT_SIMULATOR_RESISTORELEMENT_H
#define ELECTRICAL_CIRCUIT_SIMULATOR_RESISTORELEMENT_H

#include "Element.h"

class ResistorElement : Element {
public:
    ResistorElement(uint32_t n1, uint32_t n2, double val);
    void modifyCircuit(Circuit circuit);
};


#endif //ELECTRICAL_CIRCUIT_SIMULATOR_RESISTORELEMENT_H
