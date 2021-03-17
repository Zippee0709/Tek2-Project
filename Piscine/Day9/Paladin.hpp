/*
** EPITECH PROJECT, 2020
** Paladin.hpp
** File description:
** Paladin.hpp
*/

#ifndef PALADIN_HPP_
#define PALADIN_HPP_

#include "Warrior.hpp"
#include "Priest.hpp"

class Paladin : virtual public Warrior, virtual public Priest
{
	public:
		Paladin(const std::string &name, int level);
		~Paladin();
        int CloseAttack();
        int RangeAttack();
        void Heal();
        void RestorePower();
        int Intercept();
	protected:
	private:
};

#endif /* !PALADIN_HPP_ */
