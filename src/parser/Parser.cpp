/*
** EPITECH PROJECT, 2022
** abstractVM
** File description:
** Parser
*/

#include "Parser.hpp"
#include <fstream>
#include <iostream>
#include <regex>
#include <string>

namespace Parser
{
    ParssCommand::ParssCommand() {}

    ParssCommand::~ParssCommand()
    {
        if (_data.empty())
            _data.clear();
    }

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
            if (line.compare(";;") == 0 || std::cin.eof())
                break;
            _data.push_back(line);
        }
        return (0);
    }

    const std::vector<std::string> ParssCommand::getData() { return (this->_data); }

    bool ParssCommand::checkProvideData()
    {
        std::regex const patternPush("push (int8|int16|int32|int64|Float|Double|BigDecimal) ([1-9])");
        std::cout << _data.front() + " " << std::boolalpha << std::regex_search(_data.front(), patternPush)
                  << std::endl;
        return (true);
    }

} // namespace Parser