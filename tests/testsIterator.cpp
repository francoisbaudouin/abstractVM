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

Test(IteratorFunct, OK)
{
    Parser::ParssCommand pars;
    const std::string filetest = "tests/exemple/exemple.avm";
    bool result;
    pars.readData(filetest);
    pars.checkProvideData();

    Parser::Interpretor exec;

    std::vector<Parser::CommandData> &data = pars.getDataCommand();
    size_t vecSize = data.size();

    for (size_t i = 0; i < vecSize; i++) {
        auto it = exec._functPtr.find(data[i].getName());
        if (it == exec._functPtr.end()) {
            result = false;
            break;
        } else {
            exec.setDataCommand(data[i].getName(), data[i].geteOperant(), data[i].getValue());
            result = true;
            break;
        }
    }
    cr_assert_eq(pars.checkProvideData(), true);
}

Test(set_command, OK)
{
    Parser::ParssCommand pars;
    const std::string filetest = "tests/exemple/exemple.avm";
    bool result;
    pars.readData(filetest);
    pars.checkProvideData();

    Parser::Interpretor exec;

    std::vector<Parser::CommandData> &data = pars.getDataCommand();

    result = exec.setDataCommand(data[0].getName(), data[0].geteOperant(), data[0].getValue());
    cr_assert_eq(pars.checkProvideData(), true);
}

Test(set_command_bad, KO)
{
    Parser::ParssCommand pars;
    const std::string filetest = "tests/exemple/exemple.avm";
    bool result;
    pars.readData(filetest);
    pars.checkProvideData();

    Parser::Interpretor exec;

    std::vector<Parser::CommandData> &data = pars.getDataCommand();

    result = exec.setDataCommand(data[2].getName(), data[2].geteOperant(), data[2].getValue());
    std::cout << data[2].getName() << std::endl;
    cr_assert_eq(pars.checkProvideData(), false);
}