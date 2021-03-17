/*
** EPITECH PROJECT, 2020
** Mage.hpp
** File description:
** Mage.hpp
*/

#ifndef MAGE_HPP_
#define MAGE_HPP_

#include "Character.hpp"

class Mage : virtual public Character
{
	public:
		Mage(const std::string &name, int level);
		~Mage();
        int CloseAttack();
        int RangeAttack();
        void RestorePower();
	protected:
	private:
};

#endif /* !MAGE_HPP_ */
