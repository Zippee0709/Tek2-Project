/*
** EPITECH PROJECT, 2020
** cpp_d14m_2019
** File description:
** main
*/

#include <iostream>
#include <ostream>
#include "Lemon.hpp"
#include "Banana.hpp"
#include "FruitNode.hpp"
#include "FruitBox.hpp"

int  main() {
    Lemon l;
    Banana b;
    std::cout  << l.getVitamins () << std::endl;std::cout  << b.getVitamins () << std::endl;
    std::cout  << l.getName () << std::endl;
    std::cout  << b.getName () << std::endl;
    Fruit& f = l;
    std::cout  << f.getVitamins () << std::endl;
    std::cout  << f.getName () << std::endl;

    FruitBox box(5);

    Lemon le;
    Banana ba;
    Lemon a;
    Banana c;

    box.putFruit(&b);
    box.putFruit(&b);
    box.putFruit(&b);
    box.putFruit(&le);
    box.putFruit(&a);
    box.putFruit(&c);
    box.displayBox();
    return  0;
}