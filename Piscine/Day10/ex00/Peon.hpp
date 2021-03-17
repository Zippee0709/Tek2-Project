/*
** EPITECH PROJECT, 2020
** Peon.hpp
** File description:
** Peon.hpp
*/

#ifndef PEON_HPP_
#define PEON_HPP_

#include <iostream>
#include <string>
#include "Victim.hpp"

class Peon : public Victim
{
	public:
		Peon(std::string const &name);
		~Peon();
        void getPolymorphed() const;
	protected:
	private:
};

#endif /* !PEON_HPP_ */
