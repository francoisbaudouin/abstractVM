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

    bool Interpretor::setDataCommand(std::string commandLine)
    {
        std::string delimitersCommand = " ";
        std::string delimitersEOperand = "(";
        std::string delimitersValue = ")";
        std::string token;
        size_t position = 0;

        // rm command
        position = commandLine.find(delimitersCommand);
        token = commandLine.substr(0, position);
        commandLine.erase(0, position + delimitersCommand.length());

        // take my eOprand
        position = commandLine.find(delimitersEOperand);
        token = commandLine.substr(0, position);
        commandLine.erase(0, position + delimitersEOperand.length());

        // take my value
        position = commandLine.find(delimitersValue);
        token = commandLine.substr(0, position);

        return (true);
    }
} // namespace Parser