/*
** EPITECH PROJECT, 2020
** cpp_d13_2019
** File description:
** main
*/

#include <iostream>
#include <string>
#include <memory>
#include "Toy.hpp"
#include "Buzz.hpp"
#include "Woody.hpp"

int main ()
{
    std::unique_ptr<Toy> b(new Buzz ("buzziiiii"));
    std::unique_ptr<Toy> w(new Woody ("wood"));
    std::unique_ptr<Toy> t(new Toy (Toy::ALIEN, "ET", "../alien.txt"));
    b->speak ("To the code, and beyond !!!!!!!!");
    w->speak ("There's a snake in my boot.");
    t->speak ("the claaaaaaw");
    return 0;
}