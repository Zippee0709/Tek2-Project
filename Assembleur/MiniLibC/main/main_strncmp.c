/*
** EPITECH PROJECT, 2020
** ASM_minilibc_2019
** File description:
** main_memset
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int my_strncmp(char *ptr, char *str, size_t size);

int main(int ac, char **av)
{
    char str[13] = "Hello world!";

    printf("real str inf = %d\n", strncmp("Hell", "Hello", 5));
    printf("real str sup = %d\n", strncmp("Helloo", "Hello", 5));
    printf("real str equal = %d\n", strncmp("Hello", "Hello", 5));
    printf("real str inf = %d\n", strncmp("Hell", "Hello", 5));
    printf("real str sup = %d\n", strncmp("Helloo", "Hello", 6));
    printf("real str equal = %d\n", strncmp("Hello", "Hello", 4));

    printf("my str inf = %d\n", my_strncmp("Hell", "Hello", 5));
    printf("my str sup = %d\n", my_strncmp("Helloo", "Hello", 5));
    printf("my str equal = %d\n", my_strncmp("Hello", "Hello", 5));
    printf("my str inf = %d\n", my_strncmp("Hell", "Hello", 5));
    printf("my str sup = %d\n", my_strncmp("Helloo", "Hello", 6));
    printf("my str equal = %d\n", my_strncmp("Hello", "Hello", 4));
}
