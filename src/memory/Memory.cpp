/*
** EPITECH PROJECT, 2022
** abstractVM
** File description:
** Memory
*/

#include "Memory.hpp"
#include <limits>

AbstractVM::Memory::Memory() {}

AbstractVM::Memory::~Memory() {}

void AbstractVM::Memory::push(IOperand *value) { _stack.push(value); }

void AbstractVM::Memory::pop() { _stack.pop(); }

void AbstractVM::Memory::clear()
{
    while (!_stack.empty())
        _stack.pop();
}

void AbstractVM::Memory::dup() { _stack.push(_stack.top()); }

void AbstractVM::Memory::swap()
{
    IOperand *save1 = _stack.top();
    pop();
    IOperand *save2 = _stack.top();
    pop();
    push(save1);
    push(save2);
}

void AbstractVM::Memory::dump() const
{
    for (std::stack<IOperand *> newStack = _stack; !newStack.empty(); newStack.pop())
        std::cout << newStack.top()->toString() << '\n';
}

void AbstractVM::Memory::assert(IOperand *value) const
{
    IOperand *saveOpe = _stack.top();
    if (!(saveOpe->getType() == value->getType() && saveOpe->toString() == value->toString()))
        exit(84);
}

void AbstractVM::Memory::add()
{
    if (_stack.size() < 2)
        exit(84);
    IOperand *save1 = _stack.top();
    pop();
    IOperand *save2 = _stack.top();
    pop();
    _stack.push(*save1 + *save2);
}

void AbstractVM::Memory::sub()
{
    if (_stack.size() < 2)
        exit(84);
    IOperand *save1 = _stack.top();
    pop();
    IOperand *save2 = _stack.top();
    pop();
    _stack.push(*save1 - *save2);
}

void AbstractVM::Memory::mul()
{
    if (_stack.size() < 2)
        exit(84);
    IOperand *save1 = _stack.top();
    pop();
    IOperand *save2 = _stack.top();
    pop();
    _stack.push(*save1 * *save2);
}

void AbstractVM::Memory::div()
{
    if (_stack.size() < 2)
        exit(84);
    IOperand *save1 = _stack.top();
    pop();
    IOperand *save2 = _stack.top();
    pop();
    _stack.push(*save1 / *save2);
}

void AbstractVM::Memory::mod()
{
    if (_stack.size() < 2)
        exit(84);
    IOperand *save1 = _stack.top();
    pop();
    IOperand *save2 = _stack.top();
    pop();
    _stack.push(*save1 % *save2);
}

void AbstractVM::Memory::load(int value)
{
    if (_register.at(value) == NULL)
        exit(84);
    push(_register.at(value));
}

void AbstractVM::Memory::store(int value)
{
    if (_stack.size() < 1)
        exit(84);
    IOperand *save1 = _stack.top();
    pop();
    _register.at(value) = save1;
}

void AbstractVM::Memory::print()
{
    if (_stack.top()->getType() != 0)
        exit(84);
    int c = std::stoi(_stack.top()->toString());
    std::cout << static_cast<char>(c) << std::endl;
}

int AbstractVM::Memory::myExit() { return (0); }
