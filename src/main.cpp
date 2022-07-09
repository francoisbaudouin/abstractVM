/*
** EPITECH PROJECT, 2022
** abstractVM
** File description:
** main
*/

#include <iostream>
#include "parser/Parser.hpp"
#include "factory/Factory.hpp"

int main(int ac, char **argv)
{
    // Parser::ParssCommand pars;

    // Choice between reading file or user input
    // if (ac == 2) {
    //     std::string str((argv[1]));
    //     if (pars.readData(str) != 0) {
    //         return (80);
    //     }
    // } else {
    //     pars.readData();
    // }
    // if (pars.checkProvideData() == false)
    //     return (84);

    AbstractVM::Factory newfactory;

    AbstractVM::IOperand *ope = newfactory.operands.at(AbstractVM::DOUBLE)("1273");

    std::cout << ope->toString() << std::endl;
    std::cout << ope->getType() << std::endl;
    std::cout << ope->getPrecision() << std::endl;

    return 0;
}