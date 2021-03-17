/*
** EPITECH PROJECT, 2020
** Warrior.cpp
** File description:
** Warrior.cpp
*/

#include "Warrior.hpp"

Warrior::Warrior(const std::string &name, int level, std::string weapon) : Character(name, level)
{
    _weaponName = weapon;
    _strength = 12;
    _stamina = 12;
    _intelligence = 6;
    _spirit = 5;
    _agility = 7;
    std::cout << "I'm " << _name << " KKKKKKKKKKRRRRRRRRRRRRRREEEEEEEEOOOOOOORRRRGGGGGGG" << std::endl;
}

Warrior::~Warrior()
{

}

int Warrior::CloseAttack(void)
{
    int damage = 0;

    if (_mp - 30 < 0) {
        std::cout << _name << " out of range" << std::endl;
        return (damage);
    }
    _mp -= 30;
    damage = _strength + 20;
    std::cout << _name << " strikes with his " << _weaponName << std::endl;
    return (damage);
}

int Warrior::RangeAttack(void)
{
    int damage = 0;

    if (_mp - 10 < 0) {
        std::cout << _name << " out of range" << std::endl;
        return (damage);
    }
    _mp -= 10;
    damage = 0;
    Range = CLOSE;
    std::cout << _name << " intercepts" << std::endl;
    return (damage);
}