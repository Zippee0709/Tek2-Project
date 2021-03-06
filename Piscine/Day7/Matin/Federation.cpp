/*
** EPITECH PROJECT, 2020
** Federation
** File description:
** Federation
*/

#include "Federation.hpp"

// Federation :: Starfleet :: Ship
Federation :: Starfleet :: Ship :: Ship(int length, int width, std::string name, short maxWarp, int torpedo)
{
    _length = length;
    _width = width;
    _name = name;
    _maxWarp = maxWarp;
    _home = EARTH;
    _shield = 100;
    _photonTorpedo = 0;
    std :: cout << "The ship USS " << name << " has been finished." << std :: endl;
    std :: cout << "It is " << length << " m in length and " << width << " m in width." << std :: endl;
    std :: cout << "It can go to Warp " << maxWarp << "!" << std :: endl;
    if (torpedo != 0) {
        _photonTorpedo = torpedo;
        std :: cout << "Weapons are set: " << _photonTorpedo << " torpedoes ready." << std::endl;
    }
}

Federation :: Starfleet :: Ship :: Ship()
{
    _length = 289;
    _width = 132;
    _name = "Entreprise";
    _maxWarp = 6;
    _home = EARTH;
    _shield = 100;
    _photonTorpedo = 0;
    std :: cout << "The ship USS " << _name << " has been finished." << std :: endl;
    std :: cout << "It is " << _length << " m in length and " << _width << " m in width." << std :: endl;
    std :: cout << "It can go to Warp " << _maxWarp << "!" << std :: endl;

}

Federation :: Starfleet :: Ship::~Ship()
{
}

void Federation :: Starfleet :: Ship :: setupCore(WarpSystem::Core *new_core)
{
    core = new_core;
    std :: cout << "USS " << _name << ": The core is set." << std :: endl;
}

void Federation :: Starfleet :: Ship :: checkCore(void)
{
    WarpSystem::QuantumReactor * tmp = core->checkReactor();
    if (tmp->isStable() == true)
        std :: cout << "USS " << _name << ": The core is stable at the time." << std :: endl;
    else
        std :: cout << "USS " << _name << ": The core is unstable at the time." << std :: endl;
}

void Federation :: Starfleet :: Ship :: promote(Starfleet :: Captain *new_captain)
{
    _captain = new_captain;
    std :: cout << _captain->getName() << ": I'm glad to be the captain of the USS "
    << _name << "." << std :: endl;
}

bool Federation :: Starfleet :: Ship :: move(int warp, Destination d)
{
    WarpSystem::QuantumReactor *tmp = core->checkReactor();
    if ((warp <= _maxWarp) && (d != _location) && (tmp->isStable() == true)) {
        _location = d;
        return (true);
    }
    return (false);
}

bool Federation :: Starfleet :: Ship :: move(int warp)
{
    WarpSystem::QuantumReactor *tmp = core->checkReactor();
    if ((warp <= _maxWarp) && (tmp->isStable() == true)) {
         _location = _home;
        return (true);
    }
    return (false);
}

bool Federation :: Starfleet :: Ship :: move(Destination d)
{
    WarpSystem::QuantumReactor *tmp = core->checkReactor();
    if ((d != _location) && (tmp->isStable() == true)) {
        _location = d;
        return (true);
    }
    return (false);
}

bool Federation :: Starfleet :: Ship :: move()
{
    WarpSystem::QuantumReactor *tmp = core->checkReactor();
    if (tmp->isStable() == true) {
        _location = _home;
        return (true);
    }
    return (false);
}

int Federation :: Starfleet :: Ship :: getShield(void)
{
    return(_shield);
}

void Federation :: Starfleet :: Ship :: setShield(int shield)
{
    _shield = shield;
}

int Federation :: Starfleet :: Ship :: getTorpedo()
{
    return(_photonTorpedo);
}

void Federation :: Starfleet :: Ship :: setTorpedo(int torpedo)
{
    _photonTorpedo = torpedo;
}

