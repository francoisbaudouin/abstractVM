/*
** EPITECH PROJECT, 2022
** abstractVM
** File description:
** Parser
*/

#include "Parser.hpp"
#include <fstream>
#include <regex>

namespace Parser
{
    ParssCommand::ParssCommand()
    {
        _exitIsCalled = false;
        _allowToWriteData = true;
    }

    ParssCommand::~ParssCommand()
    {
        if (_data.empty())
            _data.clear();
    }

    int ParssCommand::readData(const std::string path)
    {
        std::string line;

        if (!_data.empty()) {
            return (1);
        }
        std::ifstream file(path);

        if (file.is_open()) {
            while (std::getline(file, line)) {
                if (line.compare("exit") == 0) {
                    _exitIsCalled = true;
                    _allowToWriteData = false;
                }
                if (_allowToWriteData == true)
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
            if (line.compare("exit") == 0) {
                _exitIsCalled = true;
                _allowToWriteData = false;
            }
            if (_allowToWriteData == true)
                _data.push_back(line);
        }
        return (0);
    }

    const std::vector<std::string> ParssCommand::getData() { return (this->_data); }

    bool ParssCommand::checkProvideData()
    {
        if (_exitIsCalled == false)
            return (false);
        std::regex const reg("([a-z-;]*)(\\s*(([a-z]+[0-9]?)*)\\((\\d*\\.?\\d*)\\))?"); // new regex

        for (std::string i : _data) {
            if (std::regex_match(i, reg) == false) {
                // throw execption
                return (false);
            }
        }
        return (true);
    }

} // namespace Parser