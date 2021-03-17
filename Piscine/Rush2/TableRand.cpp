/*
** EPITECH PROJECT, 2019
** cpp_rush2_2019
** File description:
** TableRand
*/

#include "TableRand.hpp"
#include "PapaXmasTable.hpp"
#include "LittlePony.hpp"
#include "Teddy.hpp"

TableRand::TableRand()
{
}

TableRand::~TableRand()
{
}

Object *rand_toy(int rand_nbr)
{
    std::cout << "rand_nbr = " << rand_nbr << std::endl;
    if (rand_nbr == 1)
        return (new LittlePony("MyPony"));
    else
        return (new Teddy("Ted"));
}

PapaXmaxTable *TableRand::randTable()
{
    PapaXmaxTable *tab = new PapaXmaxTable;
    std::srand(std::time(nullptr));
    for (int i = 0; i != 5; i++) {
        int rand_nbr = 1 + std::rand()/((RAND_MAX + 1u)/2);
        Object *obj = rand_toy(rand_nbr);
        std::cout << "obj = " << obj->getTitle() << std::endl;
        tab->put(*obj);
    }
    return (tab);
}