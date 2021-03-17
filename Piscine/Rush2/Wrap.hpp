/*
** EPITECH PROJECT, 2020
** Wrap.hpp
** File description:
** Wrap
*/

#ifndef WRAP
#define WRAP
#include <iostream>
#include "Object.hpp"


class Wrap : public Object {
    public:
        Wrap() = default;

        void wrapMeThat(Object *obj);
        Object *openMe();
        void closeMe();

        ~Wrap() = default;
    protected:
        Wrap(TYPE type) : Object(type) {};
        bool _haveObject = false;
        Object *_present = NULL;
};

Object *MyUnitTests(Object **);

#endif
