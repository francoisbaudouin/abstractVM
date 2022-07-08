/*
** EPITECH PROJECT, 2022
** abstractVM
** File description:
** Double
*/

#ifndef DOUBLE_HPP_
#define DOUBLE_HPP_

#include "AOperand.hpp"
#include <string>

namespace AbstractVM {
    class Double : public AOperand {
        public:
            Double(std::string value);
            ~Double();
            Double(const Double &other) = default;
            Double &operator=(const Double &other) = default;
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

#endif /* !DOUBLE_HPP_ */
