/*
** EPITECH PROJECT, 2022
** abstractVM
** File description:
** Parser
*/

#include "Parser.hpp"
#include <fstream>

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
                if (_allowToWriteData == true && line.c_str()[0] != ';')
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
            if (_allowToWriteData == true && line.c_str()[0] != ';') {
                _data.push_back(line);
            }
        }
        return (0);
    }

    bool ParssCommand::_setUpCommand(std::smatch &match)
    {
        CommandData command;

        command.setter(match.str(1), match.str(3), match.str(5));

        _dataCommand.push_back(command);
        return (true);
    }

    std::vector<CommandData> &ParssCommand::getDataCommand() { return (_dataCommand); }
    bool ParssCommand::checkProvideData()
    {
        if (_exitIsCalled == false)
            return (false);
        std::regex const reg(
            "(\\s*[a-z]*)(\\s*((\\s*[a-z]+\\d*?)*)\\s*\\(([-]?\\d+(\\.\\d+)?)\\)*)?(\\s*\\;.*)?"); // new regex
        std::regex const regComment("([;].*)");
        std::smatch match;

        for (std::string str : _data) {
            if (std::regex_match(str, reg) == false && std::regex_match(str, regComment) == false) {
                return (false);
            }
            if (std::regex_search(str, match, reg) != true)
                return (false);
            _setUpCommand(match);
        }
        return (true);
    }

} // namespace Parser
