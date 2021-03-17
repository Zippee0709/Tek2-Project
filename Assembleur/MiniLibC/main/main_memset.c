/*
** EPITECH PROJECT, 2020
** ASM_minilibc_2019
** File description:
** main_memset
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void my_memset(char *str, int c, size_t size);

int main(int ac, char **av)
{
    char str[13] = "Hello world!";
    str[12] = '\0';
    memset(str, '.', 0);
    printf("the real memset print . is = %s\n", str);
    my_memset(str, 'h', 0);
    printf("my memset print h is = %s\n", str);
}