/*
** EPITECH PROJECT, 2020
** menger.c
** File description:
** menger.c
*/

#include "menger.h"

int menger_box(int size, int level, int x, int y) 
{
    int half = 9 / 2;

    for (int i = 0; i < 9; i = i + 1) {
        if (i != half)
            menger(size, level, x + i / 3 * size, y + (i * size) % (size * 3));
    }
    return (0);
}

int menger(int size, int level, int x, int y) 
{
    if (size > 1 && level > 0) {
        size = size / 3;
        printf("%03d %03d %03d\n", size, x + size, y + size);
        level = level - 1;
        menger_box(size, level, x, y);
    }
    return (0);
}