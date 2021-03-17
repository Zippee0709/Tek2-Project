/*
** EPITECH PROJECT, 2020
** info.c
** File description:
** info.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "double_list.h"

unsigned int double_list_get_size(double_list_t list)
{
    unsigned int size = 0;

    if (list == NULL)
        return (size);
    for(; list != NULL; list = list->next)
        size = size + 1;
    return (size);
}

bool double_list_is_empty(double_list_t list)
{   
    if (list == NULL)
        return (true);
    return (false);
}

void double_list_dump(double_list_t list)
{
    if (list == NULL)
        return;
    for (; list != NULL; list = list->next)
        printf("%f\n", list->value);
}

bool double_list_add_elem_at_front(double_list_t *front_ptr, double elem)
{
    double_list_t node = malloc(sizeof(node));

    if (node == NULL)
        return (false);
    node->value = elem;
    node->next = NULL;
    if (double_list_is_empty(*front_ptr) == true)
        *front_ptr = node;
    else {
        node->next = *front_ptr;
        *front_ptr = node;
    }
    return (true);
}

bool double_list_add_elem_at_back(double_list_t *front_ptr, double elem)
{
    double_list_t node = malloc(sizeof(node));
    double_list_t tmp = NULL;

    if (node == NULL)
        return (false);
    node->value = elem;
    node->next = NULL;
    if (double_list_is_empty(*front_ptr) == true)
        *front_ptr = node;
    else {
        tmp = *front_ptr;
        for (;tmp->next != NULL; tmp = tmp->next);
        tmp->next = node;
    }
    return (true);
}

bool replace_by_position(double_list_t *front_ptr, double elem, unsigned int position)
{
    double_list_t node = malloc(sizeof(node));
    double_list_t tmp = NULL;

    if (node == NULL)
        return (false);
    tmp = *front_ptr;
    for (int i = 0; i < (int)(position - 1); i++, tmp = tmp->next);
    node->value = elem;
    node->next = tmp->next;
    tmp->next = node;
    return (true);
}

bool double_list_add_elem_at_position(double_list_t *front_ptr, double elem, unsigned int position)
{
    int list_size = double_list_get_size(*front_ptr);

    if (list_size < (int)position)
        return (false);
    if (position == 0)
        return (double_list_add_elem_at_front(front_ptr, elem));
    else if ((int)position == list_size)
        return (double_list_add_elem_at_back(front_ptr, elem));
    else
        return (replace_by_position(front_ptr, elem, position));
    return (true);
}

bool double_list_del_elem_at_front(double_list_t *front_ptr)
{
    double_list_t tmp = NULL;

    if (*front_ptr == NULL)
        return (false);
    if (double_list_get_size(*front_ptr) == 1) {
        free(*front_ptr);
        return (true);
    }
    tmp = *front_ptr;
    *front_ptr = (*front_ptr)->next;
    free(tmp);
    return (true);
}

bool double_list_del_elem_at_back(double_list_t *front_ptr)
{
    double_list_t tmp = NULL;
    double_list_t before = NULL;

    if (*front_ptr == NULL)
        return (false);
    if (double_list_get_size(*front_ptr) == 1) {
        free(*front_ptr);
        return (true);
    }
    tmp = *front_ptr;
    before = *front_ptr;
    for (; tmp->next != NULL; tmp = tmp->next)
        before = tmp;
    before->next = NULL;
    free(tmp);
    return (true);
}

bool delete_by_position(double_list_t *front_ptr, unsigned int position)
{
    double_list_t tmp = NULL;
    double_list_t before = NULL;

    tmp = *front_ptr;
    before = *front_ptr;
    for (int i = 0; i < (int)(position - 1) && tmp->next != NULL; i++, tmp = tmp->next)
        before = tmp;
    before->next = tmp->next;
    free(tmp);
    return (true);
}

bool double_list_del_elem_at_position(double_list_t *front_ptr, unsigned int position)
{
    int list_size = 0;

    if (double_list_is_empty(*front_ptr) == true)
        return (false);
    list_size = double_list_get_size(*front_ptr);
    if (list_size < (int)position)
        return (false);
    if (position == 0)
        return (double_list_del_elem_at_front(front_ptr));
    else if ((int)position == list_size)
        return (double_list_del_elem_at_back(front_ptr));
    else
        return (delete_by_position(front_ptr, position));
    return (true);
}

double double_list_get_elem_at_front(double_list_t list)
{
    if (double_list_is_empty(list) == true)
        return (0);
    return (list->value);
}

double double_list_get_elem_at_back(double_list_t list)
{
    if (double_list_is_empty(list) == true)
        return (0);
    for (; list->next != NULL; list = list->next);
    return (list->value);
}

double get_elem_at_position(double_list_t list, unsigned int position)
{
    double_list_t tmp = NULL;
    double_list_t before = NULL;

    tmp = list;
    before = list;
    for (int i = 0; i < (int)(position - 1) && tmp->next != NULL; i++, tmp = tmp->next)
        before = tmp;
    return (before->value);
}

double double_list_get_elem_at_position(double_list_t list, unsigned int position)
{
    int list_size = 0;
    double res = 0;

    if (double_list_is_empty(list) == true)
        return (0);
    list_size = double_list_get_size(list);
    if (list_size < (int)position)
        return (0);
    if (position == 0) {
        double_list_get_elem_at_front(list);
        return (true);
    }
    else if ((int)position == list_size - 1) {
        double_list_get_elem_at_back(list);
        return (true);
    }
    res = get_elem_at_position(list, position);
    return (res);
}

// doublelist_node_t *double_list_get_first_node_with_value(double_list_t list, double value)
// {
//     struct doublelist_node_t *node = NULL;

//     if (list->value == value) {
//         node = malloc(sizeof(node));
//         node->value = value;
//         node->next = NULL;
//         return (node);
//     }
//     return (NULL);
// }

/* Tout ce qui est en bas c'est pour tester*/
/* Tout ce qui est en bas c'est pour tester*/
/* Tout ce qui est en bas c'est pour tester*/
/* Tout ce qui est en bas c'est pour tester*/
// static void populate_list ( double_list_t * list_head )
// {
//     double_list_add_elem_at_back ( list_head , 5.2) ;
//     double_list_add_elem_at_back ( list_head , 42.5) ;
//     double_list_add_elem_at_back ( list_head , 3.3) ;
//     double_list_add_elem_at_back ( list_head , 8.3) ;
//     // printf("begin-------------------------\n");
//     double_list_dump(*list_head);
//     // double_list_add_elem_at_position ( list_head, 0, 2);
//     // printf("last-------------------------\n");
//     // double_list_dump(*list_head);
//     // printf("delbegin-------------------------\n");
//     // double_list_del_elem_at_front(list_head);
//     // double_list_dump(*list_head);
//     // printf("dellast-------------------------\n");
//     // double_list_del_elem_at_back(list_head);
//     // double_list_dump(*list_head);    // before->next = tmp->next;
//     // free(tmp);
//     // return (true);

//     printf("delbyposition-------------------------\n");
//     double res = double_list_get_elem_at_position( *list_head, 2);
//     printf("res = %f\n", res);
//     double_list_dump(*list_head);

// }
// // static void test_size ( double_list_t list_head )
// // {
// //     printf (" There are %u elements in the list \n", double_list_get_size( list_head ) ) ;
// //     double_list_dump ( list_head ) ;
// // }
// // static void test_del ( double_list_t * list_head )
// // {
// //     double_list_del_elem_at_back ( list_head ) ;
// //     printf (" There are %u elements in the list \n", double_list_get_size(* list_head ) ) ;
// //     double_list_dump (* list_head ) ;
// // }
// int main ( void )
// {
//     double_list_t list_head = NULL ;
//     populate_list (&list_head) ;
//     // test_size ( list_head ) ;
//     // test_del (& list_head ) ;
//     return 0;
// }
