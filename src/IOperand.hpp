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
        Int8 = 0,
        Int16 = 1,
        Int32 = 2,
        Float = 3,
        Double = 4,
        BigDecimal = 5
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
