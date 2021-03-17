/*
** EPITECH PROJECT, 2020
** PSU_2019_malloc
** File description:
** malloc
*/

#ifndef MALLOC_H_
#define MALLOC_H_

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct block_t
{
    size_t size;
    int avaible;
    struct block_t *next;
}   block_t;

void *malloc(size_t size);

#endif /* !MALLOC_H_ */
