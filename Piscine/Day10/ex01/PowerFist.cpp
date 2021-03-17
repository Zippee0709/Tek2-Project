/*
** EPITECH PROJECT, 2020
** PowerFist.cpp
** File description:
** PowerFist.cpp
*/

#include "PowerFist.hpp"

PowerFist::PowerFist() : AWeapon("Power Fist", 8, 50)
{
}

PowerFist::~PowerFist()
{
}

void PowerFist::attack()
{
    std::cout << "* pachhh... SBAM! *" << std::endl;
}
