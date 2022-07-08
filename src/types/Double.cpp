/*
** EPITECH PROJECT, 2022
** abstractVM
** File description:
** Int8
*/

#include "Double.hpp"

AbstractVM::Double::Double(std::string value) : _value(value), _precision(15), _type(DOUBLE) {}

AbstractVM::Double::~Double() {}

AbstractVM::eOperandType AbstractVM::Double::getType() const { return (_type); }

std::string AbstractVM::Double::toString() const { return (std::to_string(_nbr)); }

AbstractVM::IOperand *AbstractVM::Double::operator+(const AbstractVM::IOperand &rhs) const {}
AbstractVM::IOperand *AbstractVM::Double::operator-(const AbstractVM::IOperand &rhs) const {}
AbstractVM::IOperand *AbstractVM::Double::operator*(const AbstractVM::IOperand &rhs) const {}
AbstractVM::IOperand *AbstractVM::Double::operator/(const AbstractVM::IOperand &rhs) const {}
AbstractVM::IOperand *AbstractVM::Double::operator%(const AbstractVM::IOperand &rhs) const {}