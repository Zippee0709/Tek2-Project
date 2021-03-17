/*
** EPITECH PROJECT, 2020
** SickKoala.cpp
** File description:
** SickKoala.cpp
*/

#include "SickKoala.hpp"

SickKoala :: SickKoala(std::string str)
{
    name = str;
}

SickKoala :: ~SickKoala()
{
    std :: cout << "Mr." << name << ": Kreooogg!! I'm cuuuured!" << std :: endl;
}

void SickKoala :: poke(void)
{
    std :: cout << "Mr." << name << ": Gooeeeeerrk!!" << std :: endl;
}

bool SickKoala :: takeDrug(std :: string str)
{
    if (str.compare("Mars") == 0) {
        std :: cout << "Mr." << name << ": Mars, and it kreogs!" << std :: endl;
        return (true);
    }
    else if (str.compare("Buronzand") == 0) {
        std :: cout << "Mr." << name << ": And you'll sleep right away!" << std :: endl;
        return (true);
    }
    std :: cout << "Mr." << name << ": Goerkreog!" << std :: endl;
    return (false);
}

void SickKoala :: overDrive(std :: string str)
{
    while (str.find("Kreog!") != std :: string :: npos)
        str.replace(str.find("Kreog!"), 5, "1337");
    std :: cout << "Mr." << name << ": " << str << std :: endl;
}

std :: string SickKoala :: getName()
{
    return (name);
}