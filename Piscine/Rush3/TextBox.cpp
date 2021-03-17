/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** TextBox
*/

#include "TextBox.hpp"


void TextBox::drawText()
{
    sf::FloatRect bounds(_text.getLocalBounds());

    _text.setPosition(10, rect->getPosition().y + bounds.top);
}

 void TextBox::setText(const std::string &text)
 {
     _text.setString(text);
 }

void TextBox::draw(sf::RenderWindow &window)
{
    Box::draw(window);
    window.draw(_text);
    window.draw(_title);
}