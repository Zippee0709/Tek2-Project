/*
** EPITECH PROJECT, 2019
** Toy.hpp
** File description:
** Toy include
*/

#ifndef TOY
#define TOY
#include "Object.hpp"

class Toy : public virtual Object {
	public:
		Toy();
		Toy(std::string const &title, TYPE type);
		void isTaken() const;
		~Toy();
	protected:
	private:
};

#endif