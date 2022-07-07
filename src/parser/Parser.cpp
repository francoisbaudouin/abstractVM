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

    ParssCommand::~ParssCommand() { _data.clear(); }

    int ParssCommand::readData(const std::string path)
    {
        std::string line;
        std::ifstream file(path);
        int i = 0;

        if (file.is_open()) {
            while (getline(file, line)) {
                _data.push_back(line);
            }
            file.close();
        } else {
            // trow exeption
        }
        return (0);
    }

    void ParssCommand::readData() {}
} // namespace Parser