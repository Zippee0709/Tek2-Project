/*
** EPITECH PROJECT, 2020
** my_func.c
** File description:
** my_func.c
*/

#include "string.h"

char *my_malloc_string_by_pos(char *str, int pos)
{
    int j = 0;
    char *tmp = NULL;
    char *check = NULL;
    char *new_str = malloc(sizeof(char) * (strlen(str) - pos + 1));

    if (new_str == NULL)
        return (NULL);
    for (int i = pos; str[i] != '\0'; i++, j++)
        new_str[j] = str[i];
    new_str[j] = '\0';
    return (new_str);
}