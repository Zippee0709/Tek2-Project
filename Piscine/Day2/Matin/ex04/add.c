/*
** EPITECH PROJECT, 2020
** add.c
** File description:
** add.c
*/

#include "castmania.h"

int normal_add(int a, int b)
{
    int res = a + b;
    return (res);
}

int absolute_add(int a, int b)
{
    int res = abs(a) + abs(b);
    return (res);
}

void exec_add(addition_t *operation)
{
    if (operation->add_type == NORMAL)
        operation->add_op.res = normal_add(operation->add_op.a, operation->add_op.b);
    else if (operation->add_type == ABSOLUTE)
        operation->add_op.res = normal_add(operation->add_op.a, operation->add_op.b);
}