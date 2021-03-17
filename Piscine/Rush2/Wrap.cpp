/*
** EPITECH PROJECT, 2020
** Wrap.cpp
** File description:
** Wrap
*/

#include <string>
#include "Wrap.hpp"
#include "Object.hpp"

void Wrap::wrapMeThat(Object *present)
{
    if (this->_haveObject) {
        std::cerr << "Have already an object inside. You can't put an other object." << std::endl;
        return;
    }
    this->_present = present;
    this->_haveObject = true;
}

Object *Wrap::openMe()
{
    return this->_obj;
}

void Wrap::closeMe()
{
    return;
}

Object *MyUnitTests(Object **arr)
{
    Object *ted = arr[0];
    Object *box = arr[1];
    Object *giftPaper = arr[2];

    box->setObject(ted);
    giftPaper->setObject(box);
    return giftPaper;
 }