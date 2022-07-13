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
#include ""

Parser::ParssCommand pars;
const std::string filetest = "tests/exemple/exemple.avm";
bool result = true;

pars.readData(filetest);
pars.checkProvideData();

Test(IteratorFunct, OK) {}