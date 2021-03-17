/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Graphic
*/

#include "Graphic.hpp"

Graphic::Graphic::Graphic(std::shared_ptr<timePoint> start) 
    : _start(start)
{
}

void Graphic::Graphic::setMapSize(std::pair<int, int> const &mapSize)
{
    _mapSize = mapSize;
    
}

// Graphic::Graphic::~Graphic()
// {
// }