/*
** EPITECH PROJECT, 2022
** abstractVM
** File description:
** CommandData
*/

#ifndef COMMAND_DATA_HPP_
#define COMMAND_DATA_HPP_

#include <map>
#include "IOperand.hpp"

namespace Parser
{
    class CommandData {
      public:
        CommandData();
        ~CommandData();
        bool setter(std::string name, std::string type = "", std::string value = "");

        std::string getName();
        AbstractVM::eOperandType geteOperant();
        std::string getValue();

      private:
        bool simpleCommand;
        AbstractVM::eOperandType _type;
        std::string _value;
        std::string _name;
        std::map<std::string, AbstractVM::eOperandType> _whatEOperandIs{{"int8", AbstractVM::eOperandType::INT8},
            {"int16", AbstractVM::eOperandType::INT16}, {"int32", AbstractVM::eOperandType::INT32},
            {"float", AbstractVM::eOperandType::FLOAT}, {"double", AbstractVM::eOperandType::DOUBLE},
            {"bigdecimal", AbstractVM::eOperandType::BIGDECIMAL}};
    };
} // namespace Parser

#endif