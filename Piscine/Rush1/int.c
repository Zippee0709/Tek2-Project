/*
** EPITECH PROJECT, 2020
** cpp_rush1_2019
** File description:
** point
*/

#include <stdio.h>
#include <string.h>
#include "new.h"
#include "int.h"
#define BUFFSIZE 64
#define MAX_INT 11

typedef struct
{
    Class   base;
    char    *str;
    int     i;
}   IntClass;

static void Int_ctor(IntClass *this, va_list *args)
{
    this->i = va_arg((*args), int);
}

static char *Int_tostring(IntClass *this)
{
    int len = MAX_INT + strlen(this->base.__name__) + 10;

    this->str = malloc(sizeof(char) * len);
    snprintf(this->str, len, "<%s (%d)>", this->base.__name__, this->i);
    return this->str;
}

static void Int_dtor(IntClass *this)
{
    free(this->str);
}

static Object *Int_add(const IntClass *this, const IntClass *other)
{
    Object *new_point = new(Int, this->i + other->i);

    return new_point;
}

static Object *Int_sub(const IntClass *this, const IntClass *other)
{
    Object *new_point;

    new_point = new(Int, this->i - other->i);

    return new_point;
}

static Object *Int_mul(const IntClass *this, const IntClass *other)
{
    return new(Int, this->i * other->i);
}


static Object *Int_div(const IntClass *this, const IntClass *other)
{
    if (other->i == 0)
        raise("Error : floating point exception");
    return new(Int, this->i / other->i);
}

static bool Int_eq(const IntClass *this, const IntClass *other)
{
    return this->i == other->i;
}

static bool Int_gt(const IntClass *this, const IntClass *other)
{
    return this->i > other->i;
}

static bool Int_lt(const IntClass *this, const IntClass *other)
{
    return this->i < other->i;
}

static const IntClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(IntClass),
        .__name__ = "Int",
        .__ctor__ = (ctor_t)&Int_ctor,
        .__dtor__ = (dtor_t)&Int_dtor,
        .__str__ = (to_string_t)&Int_tostring,
        .__add__ = (binary_operator_t)&Int_add,
        .__sub__ = (binary_operator_t)&Int_sub,
        .__mul__ = (binary_operator_t)&Int_mul,
        .__div__ = (binary_operator_t)&Int_div,
        .__eq__ = (binary_comparator_t)&Int_eq,
        .__gt__ = (binary_comparator_t)&Int_gt,
        .__lt__ = (binary_comparator_t)&Int_lt
    },
    .i = 0,
};

const Class *Int = (const Class *)&_description;
