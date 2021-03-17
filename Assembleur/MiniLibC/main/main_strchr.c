/*
** EPITECH PROJECT, 2020
** ASM_minilibc_2019
** File description:
** main
*/

#include <stdio.h>
#include <string.h>

char* my_strchr(char *str, char c);

int main(int ac, char **av)
{
    char *str = "Hello world!";

    printf("the real char is = %s\n", strchr(str, '!'));
    printf("my char is = %s\n", my_strchr(str, 'w'));
}