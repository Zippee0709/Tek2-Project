/*
** EPITECH PROJECT, 2020
** cpp_rush1_2019
** File description:
** point
*/

#include <stdio.h>
#include <string.h>
#include "new.h"
#include "point.h"
#define BUFFSIZE 64
#define MAX_INT 11

typedef struct
{
    Class   base;
    char    *str;
    int     x, y;
}   PointClass;

static void Point_ctor(PointClass *this, va_list *args)
{
    this->x = va_arg((*args), int);
    this->y = va_arg((*args), int);
}

static char *Point_tostring(PointClass *this)
{
    int len = MAX_INT + MAX_INT + strlen(this->base.__name__) + 10;

    this->str = malloc(sizeof(char) * len);
    snprintf(this->str, len, "<%s (%d, %d)>",
                this->base.__name__, this->x, this->y);
    return this->str;
}

static void Point_dtor(PointClass *this)
{
    free(this->str);
}

static Object *Point_add(const PointClass *this, const PointClass *other)
{
    Object *new_point = new(Point, this->x + other->x, this->y + other->y);

    return new_point;
}

static Object *Point_sub(const PointClass *this, const PointClass *other)
{
    Object *new_point = new(Point, this->x - other->x, this->y - other->y);

    return new_point;
}
// Create additional functions here

static const PointClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(PointClass),
        .__name__ = "Point",
        .__ctor__ = (ctor_t)&Point_ctor,
        .__dtor__ = (dtor_t)&Point_dtor,
        .__str__ = (to_string_t)&Point_tostring,
        .__add__ = (binary_operator_t)&Point_add,    /* Implement this method for exercice 03 */
        .__sub__ = (binary_operator_t)&Point_sub,    /* Implement this method for exercice 03 */
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0
};

const Class *Point = (const Class *)&_description;
