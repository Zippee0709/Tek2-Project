/*
** EPITECH PROJECT, 2020
** KoalaNurse.cpp
** File description:
** KoalaNurse.cpp
*/

#include "KoalaNurse.hpp"

KoalaNurse::KoalaNurse(int nurse_id)
{
    id = nurse_id;
    work = false;
}

KoalaNurse::~KoalaNurse()
{
    std :: cout << "Nurse " << id << ": Finally some rest!" << std :: endl;
}

void KoalaNurse :: giveDrug(std :: string drug, SickKoala *Koala)
{
    if (Koala != NULL)
        Koala->takeDrug(drug);
}

std :: string KoalaNurse :: readReport(std :: string report)
{
    int pos = report.find(".report");
    std :: string koala_name = "";
    std :: string koala_drug = "";
    std :: ifstream file(report.c_str());

    if (pos < 0)
        return (koala_name);
    if (file) {
        if (getline(file, koala_drug)) {
            koala_name = report.replace(report.length() - 7, 7, "\0");
            std :: cout << "Nurse " << id << ": Kreog! Mr." << koala_name << " needs a " 
            << koala_drug << "!" << std :: endl;
        }
    }
    return (koala_name);
}

void KoalaNurse :: timeCheck(void)
{
    if (work == false) {
        std :: cout << "Nurse " << id << ": Time to get to work!" << std :: endl;
        work = true;    
    } else if (work == true) {
        std :: cout << "Nurse " << id << ": Time to go home to my eucalyptus forest!" << std :: endl;
        work = false;
    }
}