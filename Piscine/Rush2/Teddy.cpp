/*
** EPITECH PROJECT, 2019
** Teddy.cpp
** File description:
** Teddy functions
*/

#include "Teddy.hpp"

Teddy::Teddy() : Toy("Teddy", TYPE::TED)
{
}

Teddy::Teddy(const std::string &title) : Object(title, TYPE::TED), Toy(title, TYPE::TED)
{
}

Teddy::~Teddy()
{
}

void Teddy::isTaken() const
{
    std::cout << "gra hu" << std::endl;
}
