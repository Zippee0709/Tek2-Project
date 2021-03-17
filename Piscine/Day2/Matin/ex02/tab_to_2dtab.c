/*
** EPITECH PROJECT, 2020
** tab_to_2dtab
** File description:
** tab_to2dtab
*/

#include <stdio.h>
#include <stdlib.h>

void tab_to_2dtab(const int *tab, int length, int width, int ***res)
{
    int i = 0;
    int j = 0;
    int idx = 0;
    *res = malloc(sizeof(int *) * length + 1);

    if (res == NULL)
        exit(84);
    for(; i != length; i++)
        (*res)[i] = malloc(sizeof(int) * width + 1);
    for (i = 0; i < length; i++) {
        for (j = 0; j < width; j++) {
            (*res)[i][j] = tab[idx];
            idx++;
        }
    }
}