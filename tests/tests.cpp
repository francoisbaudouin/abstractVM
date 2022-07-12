/*
** EPITECH PROJECT, 2022
** abstractVM
** File description:
** tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "parser/Parser.hpp"
#include "factory/Factory.hpp"
#include "parser/CommandData.hpp"
#include "parser/Interpretor.hpp"
#include "parser/Parser.hpp"

Test(main_base, mainAllWork)
{
    Parser::ParssCommand pars;
    const std::string filetest = "exemple.avm";

    pars.readData(filetest);
    bool result = pars.checkProvideData();

    cr_assert_eq(result, true);
}