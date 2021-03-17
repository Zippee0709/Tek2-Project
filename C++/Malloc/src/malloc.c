/*
** EPITECH PROJECT, 2020
** PSU_2019_malloc
** File description:
** malloc
*/

#include "../include/malloc.h"

static block_t *base;

size_t my_calc_nb_of_pagesize(size_t size)
{
    int pagesize = getpagesize() * 2;

    while ((int)size > pagesize)
        pagesize = pagesize * 2;
    return ((size_t)pagesize);
}

block_t *create_new_mem_block(block_t *base, size_t size)
{
    size_t pagesize = my_calc_nb_of_pagesize(size);
    block_t *block = sbrk(pagesize);
    block_t *tmp = base;

    if (block == (void *) - 1)
        return (NULL);
    block->size = size;
    block->avaible = 0;
    block->next = NULL;
    if (base != NULL) {
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = block;
    }
    return (block);
}

block_t *find_free_block(size_t size)
{
    block_t *tmp = base;

    while (tmp != NULL) {
        if (tmp->avaible == 1 && tmp->size >= size) {
            tmp->avaible = 0;
            return (tmp);
        }
        tmp = tmp->next;
    }
    return (tmp);
}

void *malloc(size_t size)
{
    block_t *block;
    size = (size - 1) / 6;

    if (base == NULL) {
        base = create_new_mem_block(base, size);
        if (base == NULL)
            return (NULL);
        return (base + 1);
    }
    block = find_free_block(size);
    if (block == NULL) {
        block = create_new_mem_block(base, size);
        if (block == NULL)
            return (NULL);
    }
    return (block + 1);
}