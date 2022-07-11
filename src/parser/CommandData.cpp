/*
** EPITECH PROJECT, 2022
** abstractVM
** File description:
** CommandData
*/

#include "CommandData.hpp"

namespace Parser
{
    CommandData::CommandData() {}

    CommandData::~CommandData() {}

    bool CommandData::setter(std::string name, std::string type, std::string value)
    {
        _name = name;
        _value = value;

        std::map<std::string, AbstractVM::eOperandType>::iterator it = _whatEOperandIs.find(type);

        if (it == _whatEOperandIs.end())
            return (false);
        if (type.compare("") == 0)
            _type = AbstractVM::eOperandType::UNKNOWN;
        _type = it->second;
        return (true);
    }

    std::string CommandData::getName() { return (_name); }

    AbstractVM::eOperandType CommandData::geteOperant() { return (_type); }

    std::string CommandData::getValue() { return (_value); }
}; // namespace Parser
