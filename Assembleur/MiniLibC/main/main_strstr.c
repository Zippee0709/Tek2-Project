/*
** EPITECH PROJECT, 2020
** ASM_minilibc_2019
** File description:
** main_memset
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *my_strstr(char *ptr, char *str);

int main(int ac, char **av)
{
    char str[13] = "Hello world!";

    printf("real str = %s\n", strstr("Hello world!", "world"));
    printf("real str = %s\n", my_strstr("Hello world!", "wz"));

    printf("real str = %s\n", strchr("Hello world!", 'w'));
    printf("the real char is = %s\n", strchr(str, 'w'));
    printf("the real char is = %s\n", rindex(str, 'w'));

}
