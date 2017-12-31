#include "Circuit.h"


void Circuit::insertElement(Element *element)
{
    element->modifyCircuit(this);
}

void Circuit::modifyG(uint32_t row, uint32_t col, double val)
{
    this->modifyMatrix(& this->g, row, col, val);
}

void Circuit::modifyI(uint32_t row, uint32_t col, double val)
{
    this->modifyMatrix(& this->i, row, col, val);
}

void Circuit::modifyMatrix(
        Matrix<double> *matrix,
        uint32_t row,
        uint32_t col,
        double val
)
{

}