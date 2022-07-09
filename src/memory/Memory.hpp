/*
** EPITECH PROJECT, 2022
** abstractVM
** File description:
** Memory
*/

#ifndef MEMORY_HPP_
#define MEMORY_HPP_

#include <iostream>
#include <limits>
#include <map>
#include <stack>
#include <tuple>
#include <vector>
#include "IOperand.hpp"

namespace AbstractVM
{
    class Memory {
      public:
        Memory();
        ~Memory();
        Memory(const Memory &other) = default;
        Memory &operator=(const Memory &other) = default;

        void push(IOperand *value);
        void pop();
        void clear();
        void dup();
        void swap();
        void dump() const;
        void assert(IOperand *value) const;
        void add();
        void sub();
        void mul();
        void div();
        void mod();
        void load(int value);
        void store(int value);
        void print();
        int myExit();

      protected:
      private:
        std::vector<IOperand *> _register{
            NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
        std::stack<IOperand *> _stack;
        std::map<eOperandType, std::tuple<signed char, signed char>> _limits;
    };
} // namespace AbstractVM

#endif /* !MEMORY_HPP_ */
