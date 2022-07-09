/*
** EPITECH PROJECT, 2022
** abstractVM
** File description:
** Interpretor
*/

#ifndef ITERPRETOR_HPP_
#define ITERPRETOR_HPP_

#include <functional>
#include "memory/Memory.hpp"
#include <unordered_map>

namespace Parser
{
    class Interpretor {
      public:
        Interpretor();
        ~Interpretor();

      protected:
      private:
        AbstractVM::Memory _memory;
        std::shared_ptr<std::pair<AbstractVM::eOperandType, std::string>> _dataCommand;
        std::unordered_map<std::string, std::function<void()>> _functPtr{
            {"push", [this]() { _memory.push(_dataCommand); }},
            {"pop", [this]() { _memory.pop(); }},
            {"clear", [this]() { _memory.clear(); }},
            {"dup", [this]() { _memory.dup(); }},
            {"swap", [this]() { _memory.swap(); }},
            {"dump", [this]() { _memory.dump(); }},
            {"assert", [this]() { _memory.assert(_dataCommand); }},
            {"add", [this]() { _memory.add(); }},
            {"sub", [this]() { _memory.sub(); }},
            {"mul", [this]() { _memory.mul(); }},
            {"div", [this]() { _memory.div(); }},
            {"mod", [this]() { _memory.mod(); }},
            {"load", [this]() { _memory.load(); }},
            {"store", [this]() { _memory.store(); }},
            {"print", [this]() { _memory.print(); }},
            {"exit", [this]() { _memory.myExit(); }},
        };
    };
} // namespace Parser

#endif /*!ITERPRETOR_HPP_*/