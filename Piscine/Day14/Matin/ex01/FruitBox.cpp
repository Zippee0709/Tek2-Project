/*
** EPITECH PROJECT, 2020
** cpp_d14m_2019
** File description:
** FruitBox
*/

#include "FruitBox.hpp"
#include "FruitNode.hpp"

FruitBox::FruitBox(int size)
{
    node = nullptr;
    length = 0;
    max_length = size;
}

FruitBox::~FruitBox()
{
    // delete node;
}

int FruitBox::nbFruits() const
{
    return length;
}

bool FruitBox::putFruit(Fruit *f)
{
    if (length < max_length) {
        FruitNode *copy = new FruitNode();
        copy->fruit = f;
        copy->next = nullptr;
        if (node == 0) {
            node = copy;
            length += 1;
            return true;
        }
        FruitNode *tmp = node;
        for (; tmp->next != nullptr; tmp = tmp->next) {
            if (tmp->fruit == f)
                return false;
        }
        tmp->next = copy;
        length += 1;
        return true;
    }
    return false;
}

Fruit* FruitBox::pickFruit()
{
    if (node == nullptr)
        return nullptr;
    // FruitNode *tmp_node = node;
    Fruit *tmp = node->fruit;
    node = node->next;
    // delete tmp_node;
    length -= 1;
    return tmp;
}

FruitNode* FruitBox::head() const
{
    if (node == nullptr)
        return nullptr;
    return node;
}

void FruitBox::displayBox() const
{
    FruitNode *tmp = node;
    while (tmp != nullptr) {
        std::cout << tmp->fruit->getName() << std::endl;
        tmp = tmp->next;
    }
}
