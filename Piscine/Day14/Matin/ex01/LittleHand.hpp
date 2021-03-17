/*
** EPITECH PROJECT, 2020
** cpp_d14m_2019
** File description:
** LittleHand
*/

#ifndef LITTLEHAND_HPP_
#define LITTLEHAND_HPP_

#include "FruitBox.hpp"

class LittleHand {
	public:
		LittleHand();
		~LittleHand();
        static void sortFruitBox(FruitBox &unsorted, FruitBox &lemons, FruitBox &bananas, FruitBox &limes);
	protected:
	private:
};

#endif /* !LITTLEHAND_HPP_ */