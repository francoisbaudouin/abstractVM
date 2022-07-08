/*
** EPITECH PROJECT, 2022
** abstractVM
** File description:
** Int16
*/

#ifndef INT16_HPP_
#define INT16_HPP_

#include "AOperand.hpp"
#include <string>

namespace AbstractVM {
    class Int16 : public AOperand {
        public:
            Int16(std::string value);
            ~Int16();
            Int16(const Int16 &other) = default;
            Int16 &operator=(const Int16 &other) = default;
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


#endif /* !INT16_HPP_ */
