/*
** EPITECH PROJECT, 2020
** assign.c
** File description:
** assign.c
*/

#include "string.h"

void assign_s(string_t *this, const string_t *str)
{
    if (this == NULL || str == NULL)
        return;
    if (this->str != NULL)
        free(this->str);
    this->str = strdup(str->str);
}

void assign_c(string_t *this, const char *s)
{
    if (this == NULL || s == NULL)
        return;
    if (this->str != NULL)
        free(this->str);
    this->str = strdup(s);
}

void append_s(string_t *this, const string_t *ap)
{
    char *tmp = NULL;

    if (this == NULL || ap->str == NULL)
        return;
    if (this->str == NULL) {
        this->str = strdup(ap->str);
        return;
    }
    tmp = strdup(this->str);
    free(this->str);
    this->str = malloc(sizeof(char*) * (strlen(tmp) + strlen(ap->str) + 1));
    if (this->str == NULL)
        return;
    this->str = strcpy(this->str, tmp);
    this->str = strcat(this->str, ap->str);
    free(tmp);
}

void append_c(string_t *this, const char *ap)
{
    char *tmp = NULL;

    if (this == NULL || ap == NULL)
        return;
    if (this->str == NULL) {
        this->str = strdup(ap);
        return;
    }
    tmp = strdup(this->str);
    free(this->str);
    this->str = malloc(sizeof(char *) * strlen(tmp) + strlen(ap) + 1);
    if (this->str == NULL)
        return;
    this->str = strcpy(this->str, tmp);
    this->str = strcat(this->str, ap);
    free(tmp);
}