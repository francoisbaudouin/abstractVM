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

        protected:
        private:
    };
}

#endif /* !AOPERAND_HPP_ */
