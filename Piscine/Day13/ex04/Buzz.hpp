/*
** EPITECH PROJECT, 2020
** cpp_d13_2019
** File description:
** Buzz
*/

#ifndef BUZZ_HPP_
#define BUZZ_HPP_

#include "Toy.hpp"

class Buzz : public Toy
{
	public:
		Buzz(const std::string &name, const std::string &file = "Buzz.txt");
		~Buzz();
	protected:
	private:
};

#endif /* !BUZZ_HPP_ */
