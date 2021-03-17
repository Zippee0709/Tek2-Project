/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** GraphicalBox.hpp
*/

#pragma once

#include <SFML/Graphics.hpp>

class Box
{
    public:
        Box(sf::Vector2f, sf::Vector2f);
        virtual ~Box();
        void setRectangle();
        virtual void draw(sf::RenderWindow &window);
        sf::RectangleShape getRectangle() { return *rect;};

    protected:
        sf::RectangleShape *rect;
        sf::Vector2f _size = {0, 0};
        sf::Vector2f _pos = {0, 0};
};