/*
** EPITECH PROJECT, 2022
** abstractVM
** File description:
** Memory
*/

#include "Memory.hpp"

namespace AbstractVM
{
    std::map<eOperandType, std::tuple<signed char, signed char>> _limits{
        std::pair<eOperandType, std::tuple<signed char, signed char>>(
            INT8, {std::numeric_limits<int8_t>::min(), std::numeric_limits<int8_t>::max()}),
        std::pair<eOperandType, std::tuple<signed char, signed char>>(
            INT16, {std::numeric_limits<int16_t>::min(), std::numeric_limits<int16_t>::max()}),
        std::pair<eOperandType, std::tuple<signed char, signed char>>(
            INT32, {std::numeric_limits<int32_t>::min(), std::numeric_limits<int32_t>::max()}),
        std::pair<eOperandType, std::tuple<signed char, signed char>>(
            FLOAT, {std::numeric_limits<float>::min(), std::numeric_limits<float>::max()}),
        std::pair<eOperandType, std::tuple<signed char, signed char>>(
            DOUBLE, {std::numeric_limits<double>::min(), std::numeric_limits<double>::max()}),
        std::pair<eOperandType, std::tuple<signed char, signed char>>(
            BIGDECIMAL, {std::numeric_limits<double>::min(), std::numeric_limits<double>::max()}),
    };

    Memory::Memory() {}

    Memory::~Memory() {}

    void Memory::push(IOperand *value)
    {
        if (!((std::stod(value->toString()) < std::get<0>(_limits[value->getType()]))
                && (std::stod(value->toString()) > std::get<1>(_limits[value->getType()]))))
            exit(84);
        _stack.push(value);
    }

    void Memory::pop()
    {
        if (_stack.size() < 1)
            exit(84);
        _stack.pop();
    }

    void Memory::clear()
    {
        while (!_stack.empty())
            _stack.pop();
    }

    void Memory::dup()
    {
        if (_stack.size() < 1)
            exit(84);
        _stack.push(_stack.top());
    }

    void Memory::swap()
    {
        if (_stack.size() < 2)
            exit(84);
        IOperand *save1 = _stack.top();
        pop();
        IOperand *save2 = _stack.top();
        pop();
        push(save1);
        push(save2);
    }

    void Memory::dump() const
    {
        for (std::stack<IOperand *> newStack = _stack; !newStack.empty(); newStack.pop())
            std::cout << newStack.top()->toString() << '\n';
    }

    void Memory::assert(IOperand *value) const
    {
        if (_stack.size() < 1)
            exit(84);
        IOperand *saveOpe = _stack.top();
        if (!(saveOpe->getType() == value->getType() && saveOpe->toString() == value->toString()))
            exit(84);
    }

    void Memory::add()
    {
        if (_stack.size() < 2)
            exit(84);
        IOperand *save1 = _stack.top();
        pop();
        IOperand *save2 = _stack.top();
        pop();
        _stack.push(*save1 + *save2);
    }

    void Memory::sub()
    {
        if (_stack.size() < 2)
            exit(84);
        IOperand *save1 = _stack.top();
        pop();
        IOperand *save2 = _stack.top();
        pop();
        _stack.push(*save1 - *save2);
    }

    void Memory::mul()
    {
        if (_stack.size() < 2)
            exit(84);
        IOperand *save1 = _stack.top();
        pop();
        IOperand *save2 = _stack.top();
        pop();
        _stack.push(*save1 * *save2);
    }

    void Memory::div()
    {
        if (_stack.size() < 2)
            exit(84);
        IOperand *save1 = _stack.top();
        pop();
        IOperand *save2 = _stack.top();
        pop();
        _stack.push(*save1 / *save2);
    }

    void Memory::mod()
    {
        if (_stack.size() < 2)
            exit(84);
        IOperand *save1 = _stack.top();
        pop();
        IOperand *save2 = _stack.top();
        pop();
        _stack.push(*save1 % *save2);
    }

    void Memory::load(int value)
    {
        if (_register.at(value) == NULL)
            exit(84);
        push(_register.at(value));
    }

    void Memory::store(int value)
    {
        if (_stack.size() < 1)
            exit(84);
        IOperand *save1 = _stack.top();
        pop();
        _register.at(value) = save1;
    }

    void Memory::print()
    {
        if (_stack.size() < 1 || _stack.top()->getType() != 0)
            exit(84);
        int c = std::stoi(_stack.top()->toString());
        std::cout << static_cast<char>(c) << std::endl;
    }

    int Memory::myExit() { return (0); }

} // namespace AbstractVM