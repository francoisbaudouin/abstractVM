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
#include "types/Operand.hpp"

Test(Ioperand_get_type, ok)
{
    AbstractVM::IOperand *dataCommand = AbstractVM::Factory::operands.at(AbstractVM::eOperandType::INT32)("42");
    cr_assert_eq(dataCommand->getType(), AbstractVM::eOperandType::INT32);
}

Test(split_string, ok)
{
    AbstractVM::IOperand *dataCommand = AbstractVM::Factory::operands.at(AbstractVM::eOperandType::INT32)("42");
    cr_assert_eq(dataCommand->toString(), "42");
}