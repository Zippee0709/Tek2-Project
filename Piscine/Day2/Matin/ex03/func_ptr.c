/*
** EPITECH PROJECT, 2020
** func_ptr
** File description:
** func_ptr
*/

#include "func_ptr.h"

void print_normal(const char *str)
{   
    printf("%s\n", str);
}

void print_reverse(const char *str)
{
    char *new = malloc(sizeof(char) * strlen(str) + 1);
    int i = 0;
    int j = strlen(str) - 1;

    for (; j >= 0; i++, j--) {
        new[i] = str[j];
    }
    printf("%s\n", new);
    free(new);
}

void print_upper(const char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z')
            printf("%c", str[i] - 32);
        else
            printf("%c", str[i]);
    }
    printf("\n");
}

void print_42(const char *str)
{
    (void)*str;
    printf("42\n");
}

void do_action(action_t action, const char *str)
{
    tpsf tab_func[4] = {print_normal, print_reverse, print_upper, print_42};

    (*tab_func[action])(str);
}