/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Char.c
*/

#include <stdio.h>
#include <string.h>
#include "char.h"
#include "new.h"
#define CHARSIZE 64
#define MAX_CHAR 11

typedef struct
{
    Class   base;
    char    *str;
    char     x;
}   CharClass;

static void Char_ctor(CharClass *this, va_list *args)
{
    this->x = va_arg((*args), int);
}

static char *Char_tostring(CharClass *this)
{
    int len = MAX_CHAR + MAX_CHAR + MAX_CHAR + strlen(this->base.__name__) + 10;

    this->str = malloc(sizeof(char) * len);
    snprintf(this->str, len, "<%s (%c)>", this->base.__name__, this->x);
    return this->str;
}

static void Char_dtor(CharClass *this)
{
    free(this->str);
}

static Object *Char_add(const CharClass *this, const CharClass *other)
{
    return(new(Char, this->x + other->x));
}

static Object *Char_sub(const CharClass *this, const CharClass *other)
{
    return(new(Char, this->x - other->x));
}

static Object *Char_mul(const CharClass *this, const CharClass *other)
{
    return (new(Char, this->x * other->x));
}

static Object *Char_div(const CharClass *this, const CharClass *other)
{
    return (new(Char, this->x / other->x));
}

static bool Char_eq(const CharClass *this, const CharClass *other)
{
    if (this->x == other->x)
        return (true);
    return (false);
}

static bool Char_it(const CharClass *this, const CharClass *other)
{
    if (this->x < other->x)
        return (true);
    return (false);
}

static bool Char_gt(const CharClass *this, const CharClass *other)
{
    if (this->x > other->x)
        return (true);
    return (false);
}

static const CharClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(CharClass),
        .__name__ = "Char",
        .__ctor__ = (ctor_t)&Char_ctor,
        .__dtor__ = (dtor_t)&Char_dtor,
        .__str__ = (to_string_t)&Char_tostring,
        .__add__ = (binary_operator_t)&Char_add,
        .__sub__ = (binary_operator_t)&Char_sub,
        .__mul__ = (binary_operator_t)&Char_mul,
        .__div__ = (binary_operator_t)&Char_div,
        .__eq__ = (binary_comparator_t)&Char_eq,
        .__gt__ = (binary_comparator_t)&Char_gt,
        .__lt__ = (binary_comparator_t)&Char_it
    },
    .x = 0
};

const Class *Char = (const Class *)&_description;
