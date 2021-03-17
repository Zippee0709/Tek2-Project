/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** Plazza
*/

#include <cstdlib>
#include "Plazza.hpp"
#include "../Exception/PlazzaException.hpp"

PlazzaProject::Plazza::Plazza()
{
}

PlazzaProject::Plazza::~Plazza()
{
}   

void PlazzaProject::Plazza::setParameters(int ac, char **argv)
{
    if (ac != 4) {
        throw MainParsingError("3 arguments needed.");
    }
    try {
        _cookingTimeMultiplier = std::stof(argv[1]);
        _numberOfCooks = std::stof(argv[2]);
        _replaceStockCooldown = std::stof(argv[3]);
    } catch (std::invalid_argument e) {
        throw MainParsingError("arguments need to be a number.");
    }
    std::cout << "Cook time : " << _cookingTimeMultiplier << std::endl << "Number of cooks : " << _numberOfCooks << std::endl << "Cooldown : " << _replaceStockCooldown << std::endl;
}

void PlazzaProject::Plazza::start()
{
    Reception reception(_cookingTimeMultiplier, _numberOfCooks, _replaceStockCooldown);

    reception.takeCommand();
}