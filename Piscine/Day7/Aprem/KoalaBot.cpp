/*
** EPITECH PROJECT, 2020
** KoalaBot.cpp
** File description:
** KoalaBot.cpp
*/

/*
** EPITECH PROJECT, 2020
** KoalaBot.cpp
** File description:
** KoalaBot.cpp
*/

#include "KoalaBot.hpp"

KoalaBot::KoalaBot(std::string const &serial) : _serial(serial)
{

}

KoalaBot::~KoalaBot()
{
}

void KoalaBot::setParts(Arms const &parts)
{
    _arms = parts;
}

void KoalaBot::setParts(Legs const &parts)
{
    _legs = parts;
}

void KoalaBot::setParts(Head const &parts)
{
    _head = parts;
}

void KoalaBot::swapParts(Arms const &parts)
{
    setParts(parts);
}

void KoalaBot::swapParts(Legs const &parts)
{
    setParts(parts);
}

void KoalaBot::swapParts(Head const &parts)
{
    setParts(parts);
}

void KoalaBot::informations(void) const
{
    std::cout << "[KoalaBot] " << _serial << std::endl;
    _arms.information();
    _legs.information();
    _head.information();
}

bool KoalaBot::status(void) const
{
    bool a = _arms.isFunctionnal();
    bool b = _legs.isFunctionnal();
    bool c = _head.isFunctionnal();
    if ((a == true) && (b == true) && (c == true))
        return (true);
    return (false);
}