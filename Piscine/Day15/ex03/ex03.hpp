/*
** EPITECH PROJECT, 2020
** cpp_d15_2019
** File description:
** ex03
*/

#ifndef EX03_HPP_
#define EX03_HPP_

#include <iostream>
#include <string>

template<typename T>
void print(const T &str)
{
    std::cout << str << std::endl;
}

template<typename T>
void foreach(const T *tab, void(*func)(const T &a), std::size_t size)
{
    std::size_t i = 0;

    for (; i < size; i++)
        func(tab[i]);
}


#endif /* !EX03_HPP_ */