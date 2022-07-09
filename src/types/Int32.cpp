/*
** EPITECH PROJECT, 2022
** abstractVM
** File description:
** Int32
*/

#include "Int32.hpp"

AbstractVM::Int32::Int32(std::string value) : AbstractVM::Operand(AbstractVM::INT32, value, 0) {}

AbstractVM::Int32::~Int32() {}
