/*
** EPITECH PROJECT, 2020
** Bord.hpp
** File description:
** Borg
*/

#ifndef BORG_HPP_
#define BORG_HPP_

namespace Borg {
    class Ship;
}

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include "WarpSystem.hpp"
#include "Destination.hpp"
#include "Federation.hpp"

namespace Borg {
    class Ship {
        public:
        Ship(int weaponFrequency = 0, short repair = 3);
        ~Ship();
		void setupCore(WarpSystem::Core *new_core);
		void checkCore(void);

		bool move(int warp, Destination d);
		bool move(int warp);
		bool move(Destination d);
		bool move();

        int getShield(void);
		void setShield(int shield);
		int getWeaponFrequency(void);
		void setWeaponFrequency(int shield);
		int getRepair(void);
		void setRepair(int shield);

        void fire(Federation::Starfleet::Ship *target);
        void fire(Federation::Ship * target);
        void repair();

        private:
        int _side;
        short _maxWarp;
        WarpSystem::Core * core;
        Destination _home;
        Destination _location;

		int _shield;
		int _weaponFrequency;
		short _repair;
    };    
}
#endif /* !BORG_HPP_ */