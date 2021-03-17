/*
** EPITECH PROJECT, 2020
** cpp_d07a_2019
** File description:
** main.cpp
*/

#include "Skat.hpp"
#include "KoalaBot.hpp"

int main ()
{
    Skat s("Junior", 5);
    Skat z("Akaza", 5);
    Skat test;
    std::cout << "Soldier " << s.name() << std::endl;
    std::cout << "Soldier " << z.name() << std::endl;
    std::cout << "Soldier " << test.name() << std::endl;
    std::cout << z.stimPaks() << std::endl;
    std::cout << s.stimPaks() << std::endl;
    z.status();
    s.status();
    z.shareStimPaks(3, s.stimPaks());
    z.useStimPaks();
    s.useStimPaks();
    std::cout << z.stimPaks() << std::endl;
    std::cout << s.stimPaks() << std::endl;

    std::cout << "----------TEST KoalaBot TEST----------" << std::endl;
    KoalaBot kb;
    std::cout << std::boolalpha << kb.status() << std::endl;
    kb.informations();
    return 0;
}