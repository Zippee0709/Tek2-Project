/*
** EPITECH PROJECT, 2020
** cpp_d10_2019
** File description:
** Character
*/

#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

#include <iostream>
#include <string>
#include "AWeapon.hpp"
#include "AEnemy.hpp"

class Character 
{
        public:
                Character(const std::string &name);
                ~Character();
                void recoverAP();
                void equip(AWeapon *weapon);
                void attack(AEnemy *enemy);
                std::string const getName() const;
                int getAp() const;
                AWeapon* getWeapon() const;
        protected:
        private:
                std::string _name;
                int _ap;
                AWeapon *_weapon;
};

#endif /* !CHARACTER_HPP_ */