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
#include "player.h"

Object *new(const Class *class, ...)
{
    Class *p = NULL;
    va_list ap;

    if (class != NULL) {
        printf("---commencement---\n");
        va_start(ap, class);
        if (ap != NULL) {
            printf("----Jevalide tout le temps ici ici -----\n");
            return va_new(class, &ap);
        }
        p = calloc(1, class->__size__);
        if (p == NULL)
            raise("Error : Allocation memory failed\n");
        memcpy(p, class, class->__size__);
        printf("aprés mem ");
        if (class->__ctor__) {
            printf("je suis la\n");
            class->__ctor__(p, NULL);
        }
        else {
            printf("psizefin = %d\n", (int)p->__size__);
            int res = memcmp(p, Player, Player->__size__);
            printf("mem cmp else %d\n", res);
            }
    }
    printf("psizefin = %d\n", (int)p->__size__);
    return p;
}

Object *va_new(const Class *class, va_list *ap)
{
    Class *p = calloc(1, class->__size__);

    if (p == NULL)
        raise("Error : Allocation memory failed\n");
    memcpy(p, class, class->__size__);
    if (class->__ctor__) 
        class->__ctor__(p, ap);
    va_end(*ap);
    return p;
}

void delete(Object *ptr)
{
    Class *cp = ptr;

    if (ptr && cp && cp->__dtor__)
        cp->__dtor__(ptr);
    free(ptr);
}
