/*
** EPITECH PROJECT, 2020
** cpp_d02m_2019
** File description:
** tester
*/

#include  <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../ex03/new.h"
#include "../ex03/point.h"
#include "../ex03/vertex.h"

Test (utils, sub)
{
    Object   *p1 = new(Point , 12, 13);
    Object   *p2 = new(Point , 2, 2);

    cr_assert_str_eq((str(subtraction(p1 , p2))), "<Point (10, 11)>");
}

Test (utils, sub1)
{
    Object   *p1 = new(Point , 0, 13);
    Object   *p2 = new(Point , 2, 2);

    cr_assert_str_eq((str(subtraction(p1 , p2))), "<Point (-2, 11)>");
}

Test (utils, sub2)
{
    Object   *v1 = new(Vertex , 1, 2, 3);
    Object   *v2 = new(Vertex , 4, 5, 6);

    cr_assert_str_eq((str(subtraction(v1 , v2))), "<Vertex (-3, -3, -3)>");
}

Test (utils, sub3)
{
    Object   *p1 = new(Point , -12, 13);
    Object   *p2 = new(Point , 3, 2);

    cr_assert_str_eq((str(subtraction(p1 , p2))), "<Point (-15, 11)>");
}

Test (utils, sub4)
{
    Object   *p1 = new(Point , -12, 13);
    Object   *p2 = new(Point , 3, 2);
    Object   *v1 = new(Vertex , 1, 16, 3);
    Object   *v2 = new(Vertex , 4, -5, 6);

    cr_assert_str_eq((str(subtraction(p1 , p2))), "<Point (-15, 11)>");
    cr_assert_str_eq((str(subtraction(v1 , v2))), "<Vertex (-3, 21, -3)>");
}