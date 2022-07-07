/*
** EPITECH PROJECT, 2022
** abstractVM
** File description:
** Parser
*/

#ifndef PARSER_HPP_
#define PARSER_HPP_

#include <filesystem>
#include <string>

namespace Parser
{
    class ParssCommand {
      public:
        ParssCommand();
        ~ParssCommand();
        int readFile(const std::string filepath);

      protected:
      private:
    };
} // namespace Parser

#endif