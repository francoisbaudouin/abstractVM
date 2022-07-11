/*
** EPITECH PROJECT, 2022
** abstractVM
** File description:
** main
*/

#include <iostream>
#include "factory/Factory.hpp"
#include "parser/CommandData.hpp"
#include "parser/Interpretor.hpp"
#include "parser/Parser.hpp"

bool execution_prog(std::vector<Parser::CommandData> &data)
{
    Parser::Interpretor exec;
    size_t vecSize = data.size();
    if (data.empty() == true) {
        return (false);
    }
    std::cout << "data name: " << data[0].getName() << std::endl;
    /* try {
        for (size_t i = 0; i != vecSize; i++) {
            std::unordered_map<std::string, std::function<void()>>::const_iterator it =
                exec._functPtr.find(data[i].getName());
            if (it == exec._functPtr.end()) {
                return (false);
            } else {
                exec.setDataCommand(data[i].geteOperant(), data[i].getValue());
                it->second();
            }
        }
    } catch (std::out_of_range &e) {
        std::cout << e.what() << std::endl;
    } */
    for (size_t i = 0; i != vecSize - 1; i++) {
        std::unordered_map<std::string, std::function<void()>>::const_iterator it =
            exec._functPtr.find(data[i].getName());
        if (it == exec._functPtr.end()) {
            return (false);
        } else {
            exec.setDataCommand(data[i].geteOperant(), data[i].getValue());
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