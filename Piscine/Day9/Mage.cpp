/*
** EPITECH PROJECT, 2020
** Mage.cpp
** File description:
** Mage.cpp
*/

#include "Mage.hpp"

Mage::Mage(const std::string &name, int level) : Character(name, level)
{
    _strength = 6;
    _stamina = 6;
    _intelligence = 12;
    _spirit = 11;
    _agility = 7;
    std::cout << _name << " teleported" << std::endl;
}

Mage::~Mage()
{
}

int Mage::CloseAttack()
{
    int damage = 0;

    if (_mp - 10 < 0) {
        std::cout << _name << " out of range" << std::endl;
        return (damage);
    }
    _mp -= 10;
    Range = RANGE;
    std::cout << _name << " blinks" << std::endl;
    return (damage);
}

int Mage::RangeAttack()
{
    int damage = 0;

    if (_mp - 25 < 0) {
        std::cout << _name << " out of range" << std::endl;
        return (damage);
    }
    _mp -= 25;
    damage = 20 + _spirit;
    std::cout << _name << " launches a fire ball" << std::endl;
    return (damage);
}

void Mage::RestorePower()
{
    if (_mp + 50 + _intelligence > 100)
        _mp = 100;
    else
        _mp += 50 + _intelligence;
    std::cout << _name << " takes a mana potion" << std::endl;
}