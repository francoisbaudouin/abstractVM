/*
** EPITECH PROJECT, 2022
** abstractVM
** File description:
** Int16
*/

#ifndef INT16_HPP_
#define INT16_HPP_

#include <string>
#include "Operand.hpp"

namespace AbstractVM
{
    class Int16 : public Operand {
      public:
        Int16(std::string value);
        ~Int16();
        Int16(const Int16 &other) = default;
        Int16 &operator=(const Int16 &other) = default;
      protected:
      private:
    };
} // namespace AbstractVM

#endif /* !INT16_HPP_ */
