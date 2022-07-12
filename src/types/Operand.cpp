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
        frstE = str.substr(separator + 1);
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
            str.insert(0, "0");
        else
            str.push_back('0');
    }
    return (str);
}

std::tuple<std::string, std::string> fillSmallestString(std::string frst, std::string scnd, bool begin)
{
    if (frst.size() < scnd.size())
        return {fillstring(frst, scnd.size(), begin), scnd};
    return {frst, fillstring(scnd, frst.size(), begin)};
}

std::string removeZero(std::string str)
{
    for (size_t i = 0; str.at(0) == '0' && i + 1 != str.size(); i++)
        str.erase(str.begin());
    return (str);
}

std::tuple<int, std::string> subString(std::string scnd, std::string frst, size_t size, int c)
{
    std::string newstr;
    int sum = 0;
    for (int i = size - 1; i >= 0; i--) {
        sum = (scnd.at(i) - '0') - (frst.at(i) - '0');
        if (c != 0) {
            c = 0;
            sum--;
        }
        if (sum < 0) {
            sum += 10;
            c = 1;
        }
        newstr.insert(0, std::to_string(sum));
    }
    return {c, newstr};
}

std::tuple<int, std::string> addString(std::string frst, std::string scnd, size_t size, int c)
{
    std::string newstr;
    int sum = 0;
    for (int i = size - 1; i >= 0; i--) {
        sum = frst.at(i) - '0' + scnd.at(i) - '0' + c;
        c = 0;
        if (sum > 9) {
            c = sum / 10;
            sum %= 10;
        }
        newstr.insert(0, std::to_string(sum));
    }
    return {c, newstr};
}

std::string AbstractVM::Operand::infinSub(std::string frst, std::string scnd) const
{
    int c = 0;
    std::tuple<std::string, std::string> frstTuple = splitString(frst);
    std::tuple<std::string, std::string> scndTuple = splitString(scnd);
    std::tuple<std::string, std::string> smallesStringB =
        fillSmallestString(std::get<0>(frstTuple), std::get<0>(scndTuple), true);
    std::tuple<std::string, std::string> smallesStringE =
        fillSmallestString(std::get<1>(frstTuple), std::get<1>(scndTuple), false);
    std::tuple<int, std::string> scndC =
        subString(std::get<0>(smallesStringE), std::get<1>(smallesStringE), std::get<0>(smallesStringE).size(), c);
    c = std::get<0>(scndC);
    std::tuple<int, std::string> frstC =
        subString(std::get<0>(smallesStringB), std::get<1>(smallesStringB), std::get<0>(smallesStringB).size(), c);
    c = std::get<0>(frstC);

    frst = std::get<1>(frstC);
    scnd = std::get<1>(scndC);

    frst = removeZero(frst);

    if (scnd.size() > 0)
        frst += "." + scnd;

    return (frst);
}

std::string AbstractVM::Operand::infinAdd(std::string frst, std::string scnd) const
{
    int c = 0;
    std::tuple<std::string, std::string> frstTuple = splitString(frst);
    std::tuple<std::string, std::string> scndTuple = splitString(scnd);

    std::tuple<std::string, std::string> smallesStringB =
        fillSmallestString(std::get<0>(frstTuple), std::get<0>(scndTuple), true);
    std::tuple<std::string, std::string> smallesStringE =
        fillSmallestString(std::get<1>(frstTuple), std::get<1>(scndTuple), false);

    std::tuple<int, std::string> scndC =
        addString(std::get<0>(smallesStringE), std::get<1>(smallesStringE), std::get<0>(smallesStringE).size(), c);
    c = std::get<0>(scndC);
    std::tuple<int, std::string> frstC =
        addString(std::get<0>(smallesStringB), std::get<1>(smallesStringB), std::get<0>(smallesStringB).size(), c);
    c = std::get<0>(frstC);

    frst = std::get<1>(frstC);
    scnd = std::get<1>(scndC);

    if (c != 0) {
        frst.insert(0, std::to_string(c));
    }
    if (scnd.size() > 0)
        frst += "." + scnd;

    return (frst);
}

int isneg(std::string str)
{
    if (str.find('-') != std::string::npos)
        return (1);
    return (0);
}

std::tuple<int, int> getsign(std::string frst, std::string scnd) { return {isneg(frst), isneg(scnd)}; }

