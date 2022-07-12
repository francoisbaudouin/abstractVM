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

AbstractVM::EmptyStack::EmptyStack(std::string const &msg) : Exception("error: " + msg + " on empty stack.") {}

AbstractVM::InvalideSize::InvalideSize(std::string const &msg)
    : Exception("error: " + msg + " on a stack with a size less than 2 values")
{
}

AbstractVM::AssertException::AssertException(std::string const &msg)
    : Exception("error: " + msg + " : not the same values")
{
}

AbstractVM::InvalidType::InvalidType(std::string const &msg)
    : Exception("error: " + msg + " : The top value should be an INT8")
{
}

AbstractVM::EmptyRegister::EmptyRegister(std::string const &msg) : Exception("error: " + msg + " on an empty register")
{
}

AbstractVM::Underflow::Underflow(std::string const &msg, double minValue)
    : Exception("error: " + msg + "the value should be greater than" + std::to_string(minValue))
{
}

AbstractVM::Overflow::Overflow(std::string const &msg, double minValue)
    : Exception("error: " + msg + "the value should be lower than" + std::to_string(minValue))
{
}

AbstractVM::InvalidFile::InvalidFile(std::string const &msg)
    : Exception("error: " + msg + " : File doesn't exist or any other occurred")
{
}

AbstractVM::ParssingFile::ParssingFile(std::string const &msg)
    : Exception("error: " + msg + " : parssing part have problème")
{
}
