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

bool execution_prog(std::vector<std::string> data)
{
    Parser::Interpretor exec;

    for (std::string commandLine : data) {
        std::unordered_map<std::string, std::function<void()>>::const_iterator it =
            exec._functPtr.find(exec.getGivenCommand(commandLine));
        if (it == exec._functPtr.end()) {
            // throw exception, command is invalid (doesn't exist)
            return (false);
        } else {
            exec.setDataCommand(commandLine);
            return (false);
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
    if (pars.checkProvideData() == false)
        return (84);
    execution_prog(pars.getData());
    return 0;
}