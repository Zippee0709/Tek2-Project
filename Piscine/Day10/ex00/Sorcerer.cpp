/*
** EPITECH PROJECT, 2020
** Sorcerer.cpp
** File description:
** Sorcerer.cpp
*/

#include "Sorcerer.hpp"

Sorcerer::Sorcerer(std::string const &name, std::string const &title) : _name(name), _title(title)
{
    std::cout << _name << ", " << _title << ", is born!" << std::endl;
}

Sorcerer::~Sorcerer()
{
    std::cout << _name << ", " << _title << ", is dead. Consequences will never be the same!" << std::endl;
}


std::string Sorcerer::getName() const
{
    return _name;
}

std::string Sorcerer::getTitle() const
{
    return _title;
}

void Sorcerer::polymorph(const Victim &victim)
{
    victim.getPolymorphed();
}

void Sorcerer::polymorph(const Peon &peon)
{
    peon.getPolymorphed();
}

std::ostream& operator<<(std::ostream &flux, Sorcerer const &sorcerer)
{
    flux << "I am " << sorcerer.getName() << ", " << sorcerer.getTitle() << ", and I like ponies!" << std::endl;
    return flux;
}
