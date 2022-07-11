/*
** EPITECH PROJECT, 2022
** abstractVM
** File description:
** main
*/

#include <iostream>
#include "factory/Factory.hpp"
#include "parser/Interpretor.hpp"
#include "parser/Parser.hpp"

bool execution_prog(std::map<std::string, std::tuple<AbstractVM::eOperandType, std::string>> data)
{
    Parser::Interpretor exec;
    for (auto const &[key, value] : data) {
        std::unordered_map<std::string, std::function<void()>>::const_iterator it =
            exec._functPtr.find(exec.getGivenCommand(key));
        if (it == exec._functPtr.end()) {
            return (false);
        } else {
            exec.setDataCommand(value);
            it->second();
        }
    }
    return (true);
}

int main(int ac, char **argv)
{
    Parser::ParssCommand pars;

    // Choice between reading file or user input
    if (ac == 2) {
        std::string str((argv[1]));
        if (pars.readData(str) != 0) {
            return (84);
        }
    } else {
        pars.readData();
    }
    if (pars.checkProvideData() == false) {
        return (84);
    }
    execution_prog(pars.getDataCommand());
    return 0;
}