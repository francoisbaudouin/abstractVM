/*
** EPITECH PROJECT, 2022
** abstractVM
** File description:
** Int8
*/

#include "BigDecimal.hpp"

AbstractVM::BigDecimal::BigDecimal(std::string value) : _value(value), _precision(200), _type(BIGDECIMAL) {}

AbstractVM::BigDecimal::~BigDecimal() {}
