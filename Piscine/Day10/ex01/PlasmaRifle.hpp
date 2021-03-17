/*
** EPITECH PROJECT, 2020
** PlasmaRifle.hpp
** File description:
** PlasmaRifle.hpp
*/

#ifndef PLASMARIFLE_HPP_
#define PLASMARIFLE_HPP_

#include <iostream>
#include <string>
#include "AWeapon.hpp"

class PlasmaRifle : public AWeapon
{
	public:
		PlasmaRifle();
		~PlasmaRifle();
        void attack();
	protected:
	private:
};

#endif /* !PLASMARIFLE_HPP_ */
