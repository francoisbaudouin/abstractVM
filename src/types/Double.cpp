/*
** EPITECH PROJECT, 2022
** abstractVM
** File description:
** Int8
*/

#include "Double.hpp"

AbstractVM::Double::Double(std::string value) : AbstractVM::Operand(AbstractVM::DOUBLE, value, 15) {}

AbstractVM::Double::~Double() {}
