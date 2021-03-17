/*
** EPITECH PROJECT, 2020
** cpp_d14m_2019
** File description:
** FruitNode
*/

#ifndef FRUITNODE_HPP_
#define FRUITNODE_HPP_

#include "Fruit.hpp"

typedef struct FruitNode {
    Fruit *fruit;
    FruitNode *next;
}   FruitNode;

#endif /* !FRUITNODE_HPP_ */