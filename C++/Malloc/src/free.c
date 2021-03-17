/*
** EPITECH PROJECT, 2020
** PSU_2019_malloc
** File description:
** free
*/

#include "../include/malloc.h"

void free(void *ptr)
{
    block_t *free = NULL;

    if (ptr == NULL)
        return;
    free = (block_t *)ptr - 1;
    free->avaible = 1;
}

void *calloc(size_t nmemb, size_t size)
{
    size_t new_size = nmemb * size;
    block_t *ptr = malloc(new_size);

    if (ptr == NULL)
        return (NULL);
    memset(ptr, 0, size);
    return (ptr);
}

void *realloc(void *ptr, size_t size)
{
    block_t *block;
    block_t *new_block;

    if (ptr == NULL)
        return (malloc(size));
    block = (block_t *)ptr - 1;
    if (block->size >= size)
        return ptr;
    new_block = malloc(size);
    if (new_block == NULL)
        return (NULL);
    memcpy(new_block, ptr, block->size);
    free(ptr);
    return (new_block);
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
    return (realloc(ptr, nmemb * size));
}