/*
** EPITECH PROJECT, 2020
** string.h
** File description:
** string.h
*/

#ifndef STRING_H_
#define STRING_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct  string_t
{
    char *str;
    void (*assign_s)(struct string_t *, const struct string_t *str);
    void (*assign_c)(struct string_t *, const char *str);
    void (*append_s)(struct string_t *, const struct string_t *ap);
    void (*append_c)(struct string_t *, const char *ap);
    char (*at)(const struct string_t *, size_t pos);
    void (*clear)(struct string_t *);
    int (*size)(const struct string_t *);
    int (*compare_s)(const struct string_t *, const struct string_t *str);
    int (*compare_c)(const struct string_t *, const char *str);
    size_t (*copy)(const struct string_t *, char *s, size_t n, size_t pos);
}   string_t;

void string_init(string_t *this, const char *s);
void string_destroy(string_t *this);
void assign_s(string_t *this, const string_t *str);
void assign_c(string_t *this, const char *str);
void append_s(string_t *this, const string_t *ap);
void append_c(string_t *this, const char *ap);
char at(const string_t *this, size_t pos);
void clear(string_t *this);
int size(const string_t *this);
int compare_s(const string_t *this, const string_t *str);
int compare_c(const string_t *this, const char *str);
size_t copy(const string_t *this, char *s, size_t n, size_t pos);


char *my_malloc_string_by_pos(char *str, int pos);

#endif /* !STRING_H_ */
