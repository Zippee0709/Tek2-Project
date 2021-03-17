/*
** EPITECH PROJECT, 2020
** cpp_d02m_2019
** File description:
** tester
*/

#include  <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../ex02/new.h"
#include "../ex02/point.h"
#include "../ex02/vertex.h"

Test (utils, vertex)
{
    Object  *vertex = new(Vertex, 0, 1, 2);

    cr_assert_str_eq(str(vertex), "<Vertex (0, 1, 2)>");
}

Test (utils, vertex1)
{
    Object  *vertex = new(Vertex, 0, 0, 0);

    cr_assert_str_eq(str(vertex), "<Vertex (0, 0, 0)>");
}

Test (utils, vertex2)
{
    Object  *vertex = new(Vertex, 0, -1, 0);

    cr_assert_str_eq(str(vertex), "<Vertex (0, -1, 0)>");
}

Test (utils, vertex_point)
{
    Object  *vertex = new(Vertex, 0, -1, 0);
    Object   *point = new(Point, 42, 0);

    cr_assert_str_eq(str(point), "<Point (42, 0)>");
    cr_assert_str_eq(str(vertex), "<Vertex (0, -1, 0)>");
}