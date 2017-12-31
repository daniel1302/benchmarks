#ifndef ELECTRICAL_CIRCUIT_SIMULATOR_MATRIX_H
#define ELECTRICAL_CIRCUIT_SIMULATOR_MATRIX_H

#include <iostream>
#include <vector>
#include <iomanip>
#include <exception>


using namespace std;



template <typename T>
class Matrix {
private:
    vector< vector<T> > _matrix;

public:
    Matrix();
    ~Matrix();
    void insert(uint32_t row, uint32_t col, T value);
    string print() const;
    uint32_t cols() const;
    uint32_t rows() const;
    T get(uint32_t row, uint32_t col) const;

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
uint32_t Matrix<T>::cols() const
{
    if (_matrix.size() > 0) {
        return _matrix[0].size();
    }

    return 0;
}

template <typename T>
uint32_t Matrix<T>::rows() const
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
string Matrix<T>::print() const
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
//
//template <typename T>
//Matrix<T> Matrix<T>::operator*(const double multiplier)
//{
//    this->multiply(multiplier);
//
//    return Matrix<T>(*this);
//}

template <typename T>
Matrix<T> Matrix<T>::operator*=(const Matrix<T> matrix)
{
    vector< vector<T> > tmpData(_matrix);
    uint32_t rows = this->rows();

    if (this->cols() != matrix.rows() || this->rows() != matrix.cols()) {
        throw logic_error("Cannot multiply matrixes with different sizes");
    }

    T tmpValue;

    for (uint32_t row1=0; row1<rows; row1++) {
        for (uint32_t col2=0; col2<matrix.cols(); col2++) {

            tmpValue = 0;

            for (uint32_t cord=0; cord<matrix.rows(); cord++) {
                    tmpValue += tmpData[row1][cord] * matrix.get(cord, col2);
            }

            this->insert(row1, col2, tmpValue);
        }
    }

    return *this;
}

template <typename T>
T Matrix<T>::get(uint32_t row, uint32_t col) const
{
    if (_matrix.size() > row && _matrix[row].size() > col) {
        return _matrix[row][col];
    }

    return 0;
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
