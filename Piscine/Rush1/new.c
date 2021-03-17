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
    Object *p = NULL;
    va_list ap;

    if (class != NULL) {
        p = malloc(class->__size__);
        if (p == NULL)
            raise("Error : Allocation memory failed\n");
        memcpy(p, class, class->__size__);
        if (class->__ctor__) {
            va_start(ap, class);
            class->__ctor__(p, &ap);
            va_end(ap);
        }
        return p;
    }
    raise("Error class does not exists\n.");
    return NULL;
}

Object *va_new(const Class *class, va_list *ap)
{
    Object *p = NULL;

    if (class != NULL) {
        p = malloc(class->__size__);
        if (p == NULL)
            raise("Error : Allocation memory failed\n");
        memcpy(p, class, class->__size__);
        if (class->__ctor__) {
            class->__ctor__(p, ap);
        }
        return p;
    }
    raise("Error class does not exists\n.");
    return NULL;
}

void delete(Object *ptr)
{
    if (ptr && ((Class *)(ptr))->__dtor__) {
       ((Class *)(ptr))->__dtor__(ptr);
    }
    free(ptr);
}
