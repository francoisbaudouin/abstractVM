/*
** EPITECH PROJECT, 2022
** abstractVM
** File description:
** Parser
*/

#include "Parser.hpp"
#include <fstream>
#include <iostream>
#include <string>

namespace Parser
{
    ParssCommand::ParssCommand() {}

    ParssCommand::~ParssCommand() { _data.clear(); }

    int ParssCommand::readData(const std::string path)
    {
        std::string line;
        std::ifstream file(path);

        if (file.is_open()) {
            while (std::getline(file, line)) {
                _data.push_back(line);
            }
            file.close();
        } else {
            // trow exeption
            return (1);
        }
        return (0);
    }

    int ParssCommand::readData()
    {
        std::string line;

        if (!_data.empty()) {
            return (1);
        }
        while (1) {
            std::getline(std::cin, line);
            if (line.compare(";;") == 0)
                break;
            _data.push_back(line);
        }
        return (0);
    }

    const std::vector<std::string> ParssCommand::getData() { return (this->_data); }

} // namespace Parser