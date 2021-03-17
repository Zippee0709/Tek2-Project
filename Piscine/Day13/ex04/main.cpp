/*
** EPITECH PROJECT, 2020
** cpp_d13_2019
** File description:
** main
*/

# include <iostream>
# include <string>
# include <memory>
# include "Toy.hpp"
# include "Buzz.hpp"
# include "Woody.hpp"

int main ()
{
    Toy a ( Toy :: BASIC_TOY , "REX", "../rex.txt") ;
    std :: cout << a ;
    a << "test1" << "test2";
    std :: cout << a;
    return 0;
}