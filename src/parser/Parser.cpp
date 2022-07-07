/*
** EPITECH PROJECT, 2022
** abstractVM
** File description:
** Parser
*/

#include "Parser.hpp"
#include <fstream>

namespace Parser {
    ParssCommand::ParssCommand()
    {
    }

    ParssCommand::~ParssCommand()
    {
    }
    
    int ParssCommand::readFile(const std::string path)
    {
        std::string line;
        std::ifstream file(path);
        if (file.is_open()) {
            file.close();
        } else {
            //trow exeption
        }
        return (0);
    }
}