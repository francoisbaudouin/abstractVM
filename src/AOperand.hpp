/*
** EPITECH PROJECT, 2022
** abstractVM
** File description:
** AOperand
*/

#ifndef AOPERAND_HPP_
#define AOPERAND_HPP_

#include "IOperand.hpp"

namespace AbstractVM {

    class AOperand : public IOperand {
        public:
            AOperand() = default;
            ~AOperand() = default;
            AOperand(const AOperand &other) = default;
            AOperand &operator=(const AOperand &other) = default;

            virtual std::string toString() const = 0; // string that represents the instance

            virtual eOperandType getType() const = 0; // returns the type of instance

            virtual IOperand* operator+(const IOperand &rhs) const = 0; // sum
            virtual IOperand* operator-(const IOperand &rhs) const = 0; // difference
            virtual IOperand* operator*(const IOperand &rhs) const = 0; // product
            virtual IOperand* operator/(const IOperand &rhs) const = 0; // quotient
            virtual IOperand* operator%(const IOperand &rhs) const = 0; // modulo
        protected:
        private:
    };
}

#endif /* !AOPERAND_HPP_ */
