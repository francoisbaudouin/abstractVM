/*
** EPITECH PROJECT, 2022
** abstractVM
** File description:
** Parser
*/

#include "Parser.hpp"
#include <fstream>
#include <string>

namespace Parser
{
    ParssCommand::ParssCommand() {}

    ParssCommand::~ParssCommand() {}

    int ParssCommand::readData(const std::string path)
    {
        std::string line;
        std::ifstream file(path);
        if (file.is_open()) {
            file.close();
        } else {
            // trow exeption
        }
        return (0);
    }
} // namespace Parser