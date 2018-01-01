#ifndef ELECTRICAL_CIRCUIT_SIMULATOR_GAUSSIANELIMINATION_H
#define ELECTRICAL_CIRCUIT_SIMULATOR_GAUSSIANELIMINATION_H


#include "Matrix.h"

template <typename T>
class GaussianElimination {
public:
    void verifyMatrix(Matrix<T> *matrix, Matrix<T> *freeMatrix);
    void reduce(Matrix<T> *matrix, Matrix<T> *freeMatrix);
};


template <typename T>
void GaussianElimination<T>::verifyMatrix(Matrix<T> *varMatrix, Matrix<T> *freeMatrix)
{
    if (varMatrix->cols() != varMatrix->rows() //if matrix is not square
        || varMatrix->rows() < 2 //if matrix has only one or zero rows
        || freeMatrix->cols() != 1 //if free number contains more or less than 1 row
        || freeMatrix->rows() != varMatrix->rows() //if amount of free numbers is not equal to number of equations
    ) {
        throw logic_error("Gaussian elimination method is not available for this matrix");
    }
}

template <typename T>
void GaussianElimination<T>::reduce(Matrix<T> *varMatrix, Matrix<T> *freeMatrix)
{
    this->verifyMatrix(varMatrix, freeMatrix);


    uint32_t row;
    uint32_t col;
    double multiplier;

    for (uint32_t diagonal=0; diagonal<varMatrix->cols()-1; diagonal++) {
        for (row=varMatrix->rows()-1; row>diagonal; row--) {

            if (varMatrix->get(row, diagonal) == 0) {
                continue;
            }

            multiplier = varMatrix->get(row, diagonal) / varMatrix->get(diagonal, diagonal);
            varMatrix->insert(row, diagonal, 0);

            for (col=diagonal+1; col<varMatrix->cols(); col++) {

                varMatrix->insert(row,
                                  col,
                                  varMatrix->get(row, col) - varMatrix->get(diagonal, col) * multiplier
                );
            }

            freeMatrix->insert(row,
                               0,
                               freeMatrix->get(row, 0) - freeMatrix->get(diagonal, 0) * multiplier
            );
        }
    }
}

#endif //ELECTRICAL_CIRCUIT_SIMULATOR_GAUSSIANELIMINATION_H
