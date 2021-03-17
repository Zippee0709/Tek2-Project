/*
** EPITECH PROJECT, 2020
** Skat.cpp
** File description:
** Skat.cpp
*/

#include "Skat.hpp"

Skat::Skat(const std::string& name, int stimPacks) : _name(name), _stimPaks(stimPacks)
{
}

Skat::~Skat()
{
}

int& Skat::stimPaks()
{
    int& stims = _stimPaks;
    return(stims);
}

const std::string& Skat::name()
{
    return (_name);
}

void Skat::shareStimPaks(int number, int& stock)
{
    if (_stimPaks - number < 0) {
        std::cout << "Don't be greedy" << std::endl;
        return;
    }
    stock += number;
    _stimPaks -= number;
    std::cout << "Keep the change." << std::endl;
}

void Skat::addStimPaks(unsigned int number)
{
    if (number == 0) {
        std::cout << "Hey boya, did you forget something?" << std::endl;
        return;
    }
    _stimPaks += number;
}

void Skat::useStimPaks()
{
    if (_stimPaks- 1 < 0) {
        std::cout << "Mediiiiiic" << std::endl;
    }
    _stimPaks -= 1;
    std::cout << "Time to kick some ass and chew bubble gum." << std::endl;
}

void Skat::status()
{
    std::cout << "Soldier " << _name << " reporting " << _stimPaks << " stimpaks remaining sir!" << std::endl;
}