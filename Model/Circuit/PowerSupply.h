#ifndef ELECTRICAL_CIRCUIT_SIMULATOR_POWERSUPPLY_H
#define ELECTRICAL_CIRCUIT_SIMULATOR_POWERSUPPLY_H


#include "Element.h"

class PowerSupply : public Element {
public:
    PowerSupply(uint32_t n1, uint32_t n2, double val);
    void modifyCircuit(Circuit *circuit);
};


#endif //ELECTRICAL_CIRCUIT_SIMULATOR_POWERSUPPLY_H
