/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** GraphicCharacter
*/

#include "GraphicCharacter.hpp"

Graphic::GraphicCharacter::GraphicCharacter()
{
}

Graphic::GraphicCharacter::~GraphicCharacter()
{
}

void Graphic::GraphicCharacter::setTexture(std::string const &file, sf::IntRect const &rect)
{
    _texture.loadFromFile(file, rect);
}

sf::Texture Graphic::GraphicCharacter::getTexture() const
{
    return _texture;
}

void Graphic::GraphicCharacter::setSprite(sf::IntRect const &rect)
{
    _rect = rect;
    _sprite.setTexture(_texture);
    _sprite.setTextureRect(rect);
    _sprite.setScale(_sprite.getScale().x * 2, _sprite.getScale().y);
}

sf::Sprite Graphic::GraphicCharacter::getSprite() const
{
    return _sprite;
}

void Graphic::GraphicCharacter::moveRect(int offset, int maxValue)
{
    if (_rect.top < maxValue) {
        _rect.top += offset;
        if (_rect.top >= maxValue)
            _rect.top = 0;
    }
}

void Graphic::GraphicCharacter::moveEffect(int offset, int maxValue)
{
    _time = _clock.getElapsedTime();
    _second = _time.asMicroseconds() / 1000000;

    if (_second > 0.1) {
        moveRect(offset, maxValue);
        _sprite.setTextureRect(_rect);
        _clock.restart();
    }
}

void Graphic::GraphicCharacter::setPosition(float x, float y)
{
    _sprite.setPosition(x, y);
}

sf::Vector2f Graphic::GraphicCharacter::getPosition() const
{
    return _sprite.getPosition();
}