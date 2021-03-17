/*
** EPITECH PROJECT, 2020
** Paladin.cpp
** File description:
** Paladin
*/

#include "Paladin.hpp"

Paladin::Paladin(const std::string &name, int level) : Character(name, level), Warrior(name, level), Mage(name, level), Priest(name, level)
{
    Warrior::_strength = 9;
    Warrior::_stamina = 10;
    Warrior::_intelligence = 10;
    Warrior::_spirit = 10;
    Warrior::_agility = 9;

    Priest::_strength = 9;
    Priest::_stamina = 10;
    Priest::_intelligence = 10;
    Priest::_spirit = 10;
    Priest::_agility = 9;
    std::cout << "the light falls on " << Warrior::_name << std::endl;
}

Paladin::~Paladin()
{
}

int Paladin::CloseAttack()
{
    return (Warrior::CloseAttack());
}

int Paladin::RangeAttack()
{
    return (Priest::RangeAttack());
}

void Paladin::Heal()
{
    return (Priest::Heal());
}

void Paladin::RestorePower()
{
    return (Warrior::RestorePower());
}

int Paladin::Intercept()
{
    return (Warrior::RangeAttack());
}