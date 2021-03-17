/*
** EPITECH PROJECT, 2020
** Peon.cpp
** File description:
** Peon.cpp
*/

#include "Peon.hpp"

Peon::Peon(std::string const &name) : Victim(name)
{
    std::cout << "Zog zog." << std::endl;
}

Peon::~Peon()
{
    std::cout << "Bleuark..." << std::endl;
}

void Peon::getPolymorphed() const
{
    std::cout << _name << " has been turned into a pink pony!" << std::endl;
}
