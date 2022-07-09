/*
** EPITECH PROJECT, 2022
** abstractVM
** File description:
** Int32
*/

#ifndef INT32_HPP_
#define INT32_HPP_


#include "Operand.hpp"

namespace AbstractVM
{
    class Int32 : public Operand {
      public:
        Int32(std::string value);
        ~Int32();
        Int32(const Int32 &other) = default;
        Int32 &operator=(const Int32 &other) = default;
      protected:
      private:
    };
} // namespace AbstractVM

#endif /* !INT32_HPP_ */
