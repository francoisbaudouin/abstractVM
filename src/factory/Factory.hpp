/*
** EPITECH PROJECT, 2022
** abstractVM
** File description:
** Factory
*/

#ifndef OPERANDFACTORY_HPP_
#define OPERANDFACTORY_HPP_

#include <map>
#include "IOperand.hpp"

namespace AbstractVM
{
    class Factory {
      public:
        static IOperand *createOperand(eOperandType type, const std::string &value);
        static std::map<eOperandType, IOperand *(*)(const std::string &value)> operands;
      protected:
      private:
        static IOperand *createInt8(const std::string &value);
        static IOperand *createInt16(const std::string &value);
        static IOperand *createInt32(const std::string &value);
        static IOperand *createFloat(const std::string &value);
        static IOperand *createDouble(const std::string &value);
        static IOperand *createBigDecimal(const std::string &value);
    };
} // namespace AbstractVM

#endif /* !OPERANDFACTORY_HPP_ */
