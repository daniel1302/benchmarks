#include "Circuit.h"


void Circuit::insertElement(Element *element)
{
    element->modifyCircuit(this);
}

void Circuit::modifyG(uint32_t row, uint32_t col, double val)
{
    this->modifyMatrix(& this->g, row, col, val);
}

void Circuit::modifyI(uint32_t row, double val)
{
    this->modifyMatrix(& this->i, row, 0, val);
}

void Circuit::modifyMatrix(
        Matrix<double> *matrix,
        uint32_t row,
        uint32_t col,
        double val
)
{
    val = val + matrix->get(row, col);
    matrix->insert(row, col, val);
}

void Circuit::ground(uint32_t node)
{
    this->i.removeRow(node);
    this->g.removeCol(node);
    this->g.removeRow(node);
}

std::string Circuit::print()
{
    stringstream out;
    out
            << "Conductance matrix: "<<endl
            <<this->g.print()<<endl
            << "Current matrix:"<<endl
            <<this->i.print()<<endl;



    return out.str();
}