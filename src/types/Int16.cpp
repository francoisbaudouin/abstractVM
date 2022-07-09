/*
** EPITECH PROJECT, 2022
** abstractVM
** File description:
** Int16
*/

#include "Int16.hpp"

AbstractVM::Int16::Int16(std::string value) : AbstractVM::Operand(AbstractVM::INT16, value, 0) {}

AbstractVM::Int16::~Int16() {}
