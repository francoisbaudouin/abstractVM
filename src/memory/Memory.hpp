/*
** EPITECH PROJECT, 2022
** abstractVM
** File description:
** Memory
*/

#ifndef MEMORY_HPP_
#define MEMORY_HPP_

#include <iostream>
#include <stack>
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

        void push(std::pair<AbstractVM::eOperandType, std::string>);
        void pop();
        void clear();
        void dup();
        void swap();
        void dump() const;
        bool assert(const IOperand &value) const;
        void add();
        void sub();
        void mul();
        void div();
        void mod();
        // load v
        // store v
        void print();
        void exit();

      protected:
      private:
        std::vector<IOperand *> _register{};
        std::stack<IOperand *> _stack;
    };
} // namespace AbstractVM

#endif /* !MEMORY_HPP_ */
