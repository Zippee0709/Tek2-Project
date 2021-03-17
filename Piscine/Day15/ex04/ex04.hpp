/*
** EPITECH PROJECT, 2020
** cpp_d15_2019
** File description:
** ex04
*/

#ifndef EX04_HPP_
#define EX04_HPP_

#include <iostream>
#include <string>

template<typename T>
bool equal(const T &a, const T &b)
{
    if (a == b)
        return true;
    return false;
}

template<typename T>
class Tester
{
    Tester(T x);
    ~Tester();
};


#endif /* !EX04_HPP_ */