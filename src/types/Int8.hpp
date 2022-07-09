/*
** EPITECH PROJECT, 2022
** abstractVM
** File description:
** Int8
*/

#ifndef INT8_HPP_
#define INT8_HPP_

#include "Operand.hpp"

namespace AbstractVM
{
    class Int8 : public Operand {
      public:
        Int8(std::string value);
        ~Int8();
        Int8(const Int8 &other) = default;
        Int8 &operator=(const Int8 &other) = default;
      protected:
      private:
    };
} // namespace AbstractVM

#endif /* !INT8_HPP_ */
