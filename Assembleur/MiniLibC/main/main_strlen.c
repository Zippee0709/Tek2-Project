/*
** EPITECH PROJECT, 2020
** ASM_minilibc_2019
** File description:
** main
*/

#include <stdio.h>
#include <string.h>

int my_strlen(char *str);

int main(int ac, char **av)
{
    char *str = "Hello world!";

    printf("the real size is = %d\n", (int)strlen(str));
    printf("my size is = %d\n", (int)my_strlen(str));
}