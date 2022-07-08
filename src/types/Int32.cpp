/*
** EPITECH PROJECT, 2022
** abstractVM
** File description:
** Int32
*/

#include "Int32.hpp"

AbstractVM::Int32::Int32(std::string value) : _value(value), _precision(0), _type(INT32) {}

AbstractVM::Int32::~Int32() {}

AbstractVM::eOperandType AbstractVM::Int32::getType() const { return (_type); }

std::string AbstractVM::Int32::toString() const { return (std::to_string(_nbr)); }

AbstractVM::IOperand *AbstractVM::Int32::operator+(const AbstractVM::IOperand &rhs) const {}
AbstractVM::IOperand *AbstractVM::Int32::operator-(const AbstractVM::IOperand &rhs) const {}
AbstractVM::IOperand *AbstractVM::Int32::operator*(const AbstractVM::IOperand &rhs) const {}
AbstractVM::IOperand *AbstractVM::Int32::operator/(const AbstractVM::IOperand &rhs) const {}
AbstractVM::IOperand *AbstractVM::Int32::operator%(const AbstractVM::IOperand &rhs) const {}