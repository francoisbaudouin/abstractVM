/*
** EPITECH PROJECT, 2022
** abstractVM
** File description:
** Factory
*/

#ifndef OPERANDFACTORY_HPP_
#define OPERANDFACTORY_HPP_

#include "AOperand.hpp"
#include <map>

namespace AbstractVM {
    class Factory {
        public:
            Factory();
            ~Factory();
	        Factory(const Factory&);
	        const Factory& operator=(const Factory&);

            static IOperand *createOperand(eOperandType type, const std::string &value);

            IOperand *createInt8(const std::string &value);
            IOperand *createInt16(const std::string &value);
            IOperand *createInt32(const std::string &value);
            IOperand *createFloat(const std::string &value);
            IOperand *createDouble(const std::string &value);
            IOperand *createBigDecimal(const std::string &value);
        protected:
        private:
            static std::map<eOperandType, IOperand *(Factory::*)(const std::string &value)> _operands;
    };
}

#endif /* !OPERANDFACTORY_HPP_ */
