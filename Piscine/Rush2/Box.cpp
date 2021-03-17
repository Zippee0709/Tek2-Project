/*
** EPITECH PROJECT, 2020
** Box.cpp
** File description:
** Box
*/

#include <string>
#include "Box.hpp"

void Box::wrapMeThat(Object *obj)
{
    if (!_isOpen)
        return
    Wrap::wrapMeThat(obj);
}

void Box::closeMe()
{
    this->_isOpen = false;
}