/*
** EPITECH PROJECT, 2020
** SickKoala
** File description:
** SickKoala
*/

#ifndef SICKKOALA_HPP_
#define SICKKOALA_HPP_

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

class SickKoala {
    public :
    SickKoala(std::string);
    ~SickKoala(void);
    void poke(void);
    bool takeDrug(std::string);
    void overDrive(std::string);
    std :: string getName();
    private:
    std :: string name;
};

#endif /* !SICKKOALA_HPP_ */
