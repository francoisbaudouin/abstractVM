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

Test(main_base_good_file, mainAllWork)
{
    Parser::ParssCommand pars;
    const std::string filetest = "exemple.avm";

    bool result = pars.readData(filetest);

    cr_assert_eq(result, true);
}

Test(main_base_bad_file, mainAllWork)
{
    Parser::ParssCommand pars;
    const std::string filetest = "c.avm";

    bool result = pars.readData(filetest);

    cr_assert_eq(result, false);
}