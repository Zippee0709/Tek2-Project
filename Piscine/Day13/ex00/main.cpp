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
    Toy toto ;
    Toy ET ( Toy::ALIEN , "green", "/alienraze.txt") ;
    toto . setName ("TOTO !") ;
    if ( toto . getType () == Toy::BASIC_TOY)
    std :: cout << "basic toy: " << toto . getName () << std :: endl
    << toto . getAscii () << std :: endl ;
    if ( ET . getType () == Toy :: ALIEN )
    std :: cout << "this alien is: " << ET . getName () << std :: endl
    << ET . getAscii () << std :: endl ;
    return 0;
}