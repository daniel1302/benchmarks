#ifndef ELECTRICAL_CIRCUIT_SIMULATOR_FILECONTROLLER_H
#define ELECTRICAL_CIRCUIT_SIMULATOR_FILECONTROLLER_H

#include "ControllerInterface.h"
#include "Controller.h"

class FileController
        : public Controller {
public:
    uint32_t action();
};


#endif //ELECTRICAL_CIRCUIT_SIMULATOR_FILECONTROLLER_H
