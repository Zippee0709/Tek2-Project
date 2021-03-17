/*
** EPITECH PROJECT, 2020
** AEnemy.hpp
** File description:
** AEnemy.hpp
*/

#ifndef AENEMY_HPP_
#define AENEMY_HPP_

#include <iostream>
#include <string>

class AEnemy {
	public:
		AEnemy(int hp, const std::string &type);
    	virtual	~AEnemy();
        virtual void takeDamage(int damage);
        std::string const getType() const;
        int getHP() const;
	protected:
        int _hp;
        std::string _type;
	private:
};

#endif /* !AENEMY_HPP_ */
