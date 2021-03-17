/*
** EPITECH PROJECT, 2020
** KoalaNurse
** File description:
** KoalaNurse
*/

#ifndef KOALANURSE_HPP_
#define KOALANURSE_HPP_

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include "SickKoala.hpp"

class KoalaNurse {
	public:

    KoalaNurse(int id);
	~KoalaNurse();

    void giveDrug(std::string, SickKoala *koala);
    std  :: string readReport(std::string);
    void timeCheck(void);
	private:
    int id;
    bool work;
};

#endif /* !KOALANURSE_HPP_ */