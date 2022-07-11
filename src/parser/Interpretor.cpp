/*
** EPITECH PROJECT, 2022
** abstractVM
** File description:
** Interpretor
*/

#include "Interpretor.hpp"

namespace Parser
{
    Interpretor::Interpretor() {}

    Interpretor::~Interpretor()
    {
        if (!_functPtr.empty()) {
            _functPtr.clear();
        }
    }

    void Interpretor::setValue(int value) { _value = value; }

    void Interpretor::setValue(std::shared_ptr<int> val) { _val = val; }

    std::string Interpretor::getGivenCommand(std::string commandLine)
    {
        std::string delimiters = " ";
        std::string token = commandLine.substr(0, commandLine.find(delimiters));

        return (token);
    }

    bool Interpretor::setDataCommand(std::tuple<AbstractVM::eOperandType, std::string> data)
    {
        _dataCommand->first = std::get<0>(data);
        _dataCommand->second = std::get<1>(data);
        return (true);
    }

} // namespace Parser