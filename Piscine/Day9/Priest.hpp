/*
** EPITECH PROJECT, 2020
** Priest.hpp
** File description:
** Priest.hpp
*/

#ifndef PRIEST_HPP_
#define PRIEST_HPP_

#include "Mage.hpp"

class Priest : virtual public Mage
{
	public:
		Priest(const std::string &name, int level);
		~Priest();
        int CloseAttack();
        void Heal();
	protected:
	private:
};

#endif /* !PRIEST_HPP_ */
