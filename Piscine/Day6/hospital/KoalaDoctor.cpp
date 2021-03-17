/*
** EPITECH PROJECT, 2020
** KoalaDoctor
** File description:
** KoalaDoctor
*/

#include "KoalaDoctor.hpp"

KoalaDoctor :: KoalaDoctor(std :: string doctor_name)
{
    name = doctor_name;
    work = false;
    std :: cout << "Dr." << name << ": I'm Dr." << name 
    << "! How do you kreog?" << std :: endl;
}

KoalaDoctor :: ~KoalaDoctor()
{
}

void KoalaDoctor :: diagnose(SickKoala * koala)
{
    std :: string koala_name;
    int random = rand() % 5 + 1;

    if (koala == NULL)
        return;
    koala_name = koala->getName();
    std :: cout << "Dr." << name << ": So what's goerking you Mr." 
    << koala_name << "?" << std :: endl;
    koala->poke();
    koala_name = koala_name + ".report";
    std :: ofstream file(koala_name.c_str());
    if (file) {
        if (random == 1)
            file << "Mars";
        if (random == 2)
            file << "Buronzand";
        if (random == 3)
            file << "Viagra";
        if (random == 4)
            file << "Extasy";
        if (random == 5)
            file << "Eucalyptus leaf";
    }
}

void KoalaDoctor :: timeCheck(void)
{
    if (work == false) {
        std :: cout << "Doctor." << name << ": Time to get to work!" << std :: endl;
        work = true;    
    } else if (work == true) {
        std :: cout << "Doctor." << name << ": Time to go home to my eucalyptus forest!" << std :: endl;
        work = false;
    }

}