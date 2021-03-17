/*
** EPITECH PROJECT, 2019
** LittlePony.hpp
** File description:
** LittlePony include
*/

#ifndef LITTLEPONY
#define LITTLEPONY
#include "Toy.hpp"

class LittlePony : public virtual Toy{
	public:
		LittlePony();
		LittlePony(std::string const &title);
		void isTaken() const;
		~LittlePony();
	protected:
	private:
};
#endif
