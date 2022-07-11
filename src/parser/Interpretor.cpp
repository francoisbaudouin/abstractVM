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
        if (type == AbstractVM::eOperandType::UNKNOWN || value.compare("") == 0)
            return (false);

        if (test == true) {
            free(_dataCommand);
        }
        _dataCommand = AbstractVM::Factory::operands.at(type)(value);
        return (true);
    }

} // namespace Parser