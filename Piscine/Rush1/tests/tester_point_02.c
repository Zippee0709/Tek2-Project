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

Test (utils, point)
{
    Object   *point = new(Point, 42, -42);

    cr_assert_str_eq(str(point), "<Point (42, -42)>");
}

Test (utils, point1)
{
    Object   *point = new(Point, 0, -42);

    cr_assert_str_eq(str(point), "<Point (0, -42)>");
}

Test (utils, point2)
{
    Object   *point = new(Point, 42, 0);

    cr_assert_str_eq(str(point), "<Point (42, 0)>");
}