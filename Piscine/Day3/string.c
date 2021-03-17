/*
** EPITECH PROJECT, 2020
** string.c
** File description:
** string.c
*/

/*
** EPITECH PROJECT, 2020
** string.c
** File description:
** string.c
*/

#include "string.h"

void string_init(string_t *this, const char *s)
{
    if (this == NULL)
        return;
    if (s == NULL)
        this->str = NULL;
    else
        this->str = strdup(s);
    this->assign_s = &assign_s;
    this->assign_c = &assign_c;
    this->append_s = &append_s;
    this->append_c = &append_c;
    this->at = &at;
    this->clear = &clear;
    this->size = &size;
    this->compare_s = &compare_s;
    this->compare_c = &compare_c;
    this->copy = &copy;
}

void string_destroy(string_t *this)
{
    if (this == NULL || this->str == NULL)
        return;
    free(this->str);
}