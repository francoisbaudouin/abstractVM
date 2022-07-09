/*
** EPITECH PROJECT, 2022
** abstractVM
** File description:
** Double
*/

#ifndef DOUBLE_HPP_
#define DOUBLE_HPP_

#include "Operand.hpp"

namespace AbstractVM
{
    class Double : public Operand {
      public:
        Double(std::string value);
        ~Double();
        Double(const Double &other) = default;
        Double &operator=(const Double &other) = default;

      protected:
      private:
    };
} // namespace AbstractVM

#endif /* !DOUBLE_HPP_ */
