/*
** EPITECH PROJECT, 2020
** Hunter.cpp
** File description:
** Hunter
*/

#include "Hunter.hpp"

Hunter::Hunter(const std::string &name, int level, std::string weapon) : Character(name, level), Warrior(name, level, weapon)
{
    _strength = 9;
    _stamina = 9;
    _intelligence = 5;
    _spirit = 6;
    _agility = 25;
    std::cout << _name << " is born from a tree" << std::endl;
}

Hunter::~Hunter()
{
}

int Hunter::CloseAttack()
{
    return (CloseAttack());
}

int Hunter::RangeAttack()
{
    int damage = 0;

    if (_mp - 25 < 0) {
        std::cout << _name << " out of range" << std::endl;
        return (damage);
    }
    _mp -= 25;
    damage = 20 + _agility;
    std::cout << _name << " uses his bow" << std::endl;
    return (damage);
}

void Hunter::Heal()
{
    if (_hp + 50 > 100)
        _hp = 100;
    else
        _hp += 50;
    std::cout << _name << " takes a potion" << std::endl;
}

void Hunter::RestorePower()
{
    if (_mp + 100 > 100)
        _mp = 100;
    else
        _mp += 100;
    std::cout << _name << " meditates" << std::endl;
}