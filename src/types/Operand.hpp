/*
** EPITECH PROJECT, 2022
** abstractVM
** File description:
** Operand
*/

#ifndef OPERAND_HPP_
#define OPERAND_HPP_

#include "IOperand.hpp"

namespace AbstractVM
{
    class Operand : public IOperand {
      public:
        Operand(eOperandType type, const std::string &value, int precision);
        ~Operand();
        Operand(const Operand &other) = default;
        Operand &operator=(const Operand &other) = default;

        virtual std::string toString() const override;                   // string that represents the instance
        virtual eOperandType getType() const override;                   // returns the type of instance

        std::string infinAdd(std::string frst, std::string scnd) const;

        virtual IOperand *operator+(const IOperand &rhs) const override; // sum
        virtual IOperand *operator-(const IOperand &rhs) const override; // difference
        virtual IOperand *operator*(const IOperand &rhs) const override; // product
        virtual IOperand *operator/(const IOperand &rhs) const override; // quotient
        virtual IOperand *operator%(const IOperand &rhs) const override; // modulo

        virtual int getPrecision() const override;


      protected:
      private:
        eOperandType _type;
        std::string _value;
        int _precision;
    };
} // namespace AbstractVM

#endif /* !OPERAND_HPP_ */
