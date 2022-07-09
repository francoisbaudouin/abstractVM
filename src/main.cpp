/*
** EPITECH PROJECT, 2022
** abstractVM
** File description:
** main
*/

#include <iostream>
#include "factory/Factory.hpp"
#include "parser/Parser.hpp"

int main(int ac, char **argv)
{
    Parser::ParssCommand pars;

    // Choice between reading file or user input
    if (ac == 2) {
        std::string str((argv[1]));
        if (pars.readData(str) != 0) {
            return (80);
        }
    } else {
        pars.readData();
    }
    if (pars.checkProvideData() == false)
        return (84);

    return 0;
}