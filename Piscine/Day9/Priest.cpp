/*
** EPITECH PROJECT, 2020
** Priest.cpp
** File description:
** Priest.cpp
*/

#include "Priest.hpp"

Priest::Priest(const std::string &name, int level) : Character(name, level), Mage(name, level)
{
    _strength = 4;
    _stamina = 4;
    _intelligence = 42;
    _spirit = 21;
    _agility = 2;
    std::cout << _name << " enters in the order" << std::endl;
}

Priest::~Priest()
{
}

int Priest::CloseAttack()
{
    int damage = 0;

    if (_mp - 10 < 0) {
        std::cout << _name << " out of range" << std::endl;
        return (damage);
    }
    _mp -= 10;
    damage = 10 + _spirit;
    Range = RANGE;
    std::cout << _name << " uses a spirit explosion" << std::endl;
    return (damage);
}

void Priest::Heal()
{
    if (_mp - 10 < 0) {
        std::cout << _name << " out of range" << std::endl;
        return;
    }
    _mp -= 10;
    if (_hp + 70 > 100)
        _hp = 100;
    else
        _hp += 70;
    std::cout << _name << " casts a little heal spell" << std::endl;
}