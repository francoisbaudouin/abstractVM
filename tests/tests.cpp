/*
** EPITECH PROJECT, 2022
** abstractVM
** File description:
** tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../src/IOperand.hpp"
#include "../src/parser/Parser.hpp"

Test(main_base, mainAllWork)
{
    Parser::ParssCommand pars;
    std::string filetest = "exemple.avm";

    pars.readData(filetest);
    bool result = pars.checkProvideData();

    cr_assert(result == true);
}