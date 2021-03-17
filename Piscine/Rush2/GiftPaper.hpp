/*
** EPITECH PROJECT, 2020
** GiftPaper.hpp
** File description:
** GiftPaper
*/

#ifndef GIFTPAPER
#define GIFTPAPER
#include <iostream>
#include "Box.hpp"

class GiftPaper : public Wrap {
    public:
        GiftPaper() : Wrap(TYPE::GIFTPAPERS) { };
        GiftPaper(Object &obj) : Wrap(TYPE::GIFTPAPERS) {
            this->_obj = obj.getObject();
         };
        ~GiftPaper() = default;
    private:
};

#endif
