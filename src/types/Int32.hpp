/*
** EPITECH PROJECT, 2022
** abstractVM
** File description:
** Int32
*/

#ifndef INT32_HPP_
#define INT32_HPP_

#include <string>
#include "IOperand.hpp"

namespace AbstractVM
{
    class Int32 : public IOperand {
      public:
        Int32(std::string value);
        ~Int32();
        Int32(const Int32 &other) = default;
        Int32 &operator=(const Int32 &other) = default;
        virtual std::string toString() const; // string that represents the instance

        virtual eOperandType getType() const; // returns the type of instance

        virtual IOperand *operator+(const IOperand &rhs) const; // sum
        virtual IOperand *operator-(const IOperand &rhs) const; // difference
        virtual IOperand *operator*(const IOperand &rhs) const; // product
        virtual IOperand *operator/(const IOperand &rhs) const; // quotient
        virtual IOperand *operator%(const IOperand &rhs) const; // modulo
      protected:
      private:
        std::string _value;
        int _nbr;
        int _precision;
        eOperandType _type;
    };
} // namespace AbstractVM

#endif /* !INT32_HPP_ */
