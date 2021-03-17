/*
** EPITECH PROJECT, 2020
** cpp_d14m_2019
** File description:
** LittleHand
*/

#include "LittleHand.hpp"

LittleHand::LittleHand()
{
}

LittleHand::~LittleHand()
{
}

void LittleHand::sortFruitBox(FruitBox &unsorted, FruitBox &lemons, FruitBox &bananas, FruitBox &limes)
{
    if (unsorted.nbFruits() == 0)
        return;
    FruitBox tmp(unsorted.nbFruits());
    Fruit *fruit = unsorted.pickFruit();
    for (; fruit != nullptr; fruit = unsorted.pickFruit()) {
        if (fruit->getName().compare("lemon") == 0) {
            if (lemons.putFruit(fruit) == false)
                tmp.putFruit(fruit);
        }
        else if (fruit->getName().compare("banana") == 0) {
            if (bananas.putFruit(fruit) == false)
                tmp.putFruit(fruit);
        }
        else if (fruit->getName().compare("lime") == 0) {
            if (limes.putFruit(fruit) == false)
                tmp.putFruit(fruit);
        } else
            tmp.putFruit(fruit);
    }
    fruit = tmp.pickFruit();
    for (; fruit != nullptr; fruit = tmp.pickFruit())
        unsorted.putFruit(fruit);
}