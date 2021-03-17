/*
** EPITECH PROJECT, 2020
** cpp_d14m_2019
** File description:
** Lemon
*/

#ifndef LEMON_HPP_
#define LEMON_HPP_

#include "Fruit.hpp"

class Lemon : virtual public Fruit
{
	public:
		Lemon();
		Lemon(const std::string &name, int vitamins);
		virtual ~Lemon();
	protected:
	private:
};

#endif /* !LEMON_HPP_ */
