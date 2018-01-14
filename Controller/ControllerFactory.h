#ifndef ELECTRICAL_CIRCUIT_SIMULATOR_CONTROLLERFACTORY_H
#define ELECTRICAL_CIRCUIT_SIMULATOR_CONTROLLERFACTORY_H


#include <memory>
#include "Controller.h"



class ControllerFactory {
public:
    static std::unique_ptr<Controller> createController(uint32_t type);
};


#endif //ELECTRICAL_CIRCUIT_SIMULATOR_CONTROLLERFACTORY_H
