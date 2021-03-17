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

Test (utils, add)
{
    Object   *p1 = new(Point , 12, 13);
    Object   *p2 = new(Point , 2, 2);

    cr_assert_str_eq((str(addition(p1 , p2))), "<Point (14, 15)>");
}

Test (utils, add1)
{
    Object   *p1 = new(Point , 0, 13);
    Object   *p2 = new(Point , 2, 2);

    cr_assert_str_eq((str(addition(p1 , p2))), "<Point (2, 15)>");
}

Test (utils, add2)
{
    Object   *v1 = new(Vertex , 1, 2, 3);
    Object   *v2 = new(Vertex , 4, 5, 6);

    cr_assert_str_eq((str(addition(v1 , v2))), "<Vertex (5, 7, 9)>");
}

Test (utils, add3)
{
    Object   *p1 = new(Point , -12, 13);
    Object   *p2 = new(Point , 3, 2);

    cr_assert_str_eq((str(addition(p1 , p2))), "<Point (-9, 15)>");
}

Test (utils, add4)
{
    Object   *p1 = new(Point , -12, 13);
    Object   *p2 = new(Point , 3, 2);
    Object   *v1 = new(Vertex , 1, -16, 3);
    Object   *v2 = new(Vertex , 4, 5, 6);

    cr_assert_str_eq((str(addition(p1 , p2))), "<Point (-9, 15)>");
    cr_assert_str_eq((str(addition(v1 , v2))), "<Vertex (5, -11, 9)>");
}