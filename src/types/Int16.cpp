/*
** EPITECH PROJECT, 2022
** abstractVM
** File description:
** Int16
*/

#include "Int16.hpp"

AbstractVM::Int16::Int16(std::string value) : _value(value), _precision(0), _type(INT16) {}

AbstractVM::Int16::~Int16() {}

AbstractVM::eOperandType AbstractVM::Int16::getType() const { return (_type); }

std::string AbstractVM::Int16::toString() const { return (std::to_string(_nbr)); }

AbstractVM::IOperand *AbstractVM::Int16::operator+(const AbstractVM::IOperand &rhs) const {}
AbstractVM::IOperand *AbstractVM::Int16::operator-(const AbstractVM::IOperand &rhs) const {}
AbstractVM::IOperand *AbstractVM::Int16::operator*(const AbstractVM::IOperand &rhs) const {}
AbstractVM::IOperand *AbstractVM::Int16::operator/(const AbstractVM::IOperand &rhs) const {}
AbstractVM::IOperand *AbstractVM::Int16::operator%(const AbstractVM::IOperand &rhs) const {}
