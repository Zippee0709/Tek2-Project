/*
** EPITECH PROJECT, 2020
** Parts.cpp
** File description:
** Parts.cpp
*/

#include "Parts.hpp"


// Arms
Arms::Arms(std::string const &serial, bool functionnal) : _serial(serial), _functionnal(functionnal)
{
}

Arms::~Arms()
{
}

bool Arms::isFunctionnal() const
{
    if (_functionnal == true)
        return (true);
    return (false);
}

std::string Arms::serial()
{
    return (_serial);
}

void Arms::information() const
{
    if (isFunctionnal() == true)
        std::cout << "     [Parts] Arms " << _serial << " status : OK" << std::endl;
    else
        std::cout << "     [Parts] Arms " << _serial << " status : KO" << std::endl;
}

// Legs
Legs::Legs(std::string const  &serial, bool functionnal) : _serial(serial), _functionnal(functionnal)
{
}

Legs::~Legs()
{
}

bool Legs::isFunctionnal() const
{
    if (_functionnal == true)
        return (true);
    return (false);
}

std::string Legs:: serial()
{
    return (_serial);
}

void Legs::information() const
{
    if (isFunctionnal() == true)
        std::cout << "     [Parts] Legs " << _serial << " status : OK" << std::endl;
    else
        std::cout << "     [Parts] Legs " << _serial << " status : KO" << std::endl;
}

// Head
Head::Head(std::string const &serial, bool functionnal) : _serial(serial), _functionnal(functionnal)
{
}

Head::~Head()
{
}

bool Head::isFunctionnal() const
{
    if (_functionnal == true)
        return (true);
    return (false);
}

std::string Head:: serial()
{
    return (_serial);
}

void Head::information() const
{
    if (isFunctionnal() == true)
        std::cout << "     [Parts] Head " << _serial << " status : OK" << std::endl;
    else
        std::cout << "     [Parts] Head " << _serial << " status : KO" << std::endl;
}