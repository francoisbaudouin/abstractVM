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

Test(main_base_good_file, goodFileProvide)
{
    Parser::ParssCommand pars;
    const std::string filetest = "exemple/exemple.avm";

    int result = pars.readData(filetest);

    cr_assert_eq(result, 0);
}

Test(main_base_bad_file, badFileProvide)
{
    Parser::ParssCommand pars;
    const std::string filetest = "exemple/badFile.avm";

    bool result = pars.readData(filetest);

    cr_assert_eq(result, 1);
}

Test(data_given_is_good, dataOk)
{
    Parser::ParssCommand pars;
    const std::string filetest = "exemple/exemple.avm";

    pars.readData(filetest);
    bool result = pars.checkProvideData();

    cr_assert_eq(result, true);
}

Test(data_given_is_bad, dataKO)
{
    Parser::ParssCommand pars;
    const std::string filetest = "exemple/badexemple.avm";

    pars.readData(filetest);
    bool result = pars.checkProvideData();

    cr_assert_eq(result, false);
}

Test(given_over_data, Ok)
{
    Parser::ParssCommand pars;
    const std::string filetest = "exemple/exempleoverdata.avm";

    pars.readData(filetest);
    bool result = pars.checkProvideData();

    cr_assert_eq(result, false);
}

Test(code_with_comment_at_the_beginning, OK)
{
    Parser::ParssCommand pars;
    const std::string filetest = "exemple/exmp_with_code_command.avm";

    pars.readData(filetest);
    bool result = pars.checkProvideData();

    cr_assert_eq(result, true);
}

Test(code_with_comment_line, OK)
{
    Parser::ParssCommand pars;
    const std::string filetest = "exemple/exmp_comment_inline.avm";

    pars.readData(filetest);
    bool result = pars.checkProvideData();

    cr_assert_eq(result, true);
}
