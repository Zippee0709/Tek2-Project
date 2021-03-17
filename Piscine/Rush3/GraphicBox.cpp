/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** GraphicBox
*/

#include <iostream>
#include "GraphicBox.hpp"

GraphicBox::~GraphicBox()
{
}

void GraphicBox::setText(const std::string &text)
{
    _font.loadFromFile("srcs/Lobster_1.3.otf");
    _title.setFont(_font);
    _title.setString(text);
    _title.setCharacterSize(24);
    _title.setPosition(0, rect->getPosition().y + 15);
}
