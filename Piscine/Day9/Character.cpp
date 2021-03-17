/*
** EPITECH PROJECT, 2020
** Character.cpp
** File description:
** Character.cpp
*/

#include "Character.hpp"

Character::Character(const std::string &name, int level) : Range(CLOSE), _name(name), _level(level), _hp(100), _mp(100), _strength(5), _stamina(5), _intelligence(5), _spirit(5), _agility(5)
{
    std::cout << _name << " Created" << std::endl;
}

Character::~Character()
{
}

//getter
const std::string &Character::getName(void) const 
{
    const std::string &name = _name;
    return name;
}

int Character::getLvl(void) const
{
    return _level;
}

int Character::getPv(void) const
{
    return _hp;
}

int Character::getPower(void) const
{
    return (_mp);
}

//Technique

int Character::CloseAttack()
{
    int damage = 0;

    if (_mp - 10 < 0) {
        std::cout << _name << " out of power" << std::endl;
        return (damage);
    }
    _mp -= 10;
    damage = 10 + _strength;
    std::cout << _name << " strikes with a wooden stick" << std::endl;
    return (damage);
}

int Character::RangeAttack()
{
    int damage = 0;

    if (_mp -10 < 0) {
        std::cout << _name << "out of power" << std::endl;
        return (damage);
    }
    _mp -= 10;
    damage = 5 + _strength;
    std::cout << _name << " tosses a stone" << std::endl;
    return (damage);
}

void Character::Heal()
{
    if (_hp + 50 > 100)
        _hp = 100;
    else
        _hp += 50;
    std::cout << _name << " takes a potion" << std::endl;
}

void Character::RestorePower()
{
    if (_mp + 100 > 100)
        _mp = 100;
    else
        _mp += 100;
    std::cout << _name << " eats" << std::endl;
}

void Character::TakeDamage(int damage)
{
    if (_hp - damage < 0) {
        _hp = 0;
        std::cout << _name << " out of combat" << std::endl;
    } else {
        _hp -= damage;
        std::cout << _name << " takes " << damage << " damage" << std::endl;
    }
}