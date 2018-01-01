#ifndef ELECTRICAL_CIRCUIT_SIMULATOR_GAUSSIANELIMINATION_H
#define ELECTRICAL_CIRCUIT_SIMULATOR_GAUSSIANELIMINATION_H


#include "Matrix.h"

template <typename T>
class GaussianElimination {
public:
    void verifyMatrix(Matrix<T> *matrix);
    void reduce(Matrix<T> *matrix);
};


template <typename T>
void GaussianElimination<T>::verifyMatrix(Matrix<T> *matrix)
{
    if (matrix->cols() != matrix->rows() && matrix->rows() < 2) {
        throw logic_error("Gaussian elimination method is not available for this matrix");
    }
}

template <typename T>
void GaussianElimination<T>::reduce(Matrix<T> *matrix)
{
    this->verifyMatrix(matrix);

    uint32_t row;
    uint32_t col;
    double multiplier;

    for (uint32_t diagonal=0; diagonal<matrix->cols()-1; diagonal++) {
        for (row=matrix->rows()-1; row>diagonal; row--) {

            if (matrix->get(row, diagonal) == 0) {
                continue;
            }

            multiplier = matrix->get(row, diagonal) / matrix->get(diagonal, diagonal);
            matrix->insert(row, diagonal, 0);

            for (col=diagonal+1; col<matrix->cols(); col++) {

                matrix->insert(row,
                               col,
                               matrix->get(row, col) - matrix->get(diagonal, col) * multiplier
                );
            }
        }
    }
}

#endif //ELECTRICAL_CIRCUIT_SIMULATOR_GAUSSIANELIMINATION_H
