/*
** EPITECH PROJECT, 2020
** cpp_d14a_2019
** File description:
** main
*/

#include "Errors.hpp"

// int main()
// {
//     NasaError const error("ca marche ?");
//     std::cout << error.getComponent() << std::endl;

//     LifeCriticalError const abc("rarara", "coco");
//     std::cout << abc.getComponent() << std::endl;

//     LifeCriticalError const cba("babababa");
//     std::cout << cba.getComponent() << std::endl;
// }

int main()
{
    LifeCriticalError crit("Message", "Reactor");
    LifeCriticalError nasa("Message");

    std::cout << "Test life critical errror" << std::endl;
    std::cout << crit.what() << std::endl;
    std::cout << crit.getComponent() << std::endl;
    std::cout << nasa.what() << std::endl;
    std::cout << nasa.getComponent() << std::endl;
}