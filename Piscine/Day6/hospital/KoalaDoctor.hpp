/*
** EPITECH PROJECT, 2020
** KoalaDoctor
** File description:
** KoalaDoctor
*/

#ifndef KOALADOCTOR_HPP_
#define KOALADOCTOR_HPP_

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include "SickKoala.hpp"
#include "KoalaNurse.hpp"

class KoalaDoctor {
	public:
    KoalaDoctor(std :: string doctor_name);
	~KoalaDoctor();
    void diagnose(SickKoala *koala);
    void timeCheck(void);
	private:
    std :: string name;
    bool work;
};

#endif /* !KOALADOCTOR_HPP_ */
