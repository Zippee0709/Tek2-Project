/*
** EPITECH PROJECT, 2020
** div.c
** File description:
** div.c
*/

#include "castmania.h"

int integer_div(int a, int b)
{
    int res = 0;

    if (b == 0)
        return 0;
    res = a / b;
    return (res);
}

float decimale_div(int a, int b)
{
    float res = 0;
    float tmp_a = (float)a;
    float tmp_b = (float)b;

    if (b == 0)
        return (0);
    res = tmp_a / tmp_b;
    return (res);
}

void exec_div(division_t *operation)
{
    if (operation->div_type == INTEGER)
        ((integer_op_t *)operation->div_op)->res = integer_div(((integer_op_t*)operation->div_op)->a, ((integer_op_t*)operation->div_op)->b);
    else if (operation->div_type == DECIMALE)
        ((decimale_op_t *)operation->div_op)->res = decimale_div(((decimale_op_t*)operation->div_op)->a, ((decimale_op_t*)operation->div_op)->b);
}