/*
** EPITECH PROJECT, 2022
** abstractVM
** File description:
** Memory
*/

#include "Memory.hpp"
#include "exception/Exception.hpp"

namespace AbstractVM
{
    Memory::Memory() {}

    Memory::~Memory() {}

    double Memory::getmin(eOperandType type)
    {
        double min = 0;
        switch (type) {
            case INT8: min = std::numeric_limits<int8_t>::min(); break;
            case INT16: min = std::numeric_limits<int16_t>::min(); break;
            case INT32: min = std::numeric_limits<int32_t>::min(); break;
            case FLOAT: min = std::numeric_limits<float>::min(); break;
            case DOUBLE: min = std::numeric_limits<double>::min(); break;
            case BIGDECIMAL: min = std::numeric_limits<double>::min(); break;
            default: break; // throw exection
        }
        return (min);
    }

    double Memory::getmax(eOperandType type)
    {
        double max = 0;
        switch (type) {
            case INT8: max = std::numeric_limits<int8_t>::max(); break;
            case INT16: max = std::numeric_limits<int16_t>::max(); break;
            case INT32: max = std::numeric_limits<int32_t>::max(); break;
            case FLOAT: max = std::numeric_limits<float>::max(); break;
            case DOUBLE: max = std::numeric_limits<double>::max(); break;
            case BIGDECIMAL: max = std::numeric_limits<double>::max(); break;
            default: break; // throw exection
        }
        return (max);
    }

    void Memory::push(IOperand *value)
    {
        if (std::stod(value->toString()) < getmin(value->getType()))
            throw Underflow("push", getmin(value->getType()));
        if (std::stod(value->toString()) > getmax(value->getType()))
            throw Overflow("Overflow", getmax(value->getType()));
        _stack.push(value);
    }

    void Memory::pop()
    {
        if (_stack.size() < 1)
            throw EmptyStack("pop");
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
            throw EmptyStack("dump");
        _stack.push(_stack.top());
    }

    void Memory::swap()
    {
        if (_stack.size() < 2)
            throw InvalideSize("swap");
        IOperand *save1 = _stack.top();
        pop();
        IOperand *save2 = _stack.top();
        pop();
        push(save1);
        push(save2);
    }

    void printInt(IOperand *ope)
    {
        for (size_t i = 0; i < ope->toString().size(); i++) {
            if (ope->toString().at(i) == '.')
                break;
            std::cout << ope->toString().at(i);
        }
        std::cout << std::endl;
    }

    void printPrecision(IOperand *ope)
    {
        int maxPrecs = 0;
        for (size_t i = 0; i < ope->toString().size(); i++) {
            if (ope->toString().at(i) == '.') {
                std::cout << ope->toString().at(i);
                i++;
            }
            if (maxPrecs < ope->getPrecision())
                break;
            std::cout << ope->toString().at(i);
        }
        std::cout << std::endl;
    }

    void Memory::dump() const
    {
        for (std::stack<IOperand *> newStack = _stack; !newStack.empty(); newStack.pop())
            newStack.top()->getType() < 4 ? printInt(newStack.top()) : printPrecision(newStack.top());
    }

    void Memory::assert(IOperand *value) const
    {
        if (_stack.size() < 1)
            throw EmptyStack("assert");
        IOperand *saveOpe = _stack.top();
        if (!(saveOpe->getType() == value->getType()) && (saveOpe->toString() == value->toString()))
            throw AssertException("assert");
    }

    void Memory::add()
    {
        if (_stack.size() < 2)
            throw InvalideSize("add");
        IOperand *save1 = _stack.top();
        pop();
        IOperand *save2 = _stack.top();
        pop();
        _stack.push(*save1 + *save2);
    }

    void Memory::sub()
    {
        if (_stack.size() < 2)
            throw InvalideSize("sub");
        IOperand *save1 = _stack.top();
        pop();
        IOperand *save2 = _stack.top();
        pop();
        _stack.push(*save1 - *save2);
    }

    void Memory::mul()
    {
        if (_stack.size() < 2)
            throw InvalideSize("mul");
        IOperand *save1 = _stack.top();
        pop();
        IOperand *save2 = _stack.top();
        pop();
        _stack.push(*save1 * *save2);
    }

    void Memory::div()
    {
        if (_stack.size() < 2)
            throw InvalideSize("div");
        IOperand *save1 = _stack.top();
        pop();
        IOperand *save2 = _stack.top();
        pop();
        _stack.push(*save1 / *save2);
    }

    void Memory::mod()
    {
        if (_stack.size() < 2)
            throw InvalideSize("mod");
        IOperand *save1 = _stack.top();
        pop();
        IOperand *save2 = _stack.top();
        pop();
        _stack.push(*save1 % *save2);
    }

    void Memory::load(int value)
    {
        if (_register.at(value) == NULL)
            throw EmptyRegister("load");
        push(_register.at(value));
    }

    void Memory::store(int value)
    {
        if (_stack.size() < 1)
            throw EmptyStack("store");
        IOperand *save1 = _stack.top();
        pop();
        _register.at(value) = save1;
    }

    void Memory::print()
    {
        if (_stack.size() < 1)
            throw EmptyStack("print");
        if (_stack.top()->getType() != 0)
            throw InvalidType("print");
        int c = std::stoi(_stack.top()->toString());
        std::cout << static_cast<char>(c) << std::endl;
    }

    int Memory::myExit() { return (0); }

} // namespace AbstractVM
