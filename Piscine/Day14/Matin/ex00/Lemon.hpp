/*
** EPITECH PROJECT, 2020
** cpp_d14m_2019
** File description:
** Lemon
*/

#ifndef LEMON_HPP_
#define LEMON_HPP_

#include "Fruit.hpp"

class Lemon : public Fruit
{
	public:
		Lemon(const std::string &name = "lemon", int vitamins = 3);
		virtual ~Lemon();
	protected:
	private:
};

#endif /* !LEMON_HPP_ */
