/*
** EPITECH PROJECT, 2022
** abstractVM
** File description:
** Interpretor
*/

#ifndef ITERPRETOR_HPP_
#define ITERPRETOR_HPP_

#include <functional>
#include <map>
#include "memory/Memory.hpp"
#include <unordered_map>

namespace Parser
{
    class Interpretor {
      public:
        Interpretor();

        ~Interpretor();

        int getValue(void) { return (_value); }

        void setValue(int value);

        void setValue(std::shared_ptr<int> val);

        std::string getGivenCommand(std::string commandLine);

        bool setDataCommand(std::string commandLine);

        AbstractVM::Memory _memory;

        int _value;

        std::shared_ptr<int> _val;

        std::shared_ptr<std::pair<AbstractVM::eOperandType, std::string>> _dataCommand;

        std::map<std::string, AbstractVM::eOperandType> whatOperandIs{{"int8", AbstractVM::eOperandType::INT8},
            {"int16", AbstractVM::eOperandType::INT16}, {"int32", AbstractVM::eOperandType::INT32},
            {"float", AbstractVM::eOperandType::FLOAT}, {"double", AbstractVM::eOperandType::DOUBLE},
            {"bigdecimal", AbstractVM::eOperandType::BIGDECIMAL}};

        std::unordered_map<std::string, std::function<void()>> _functPtr{
            {"push", [this]() { _memory.push(_dataCommand); }}, {"pop", [this]() { _memory.pop(); }},
            {"clear", [this]() { _memory.clear(); }}, {"dup", [this]() { _memory.dup(); }},
            {"swap", [this]() { _memory.swap(); }}, {"dump", [this]() { _memory.dump(); }},
            {"assert", [this]() { _memory.assert(_dataCommand); }}, {"add", [this]() { _memory.add(); }},
            {"sub", [this]() { _memory.sub(); }}, {"mul", [this]() { _memory.mul(); }},
            {"div", [this]() { _memory.div(); }}, {"mod", [this]() { _memory.mod(); }},
            {"load", [this]() { _memory.load(_value); }}, {"store", [this]() { _memory.store(_value); }},
            {"print", [this]() { _memory.print(); }}, {"exit", [this]() { _memory.myExit(); }}};
    };
} // namespace Parser

#endif /*!ITERPRETOR_HPP_*/