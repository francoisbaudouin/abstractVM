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

      protected:
      private:
        // std::fonction
        std::map<std::function<std::string(std::string, std::string)>> fonction;
        bool _dataAvailable;
        std::vector<std::string> _data;
    };
} // namespace Parser

#endif