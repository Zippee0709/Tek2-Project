/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main.c
*/

#include "menger.h"

int my_isnum(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9')
            return (-1);
    }
    return (0);
}

int my_pow(int nb, int pow)
{
    int res = 1;

    for (int i = 0; i < nb; i++)
        res = res * pow;
    return (res);
}

int my_check_pow(int size, int level)
{
    int rest = 0;

    if (size < my_pow(level, 3))
        return (-1);
    while (size != 1) {
        rest = size % 3;
        if (rest != 0)
            return (-1);
        size = size / 3;
    }
    return (0);
}

int main(int ac, char **av)
{
    int size = 0;
    int level = 0;

    if (ac != 3 || my_isnum(av[1]) == -1 || my_isnum(av[2]) == -1) {
        printf("Error: invalid av\n");
        return (84);
    }
    size = atoi(av[1]);
    level = atoi(av[2]);
    if (size % 3 != 0  || level == 0 || my_check_pow(size, level) != 0) {
        printf("Error: invalid number\n");
        return (84);
    }
    menger(size, level, 0, 0);
    return (0);
}