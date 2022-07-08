/*
** EPITECH PROJECT, 2022
** abstractVM
** File description:
** BigDecimal
*/

#ifndef BIGDECIMAL_HPP_
#define BIGDECIMAL_HPP_

#include <string>
#include "IOperand.hpp"

namespace AbstractVM
{
    class BigDecimal : public IOperand {
      public:
        BigDecimal(std::string value);
        ~BigDecimal();
        BigDecimal(const BigDecimal &other) = default;
        BigDecimal &operator=(const BigDecimal &other) = default;
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
        double _nbr;
        int _precision;
        eOperandType _type;
    };
} // namespace AbstractVM

#endif /* !BIGDECIMAL_HPP_ */
