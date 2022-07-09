/*
** EPITECH PROJECT, 2022
** abstractVM
** File description:
** Parser
*/

#ifndef PARSER_HPP_
#define PARSER_HPP_

#include <filesystem>
#include <functional>
#include <iostream>
#include <map>
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
        void push();
        void pop();

      protected:
      private:
        std::shared_ptr(Operand type, std::string) _dataCommand;
        std::unordered_map<std::string, std::function<void()>> _functPtr{
            {"push", [this]() { this->push(); }},
        };
        bool _dataAvailable;
        std::vector<std::string> _data;
    };
} // namespace Parser

#endif
