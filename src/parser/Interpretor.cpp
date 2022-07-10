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

        // here token is equal to eOprand
        position = commandLine.find(delimitersCommand);
        commandLine.erase(0, position + delimitersCommand.length());
        token = commandLine.substr(0, position);

        std::cout << "mon token: " << token << std::endl;

        position = commandLine.find(delimitersEOperand);
        token = commandLine.substr(0, position);
        commandLine.erase(0, position + delimitersEOperand.length());

        std::cout << "reste de commande : " << commandLine << std::endl;
        std::cout << "Ma commande stock : " << commandLine << std::endl;

        position = commandLine.find(delimitersValue);
        token = commandLine.substr(0, position);
        //commandLine.erase(0, position + delimitersValue.length());

        std::cout << "reste de commande : " << commandLine << std::endl;
        std::cout << "Ma commande stock : " << commandLine << std::endl;

        return (true);
    }
} // namespace Parser