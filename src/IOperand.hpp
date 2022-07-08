/*
** EPITECH PROJECT, 2022
** abstractVM
** File description:
** IOperand
*/

#ifndef IOPERAND_HPP_
#define IOPERAND_HPP_

#include <string>

namespace AbstractVM {

    enum eOperandType {
        INT8 = 0,
        INT16 = 1,
        INT32 = 2,
        FLOAT = 3,
        DOUBLE = 4,
        BIGDECIMAL = 5
    };

    class IOperand
    {
        public:
            virtual std::string toString() const = 0; // string that represents the instance

            virtual eOperandType getType() const = 0; // returns the type of instance

            virtual IOperand* operator+(const IOperand &rhs) const = 0; // sum
            virtual IOperand* operator-(const IOperand &rhs) const = 0; // difference
            virtual IOperand* operator*(const IOperand &rhs) const = 0; // product
            virtual IOperand* operator/(const IOperand &rhs) const = 0; // quotient
            virtual IOperand* operator%(const IOperand &rhs) const = 0; // modulo
            virtual ~IOperand() {}
    };
}

#endif /* !IOPERAND_HPP_ */
