/*
** EPITECH PROJECT, 2020
** AWeapon
** File description:
** AWeapon
*/

#ifndef AWEAPON_HPP_
#define AWEAPON_HPP_

#include <iostream>
#include <string>

class AWeapon {
	public:
		AWeapon(const std::string &name, int apcost, int damage);
		virtual ~AWeapon();
        std::string const getName() const;
        int getAPCost() const;
        int getDamage() const;
        virtual void attack() const = 0;
	protected:
        std::string _name;
        int _apcost;
        int _damage;
    private:
};

#endif /* !AWEAPON_HPP_ */
