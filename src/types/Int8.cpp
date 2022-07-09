/*
** EPITECH PROJECT, 2022
** abstractVM
** File description:
** Int8
*/

#include "Int8.hpp"
#include <string>

AbstractVM::Int8::Int8(std::string value) : AbstractVM::Operand(AbstractVM::INT8, value, 0) {}

AbstractVM::Int8::~Int8() {}
