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
    int cols();
    int rows();

public:
//    Matrix<T> operator*(const double multiplier);
    Matrix<T> operator*=(const Matrix<T> matrix);
    Matrix<T> operator*=(const double multiplier);
    Matrix<T> operator*=(const int multiplier);

protected:
    void multiply(double multiplier);
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
int Matrix<T>::cols()
{
    if (_matrix.size() > 0) {
        return _matrix[0].size();
    }

    return 0;
}

template <typename T>
int Matrix<T>::rows()
{
    return _matrix.size();
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

template <typename T>
Matrix<T> Matrix<T>::operator*(const double multiplier)
{
    this->multiply(multiplier);

    return Matrix<T>(*this);
}

template <typename T>
Matrix<T> Matrix<T>::operator*=(const int multiplier)
{
    this->multiply((double)multiplier);

    return Matrix<T>(*this);
}

template <typename T>
Matrix<T> Matrix<T>::operator*=(const double multiplier)
{
    this->multiply(multiplier);

    return Matrix<T>(*this);
}

template <typename T>
void Matrix<T>::multiply(double multiplier)
{
    for (uint32_t row=0; row<_matrix.size(); row++) {
        for(uint32_t col=0; col<_matrix[row].size(); col++) {
            _matrix[row][col] = _matrix[row][col] * multiplier;
        }
    }
}

#endif //ELECTRICAL_CIRCUIT_SIMULATOR_MATRIX_H
