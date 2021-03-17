/*
** EPITECH PROJECT, 2020
** ASM_minilibc_2019
** File description:
** main_memset
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *my_rindex(char *ptr, char c);

int main(int ac, char **av)
{
    char str[13] = "Hello world!";

    printf("real str = %s\n", rindex(str, '!'));
    printf("real str = %s\n", rindex(str, 'Z'));

    printf("my str = %s\n", my_rindex(str, '!'));
    printf("my str = %s\n", my_rindex(str, 'Z'));
}
