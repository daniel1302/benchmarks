#include <iostream>
#include <memory>
#include <Math/Matrix.h>
#define TEST

#ifdef TEST
    #include <Tests/Matrix.cpp>
    #include <Tests/GaussianElimination.cpp>
#include <Circuit/PowerSupply.h>
#include <Circuit/ResistorElement.h>

#endif


void testCircuit()
{
    Circuit circuit;
    std::cout<<circuit.print();

    PowerSupply current1(0, 1, 0.001);
    ResistorElement r1(1, 2, 10000);
    ResistorElement r2(2, 0, 20000);
    ResistorElement r3(2, 3, 16000);
    ResistorElement r4(3, 0, 4000);

    circuit.insertElement((Element*)&current1);
    circuit.insertElement((Element*)&r1);
    circuit.insertElement((Element*)&r2);
    circuit.insertElement((Element*)&r3);
    circuit.insertElement((Element*)&r4);
    circuit.ground(0);



    std::cout<<circuit.print();
}

int main() {
//    matrixTest();
    gaussianEliminationTest();
//    testCircuit();

    return 0;
}

