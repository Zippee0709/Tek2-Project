/*
** EPITECH PROJECT, 2020
** cpp_d15_2019
** File description:
** ex01
*/

#ifndef EX01_HPP_
#define EX01_HPP_

template<typename T>
int compare(const T &a, const T &b)
{
    if (a > b)
        return 1;
    else if (a < b)
        return -1;
    return 0;
}

template<typename T, typename U>
int compare(const T &a, const U &b)
{
    if (a > b)
        return 1;
    else if (a < b)
        return -1;
    return 0;
}

#endif /* !EX01_HPP_ */

