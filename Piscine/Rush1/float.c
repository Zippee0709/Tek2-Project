/*
** EPITECH PROJECT, 2020
** cpp_rush1_2019
** File description:
** float
*/

#include <stdio.h>
#include <string.h>
#include "new.h"
#include "float.h"
#define FLOAT_MAX_LENGTH 18

typedef struct
{
    Class   base;
    char    *str;
    float     x;
}   FloatClass;

static void Float_ctor(FloatClass *this, va_list *args)
{
    this->x = (float)va_arg((*args), double);
}

static char *Float_tostring(FloatClass *this)
{
    int len = FLOAT_MAX_LENGTH + strlen(this->base.__name__) + 10;

    this->str = malloc(sizeof(char) * len);
    snprintf(this->str, len, "<%s (%f)>", this->base.__name__, (float)this->x);
    return this->str;
}

static void Float_dtor(FloatClass *this)
{
    free(this->str);
}

static Object *Float_add(const FloatClass *this, const FloatClass *other)
{
    Object *new_point = new(Float, this->x + other->x);

    return new_point;
}

static Object *Float_sub(const FloatClass *this, const FloatClass *other)
{

    return new(Float, this->x - other->x);
}

static Object *Float_mul(const FloatClass *this, const FloatClass *other)
{

    return new(Float, this->x * other->x);
}

static Object *Float_div(const FloatClass *this, const FloatClass *other)
{
    if (other->x == 0)
        raise("Error : floating point exception");
    return new(Float, this->x / other->x);
}

static bool Float_eq(const FloatClass *this, const FloatClass *other)
{
    return this->x == other->x;
}

static bool Float_gt(const FloatClass *this, const FloatClass *other)
{
    return this->x > other->x;
}

static bool Float_lt(const FloatClass *this, const FloatClass *other)
{
    return this->x < other->x;
}

// Create additional functions here

static const FloatClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(FloatClass),
        .__name__ = "Float",
        .__ctor__ = (ctor_t)&Float_ctor,
        .__dtor__ = (dtor_t)&Float_dtor,
        .__str__ = (to_string_t)&Float_tostring,
        .__add__ = (binary_operator_t)&Float_add,
        .__sub__ = (binary_operator_t)&Float_sub,
        .__mul__ = (binary_operator_t)&Float_mul,
        .__div__ = (binary_operator_t)&Float_div,
        .__eq__ = (binary_comparator_t)&Float_eq,
        .__gt__ =(binary_comparator_t)&Float_gt,
        .__lt__ = (binary_comparator_t)&Float_lt
    },
    .x = 0
};

const Class *Float = (const Class *)&_description;
