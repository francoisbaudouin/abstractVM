/*
** EPITECH PROJECT, 2022
** abstractVM
** File description:
** Int8
*/

#include "BigDecimal.hpp"

AbstractVM::BigDecimal::BigDecimal(std::string value) : AbstractVM::Operand(AbstractVM::BIGDECIMAL, value, 200) {}

AbstractVM::BigDecimal::~BigDecimal() {}
