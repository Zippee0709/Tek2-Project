/*
** EPITECH PROJECT, 2020
** Droid.cpp
** File description:
** Droid
*/

#include "Droid.hpp"

Droid::Droid(std::string id) : Id(id), Energy(50), Attack(25), Toughness(15), Status(new std::string ("Standing by"))
{
    std::cout << "Droid '" << Id << "' Activated" << std::endl;
}

Droid::Droid(Droid const &droid) : Id(droid.getId()), Energy(droid.getEnergy()), Attack(droid.getAttack()), Toughness(droid.getToughness())
{
    Status = new std::string (*droid.getStatus());
    std::cout << "Droid '" << Id << "' Activated, Memory Dumped" << std::endl;
}

Droid::~Droid()
{
    delete Status;
    std::cout << "Droid '" << Id << "' Destroyed" << std::endl;
}

std::string Droid::getId() const
{
    return (Id);
}

size_t Droid::getEnergy() const
{
    return (Energy);
}

size_t Droid::getAttack() const
{
    return (Attack);
}

size_t Droid::getToughness() const
{
    return (Toughness);
}

std::string * Droid::getStatus() const
{
    return (Status);
}

void Droid::setId(std::string id)
{
    Id = id;
}

void Droid::setEnergy(size_t energy)
{
    Energy = energy;
}

void Droid::setStatus(std::string *status)
{
    delete Status;
    Status = status;
}

void Droid::operator=(const Droid &droid)
{
    Id = droid.getId();
    Energy = droid.getEnergy();
    delete Status;
    Status = new std::string(*droid.getStatus());
}

bool Droid::operator==(const Droid &droid)
{
    if ((Id == droid.getId()) &&
        (Energy == droid.getEnergy()) &&
        (*Status == *droid.getStatus()))
        return (true);
    return (false);
}

bool Droid::operator!=(const Droid &droid)
{
    if ((Id != droid.getId()) ||
        (Energy != droid.getEnergy()) ||
        (*Status != *droid.getStatus()))
        return (true);
    return (false);
}

void Droid::operator<<(size_t &energy)
{
    size_t need_energy = 100 - Energy;

    if (energy == 0 || need_energy == 0)
        return;
    if (need_energy > energy) {
        need_energy = energy;
        Energy += need_energy;
        energy = 0;
    } else {
        Energy += need_energy;
        energy -= need_energy;
    }
}

std::ostream& operator<<(std::ostream &flux, Droid const &droid)
{
    flux << "Droid '" << droid.getId() << "', " << (*droid.getStatus()) << ", " << droid.getEnergy();
    return (flux);
}