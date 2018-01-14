#include <iostream>
#include <memory>
#include <Model/Math/Matrix.h>
#include <Model/Math/GaussianElimination.h>

#ifndef TEST_MATRIX_TEST
#define TEST_MATRIX_TEST


/**
[     0.65        2        4]
[        5     11.1        7]
[        1     3.33      9.3]




                                [     0.65        2        4]
                                [        5     11.1        7]
                                [        1     3.33      9.3]
[      1.3        4        8]
[       10     22.2       14]
[        2     6.66     18.6]
*/
void matrixTest()
{
    auto matrix = make_unique<Matrix<double>>();

    matrix->insert(0, 0, 0.65);
    matrix->insert(0, 1, 2);
    matrix->insert(0, 2, 4);
    matrix->insert(1, 0, 5);
    matrix->insert(1, 1, 11.1);
    matrix->insert(1, 2, 7);
    matrix->insert(2, 0, 1);
    matrix->insert(2, 1, 3.33);
    matrix->insert(2, 2, 9.3);

//    matrix.multiply(2.);
    *matrix *= 2.;
    std::cout
            <<"Matrix [" <<matrix->rows() << " x " << matrix->cols() << "]" << std::endl
            <<matrix->print()<<endl;

    auto matrix2 = new Matrix<double>();

    matrix2->insert(0, 0, 0.65);
    matrix2->insert(0, 1, 2);
    matrix2->insert(0, 2, 4);
    matrix2->insert(1, 0, 5);
    matrix2->insert(1, 1, 11.1);
    matrix2->insert(1, 2, 7);
    matrix2->insert(2, 0, 1);
    matrix2->insert(2, 1, 3.33);
    matrix2->insert(2, 2, 9.3);

    *matrix *= *matrix2;

////    matrix->removeRow(2);
//    matrix->removeCol(0);
    std::cout << "Multiplication"
              <<"Matrix [" <<matrix->rows() << " x " << matrix->cols() << "]" << std::endl
              <<matrix->print()<<endl;



    std::cout<<matrix->get(2, 2)<<endl;
    std::cout<<matrix->get(3, 2)<<endl;
}

#endif

/**

 **/