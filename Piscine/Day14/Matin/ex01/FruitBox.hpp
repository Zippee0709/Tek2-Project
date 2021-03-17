/*
** EPITECH PROJECT, 2020
** cpp_d14m_2019
** File description:
** FruitBox
*/

#ifndef FRUITBOX_HPP_
#define FRUITBOX_HPP_

#include "FruitNode.hpp"
#include "Fruit.hpp"

class FruitBox {
	public:
		FruitBox(int size);
		~FruitBox();
        int nbFruits() const;
        bool putFruit(Fruit *f);
		Fruit *pickFruit();
		FruitNode *head() const;
        void displayBox() const;
	protected:
	private:
        FruitNode *node;
        int length;
        int max_length;
};

#endif /* !FRUITBOX_HPP_ */