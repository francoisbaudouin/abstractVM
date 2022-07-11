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
        std::vector<std::string> delimiters{" ", "(", ")"};
        std::string delimitersCommand = " ";
        std::string delimitersEOperand = "(";
        std::string delimitersValue = ")";
        std::string token;
        size_t position = 0;
        int nmIteration;

        for (const std::string &str : delimiters) {
            while (position != std::string::npos) {
                position = commandLine.find(str);
                token = commandLine.substr(0, position);
                commandLine.erase(0, position + str.length());
                switch (nmIteration)
                {
                case (1):
                    /* code */
                    break;
                
                default:
                    break;
                }
            }
        }
        // rm command

        // take my eOprand
        position = commandLine.find(delimitersEOperand);
        token = commandLine.substr(0, position);
        commandLine.erase(0, position + delimitersEOperand.length());
        std::map<std::string, AbstractVM::eOperandType>::const_iterator it = whatEOperandIs.find(token);
        if (it == whatEOperandIs.end()) {
            // throw excption >
            return (false);
        }
        _dataCommand->first = it->second;

        // take my value
        position = commandLine.find(delimitersValue);
        token = commandLine.substr(0, position);
        _dataCommand->second = token;
        return (true);
    }
} // namespace Parser