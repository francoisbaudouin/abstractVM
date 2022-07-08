/*
** EPITECH PROJECT, 2022
** abstractVM
** File description:
** Factory
*/

#include "Factory.hpp"

std::map<AbstractVM::eOperandType, AbstractVM::IOperand *(AbstractVM::Factory::*)(const std::string &value)> AbstractVM::Factory::operands = {
    std::pair<eOperandType, IOperand *(Factory::*)(const std::string &value)> (AbstractVM::INT8, &Factory::createInt8),
    std::pair<eOperandType, IOperand *(Factory::*)(const std::string &value)> (AbstractVM::INT16, &Factory::createInt16),
    std::pair<eOperandType, IOperand *(Factory::*)(const std::string &value)> (AbstractVM::INT32, &Factory::createInt32),
    std::pair<eOperandType, IOperand *(Factory::*)(const std::string &value)> (AbstractVM::FLOAT, &Factory::createFloat),
    std::pair<eOperandType, IOperand *(Factory::*)(const std::string &value)> (AbstractVM::DOUBLE, &Factory::createDouble),
    std::pair<eOperandType, IOperand *(Factory::*)(const std::string &value)> (AbstractVM::BIGDECIMAL, &Factory::createBigDecimal)
};

AbstractVM::IOperand *AbstractVM::Factory::createOperand(eOperandType type, const std::string &value)
{
    Factory tmpFactory;
    AbstractVM::IOperand *newOpe = (tmpFactory.*operands[type])(value);
    return (newOpe);
    // IOperand *(Factory::*)(const std::string &value) operandFactory = operands[type];
    // return operandFactory(value);
}

AbstractVM::IOperand *createInt8(const std::string &value) { return (new AbstractVM::Int8(value)); }

AbstractVM::IOperand *createInt16(const std::string &value) { return (new AbstractVM::Int16(value)); }

AbstractVM::IOperand *createInt32(const std::string &value) { return (new AbstractVM::Int32(value)); }

AbstractVM::IOperand *createFloat(const std::string &value) { return (new AbstractVM::Float(value)); }

AbstractVM::IOperand *createDouble(const std::string &value) { return (new AbstractVM::Double(value)); }

AbstractVM::IOperand *createBigDecimal(const std::string &value) { return (new AbstractVM::Double(value)); }