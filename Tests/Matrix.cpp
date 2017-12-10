#include <iostream>
#include <memory>
#include <Math/Matrix.h>

#ifndef TEST_MATRIX_TEST
#define TEST_MATRIX_TEST


/**
[     0.65        2        4]
[        5     11.1        7]
[        1     3.33      9.3]
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
            <<matrix->print()<<endl;
}

#endif

/**

 **/