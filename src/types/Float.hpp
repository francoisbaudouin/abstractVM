/*
** EPITECH PROJECT, 2022
** abstractVM
** File description:
** Float
*/

#ifndef FLOAT_HPP_
#define FLOAT_HPP_

#include <string>
#include "IOperand.hpp"

namespace AbstractVM
{
    class Float : public IOperand {
      public:
        Float(std::string value);
        ~Float();
        Float(const Float &other) = default;
        Float &operator=(const Float &other) = default;
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
        float _nbr;
        int _precision;
        eOperandType _type;
    };
} // namespace AbstractVM

#endif /* !FLOAT_HPP_ */
