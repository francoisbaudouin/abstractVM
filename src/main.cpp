/*
** EPITECH PROJECT, 2022
** abstractVM
** File description:
** main
*/

#include <iostream>
#include "parser/Parser.hpp"

int main(int ac, char **argv)
{
    Parser::ParssCommand pars;

    if (ac == 2) {
        std::string str((argv[1]));
        if (pars.readData(str) != 0) {
            return (80);
        }
    }
    return 0;
}