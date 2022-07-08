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
#include "types/BigDecimal.hpp"
#include "types/Double.hpp"
#include "types/Float.hpp"
#include "types/Int16.hpp"
#include "types/Int32.hpp"
#include "types/Int8.hpp"

namespace AbstractVM
{
    class Factory {
      public:
        static IOperand *createOperand(eOperandType type, const std::string &value);
        static std::map<eOperandType, IOperand *(Factory::*)(const std::string &value)> operands;
      protected:
      private:
        IOperand *createInt8(const std::string &value);
        IOperand *createInt16(const std::string &value);
        IOperand *createInt32(const std::string &value);
        IOperand *createFloat(const std::string &value);
        IOperand *createDouble(const std::string &value);
        IOperand *createBigDecimal(const std::string &value);
    };
} // namespace AbstractVM

#endif /* !OPERANDFACTORY_HPP_ */
