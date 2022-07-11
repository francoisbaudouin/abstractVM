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
#include "parser/CommandData.hpp"

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

        std::vector<CommandData> &getDataCommand();

      protected:
      private:
        std::vector<CommandData> _dataCommand;
        bool _setUpCommand(std::smatch &match);

        bool _exitIsCalled;
        bool _allowToWriteData;
        std::vector<std::string> _data;
    };

} // namespace Parser

#endif
