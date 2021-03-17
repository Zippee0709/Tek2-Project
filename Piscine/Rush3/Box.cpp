/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** Box.cpp
*/

#include <iostream>
#include "Box.hpp"

Box::Box(sf::Vector2f size, sf::Vector2f pos) : _size(size), _pos(pos), rect(new sf::RectangleShape(size))
{
}

Box::~Box()
{}

void Box::setRectangle()
{
    rect->setSize(_size);
    rect->setFillColor(sf::Color(100, 250, 50, 0));
    rect->setOutlineColor(sf::Color::Red);
    rect->setOutlineThickness(0.5);
    rect->setPosition(_pos);
}

void Box::draw(sf::RenderWindow &window)
{
    window.draw(*rect);
}