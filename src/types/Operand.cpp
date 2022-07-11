/*
** EPITECH PROJECT, 2022
** abstractVM
** File description:
** Operand
*/

#include "Operand.hpp"
#include <algorithm>
#include <cmath>
#include <iostream>
#include "factory/Factory.hpp"

AbstractVM::Operand::Operand(eOperandType type, const std::string &value, int precision)
    : _type(type), _value(value), _precision(precision)
{
}

AbstractVM::Operand::~Operand() {}

AbstractVM::eOperandType AbstractVM::Operand::getType() const { return (_type); }

std::string AbstractVM::Operand::toString() const { return (_value); }

std::tuple<std::string, std::string> splitString(std::string str)
{
    std::size_t separator = str.find(".");
    std::string frstB;
    std::string frstE;

    if (str.find('.') != std::string::npos) {
        frstB = str.substr(0, separator);
        frstE = str.substr(separator+1);
    } else {
        frstB = str;
        frstE = "";
    }
    return {frstB, frstE};
}

std::string fillstring(std::string str, size_t size, bool begin)
{
    for (size_t i = str.size(); i != size; i++) {
        if (begin == true)
            str.insert(0,"0");
        else
            str.push_back('0');
    }
    return (str);
}

std::tuple<std::string, std::string> fillSmallestString(std::string frst, std::string scnd, bool begin)
{
    if (frst.size() < scnd.size())
        return {fillstring(frst, scnd.size(), begin), scnd};
    return {fillstring(scnd, frst.size(), begin), frst};
}

std::tuple<int, std::string>addString(std::string frst, std::string scnd, size_t size, int c)
{
    std::string newstr;
    int sum = 0;
    for (int i = size-1; i >= 0; i--) {
        sum = frst.at(i) - '0' + scnd.at(i) - '0' + c;
        c = 0;
        if (sum > 9) {
            c = sum/10;
            sum %= 10;
        }
        newstr.insert(0, std::to_string(sum));
    }
    return {c, newstr};
}

std::string AbstractVM::Operand::infinAdd(std::string frst, std::string scnd) const
{
    int c = 0;
    std::tuple<std::string, std::string> frstTuple = splitString(frst);
    std::tuple<std::string, std::string> scndTuple = splitString(scnd);
    std::tuple<std::string, std::string> smallesStringB = fillSmallestString(std::get<0>(frstTuple), std::get<0>(scndTuple), true);
    std::tuple<std::string, std::string> smallesStringE = fillSmallestString(std::get<1>(frstTuple), std::get<1>(scndTuple), false);
    std::tuple<int, std::string> scndC = addString(std::get<0>(smallesStringE), std::get<1>(smallesStringE), std::get<0>(smallesStringE).size(), c);
    c = std::get<0>(scndC);
    std::tuple<int, std::string> frstC = addString(std::get<0>(smallesStringB), std::get<1>(smallesStringB), std::get<0>(smallesStringB).size(), c);

    frst = std::get<1>(frstC);
    scnd = std::get<1>(scndC);

    return (frst+"."+scnd);
}

AbstractVM::IOperand *AbstractVM::Operand::operator+(const AbstractVM::IOperand &rhs) const
{
    IOperand *newope;
    AbstractVM::Factory *factory = new AbstractVM::Factory();

    std::string ope1 = rhs.toString();
    std::string ope2 = this->toString();

    std::string newValue = infinAdd(ope1, ope2);

    if (this->getPrecision() < rhs.getPrecision())
        newope = factory->createOperand(rhs.getType(), newValue);
    else
        newope = factory->createOperand(this->getType(), newValue);
    return newope;
}

AbstractVM::IOperand *AbstractVM::Operand::operator-(const AbstractVM::IOperand &rhs) const
{
    IOperand *newope;
    AbstractVM::Factory *factory = new AbstractVM::Factory();

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
    AbstractVM::Factory *factory = new AbstractVM::Factory();

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
    AbstractVM::Factory *factory = new AbstractVM::Factory();

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
    AbstractVM::Factory *factory = new AbstractVM::Factory();

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
