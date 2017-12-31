#include "ResistorElement.h"

ResistorElement::ResistorElement(uint32_t n1, uint32_t n2, double val)
    : Element(n1, n2, val)
{
    this->conductance = 1./val;
}

void ResistorElement::modifyCircuit(Circuit *circuit) {
    circuit->modifyG(node1, node1, this->conductance);
    circuit->modifyG(node1, node2, (-1.) * this->conductance);
    circuit->modifyG(node2, node1, (-1.) * this->conductance);
    circuit->modifyG(node2, node2, this->conductance);

    circuit->modifyI(node1, 0);
    circuit->modifyI(node2, 0);
}