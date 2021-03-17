/*
** EPITECH PROJECT, 2020
** cpp_d17_2019
** File description:
** find
*/

#ifndef FIND_HPP_
#define FIND_HPP_

#include <iostream>
#include <algorithm>
#include <array>
#include <string>

template<typename T>
typename T::iterator do_find(const T &data, int nb)
{
    return (std::find(data.begin(), data.end(), nb));
}

#endif /* !FIND_HPP_ */