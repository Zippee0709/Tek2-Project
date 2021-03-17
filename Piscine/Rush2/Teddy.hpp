/*
** EPITECH PROJECT, 2019
** Teddy.hpp
** File description:
** Teddy include
*/

#ifndef TEDDY
#define TEDDY
#include "Toy.hpp"

class Teddy : public virtual Toy {
	public:
		Teddy();
		Teddy(const std::string &title);
		void isTaken() const ;
		~Teddy();
	protected:
	private:
};
#endif
