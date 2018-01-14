#ifndef ELECTRICAL_CIRCUIT_SIMULATOR_PARSER_H
#define ELECTRICAL_CIRCUIT_SIMULATOR_PARSER_H

#include <vector>
#include "Model/Circuit/Element.h"

class Parser {
protected:
    std::vector<Element> lines;

public:
    void parseLine(std::string line);

    vector<std::string> split(std::string &str, char delimiter);
protected:

};


#endif //ELECTRICAL_CIRCUIT_SIMULATOR_PARSER_H
