/*
** EPITECH PROJECT, 2020
** cpp_d14m_2019
** File description:
** Lime
*/

#ifndef LIME_HPP_
#define LIME_HPP_

#include "Lemon.hpp"
#include "Fruit.hpp"

class Lime : virtual public Lemon
{
	public:
		Lime(const std::string &name = "lime", int vitamins = 2);
		~Lime();
	protected:
	private:
};

#endif /* !LIME_HPP_ */
