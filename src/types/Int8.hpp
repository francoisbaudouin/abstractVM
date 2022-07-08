/*
** EPITECH PROJECT, 2022
** abstractVM
** File description:
** Int8
*/

#ifndef INT8_HPP_
#define INT8_HPP_

#include <string>
#include "IOperand.hpp"

namespace AbstractVM
{
    class Int8 : public IOperand {
      public:
        Int8(std::string value);
        ~Int8();
        Int8(const Int8 &other) = default;
        Int8 &operator=(const Int8 &other) = default;
        virtual std::string toString() const override;                   // string that represents the instance
        virtual eOperandType getType() const override;                   // returns the type of instance
        virtual IOperand *operator+(const IOperand &rhs) const override; // sum
        virtual IOperand *operator-(const IOperand &rhs) const override; // difference
        virtual IOperand *operator*(const IOperand &rhs) const override; // product
        virtual IOperand *operator/(const IOperand &rhs) const override; // quotient
        virtual IOperand *operator%(const IOperand &rhs) const override; // modulo
      protected:
      private:
        std::string _value;
        char _nbr;
        int _precision;
        eOperandType _type;
    };
} // namespace AbstractVM

#endif /* !INT8_HPP_ */
