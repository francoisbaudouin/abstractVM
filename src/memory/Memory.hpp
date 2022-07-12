/*
** EPITECH PROJECT, 2022
** abstractVM
** File description:
** Memory
*/

#ifndef MEMORY_HPP_
#define MEMORY_HPP_

#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <memory>
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

        double getmin(eOperandType type);
        double getmax(eOperandType type);

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
        void load(int value, eOperandType type);
        void store(int value, eOperandType type);
        void print();
        int myExit();

      protected:
      private:
        std::vector<IOperand *> _register{
            NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
        std::stack<IOperand *> _stack;
    };
} // namespace AbstractVM

#endif /* !MEMORY_HPP_ */
