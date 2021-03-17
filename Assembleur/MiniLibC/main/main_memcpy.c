/*
** EPITECH PROJECT, 2020
** ASM_minilibc_2019
** File description:
** main_memset
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void my_memcpy(char *ptr, char *str, size_t size);

int main(int ac, char **av)
{
    char str[13] = "Hello world!";
    str[12] = '\0';
    char *ptr = malloc(sizeof(char) * 13);
    memcpy(ptr, str, 5);
    printf("the real memset print str = %s\n", str);
    printf("the real memset print ptr = %s\n", ptr);
    my_memcpy(ptr, str, 124);
    printf("my memset print 10c str = %s\n", str);
    printf("my memset print 10c ptr = %s\n", ptr);
    if (ptr != NULL)
        free(ptr);
}
