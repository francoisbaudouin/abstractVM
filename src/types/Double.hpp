/*
** EPITECH PROJECT, 2022
** abstractVM
** File description:
** Double
*/

#ifndef DOUBLE_HPP_
#define DOUBLE_HPP_

#include <string>
#include "IOperand.hpp"

namespace AbstractVM
{
    class Double : public IOperand {
      public:
        Double(std::string value);
        ~Double();
        Double(const Double &other) = default;
        Double &operator=(const Double &other) = default;
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

#endif /* !DOUBLE_HPP_ */