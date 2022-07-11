/*
** EPITECH PROJECT, 2022
** abstractVM
** File description:
** Exception
*/

#include "Exception.hpp"

AbstractVM::Exception::Exception(const std::string &str) throw() : _str(str) {}

const char *AbstractVM::Exception::what() const throw() { return (_str.c_str()); }

AbstractVM::Test::Test(std::string const &msg) : Exception(msg) {}