//
// Created by daniel on 31.12.17.
//

#ifndef ELECTRICAL_CIRCUIT_SIMULATOR_CIRCUIT_H
#define ELECTRICAL_CIRCUIT_SIMULATOR_CIRCUIT_H


#include <Model/Math/Matrix.h>
#include <Model/Circuit/Element.h>

class Element;

class Circuit {
protected:
    Matrix<double> g;
    Matrix<double> i;

    uint32_t groundNode;

protected:
    void modifyMatrix(Matrix<double> *matrix, uint32_t row, uint32_t col, double val);

public:
    void insertElement(Element *element);
    void modifyG(uint32_t row, uint32_t col, double val);
    void modifyI(uint32_t row, double val);
    void ground(uint32_t node);
    void calculate(Matrix<double> *matrix);
    std::string print();
};


#endif //ELECTRICAL_CIRCUIT_SIMULATOR_CIRCUIT_H
