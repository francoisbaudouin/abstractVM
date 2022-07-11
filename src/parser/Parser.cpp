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

    std::tuple<AbstractVM::eOperandType, std::string> ParssCommand::_getdataCommand(
        std::string eoprand, std::string value)
    {
        if (eoprand.empty() == 0 && value.empty() == 0)
            return (std::make_tuple(AbstractVM::eOperandType::UNKNOWN, ""));
        std::map<std::string, AbstractVM::eOperandType>::const_iterator it = _whatEOperandIs.find(eoprand);
        /* if (it == _whatEOperandIs.end())
            throw _getdataCommand("Operant doesn't exist"); */
        return (std::make_tuple(it->second, value));
    }

    bool ParssCommand::_setUpCommand(std::smatch match)
    {
        std::string nullStr;
        switch (match.size()) {
            case (1): _dataCommand.insert({match.str(1), _getdataCommand(" ", " ")}); break;
            case (3): _dataCommand.insert({match.str(1), _getdataCommand(match.str(3), match.str(5))}); break;
            default: break;
        }
        return (true);
    }

    bool ParssCommand::checkProvideData()
    {
        if (_exitIsCalled == false)
            return (false);
        std::regex const reg("([a-z]*)(\\s*(([a-z]+[0-9]?)*)\\((\\d*\\.?\\d*)\\))?"); // new regex
        std::smatch match;

        for (std::string str : _data) {
            if (std::regex_match(str, reg) == false) {
                // throw execption
                return (false);
            }
            if (std::regex_search(str, match, reg) != true)
                return (false);
            _setUpCommand(match);
        }

        return (true);
    }

} // namespace Parser