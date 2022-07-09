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

        void push(std::shared_ptr<std::pair<AbstractVM::eOperandType, std::string>>);
        void push(IOperand *value);
        void pop();
        void clear();
        void dup();
        void swap();
        void dump() const;
        bool assert(std::shared_ptr<std::pair<AbstractVM::eOperandType, std::string>> ops) const;
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
    };
} // namespace AbstractVM

#endif /* !MEMORY_HPP_ */
