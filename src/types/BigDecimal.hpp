/*
** EPITECH PROJECT, 2022
** abstractVM
** File description:
** BigDecimal
*/

#ifndef BIGDECIMAL_HPP_
#define BIGDECIMAL_HPP_

#include "Operand.hpp"

namespace AbstractVM
{
    class BigDecimal : public Operand {
      public:
        BigDecimal(std::string value);
        ~BigDecimal();
        BigDecimal(const BigDecimal &other) = default;
        BigDecimal &operator=(const BigDecimal &other) = default;

      protected:
      private:
    };
} // namespace AbstractVM

#endif /* !BIGDECIMAL_HPP_ */
