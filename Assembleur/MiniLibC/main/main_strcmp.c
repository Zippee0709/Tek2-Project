/*
** EPITECH PROJECT, 2020
** ASM_minilibc_2019
** File description:
** main_memset
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int my_strcmp(char *ptr, char *str);

int main(int ac, char **av)
{
    char str[13] = "Hello world!";

    printf("real str inf = %d\n", strcmp("Hell", "Hello"));
    printf("real str sup = %d\n", strcmp("Helloo", "Hello"));
    printf("real str equal = %d\n", strcmp("Hello", "Hello"));

    printf("my str inf = %d\n", my_strcmp("Hell", "Hello"));
    printf("my str sup = %d\n", my_strcmp("Helloo", "Hello"));
    printf("my str equal = %d\n", my_strcmp("Hello", "Hello"));
}
