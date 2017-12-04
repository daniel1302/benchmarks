#ifndef ELECTRICAL_CIRCUIT_SIMULATOR_MATRIX_H
#define ELECTRICAL_CIRCUIT_SIMULATOR_MATRIX_H

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;



template <typename T>
class Matrix {
private:
    vector< vector<T> > _matrix;

public:
    Matrix();
    ~Matrix();
    void insert(uint32_t x, uint32_t y, T value);
    string print();
};


template <typename T>
Matrix<T>::Matrix()
{
}


template <typename T>
Matrix<T>::~Matrix()
{
}

template <typename T>
void Matrix<T>::insert(uint32_t row, uint32_t col, T value)
{
    uint32_t expectedHeight = row+1;

    uint32_t expectedWidth = col+1;
    if (_matrix.size() > 0 && _matrix[0].size() > expectedWidth) {
        expectedWidth = (uint32_t)_matrix[0].size();
    }

    if (_matrix.size() < expectedHeight) {
        _matrix.resize(expectedHeight);
        _matrix[row] = vector<T>(expectedWidth);
    }

    for(uint32_t i=0; i<_matrix.size(); i++) {
        _matrix[i].resize(expectedWidth);
    }

    _matrix[row][col] = value;
}


template <typename T>
string Matrix<T>::print()
{
    stringstream out;

    for (uint32_t row=0; row<_matrix.size(); row++) {
        out << "[";
        for(uint32_t col=0; col<_matrix[row].size(); col++) {
            out
                    << setw(9)
                    << setprecision(4)
                    << _matrix[row][col];
        }
        out << "]\n";
    }

    return out.str();
}



#endif //ELECTRICAL_CIRCUIT_SIMULATOR_MATRIX_H
