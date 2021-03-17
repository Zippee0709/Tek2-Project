/*
** EPITECH PROJECT, 2020
** Character.hpp
** File description:
** Character.hpp
*/

#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

#include <iostream>
#include <string>

class Character 
{
	public:
		Character(const std::string &name, int level);
		~Character();
        //getter
        const std::string &getName() const;
        int getLvl() const;
        int getPv() const;
        int getPower() const;
        //enum
        enum AttackRange {
            CLOSE,
            RANGE
        } Range;
        // Technique
        int CloseAttack();
        int RangeAttack();
        void Heal();
        void RestorePower();
        void TakeDamage(int damage);

    protected:
        std::string _name;
        int _level;
        // _hp == pv
        int _hp;
        //  mp == power
        int _mp;
        //Not sure
        // std::string _class;
        // std::string _race;
        //attributs
        int _strength;
        int _stamina;
        int _intelligence;
        int _spirit;
        int _agility;
    private:
};

#endif /* !CHARACTER_HPP_ */
