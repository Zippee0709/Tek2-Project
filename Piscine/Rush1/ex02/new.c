/*
** EPITECH PROJECT, 2020
** new.c
** File description:
** new
*/

#include <stdarg.h>
#include <assert.h>
#include "object.h"
#include "new.h"

Object *new(const Class *class, ...)
{
    const Class *copy = class;
    Object *p;
    va_list ap;

    if (class != NULL) {
        va_start(ap, class);
        if (ap != NULL) {
            return va_new(class, &ap);
        }
        p = malloc(class->__size__);
        if (p == NULL)
            raise("Error : Allocation memory failed\n");
        memcpy(p, class, copy->__size__);
        *(const Class **)p = copy;
        if (copy->__ctor__)
            copy->__ctor__(p, NULL);
    }
    va_end(ap);
    return p;
}

Object *va_new(const Class *class, va_list *ap)
{
    const Class *copy = class;
    Object *p = malloc(class->__size__);

    if (p == NULL)
        raise("Error : Allocation memory failed\n");
    memcpy(p, class, copy->__size__);
    *(const Class **)p = copy;
    if (copy->__ctor__) 
        copy->__ctor__(p, ap);
    va_end(*ap);
    return p;
}

void delete(Object *ptr)
{
    const Class **cp = ptr;

    if (ptr && *cp && (*cp)->__dtor__) {
        (*cp)->__dtor__(ptr);
    }
    free(ptr);
}
