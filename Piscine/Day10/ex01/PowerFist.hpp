/*
** EPITECH PROJECT, 2020
** PowerFist.hpp
** File description:
** PowerFist.hpp
*/

#ifndef POWERFIST_HPP_
#define POWERFIST_HPP_

#include <iostream>
#include <string>
#include "AWeapon.hpp"

class PowerFist : public AWeapon
{
	public:
		PowerFist();
		~PowerFist();
        void attack();
	protected:
	private:
};

#endif /* !POWERFIST_HPP_ */
