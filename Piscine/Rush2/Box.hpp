/*
** EPITECH PROJECT, 2020
** Box.hpp
** File description:
** Box
*/

#ifndef BOX
#define BOX
#include <iostream>
#include "Toy.hpp"
#include "Wrap.hpp"

class Box : public Wrap  {
    public:
        Box() : Wrap(TYPE::BOXES) { };
        Box(Object &obj) : Wrap(TYPE::BOXES) {
            this->_obj = obj.getObject();
        };
        void wrapMeThat(Object *obj);
        Object *openMe();
        void closeMe();

        ~Box() = default;
    private:
        bool _isOpen = true;
};

#endif
