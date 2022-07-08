/*
** EPITECH PROJECT, 2022
** abstractVM
** File description:
** Float
*/

#ifndef FLOAT_HPP_
#define FLOAT_HPP_

#include "AOperand.hpp"
#include <string>

namespace AbstractVM {
    class Float : public AOperand {
        public:
            Float(std::string value);
            ~Float();
            Float(const Float &other) = default;
            Float &operator=(const Float &other) = default;
            virtual std::string toString() const; // string that represents the instance

            virtual eOperandType getType() const; // returns the type of instance

            virtual IOperand* operator+(const IOperand &rhs) const; // sum
            virtual IOperand* operator-(const IOperand &rhs) const; // difference
            virtual IOperand* operator*(const IOperand &rhs) const; // product
            virtual IOperand* operator/(const IOperand &rhs) const; // quotient
            virtual IOperand* operator%(const IOperand &rhs) const; // modulo
        protected:
        private:
            std::string _value;
            int _precision;
            eOperandType _type;
    };
}

#endif /* !FLOAT_HPP_ */
