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
        std::string delimiters = " ()";
        std::string token;
        size_t position = 0;
        std::cout << "test" << std::endl;
        while ((position = commandLine.find(delimiters)) != std::string::npos) {
            token = token.substr(0, token.find(delimiters));
            std::cout << token << std::endl;
            commandLine.erase(0, position + delimiters.length());
        }

        return (true);
    }
} // namespace Parser