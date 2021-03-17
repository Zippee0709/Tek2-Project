/*
** EPITECH PROJECT, 2020
** cpp_d15_2019
** File description:
** main
*/

#include <iostream>
#include "ex01.hpp"

int main()
{
    const char *a = "chaineZ";
    const char *b = "chaineA42";

    const char c[8] = "chaineZ";
    const char d[10]  = "chaineA42";

    std::cout << compare(a, b) << std::endl;
    std::cout << compare(c, d) << std::endl;
    return 0;
}