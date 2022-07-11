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
#include <string>
#include <vector>

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

        const std::vector<std::string> getData();

        bool checkProvideData();

      protected:
      private:
        bool _setUpCommand(std::smatch match);
        bool _exitIsCalled;
        bool _allowToWriteData;
        std::vector<std::string> _data;
        std::map<std::string, AbstractVM::eOperandType, std::string> _dataCommand;
    };
} // namespace Parser

#endif
