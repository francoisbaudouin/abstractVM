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

void half(std::string test = "test") { std::cout << test << std::endl; }

namespace Parser
{
    ParssCommand::ParssCommand() {}

    ParssCommand::~ParssCommand()
    {
        if (_data.empty())
            _data.clear();
        if (_functPtr.empty())
            _functPtr.clear();
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
        std::regex const reg("([a-z]*)(\\s*(([a-z]+[0-9]?)*)\\((\\d+)\\))?"); // new regex

        for (std::string i : _data) {
            if (std::regex_match(i, reg)) {
                // throw execption
                return (false);
            }
        }
        std::function<void(std::string)> fn1 = half;

        _functPtr["push"] = fn1;
        std::cout << "test" << std::endl;
        _functPtr["push"];

        return (true);
    }

} // namespace Parser