/*
** EPITECH PROJECT, 2022
** abstractVM
** File description:
** Parser
*/

#ifndef PARSER_HPP_
#define PARSER_HPP_

#include <filesystem>
#include <iostream>
#include <regex>
#include <string>
#include <tuple>
#include <vector>
#include "IOperand.hpp"

namespace Parser
{
    class ParssCommand {
      public:
        ParssCommand();
        ~ParssCommand();
        // read Data from file pass as parameter
        int readData(const std::string filepath);
        // read Data from input and write in dataInput.avm
        int readData();

        bool checkProvideData();

        const std::map<std::string, std::tuple<AbstractVM::eOperandType, std::string>> getDataCommand();

      protected:
      private:
        bool _setUpCommand(std::smatch match);
        std::tuple<AbstractVM::eOperandType, std::string> _getdataCommand(std::string eoprand, std::string value);

        bool _exitIsCalled;
        bool _allowToWriteData;
        std::vector<std::string> _data;
        std::map<std::string, std::tuple<AbstractVM::eOperandType, std::string>> _dataCommand;

        std::map<std::string, AbstractVM::eOperandType> _whatEOperandIs{{"int8", AbstractVM::eOperandType::INT8},
            {"int16", AbstractVM::eOperandType::INT16}, {"int32", AbstractVM::eOperandType::INT32},
            {"float", AbstractVM::eOperandType::FLOAT}, {"double", AbstractVM::eOperandType::DOUBLE},
            {"bigdecimal", AbstractVM::eOperandType::BIGDECIMAL}};
    };
} // namespace Parser

#endif
