/*
** EPITECH PROJECT, 2022
** abstractVM
** File description:
** tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "factory/Factory.hpp"
#include "parser/CommandData.hpp"
#include "parser/Interpretor.hpp"
#include "parser/Parser.hpp"
#include "IOperand.hpp"

Test(calcmul, str)
{
    AbstractVM::IOperand *ope1 = AbstractVM::Factory::operands.at(AbstractVM::BIGDECIMAL)("4782.2123");
    AbstractVM::IOperand *ope2 = AbstractVM::Factory::operands.at(AbstractVM::BIGDECIMAL)("-291");
    AbstractVM::IOperand *ope3 = *ope1 * *ope2;

    cr_assert_eq(ope3->toString().compare("-1391623.77930000"), 0);
}

Test(calcmsmul1, str)
{
    AbstractVM::IOperand *ope1 = AbstractVM::Factory::operands.at(AbstractVM::BIGDECIMAL)("4782.2123");
    AbstractVM::IOperand *ope2 = AbstractVM::Factory::operands.at(AbstractVM::BIGDECIMAL)("-291");
    AbstractVM::IOperand *ope3 = *ope1 * *ope2;

    cr_assert_eq(ope3->toString().compare("-1391623.77930000"), 0);
}

Test(calcmmul2, str)
{
    AbstractVM::IOperand *ope1 = AbstractVM::Factory::operands.at(AbstractVM::BIGDECIMAL)("4782.2123");
    AbstractVM::IOperand *ope2 = AbstractVM::Factory::operands.at(AbstractVM::BIGDECIMAL)("291");
    AbstractVM::IOperand *ope3 = *ope1 * *ope2;

    cr_assert_eq(ope3->toString().compare("1391623.77930000"), 0);
}

Test(calcmmul3, str)
{
    AbstractVM::IOperand *ope1 = AbstractVM::Factory::operands.at(AbstractVM::BIGDECIMAL)("-4782.2123");
    AbstractVM::IOperand *ope2 = AbstractVM::Factory::operands.at(AbstractVM::BIGDECIMAL)("291");
    AbstractVM::IOperand *ope3 = *ope1 * *ope2;

    cr_assert_eq(ope3->toString().compare("-1391623.77930000"), 0);
}

Test(calcmmul4, str)
{
    AbstractVM::IOperand *ope1 = AbstractVM::Factory::operands.at(AbstractVM::BIGDECIMAL)("-4782.2123");
    AbstractVM::IOperand *ope2 = AbstractVM::Factory::operands.at(AbstractVM::BIGDECIMAL)("-291");
    AbstractVM::IOperand *ope3 = *ope1 * *ope2;

    cr_assert_eq(ope3->toString().compare("1391623.77930000"), 0);
}

Test(calcmsub1, str)
{
    AbstractVM::IOperand *ope1 = AbstractVM::Factory::operands.at(AbstractVM::BIGDECIMAL)("4782.2123");
    AbstractVM::IOperand *ope2 = AbstractVM::Factory::operands.at(AbstractVM::BIGDECIMAL)("291");
    AbstractVM::IOperand *ope3 = *ope1 - *ope2;

    std::cout << ope3->toString() << std::endl;

    cr_assert_eq(ope3->toString().compare("4491.2123"), 0);
}

Test(calcmsub2, str)
{
    AbstractVM::IOperand *ope1 = AbstractVM::Factory::operands.at(AbstractVM::BIGDECIMAL)("4782.2123");
    AbstractVM::IOperand *ope2 = AbstractVM::Factory::operands.at(AbstractVM::BIGDECIMAL)("-291");
    AbstractVM::IOperand *ope3 = *ope1 - *ope2;

    std::cout << ope3->toString() << std::endl;

    cr_assert_eq(ope3->toString().compare("5073.2123"), 0);
}

Test(calcmsub1, str)
{
    AbstractVM::IOperand *ope1 = AbstractVM::Factory::operands.at(AbstractVM::BIGDECIMAL)("4782.2123");
    AbstractVM::IOperand *ope2 = AbstractVM::Factory::operands.at(AbstractVM::BIGDECIMAL)("291");
    AbstractVM::IOperand *ope3 = *ope1 - *ope2;

    std::cout << ope3->toString() << std::endl;

    cr_assert_eq(ope3->toString().compare("4491.2123"), 0);
}