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
    std::vector<std::string> test;

    // Choice between reading file or user input
    if (ac == 2) {
        std::string str((argv[1]));
        if (pars.readData(str) != 0) {
            return (80);
        }
    } else {
        pars.readData();
    }

    //get my data and display it
    test = pars.getData();
    for (std::string i : test)
        std::cout << i << std::endl;
    test.clear();
    return 0;
}