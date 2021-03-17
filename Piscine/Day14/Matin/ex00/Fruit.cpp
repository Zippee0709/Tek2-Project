/*
** EPITECH PROJECT, 2020
** cpp_d14m_2019
** File description:
** Fruit
*/

#include "Fruit.hpp"

Fruit::Fruit(const std::string &name, int vitamins) : _name(name), _vitamins(vitamins)
{
}

Fruit::~Fruit()
{
}

int Fruit::getVitamins() const
{
    return _vitamins;
}

std::string Fruit::getName() const
{
    return _name;
}
