#ifndef ELECTRICAL_CIRCUIT_SIMULATOR_CONTROLLER_H
#define ELECTRICAL_CIRCUIT_SIMULATOR_CONTROLLER_H


#include "ControllerInterface.h"

class Controller : public ControllerInterface {
public:
    virtual uint32_t action();
};


#endif //ELECTRICAL_CIRCUIT_SIMULATOR_CONTROLLER_H
