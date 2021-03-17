/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 02
*/

#include <stdio.h>
#include <string.h>
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
    int arg1 = va_arg((*args), int);
    int arg2 = va_arg((*args), int);

    this->x = arg1;
    this->y = arg2;
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

// Create additional functions here

static const PointClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(PointClass),
        .__name__ = "Point",
        .__ctor__ = (ctor_t)&Point_ctor,
        .__dtor__ = (dtor_t)&Point_dtor,
        .__str__ = (to_string_t)&Point_tostring,
        .__add__ = NULL,    /* Implement this method for exercice 03 */
        .__sub__ = NULL,    /* Implement this method for exercice 03 */
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
