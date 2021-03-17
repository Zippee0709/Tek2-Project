/*
** EPITECH PROJECT, 2019
** LittlePony.cpp
** File description:
** LitllePony functions
*/

#include "LittlePony.hpp"

LittlePony::LittlePony() : Toy("Little Pony", TYPE::PONY)
{
}

LittlePony::LittlePony(std::string const &title) : Object(title, TYPE::PONY), Toy(title, TYPE::PONY)
{
}

LittlePony::~LittlePony()
{
}

void  LittlePony::isTaken() const
{
    std::cout << "yo man" << std::endl;
}