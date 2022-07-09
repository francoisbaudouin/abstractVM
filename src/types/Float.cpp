/*
** EPITECH PROJECT, 2022
** abstractVM
** File description:
** Int8
*/

#include "Float.hpp"

AbstractVM::Float::Float(std::string value) : AbstractVM::Operand(AbstractVM::FLOAT, value, 7) {}

AbstractVM::Float::~Float() {}
