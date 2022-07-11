/*
** EPITECH PROJECT, 2022
** abstractVM
** File description:
** Exception
*/

#ifndef EXCEPTION_HPP_
#define EXCEPTION_HPP_

#include <exception>
#include <iostream>

namespace AbstractVM
{
    class Exception : public std::exception {
      public:
        Exception(std::string const &msg) throw();
        const char *what() const throw();

      protected:
      private:
        std::string _str;
    };

    class Test : public Exception {
      public:
        Test(std::string const &msg);
    };

    class InvalideSize : public Exception {
      public:
        InvalideSize(std::string const &msg);
    };

    class EmptyStack : public Exception {
      public:
        EmptyStack(std::string const &msg);
    };

    class AssertException : public Exception {
      public:
        AssertException(std::string const &msg);
    };

    class InvalidType : public Exception {
      public:
        InvalidType(std::string const &msg);
    };

    class EmptyRegister : public Exception {
      public:
        EmptyRegister(std::string const &msg);
    };

    class Underflow : public Exception {
      public:
        Underflow(std::string const &msg, double minValue);
    };

    class Overflow : public Exception {
      public:
        Overflow(std::string const &msg, double minValue);
    };

} // namespace AbstractVM

#endif /* !EXCEPTION_HPP_ */
