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
#include "LittleHand.hpp"
#include "Lime.hpp"

int  main() {
    // Lemon l;
    // std::cout  << l.getVitamins () << std::endl;std::cout  << b.getVitamins () << std::endl;
    // std::cout  << l.getName () << std::endl;
    // std::cout  << b.getName () << std::endl;
    // Fruit& f = l;
    // std::cout  << f.getVitamins () << std::endl;
    // std::cout  << f.getName () << std::endl;

    FruitBox box(50);
    FruitBox bananaBox(1);
    FruitBox lemonBox(1);
    FruitBox limeBox(1);
    Lemon le;
    Banana b;
    Lemon a;
    Banana c;
    Lime li;
    LittleHand tri;
    box.putFruit(&b);
    box.putFruit(&b);
    box.putFruit(&b);
    box.putFruit(&li);
    box.putFruit(&le);
    box.putFruit(&li);
    box.putFruit(&li);
    box.putFruit(&a);
    box.putFruit(&c);
    box.putFruit(&li);
    box.displayBox();
    std::cout << "------------------TRI------------------" << std::endl;
    LittleHand::sortFruitBox(box, lemonBox, bananaBox, limeBox);
    std::cout << "------------------FIN-TRI------------------" << std::endl;
    std::cout << "Box display" << std::endl;
    box.displayBox();
    std::cout << "bananaBox display" << std::endl;
    bananaBox.displayBox();
    std::cout << "lemon display" << std::endl;
    lemonBox.displayBox();
    std::cout << "lime display" << std::endl;
    limeBox.displayBox();
    return  0;
}