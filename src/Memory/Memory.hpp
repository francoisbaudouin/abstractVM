/*
** EPITECH PROJECT, 2022
** abstractVM
** File description:
** Memory
*/

#ifndef MEMORY_HPP_
#define MEMORY_HPP_

#include "IOperand.hpp"
#include <stack>
#include <vector>

namespace AbstractVM {
    template <class DataType>
    class Memory {
        public:
            Memory();
            ~Memory();
            Memory(const Memory &other) = default;
            Memory &operator=(const Memory &other) = default;

            void push();
        protected:
        private:
        std::vector<DataType> _register {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
        std::stack<DataType> _stack;
    };
}
#endif /* !MEMORY_HPP_ */
