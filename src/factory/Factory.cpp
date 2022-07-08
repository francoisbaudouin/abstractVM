/*
** EPITECH PROJECT, 2022
** abstractVM
** File description:
** Factory
*/

#include "Factory.hpp"

#include "types/BigDecimal.hpp"
#include "types/Double.hpp"
#include "types/Float.hpp"
#include "types/Int16.hpp"
#include "types/Int32.hpp"
#include "types/Int8.hpp"

namespace AbstractVM
{
    std::map<eOperandType, IOperand *(*)(const std::string &value)> Factory::operands = {
        std::pair<eOperandType, IOperand *(*)(const std::string &value)>(INT8, &Factory::createInt8),
        std::pair<eOperandType, IOperand *(*)(const std::string &value)>(INT16, &Factory::createInt16),
        std::pair<eOperandType, IOperand *(*)(const std::string &value)>(INT32, &Factory::createInt32),
        std::pair<eOperandType, IOperand *(*)(const std::string &value)>(FLOAT, &Factory::createFloat),
        std::pair<eOperandType, IOperand *(*)(const std::string &value)>(DOUBLE, &Factory::createDouble),
        std::pair<eOperandType, IOperand *(*)(const std::string &value)>(DOUBLE, &Factory::createBigDecimal)};

    IOperand *Factory::createOperand(eOperandType type, const std::string &value)
    {
        Factory tmpFactory;
        auto newOpe = (operands[type]);
        return (newOpe)(value);
    }

    IOperand *Factory::createInt8(const std::string &value) { return (new Int8(value)); }
    IOperand *Factory::createInt16(const std::string &value) { return (new Int16(value)); }
    IOperand *Factory::createInt32(const std::string &value) { return (new Int32(value)); }
    IOperand *Factory::createFloat(const std::string &value) { return (new Float(value)); }
    IOperand *Factory::createDouble(const std::string &value) { return (new Double(value)); }
    IOperand *Factory::createBigDecimal(const std::string &value) { return (new BigDecimal(value)); }

} // namespace AbstractVM