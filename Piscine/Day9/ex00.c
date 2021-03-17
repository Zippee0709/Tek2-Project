/*
** EPITECH PROJECT, 2020
** ex00.c
** File description:
** ex00.c
*/

#include "ex00.h"

static void cthulhu_initializer(cthulhu_t *this);
static void koala_initializer(koala_t *this, char *_name, char _is_A_Legend);

cthulhu_t *new_cthulhu(void)
{
    cthulhu_t *new = malloc(sizeof(new));

    if (new == NULL)
        return (NULL);
    cthulhu_initializer(new);
    return (new);
}

void print_power(cthulhu_t *this)
{
    printf("Power => %d\n", this->m_power);
}

void attack(cthulhu_t *this)
{
    if (this->m_power >= 42) {
        this->m_power -= 42;
        printf("%s attacks and destroys the city\n", this->m_name);
        return;
    }
    printf("%s can't attack, he doesn't have enough power\n", this->m_name);
}

void sleeping(cthulhu_t *this)
{
    this->m_power += 42000;
    printf("%s sleeps\n", this->m_name);
}

koala_t *new_koala(char *name, char is_a_legend)
{
    koala_t *koala = malloc(sizeof(koala));

    if (koala == NULL)
        return (NULL);
    koala_initializer(koala, name, is_a_legend);
    return (koala);
}

void eat(koala_t *this)
{
    this->m_parent.m_power += 42;
    printf("%s eats\n", this->m_parent.m_name);
}

static void koala_initializer(koala_t *this, char *_name, char _is_A_Legend)
{
    cthulhu_initializer(&this->m_parent);
    if (_name != NULL) {
        free(this->m_parent.m_name);
        this->m_parent.m_name = strdup(_name);
    }
    if (_is_A_Legend == 1)
        this->m_parent.m_power = 42;
    else
        this->m_parent.m_power = 0;
    this->m_is_a_legend = _is_A_Legend;
    printf("Building %s\n", this->m_parent.m_name);
}

static void cthulhu_initializer(cthulhu_t *this)
{
    printf("----\n");
    this->m_name = strdup("Cthulhu");
    this->m_power = 42;
    printf("Building %s\n", this->m_name);
}