int getbigger(std::string frst, std::string scnd)
{
    std::tuple<std::string, std::string> frstTuple = splitString(frst);
    std::tuple<std::string, std::string> scndTuple = splitString(scnd);

    std::string frstB = std::get<0>(frstTuple) + std::get<1>(frstTuple);
    std::string scndB = std::get<0>(scndTuple) + std::get<1>(scndTuple);

    if (std::get<0>(frstTuple).size() > std::get<0>(scndTuple).size())
        return (1);
    else if (std::get<0>(frstTuple).size() < std::get<0>(scndTuple).size())
        return (0);

    if (frstB.compare(scndB) == 0)
        return (3);
    for (size_t i = 0; i < frstB.size(); i++) {
        if (frstB.at(i) != scndB.at(i)) {
            if (frstB.at(i) > scndB.at(i))
                return (1);
            return (0);
        }
    }
    return (1);
}

std::string AbstractVM::Operand::opeManagementAdd(std::string frst, std::string scnd) const
{
    std::tuple<int, int> strSign = getsign(frst, scnd);

    frst.erase(remove(frst.begin(), frst.end(), '-'), frst.end());
    scnd.erase(remove(scnd.begin(), scnd.end(), '-'), scnd.end());

    int mSize = getbigger(frst, scnd);

    if (mSize == 3 && std::tuple<int, int>{1, 1} == strSign)
        return (infinAdd(frst, scnd).insert(0, "-"));

    if (strSign == std::tuple<int, int>{0, 1} && mSize == 0) {
        return (infinSub(scnd, frst).insert(0, "-"));
    } else if (strSign == std::tuple<int, int>{1, 0} && mSize == 0) {
        return (infinSub(scnd, frst));
    } else if (strSign == std::tuple<int, int>{0, 1} && mSize == 1) {
        return (infinSub(frst, scnd));
    } else if (strSign == std::tuple<int, int>{1, 1} && mSize == 0) {
        return (infinAdd(frst, scnd).insert(0, "-"));
    } else if (strSign == std::tuple<int, int>{0, 0}) {
        return (infinAdd(frst, scnd));
    } else {
        return (infinSub(frst, scnd).insert(0, "-"));
    }
}

std::string AbstractVM::Operand::opeManagementSub(std::string frst, std::string scnd) const
{
    std::tuple<int, int> strSign = getsign(frst, scnd);

    frst.erase(remove(frst.begin(), frst.end(), '-'), frst.end());
    scnd.erase(remove(scnd.begin(), scnd.end(), '-'), scnd.end());

    int mSize = getbigger(frst, scnd);

    if (mSize == 3 && std::tuple<int, int>{1, 1} == strSign)
        return (infinAdd(frst, scnd).insert(0, "-"));

    if (strSign == std::tuple<int, int>{1, 1} && mSize == 1) {
        return (infinSub(frst, scnd).insert(0, "-"));
    } else if (strSign == std::tuple<int, int>{0, 0} && mSize == 1) {
        return (infinSub(frst, scnd));
    } else if (strSign == std::tuple<int, int>{0, 1}) {
        return (infinAdd(frst, scnd));
    } else if (strSign == std::tuple<int, int>{1, 0}) {
        return (infinAdd(frst, scnd).insert(0, "-"));
    } else if (strSign == std::tuple<int, int>{0, 0} && mSize == 0) {
        return (infinSub(scnd, frst).insert(0, "-"));
    } else {
        return (infinSub(scnd, frst));
    }
}

AbstractVM::IOperand *AbstractVM::Operand::operator+(const AbstractVM::IOperand &rhs) const
{
    IOperand *newope;
    AbstractVM::Factory *factory = new AbstractVM::Factory();

    std::string ope1 = this->toString();
    std::string ope2 = rhs.toString();

    std::string newValue = opeManagementAdd(ope1, ope2);

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

    std::string ope1 = this->toString();
    std::string ope2 = rhs.toString();

    std::string newValue = opeManagementSub(ope1, ope2);

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

    double ope1 = std::stod(this->toString());
    double ope2 = std::stod(rhs.toString());

    double newDouble = ope2 / ope1;

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

    double ope1 = std::stod(this->toString());
    double ope2 = std::stod(rhs.toString());

    double newDouble = std::fmod(ope2, ope1);

    std::string newValue = std::to_string(newDouble);

    if (this->getPrecision() < rhs.getPrecision())
        newope = factory->createOperand(rhs.getType(), newValue);
    else
        newope = factory->createOperand(this->getType(), newValue);

    return newope;
};

int AbstractVM::Operand::getPrecision() const { return (_precision); }
