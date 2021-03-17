/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Cursor
*/

#include "my_sfml.hpp"

void Graphic::Sfml::Cursor::init(Sfml *parent)
    {
    int counter = 0;
    const float offsetX = 15;
    const float offsetY = 10;

    std::cout << "Cursor CContrsuctor" << std::endl;
    for (auto &game : parent->_gameTextList) {
        _gamePosition.insert(std::pair<int, sf::Vector2f>(counter, 
            {game.second.getPosition().x - offsetX, game.second.getPosition().y - offsetY}));
        counter++;
    }
    counter = 0;
    for (auto &graph : parent->_graphTextList) {
        _graphicPosition.insert(std::pair<int, sf::Vector2f>(counter, 
            {graph.second.getPosition().x - offsetX, graph.second.getPosition().y - offsetY}));
    counter++;
    }
}

void Graphic::Sfml::Cursor::checkVertical(bool isCheckTop)
{
    std::map<int, sf::Vector2f> position = _isGameTab ? _gamePosition : _graphicPosition;

    if (isCheckTop) {
        if (_actualPosition == 0)
            return;
        moveCursorVertical(isCheckTop, position);
        return;
    }
    if (position.find(_actualPosition + 1) == position.end())
        return;
    moveCursorVertical(isCheckTop, position);
}

void Graphic::Sfml::Cursor::moveCursorVertical(bool moveTop, std::map<int, sf::Vector2f> &position)
{
    _actualPosition += moveTop ? -1 : 1;
    _shape.setPosition(position[_actualPosition]);
    _moveCursorSound.play();
}

void Graphic::Sfml::Cursor::checkHorizontal(bool isCheckLeft)
{
    if (isCheckLeft) {
        if (_isGameTab)
            return;
        moveCursorHorizontal(isCheckLeft);
        return;
    }
    if (!_isGameTab)
        return;
    moveCursorHorizontal(isCheckLeft);
}

void Graphic::Sfml::Cursor::moveCursorHorizontal(bool moveLeft)
{
    std::map<int, sf::Vector2f> position = !_isGameTab ? _gamePosition : _graphicPosition;

    _isGameTab = !_isGameTab;
    _shape.setPosition(position[0]);
    _actualPosition = 0;
    _moveCursorSound.play();
}
