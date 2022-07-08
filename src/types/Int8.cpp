/*
** EPITECH PROJECT, 2022
** abstractVM
** File description:
** Int8
*/

#include "Int8.hpp"
#include <string>

AbstractVM::Int8::Int8(std::string value) : _value(value), _precision(0), _type(INT8) {}

AbstractVM::Int8::~Int8() {}

AbstractVM::eOperandType AbstractVM::Int8::getType() const { return (_type); }

std::string AbstractVM::Int8::toString() const { return (std::to_string(_nbr)); }

AbstractVM::IOperand *AbstractVM::Int8::operator+(const AbstractVM::IOperand &rhs) const {}
AbstractVM::IOperand *AbstractVM::Int8::operator-(const AbstractVM::IOperand &rhs) const {}
AbstractVM::IOperand *AbstractVM::Int8::operator*(const AbstractVM::IOperand &rhs) const {}
AbstractVM::IOperand *AbstractVM::Int8::operator/(const AbstractVM::IOperand &rhs) const {}
AbstractVM::IOperand *AbstractVM::Int8::operator%(const AbstractVM::IOperand &rhs) const {}