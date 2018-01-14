#include "ControllerFactory.h"
#include "FileController.h"

std::unique_ptr<Controller> ControllerFactory::createController(uint32_t type)
{
    std::unique_ptr<Controller> controller = std::make_unique<FileController>();

    return controller;
}