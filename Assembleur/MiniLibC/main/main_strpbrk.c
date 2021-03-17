/*
** EPITECH PROJECT, 2020
** ASM_minilibc_2019
** File description:
** main_memset
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *my_strpbrk(char *ptr, char *str);

int main(int ac, char **av)
{
    char str[13] = "Hello world!";

    printf("real str = %s\n", strpbrk("Hello world ! wo wx", "z!hgt"));
    printf("my str = %s\n", my_strpbrk("Hello world ! wo wx", "z!hgt"));
}
