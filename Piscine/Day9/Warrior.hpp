/*
** EPITECH PROJECT, 2020
** Warriror.hpp
** File description:
** Warrior.hpp
*/

#ifndef WARRIOR_HPP_
#define WARRIOR_HPP_

#include "Character.hpp"

class Warrior : virtual public Character
{
	public:
		Warrior(const std::string &string, int level, std::string weapon = "hammer");
		~Warrior();
        int CloseAttack();
        int RangeAttack();
    protected:
        std::string _weaponName;
	private:
};
#endif /* !WARRIOR_HPP_ */
