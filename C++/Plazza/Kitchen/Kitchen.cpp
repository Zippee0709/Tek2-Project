/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** Kitchen
*/

#include <iostream>
#include <vector>
#include <unistd.h>
#include "Kitchen.hpp"
#include "../Plazza/PlazzaProject.hpp"

PlazzaProject::Kitchen::Kitchen(float cookingTimeMultiplier, int numberOfCooks, int replaceStockCoolDown, SharedMemory sharedMemory)
    :_cookingTimeMultiplier(cookingTimeMultiplier), _numberOfCooks(numberOfCooks), _replaceStockCooldown(replaceStockCoolDown), _shMem(sharedMemory)
{
    _stock[Ingredient::doe] = 5;
    _stock[Ingredient::tomato] = 5;
    _stock[Ingredient::gruyere] = 5;
    _stock[Ingredient::ham] = 5;
    _stock[Ingredient::mushroom] = 5;
    _stock[Ingredient::steak] = 5;
    _stock[Ingredient::eggplant] = 5;
    _stock[Ingredient::goatCheese] = 5;
    _stock[Ingredient::chiefLove] = 5;
    for (int i = 0; i < _numberOfCooks; i++) {
        _cooks.push_back(new Thread);
    }
}

PlazzaProject::Kitchen::~Kitchen()
{
    for (auto it = _cooks.begin(); it != _cooks.end(); it++) {
        delete (*it);
    }
}

void PlazzaProject::Kitchen::receiveCommand()
{
    std::chrono::time_point<std::chrono::high_resolution_clock> end;
    _start = std::chrono::high_resolution_clock::now();

    _shMem.updateSharedMemory();
    while (isAlive) {
        std::cout << _shMem.getSharedMemoryData().commands->at(0) << std::endl;
        for (auto command : *(_shMem.getSharedMemoryData().commands)) {
            std::cout << command << std::endl;
        }
        sleep(10);
    }
}