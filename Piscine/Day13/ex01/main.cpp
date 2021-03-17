/*
** EPITECH PROJECT, 2020
** cpp_d13_2019
** File description:
** main
*/

#include "Picture.hpp"
#include "Toy.hpp"

int main()
{
    Picture a("../alien.txt");
    Picture b("../rex.txt");
    Picture c("../alien.txt");

    c = a = b;
    std::cout << a.getData();
    std::cout << b.getData();
}