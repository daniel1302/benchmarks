#ifndef ELECTRICAL_CIRCUIT_SIMULATOR_GAUSSIANELIMINATION_H
#define ELECTRICAL_CIRCUIT_SIMULATOR_GAUSSIANELIMINATION_H


#include "Matrix.h"

template <typename T>
class GaussianElimination {
protected:
    Matrix<T> *varMatrix;
    Matrix<T> *freeNumbersMatrix;
public:
    GaussianElimination(Matrix<T> *matrix, Matrix<T> *freeMatrix);
    void verifyMatrix(Matrix<T> *matrix, Matrix<T> *freeMatrix);
    void reduce();
    void calculate(Matrix<T> *result);
};

template <typename T>
void GaussianElimination<T>::calculate(Matrix<T> *result)
{
    //TODO: TEST IF matrix IS triangle

    uint32_t col;
    double tmpSum;


    for (int row=varMatrix->rows()-1;row>=0; row--)
    {
        tmpSum = 0;

        for (col=(uint32_t)row; col<varMatrix->rows(); col++) {
            tmpSum += result->get(col, 0) * varMatrix->get((uint32_t)row, col);
        }

        result->insert((uint32_t)row,
                       0,
                       (freeNumbersMatrix->get((uint32_t)row, 0) - tmpSum) / varMatrix->get((uint32_t)row, (uint32_t)row)
        );
    }
}

template <typename T>
GaussianElimination<T>::GaussianElimination(Matrix<T> *matrix, Matrix<T> *freeMatrix)
:varMatrix(matrix)
,freeNumbersMatrix(freeMatrix)
{
    this->verifyMatrix(matrix, freeMatrix);
}

template <typename T>
void GaussianElimination<T>::verifyMatrix(Matrix<T> *matrix, Matrix<T> *freeMatrix)
{
    if (varMatrix->cols() != varMatrix->rows() //if matrix is not square
        || varMatrix->rows() < 2 //if matrix has only one or zero rows
        || freeNumbersMatrix->cols() != 1 //if free number contains more or less than 1 row
        || freeNumbersMatrix->rows() != varMatrix->rows() //if amount of free numbers is not equal to number of equations
    ) {
        throw logic_error("Gaussian elimination method is not available for this matrix");
    }
}

template <typename T>
void GaussianElimination<T>::reduce()
{
    this->verifyMatrix(varMatrix, freeNumbersMatrix);

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

            freeNumbersMatrix->insert(row,
                               0,
                               freeNumbersMatrix->get(row, 0) - freeNumbersMatrix->get(diagonal, 0) * multiplier
            );
        }
    }
}

#endif //ELECTRICAL_CIRCUIT_SIMULATOR_GAUSSIANELIMINATION_H
