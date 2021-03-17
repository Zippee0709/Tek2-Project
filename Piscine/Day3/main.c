/*
** EPITECH PROJECT, 2020
** ex04
** File description:
** main
*/

#include "string.h"

int main(void)
{   
    string_t s;
    string_t test;

    printf("-----init-----\n");
    string_init(&s, "tout le monde");
    string_init(&test, "Bonjour Tout le monde");
    printf("%s\n", s.str);
    printf("%s\n", test.str);

    printf("-----assign_s-----\n");
    test.assign_s(&test, &s);
    printf("%s\n", test.str);

    printf("-----assign_c-----\n");
    test.assign_c(&test, "Ca va");
    printf("%s\n", test.str);

    printf("-----append_s-----\n");
    test.append_s(&test, &s);
    printf("%s\n", test.str);

    printf("-----append_c-----\n");
    test.append_c(&test, "haha");
    printf("%s\n", test.str);

    string_destroy(&s);
    string_destroy(&test);
    return (0);
}