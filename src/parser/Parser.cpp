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
        std::regex const reg("([a-z]*)(\\s*(([a-z]+[0-9]?)*)\\((\\d+)\\))?"); // new regex
        /* std::regex const patternCommandWithData("(push|assert) (int8|int16|int32|int64|float|double|bigDecimal)");
        std::regex const patternSimpleCommand("(;|pop|clear|dup|swap|dump|add|sub|mul|div|mod|print|exit)");
        std::regex const patternRegistre("(load|store)");
        std::regex const partternNbN("[-]?[0..9]+");
        std::regex const partternNbZ("[-]?[0..9]+[.]?[0..9]*"); */
        for (std::string i : _data) {
                std::cout << i + " " << std::boolalpha << std::regex_match(i, reg) << std::endl;
            //if (std::regex_search(i, patternCommandWithData) == false
            //    && std::regex_search(i, patternSimpleCommand) == false
            //    && std::regex_search(i, patternRegistre) == false) {
            //    return (false);
            //}
        }
        return (true);
    }

} // namespace Parser