/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 01
*/

#include <string.h>
#include "new.h"
#include "player.h"

int main(void)
{
    Object *dummy = new(Test);
    delete(dummy);

    printf("sizeof char = %d\n", (int)sizeof(int));
    printf("sizeof char* = %d\n", (int)sizeof(int *));
    return (0);
}
