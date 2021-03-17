/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** vertex.c
*/

#include <stdio.h>
#include <string.h>
#include "vertex.h"
#define BUFFSIZE 64
#define MAX_INT 11

typedef struct
{
    Class   base;
    char    *str;
    int     x, y, z;
}   VertexClass;

static void Vertex_ctor(VertexClass *this, va_list *args)
{
    this->x = va_arg((*args), int);
    this->y = va_arg((*args), int);
    this->z = va_arg((*args), int);
}

static char *Vertex_tostring(VertexClass *this)
{
    int len = MAX_INT + MAX_INT + MAX_INT + strlen(this->base.__name__) + 10;

    this->str = malloc(sizeof(char) * len);
    snprintf(this->str, len, "<%s (%d, %d, %d)>",
             this->base.__name__, this->x, this->y, this->z);
    return this->str;
}

static void Vertex_dtor(VertexClass *this)
{
    free(this->str);
}

// Create additional functions here

static const VertexClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(VertexClass),
        .__name__ = "Vertex",
        .__ctor__ = (ctor_t)&Vertex_ctor,
        .__dtor__ = (dtor_t)&Vertex_dtor,
        .__str__ = (to_string_t)&Vertex_tostring,
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

const Class *Vertex = (const Class *)&_description;
