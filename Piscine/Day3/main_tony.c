/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include  <stdio.h>
#include "string.h"

int  main(void)
{
    string_t s1;
    const char *assignC = "Salut";
    const char *appendC = "La Suite lol";
    size_t char_n = 3;
    string_t s2;
    char *copy = malloc(128);

    string_init(&s1, "Hello  World");
    string_init(&s2, "Yo");
    printf("Init s1 : %s\n", s1.str);
    printf("Init s2 : %s\n", s2.str);

    s1.assign_c(&s1, assignC);
    printf("Assign s1 with c : %s\n", s1.str);
    s1.assign_s(&s1, &s2);
    printf("Assign s1 with s2 : %s\n", s1.str);

    s1.append_s(&s1, &s2);
    printf("Append s1 with s2 : %s\n", s1.str);
    s1.append_c(&s1, appendC);
    printf("Append s1 with c : %s\n", s1.str);

    printf("s1 at %ld : %c\n", char_n, s1.at(&s1, char_n));

    printf("Size of s1 before clear : %d\n", s1.size(&s1));
    s1.clear(&s1);
    printf("Clear s1 : %s\n", s1.str);
    printf("Size of s1 after clear : %d\n", s1.size(&s1));

    s1.assign_c(&s1, assignC);
    printf("Assign s1 with c : %s\n", s1.str);
    printf("s2 : %s\n", s2.str);
    printf("Compare s1 with c : %d\n", s1.compare_c(&s1, assignC));
    printf("Compare s1 with s2 : %d\n", s1.compare_s(&s1, &s2));

    int res = s1.copy(&s1, copy, 2, 4);
    printf("Copy s1 to $copy : %d\n", res);
    // printf("Copy s1 to $copy : %s\n", copy);

    string_destroy(&s1);
    string_destroy(&s2);
    return (0);
}
