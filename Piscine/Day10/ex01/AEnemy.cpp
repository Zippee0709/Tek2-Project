/*
** EPITECH PROJECT, 2020
** AEnemy.cpp
** File description:
** AEnemy.cpp
*/

#include "AEnemy.hpp"

AEnemy::AEnemy(int hp, std::string const &type) : _hp(hp), _type(type)
{
}

AEnemy::~AEnemy()
{
}

std::string const AEnemy::getType() const
{
    return _type;
}

int AEnemy::getHP() const
{
    return _hp;
}
