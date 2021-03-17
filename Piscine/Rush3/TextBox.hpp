/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** TextBox
*/

#ifndef TEXTBOX_HPP_
#define TEXTBOX_HPP_

#include "Box.hpp"

class TextBox : public Box {
	public:
		TextBox(sf::Vector2f size, sf::Vector2f pos, const std::string &text, const std::string &title) 
        : Box(size, pos)  {
            _font.loadFromFile("srcs/Lobster_1.3.otf");
            _text.setFont(_font);
            _text.setString(text);
            _text.setCharacterSize(24);

            _text.setFont(_font);
            _text.setString(title);
            _text.setCharacterSize(24);
            _title.setPosition(0, rect->getPosition().y + 15);
        };
        void draw(sf::RenderWindow &window) override;
        sf::Text getText() { return _text;};
        void drawText();
        void setText(const std::string &text);
		~TextBox() = default;

	protected:
        sf::Text _text;
        sf::Text _title;
        sf::Font _font;
};

#endif /* !TEXTBOX_HPP_ */
