/*
** EPITECH PROJECT, 2020
** Sorcerer.hpp
** File description:
** Sorcerer.hpp
*/

#ifndef SORCERER_HPP_
#define SORCERER_HPP_

#include <iostream>
#include <string>
#include "Victim.hpp"
#include "Peon.hpp"

class Sorcerer {
	public:
		Sorcerer(std::string const &name, std::string const &title);
		~Sorcerer();
        std::string getName() const;
        std::string getTitle() const;
        void polymorph(const Victim &victim);
        void polymorph(const Peon &Peon);
	protected:
	private:
        std::string _name;
        std::string _title;
};

std::ostream& operator<<(std::ostream &flux, Sorcerer const &sorcerer);

#endif /* !SORCERER_HPP_ */
