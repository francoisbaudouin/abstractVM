/*
** EPITECH PROJECT, 2022
** abstractVM
** File description:
** Int8
*/

#include "BigDecimal.hpp"

AbstractVM::BigDecimal::BigDecimal(std::string value) : _value(value), _precision(200), _type(BIGDECIMAL) {}

AbstractVM::BigDecimal::~BigDecimal() {}

AbstractVM::eOperandType AbstractVM::BigDecimal::getType() const { return (_type); }

std::string AbstractVM::BigDecimal::toString() const { return (std::to_string(_nbr)); }

AbstractVM::IOperand *AbstractVM::BigDecimal::operator+(const AbstractVM::IOperand &rhs) const {}
AbstractVM::IOperand *AbstractVM::BigDecimal::operator-(const AbstractVM::IOperand &rhs) const {}
AbstractVM::IOperand *AbstractVM::BigDecimal::operator*(const AbstractVM::IOperand &rhs) const {}
AbstractVM::IOperand *AbstractVM::BigDecimal::operator/(const AbstractVM::IOperand &rhs) const {}
AbstractVM::IOperand *AbstractVM::BigDecimal::operator%(const AbstractVM::IOperand &rhs) const {}