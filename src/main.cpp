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

void execution_prog(std::vector<std::string> data)
{
    (void)data;
    std::cout << "exec" << std::endl;
    Parser::Interpretor exec;
    std::string test = "add";
    std::unordered_map<std::string, std::function<void()>>::const_iterator it = exec._functPtr.find("add");
    std::shared_ptr<std::pair<AbstractVM::eOperandType, std::string>> _dataCommand;
    if (it == exec._functPtr.end()) {
        std::cout << "j'ai pas trouver =(" << std::endl;
    } else {
        std::cout << "j'ai trouver !" << std::endl;
        it->second(_dataCommand);
    }
    // std::string yolo = "40";
    // AbstractVM::IOperand *test = AbstractVM::Factory::createOperand(AbstractVM::eOperandType::INT8, yolo);
    // exec._memory.push(test);
    // exec._memory.print();
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