/*
** EPITECH PROJECT, 2022
** abstractVM
** File description:
** Float
*/

#ifndef FLOAT_HPP_
#define FLOAT_HPP_

#include "Operand.hpp"

namespace AbstractVM
{
    class Float : public Operand {
      public:
        Float(std::string value);
        ~Float();
        Float(const Float &other) = default;
        Float &operator=(const Float &other) = default;

      protected:
      private:
    };
} // namespace AbstractVM

#endif /* !FLOAT_HPP_ */
