/*
** EPITECH PROJECT, 2020
** Hunter.hpp
** File description:
** Hunter
*/

#ifndef HUNTER_HPP_
#define HUNTER_HPP_

#include "Warrior.hpp"

class Hunter : virtual public Warrior
{
	public:
		Hunter(const std::string &name, int level, std::string weapon = "hammer");
		~Hunter();
        int CloseAttack();
        int RangeAttack();
        void Heal();
        void RestorePower();
	protected:
	private:
};

#endif /* !HUNTER_HPP_ */
