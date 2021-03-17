/*
** EPITECH PROJECT, 2020
** cpp_d14m_2019
** File description:
** Fruit
*/

/*
** EPITECH PROJECT, 2020
** cpp_d14m_2019
** File description:
** Fruit
*/

#ifndef FRUIT_HPP_
#define FRUIT_HPP_

class Fruit;

#include <iostream>
#include <string>
#include "FruitNode.hpp"

class Fruit {
	public:
		Fruit(const std::string &name, int vitamins);
		virtual ~Fruit();
        int getVitamins() const;
        std::string getName() const;
	protected:
        std::string _name;
        int _vitamins;
	private:
};

#endif /* !FRUIT_HPP_ */
