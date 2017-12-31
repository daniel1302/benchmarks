#include "PowerSupply.h"

PowerSupply::PowerSupply(uint32_t n1, uint32_t n2, double val)
        : Element(n1, n2, val)
{
}


void PowerSupply::modifyCircuit(Circuit *circuit)
{
    circuit->modifyG(this->node1, this->node1, 0);
    circuit->modifyG(this->node1, this->node2, 0);
    circuit->modifyG(this->node2, this->node1, 0);
    circuit->modifyG(this->node2, this->node2, 0);

    circuit->modifyI(this->node1, (-1.) * this->value);
    circuit->modifyI(this->node1, this->value);
}