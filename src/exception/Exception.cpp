/*
** EPITECH PROJECT, 2022
** abstractVM
** File description:
** Exception
*/

#include "Exception.hpp"

AbstractVM::Exception::Exception(const std::string &str) throw() : _str(str)
{
}

AbstractVM::Exception::~Exception() throw()
{
}

const char *AbstractVM::Exception::what() const throw()
{
    return (_str.c_str());
}
