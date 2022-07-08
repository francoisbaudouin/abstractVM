/*
** EPITECH PROJECT, 2022
** abstractVM
** File description:
** Factory
*/

#include "Factory.hpp"
#include "Int8.hpp"
#include "Int16.hpp"
#include "Int32.hpp"
#include "Float.hpp"
#include "Double.hpp"
#include "BigDecimal.hpp"

AbstractVM::Factory::Factory()
{
	_operands[INT8] = &Factory::createInt8;
	_operands[INT16] = &Factory::createInt16;
	_operands[INT32] = &Factory::createInt32;
	_operands[FLOAT] = &Factory::createFloat;
	_operands[DOUBLE] = &Factory::createDouble;
	_operands[BIGDECIMAL] = &Factory::createBigDecimal;
}

AbstractVM::Factory::~Factory()
{
}

AbstractVM::IOperand *AbstractVM::Factory::createOperand(eOperandType type, const std::string &value)
{
    Factory tmpFactory;
    return ((tmpFactory.*_operands[type])(value));
}

AbstractVM::IOperand *createInt8(const std::string &value)
{
	return (new AbstractVM::Int8(value));
}

AbstractVM::IOperand *createInt16(const std::string &value)
{
	return (new AbstractVM::Int16(value));
}

AbstractVM::IOperand *createInt32(const std::string &value)
{
	return (new AbstractVM::Int32(value));
}

AbstractVM::IOperand *createFloat(const std::string &value)
{
	return (new AbstractVM::Float(value));
}

AbstractVM::IOperand *createDouble(const std::string &value)
{
	return (new AbstractVM::Double(value));
}

AbstractVM::IOperand *createBigDecimal(const std::string &value)
{
	return (new AbstractVM::Double(value));
}