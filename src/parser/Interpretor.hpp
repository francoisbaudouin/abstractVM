/*
** EPITECH PROJECT, 2022
** abstractVM
** File description:
** Interpretor
*/

#ifndef ITERPRETOR_HPP_
#define ITERPRETOR_HPP_

#include <functional>
#include <memory>
#include "memory/Memory.hpp"
#include <unordered_map>

class Interpretor {
  public:
    Interpretor();
    ~Interpretor();

  protected:
  private:
    AbstractVM::Memory memory;
    std::shared_ptr<std::pair<AbstractVM::eOperandType, std::string>> _dataCommand;
    std::unordered_map<std::string, std::function<void()>> _functPtr{
        {"push", [this]() { memory.push(); }},
        {"pop", [this]() { memory.pop(); }},
        {"clear", [this]() { memory.clear(); }},
        {"dup", [this]() { memory.dup(); }},
        {"swap", [this]() { memory.swap(); }},
        {"dump", [this]() { memory.dump(); }},
        {"assert", [this]() { memory.assert(); }},
        {"add", [this]() { memory.add(); }},
        {"sub", [this]() { memory.sub(); }},
        {"mul", [this]() { memory.mul(); }},
        {"div", [this]() { memory.div(); }},
        {"mod", [this]() { memory.mod(); }},
        {"load", [this]() { memory.load(); }},
        {"store", [this]() { memory.store(); }},
        {"print", [this]() { memory.print(); }},
        {"exit", [this]() { memory.exit(); }},
    };
};

#endif /*!ITERPRETOR_HPP_*/