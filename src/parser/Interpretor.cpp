/*
** EPITECH PROJECT, 2022
** abstractVM
** File description:
** Interpretor
*/

#include "Interpretor.hpp"

namespace Parser
{
    Interpretor::Interpretor() {}

    Interpretor::~Interpretor() 
    {
        if (!_functPtr.empty()) {
            std::cout << "Map clear captain" << std::endl;
            _functPtr.clear();
        }
    }
} // namespace Parser