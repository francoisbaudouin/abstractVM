/*
** EPITECH PROJECT, 2022
** abstractVM
** File description:
** Int8
*/

#include "Float.hpp"

AbstractVM::Float::Float(std::string value) : _value(value), _precision(7), _type(FLOAT) {}

AbstractVM::Float::~Float() {}

AbstractVM::eOperandType AbstractVM::Float::getType() const { return (_type); }

std::string AbstractVM::Float::toString() const { return (std::to_string(_nbr)); }

AbstractVM::IOperand *AbstractVM::Float::operator+(const AbstractVM::IOperand &rhs) const {}
AbstractVM::IOperand *AbstractVM::Float::operator-(const AbstractVM::IOperand &rhs) const {}
AbstractVM::IOperand *AbstractVM::Float::operator*(const AbstractVM::IOperand &rhs) const {}
AbstractVM::IOperand *AbstractVM::Float::operator/(const AbstractVM::IOperand &rhs) const {}
AbstractVM::IOperand *AbstractVM::Float::operator%(const AbstractVM::IOperand &rhs) const {}