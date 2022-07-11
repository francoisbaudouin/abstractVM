/*
** EPITECH PROJECT, 2022
** abstractVM
** File description:
** Interpretor
*/

#include "Interpretor.hpp"
#include "factory/Factory.hpp"

namespace Parser
{
    Interpretor::Interpretor() {}

    Interpretor::~Interpretor()
    {
        if (!_functPtr.empty()) {
            _functPtr.clear();
        }
    }

    bool Interpretor::setDataCommand(AbstractVM::eOperandType type, std::string value)
    {
        AbstractVM::Factory tmpFactory;

        _dataCommand = tmpFactory.operands.at(type)(value);
        return (true);
    }

} // namespace Parser