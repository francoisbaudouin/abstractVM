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
    const std::string filetest = "exemple.avm";

    int result = pars.readData(filetest);

    cr_assert_eq(result, 0);
}

Test(main_base_bad_file, badFileProvide)
{
    Parser::ParssCommand pars;
    const std::string filetest = "badFile.avm";

    bool result = pars.readData(filetest);

    cr_assert_eq(result, 1);
}

Test(data_given_is_good, dataOk)
{
    Parser::ParssCommand pars;
    const std::string filetest = "exemple.avm";

    pars.readData(filetest);
    bool result = pars.checkProvideData();

    cr_assert_eq(result, true);
}

Test(data_given_is_bad, dataKO)
{
    Parser::ParssCommand pars;
    const std::string filetest = "badexemple.avm";

    pars.readData(filetest);
    bool result = pars.checkProvideData();

    cr_assert_eq(result, false);
}

Test(given_over_data, Ok)
{
    Parser::ParssCommand pars;
    const std::string filetest = "exempleoverdata.avm";

    pars.readData(filetest);
    bool result = pars.checkProvideData();

    cr_assert_eq(result, false);
}

Test(storage_data_not_empty, KO)
{
    Parser::ParssCommand pars;
    const std::string filetest = "exemple.avm";

    pars.readData(filetest);
    bool result = pars.readData(filetest);
    std::cout << result << std::endl;

    cr_assert_eq(result, false);
}
