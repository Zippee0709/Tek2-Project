/*
** EPITECH PROJECT, 2020
** add_mul
** File description:
** add_mul
*/

void add_mul_4param(int first, int second, int *sum, int *product)
{
    *sum = first + second;
    *product = first * second;
}

void add_mul_2param(int *first, int *second)
{
    int tmp1 = *first;
    int tmp2 = *second;

    *first = tmp1 + tmp2;
    *second = tmp1 * tmp2;
}