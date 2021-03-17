/*
** EPITECH PROJECT, 2020
** cpp_d14m_2019
** File description:
** Lime
*/

#include "Lime.hpp"

Lime::Lime(const std::string &name, int vitamins) : Fruit(name, vitamins), Lemon(name, vitamins)
{
}

Lime::~Lime()
{
}
