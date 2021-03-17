/*
** EPITECH PROJECT, 2020
** Federation
** File description:
** Federation
*/

#ifndef FEDERATION_HPP_
#define FEDERATION_HPP_

namespace Federation {
	namespace Starfleet {
		class Ensign;
		class Captain;
		class Ship;
	}
	class Ship;
}

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include "WarpSystem.hpp"
#include "Destination.hpp"
#include "Borg.hpp"

namespace Federation 
{
	namespace Starfleet {
		class Ensign {
			public:
			Ensign(std :: string new_name);
			~Ensign();
			private:
			std :: string _name;
		};
		class Captain {
			public:
			Captain(std :: string captain_name);
			~Captain();
			std::string getName();
			int getAge();
			void setAge(int age);
			private:
			std :: string _name;
			int _age;
		};
		class Ship {
			public:
			Ship(int length, int width, std::string name, short maxWarp, int torpedo = 0);
			Ship();
			~Ship();
			void setupCore(WarpSystem :: Core *new_core);
			void checkCore(void);
			void promote(Captain *new_captain);

			bool move(int warp, Destination d);
			bool move(int warp);
			bool move(Destination d);
			bool move();

			int getShield(void);
			void setShield(int shield);
			int getTorpedo(void);
			void setTorpedo(int torpedo);

			void fire(Borg::Ship *target);
			void fire(int torpedoes, Borg::Ship *target);

			private:
			int _length;
			int _width;
			std :: string _name;
			short _maxWarp;
			WarpSystem :: Core *core;
			Captain *_captain;
			Destination _location;
			Destination _home;
			int _shield;
			int _photonTorpedo;
		};
	}
	class Ship {
		public:
		Ship(int length, int width, std::string name);
		~Ship();
		void setupCore(WarpSystem :: Core *new_core);
		void checkCore(void);

		bool move(int warp, Destination d);
		bool move(int warp);
		bool move(Destination d);
		bool move();

		WarpSystem::Core* getCore();

		private:
		int _length;
		int _width;
		std :: string _name;
		WarpSystem :: Core *core;
		Destination _location;
		Destination _home;
	};
}

#endif /* !FEDERATION_HPP_ */
