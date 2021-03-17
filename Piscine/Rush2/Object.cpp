/*
** EPITECH PROJECT, 2019
** Object.cpp
** File description:
** Object function
*/

#include "LittlePony.hpp"
#include "Teddy.hpp"

Object::Object()
{
}

Object::~Object()
{
/*     delete this->_obj;
*/
}

void Object::setObject(Object *obj) 
{
     this->_obj = obj;
}

Object **MyUnitTests()
{
    Teddy ted("cuddles");
    LittlePony pony("happy pony");
    static Object *array = new Object[2];

    array[0] = ted;
    array[1] = pony;
    return &array;
}