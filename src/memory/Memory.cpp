// /*
// ** EPITECH PROJECT, 2022
// ** abstractVM
// ** File description:
// ** Memory
// */

// #include "Memory.hpp"

// AbstractVM::Memory::Memory() {}

// AbstractVM::Memory::~Memory() {}

// void AbstractVM::Memory::push(const IOperand &value) { _stack.push(value); }

// void AbstractVM::Memory::pop() { _stack.pop(); }

// void AbstractVM::Memory::clear()
// {
//     while (!_stack.empty())
//         _stack.pop();
// }

// void AbstractVM::Memory::dup() { _stack.push(_stack.top()); }

// void AbstractVM::Memory::swap()
// {
//     // IOperand save1 = _stack.top();
//     pop();
//     // IOperand save2 = _stack.top();
//     pop();
//     // push(save1);
//     // push(save2);
// }

// void AbstractVM::Memory::dump() const
// {
//     // for (IOperand *dump = _stack; !dump.empty(); dump.pop())
//     //     std::cout << dump.top() << '\n';
// }