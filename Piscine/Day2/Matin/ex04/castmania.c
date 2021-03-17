/*
** EPITECH PROJECT, 2020
** castmania.c
** File description:
** castmania.c
*/

#include "castmania.h"

void exec_operation(instruction_type_t instruction_type, void *data)
{
    if (instruction_type == DIV_OPERATION) {
        exec_div(((instruction_t*)data)->operation);
        if (((instruction_t *)data)->output_type == VERBOSE) {
            if(((division_t*)((instruction_t *)data)->operation)->div_type == INTEGER)
                printf("%d\n", ((integer_op_t *)((division_t*)((instruction_t*)data)->operation)->div_op)->res);
            else if (((division_t*)((instruction_t *)data)->operation)->div_type == DECIMALE)
                printf("%f\n", ((decimale_op_t *)((division_t*)((instruction_t*)data)->operation)->div_op)->res);
        }
    } else if (instruction_type == ADD_OPERATION) {
        exec_add(((instruction_t*)data)->operation);
        if (((instruction_t *)data)->output_type == VERBOSE)
                printf("%d\n", ((addition_t *)((instruction_t*)data)->operation)->add_op.res);
    }
}

void exec_instruction(instruction_type_t instruction_type, void *data)
{
    if (instruction_type == PRINT_INT)
        printf("%d\n", (*(int *)data));
    else if (instruction_type == PRINT_FLOAT)
        printf("%f\n", (*(float *)data));
    else
        exec_operation(instruction_type, data);
}
