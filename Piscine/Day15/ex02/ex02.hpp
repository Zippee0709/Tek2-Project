/*
** EPITECH PROJECT, 2020
** cpp_d15_2019
** File description:
** ex02
*/

#ifndef EX02_HPP_
#define EX02_HPP_

#include <iostream>
#include <string>

template<typename T>
T min(const T &a, const T &b)
{
    std::cout << "template min" << std::endl;

    if (a > b)
        return b;
    else if (a < b)
        return a;
    return a;
}

int min(const int a, const int b)
{
    std::cout << "non-template min" << std::endl;

    if (a > b)
        return b;
    else if (a < b)
        return a;
    return a;
}

template<typename T>
T templateMin(const T *tab, std::size_t size)
{
    std::size_t i = 0;
    T save;

    if (tab == nullptr)
        return -1;
    save = tab[0];
    for (i = 0; i < size && i + 1 < size; i++) {
        save = min<T>(tab[i], tab[i + 1]);
    }
    return save;
}

int nonTemplateMin(int *tab, std::size_t size)
{
    std::size_t i;
    int save;

    if (tab == nullptr)
        return -1;
    save = tab[0];
    for (i = 0; i < size && i + 1 < size; i++) {
        save = min(tab[i], tab[i + 1]);
    }
    return save;
}

#endif /* !EX02_HPP_ */
