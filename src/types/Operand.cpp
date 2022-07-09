/*
** EPITECH PROJECT, 2022
** abstractVM
** File description:
** Operand
*/

#include "Operand.hpp"
#include <cmath>
#include "factory/Factory.hpp"

AbstractVM::Operand::Operand(eOperandType type, const std::string &value, int precision)
    : _type(type), _value(value), _precision(precision)
{
}

AbstractVM::Operand::~Operand() {}

AbstractVM::eOperandType AbstractVM::Operand::getType() const { return (_type); }

std::string AbstractVM::Operand::toString() const { return (_value); }

AbstractVM::IOperand *AbstractVM::Operand::operator+(const AbstractVM::IOperand &rhs) const
{
    IOperand *newope;
    AbstractVM::Factory *factory = new Factory();

    double rhsDouble = std::stod(rhs.toString());
    double thisDouble = std::stod(this->toString());

    double newDouble = rhsDouble + thisDouble;

    std::string newValue = std::to_string(newDouble);

    if (this->getPrecision() < rhs.getPrecision())
        newope = factory->createOperand(rhs.getType(), newValue);
    else
        newope = factory->createOperand(this->getType(), newValue);

    return newope;
}

AbstractVM::IOperand *AbstractVM::Operand::operator-(const AbstractVM::IOperand &rhs) const
{
    IOperand *newope;
    AbstractVM::Factory *factory = new Factory();

    double rhsDouble = std::stod(rhs.toString());
    double thisDouble = std::stod(this->toString());

    double newDouble = rhsDouble - thisDouble;

    std::string newValue = std::to_string(newDouble);

    if (this->getPrecision() < rhs.getPrecision())
        newope = factory->createOperand(rhs.getType(), newValue);
    else
        newope = factory->createOperand(this->getType(), newValue);

    return newope;
}

AbstractVM::IOperand *AbstractVM::Operand::operator*(const AbstractVM::IOperand &rhs) const
{
    IOperand *newope;
    AbstractVM::Factory *factory = new Factory();

    double rhsDouble = std::stod(rhs.toString());
    double thisDouble = std::stod(this->toString());

    double newDouble = rhsDouble * thisDouble;

    std::string newValue = std::to_string(newDouble);

    if (this->getPrecision() < rhs.getPrecision())
        newope = factory->createOperand(rhs.getType(), newValue);
    else
        newope = factory->createOperand(this->getType(), newValue);

    return newope;
}

AbstractVM::IOperand *AbstractVM::Operand::operator/(const AbstractVM::IOperand &rhs) const
{
    IOperand *newope;
    AbstractVM::Factory *factory = new Factory();

    double rhsDouble = std::stod(rhs.toString());
    double thisDouble = std::stod(this->toString());

    double newDouble = rhsDouble / thisDouble;

    std::string newValue = std::to_string(newDouble);

    if (this->getPrecision() < rhs.getPrecision())
        newope = factory->createOperand(rhs.getType(), newValue);
    else
        newope = factory->createOperand(this->getType(), newValue);

    return newope;
}

AbstractVM::IOperand *AbstractVM::Operand::operator%(const AbstractVM::IOperand &rhs) const
{
    IOperand *newope;
    AbstractVM::Factory *factory = new Factory();

    double rhsDouble = std::stod(rhs.toString());
    double thisDouble = std::stod(this->toString());

    double newDouble = std::fmod(rhsDouble, thisDouble);

    std::string newValue = std::to_string(newDouble);

    if (this->getPrecision() < rhs.getPrecision())
        newope = factory->createOperand(rhs.getType(), newValue);
    else
        newope = factory->createOperand(this->getType(), newValue);

    return newope;
};
int AbstractVM::Operand::getPrecision() const { return (_precision); }
