/*
** EPITECH PROJECT, 2020
** Borg.cpp
** File description:
** Borg.cpp
*/

#include "WarpSystem.hpp"
#include "Borg.hpp"

Borg :: Ship :: Ship(int weaponFrequency, short repair)
{
    _side = 300;
    _maxWarp = 9;
    _home = UNICOMPLEX;
    _shield = 100;
    _weaponFrequency = weaponFrequency;
    _repair = repair;
    std :: string msg = "we are the Borgs. Lower your shields and surrender yourselves unconditionally.";
    std :: cout <<  msg << std :: endl;
    std :: cout << "Your biological characteristics and technologies will be assimilated." << std :: endl;
    std :: cout << "Resistance is futile." << std :: endl;
}

Borg :: Ship :: ~Ship()
{
}

void Borg :: Ship :: setupCore(WarpSystem::Core *new_core)
{
    core = new_core;
}

void Borg :: Ship :: checkCore(void)
{
    WarpSystem::QuantumReactor * tmp = core->checkReactor();
    if (tmp->isStable() == true)
        std :: cout << "Everything is in order." << std :: endl;
    else
        std :: cout << "Critical failure imminent." << std :: endl;
}

bool Borg :: Ship :: move(int warp, Destination d)
{
    WarpSystem::QuantumReactor *tmp = core->checkReactor();
    if ((warp <= _maxWarp) && (d != _location) && (tmp->isStable() == true)) {
        _location = d;
        return (true);
    }
    return (false);
}

bool Borg :: Ship :: move(int warp)
{
    WarpSystem::QuantumReactor *tmp = core->checkReactor();
    if ((warp <= _maxWarp) && (tmp->isStable() == true)) {
         _location = _home;
        return (true);
    }
    return (false);
}

bool Borg :: Ship :: move(Destination d)
{
    WarpSystem::QuantumReactor *tmp = core->checkReactor();
    if ((d != _location) && (tmp->isStable() == true)) {
        _location = d;
        return (true);
    }
    return (false);
}

bool Borg :: Ship :: move()
{
    WarpSystem::QuantumReactor *tmp = core->checkReactor();
    if (tmp->isStable() == true) {
        _location = _home;
        return (true);
    }
    return (false);
}


int Borg :: Ship :: getShield(void)
{
    return(_shield);
}

void Borg :: Ship :: setShield(int shield)
{
    _shield = shield;
}

int Borg :: Ship :: getWeaponFrequency()
{
    return (_weaponFrequency);
}

void Borg :: Ship :: setWeaponFrequency(int weaponFrequency)
{
    _weaponFrequency = weaponFrequency;
}

int Borg :: Ship :: getRepair()
{
    return (_repair);
}

void Borg :: Ship :: setRepair(int repair)
{
    _repair = repair;
}

void Borg::Ship::fire(Federation::Starfleet::Ship *target)
{
    int new_shield = target->getShield() - getWeaponFrequency();
    target->setShield(new_shield);
    std::cout << "Firing on target with " << getWeaponFrequency() << "GW frequency." << std::endl;
}

void Borg::Ship::fire(Federation::Ship *target)
{
    WarpSystem::QuantumReactor new_react;
    new_react.setStability(false);
    WarpSystem::Core new_core(&new_react);
    target->setupCore(&new_core);
    std::cout << "Firing on target with " << getWeaponFrequency() << "GW frequency." << std::endl;
}

void Borg::Ship::repair()
{
    if (_repair > 0) {
        _repair = _repair - 1;
        _shield = 100;
        std::cout << "Begin shield re-initialisation... Done. Awaiting further instructions." << std::endl;
        return;
    }
    std::cout << "Energy cells depleted, shield weakening." << std::endl;
}