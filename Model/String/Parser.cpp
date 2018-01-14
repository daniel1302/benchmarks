#include "Parser.h"

void Parser::parseLine(std::string line)
{

}

vector<std::string> Parser::split(std::string &str, char delimiter)
{
    std::vector<std::string> elems;
    std::stringstream ss(str);
    std::string item;

    while (getline(ss, item, delimiter))
    {
        elems.push_back(item);
    }

    return elems;
}