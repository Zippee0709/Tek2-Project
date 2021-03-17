/*
** EPITECH PROJECT, 2020
** Victim.hpp
** File description:
** Victim.hpp
*/

#ifndef VICTIM_HPP_
#define VICTIM_HPP_

#include <iostream>
#include <string>

class Victim {
	public:
		Victim(std::string const &name);
		~Victim();
        std::string getName() const;
        void getPolymorphed() const;
	protected:
        std::string _name;
	private:
};

std::ostream& operator<<(std::ostream &flux, Victim const &victim);

#endif /* !VICTIM_HPP_ */
