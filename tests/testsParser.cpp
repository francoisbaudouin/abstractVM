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

Test(give_good_file, OK)
{
    Parser::ParssCommand pars;
    const std::string filetest = "tests/exemple/exemple.avm";

    int result = pars.readData(filetest);

    cr_assert_eq(result, 0);
}

Test(give_bad_file, KO)
{
    Parser::ParssCommand pars;
    const std::string filetest = "tests/exemple/badfile.avm";

    int result = pars.readData(filetest);

    cr_assert_eq(result, 1);
}

Test(file_with_good_data, OK)
{
    Parser::ParssCommand pars;
    const std::string filetest = "tests/exemple/exemple.avm";

    pars.readData(filetest);
    bool result = pars.checkProvideData();
    cr_assert_eq(result, true);
}

Test(file_with_bad_data, KO)
{
    Parser::ParssCommand pars;
    const std::string filetest = "tests/exemple/badexemple.avm";

    pars.readData(filetest);
    bool result = pars.checkProvideData();
    cr_assert_eq(result, false);
}

Test(check_data_with_empty_dataStorage, KO)
{
    Parser::ParssCommand pars;
    const std::string filetest = "tests/exemple/badexemple.avm";

    bool result = pars.checkProvideData();
    cr_assert_eq(result, false);
}