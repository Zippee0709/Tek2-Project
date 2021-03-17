/*
** EPITECH PROJECT, 2020
** PlasmaRifle.cpp
** File description:
** PlasmaRifle.cpp
*/

#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle() : AWeapon("Plasma Rifle", 5, 21)
{
}

PlasmaRifle::~PlasmaRifle()
{
}

void PlasmaRifle::attack()
{
    std::cout << "* piouuu piouuu piouuu *" << std::endl;
}