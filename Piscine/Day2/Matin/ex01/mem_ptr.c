/*
** EPITECH PROJECT, 2020
** mem_ptr.c
** File description:
** mem_ptr.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mem_ptr.h"

void add_str(const char *str1, const char *str2, char **res)
{
    *res = malloc(sizeof(char) * strlen(str1) + strlen(str2) + 1);

    if (*res == NULL)
        exit(84);
    strcat(*res, str1);
    strcat(*res, str2);
}

void add_str_struct(str_op_t *str_op)
{
    int size = strlen(str_op->str1) + strlen(str_op->str2) + 1;
    str_op->res = malloc(sizeof(char) + size);
    add_str(str_op->str1, str_op->str2, &str_op->res);
}