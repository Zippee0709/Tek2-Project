/*
** EPITECH PROJECT, 2020
** utilities
** File description:
** utilities
*/

#include "string.h"

char at(const string_t *this, size_t pos)
{
    int i = (int)pos;
    char res = 0;

    if (this == NULL || this->str == NULL)
        return (-1);
    if (i >= strlen(this->str))
        return (-1);
    res = this->str[i];
    return (res);
}

void clear(string_t *this)
{
    int i = 0;

    if (this == NULL || this->str == NULL)
        return;
    for (i = 0; this->str[i] != '\0'; i++)
        this->str[i] = '\0';
}

int size(const string_t *this)
{
    if (this == NULL || this->str == NULL)
        return (0);
    return (strlen(this->str));
}

int compare_s(const string_t *this, const string_t *str)
{
    int res = 0;

    if (this == NULL || str == NULL || this->str == NULL || str->str == NULL)
        return (-1);
    res = strcmp(this->str, str->str);
    return (res);
}

int compare_c(const string_t *this, const char *str)
{
    int res = 0;

    if (this == NULL || this->str == NULL || str == NULL)
        return (-1);
    res = strcmp(this->str, str);
    return (res);
}