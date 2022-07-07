/*
** EPITECH PROJECT, 2022
** abstractVM
** File description:
** OperandFactory
*/

#ifndef OPERANDFACTORY_HPP_
#define OPERANDFACTORY_HPP_

#include "AOperand.hpp"
#include <map>

namespace AbstractVM {
    class OperandFactory {
        public:
            OperandFactory();
            ~OperandFactory();
	        OperandFactory(const OperandFactory&);
	        const OperandFactory& operator=(const OperandFactory&);

            static IOperand *createOperand(eOperandType type, const std::string &value);

        protected:
        private:
            IOperand const *createInt8(std::string const &value) const;
	        IOperand const *createInt16(std::string const &value) const;
	        IOperand const *createInt32(std::string const &value) const;
	        IOperand const *createFloat(std::string const &value) const;
	        IOperand const *createDouble(std::string const &value) const;
	        IOperand const *createBigDecimal(std::string const &value) const;

            std::map<eOperandType, IOperand const* (OperandFactory::*)(std::string const & value) const> operands;
	        std::map<const std::string, eOperandType> operands_str;
    };
}

#endif /* !OPERANDFACTORY_HPP_ */