void Federation :: Starfleet :: Ship :: fire(Borg::Ship *target)
{
    int new_shield = 0;

    if (_photonTorpedo == 0)
        std :: cout << _name << ": No enough torpedoes to fire, " 
        << _captain->getName() << "!" << std::endl;
    else {
        _photonTorpedo = _photonTorpedo - 1;
        std :: cout << _name << ": Firing on target. " 
        << _photonTorpedo << "torpedoes remaining." << std::endl;
        if (_photonTorpedo == 0)
            std :: cout << _name << ": No more torpedo to fire, " 
            << _captain->getName() << "!" << std::endl;
        new_shield = target->getShield() - 50;
        target->setShield(new_shield);
    }
}

void Federation :: Starfleet :: Ship :: fire(int torpedoes, Borg::Ship *target)
{
    int new_shield = 0;

    if (_photonTorpedo == 0 || _photonTorpedo - torpedoes < 0)
        std :: cout << _name << ": No enough torpedoes to fire, " 
        << _captain->getName() << "!" << std::endl;
    else {
        _photonTorpedo = _photonTorpedo - torpedoes;
        std :: cout << _name << ": Firing on target. " 
        << _photonTorpedo << "torpedoes remaining." << std::endl;
        if (_photonTorpedo == 0)
            std :: cout << _name << ": No more torpedo to fire, " 
            << _captain->getName() << "!" << std::endl;
        new_shield = target->getShield() - (50 * torpedoes);
        target->setShield(new_shield);
    }
}

// Federation :: Starfleet :: Captain

Federation :: Starfleet :: Captain :: Captain(std :: string captain_name)
{
    _name = captain_name;
}

Federation :: Starfleet :: Captain :: ~Captain()
{
    
}

std :: string Federation :: Starfleet :: Captain :: getName()
{
    return(_name);
}

int Federation :: Starfleet :: Captain :: getAge()
{
    return(_age);
}

void Federation :: Starfleet :: Captain :: setAge(int age)
{
    _age = age;
}

// Federation :: Starfleet :: Ensign

Federation :: Starfleet :: Ensign :: Ensign(std :: string new_name)
{
    _name = new_name;
    std :: cout << "Ensign " << _name << ", awaiting orders." << std :: endl;
}

Federation :: Starfleet :: Ensign :: ~Ensign()
{
    
}

// Federation :: Ship
Federation :: Ship :: Ship(int length, int width, std::string name)
{
    _length = length;
    _width = width;
    _name = name;
    _home = VULCAN;
    std :: cout << "The independent ship " << name << " just finished its construction." << std :: endl;
    std :: cout << "It is " << length << " m in length and " << width << " m in width." << std :: endl;
}

Federation :: Ship :: ~Ship()
{

}

void Federation :: Ship :: setupCore(WarpSystem::Core *new_core)
{
    core = new_core;
    std :: cout << _name << ": The core is set." << std :: endl;
}

void Federation :: Ship :: checkCore(void)
{
    WarpSystem::QuantumReactor * tmp = core->checkReactor();
    if (tmp->isStable() == true)
        std :: cout << _name << ": The core is stable at the time." << std :: endl;
    else
        std :: cout << _name << ": The core is unstable at the time." << std :: endl;
}

bool Federation :: Ship :: move(int warp, Destination d)
{
    WarpSystem::QuantumReactor *tmp = core->checkReactor();
    (void)warp;
    if ((d != _location) && (tmp->isStable() == true)) {
        _location = d;
        return (true);
    }
    return (false);
}

bool Federation :: Ship :: move(int warp)
{
    WarpSystem::QuantumReactor *tmp = core->checkReactor();
    (void)warp;
    if (tmp->isStable() == true) {
         _location = _home;
        return (true);
    }
    return (false);
}

bool Federation :: Ship :: move(Destination d)
{
    WarpSystem::QuantumReactor *tmp = core->checkReactor();
    if ((d != _location) && (tmp->isStable() == true)) {
        _location = d;
        return (true);
    }
    return (false);
}

bool Federation :: Ship :: move()
{
    WarpSystem::QuantumReactor *tmp = core->checkReactor();
    if (tmp->isStable() == true) {
        _location = _home;
        return (true);
    }
    return (false);
}

WarpSystem::Core *Federation :: Ship :: getCore(void)
{
    return(core);
}