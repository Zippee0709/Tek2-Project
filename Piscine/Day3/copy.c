/*
** EPITECH PROJECT, 2020
** copy.c
** File description:
** copy.c
*/

#include "string.h"

size_t copy(const string_t *this, char *s, size_t n, size_t pos)
{
    int i = 0;

    if (this->str == NULL || pos >= strlen(this->str) || n >= strlen(this->str))
        return (-1);
    s = malloc(sizeof(char) * (n + 1));
    if (s == NULL)
        return (-1);
    for (i = 0; this->str[pos] != '\0' && n > 0; pos++, n--, i++)
        s[i] = this->str[pos];
    s[i] = '\0';
    // free(s);
    return ((size_t)i + 1);
}

const char *c_str(const string_t *this)
{
    if (this == NULL || this->str == NULL)
        return (NULL);
    return (this->str);
}

int empty(const string_t *this)
{
    if (this->str == NULL || strlen(this->str) == 0)
        return (1);
    return (0);
}

int find_s(const string_t *this, const string_t *str, size_t pos)
{
    if (this == NULL || str == NULL || this->str == NULL || str->str == NULL)
        return (-1);
}

int find_c(const string_t *this, const char *str, size_t pos)
{
    char *check = NULL;
    char *new_str = NULL;
    int res = 0;

    if (this == NULL || this->str == NULL || str == NULL)
        return (-1);
    if (pos >= strlen(this->str))
        return (-1);
    new_str = my_malloc_string_by_pos(this->str, (int)pos);
    check = strstr(new_str, str);
    if (check == NULL)
        return (-1);
    printf("%s\n", check);
    return (0);
}