/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** GraphicCharacter
*/

#ifndef GRAPHICCHARACTER_HPP_
#define GRAPHICCHARACTER_HPP_

#include "SFML/Graphics.hpp"
#include <iostream>
#include <string>

namespace Graphic {
    class GraphicCharacter {
        public:
            GraphicCharacter();
            ~GraphicCharacter();

            void setTexture(std::string const &file, sf::IntRect const &rect);
            sf::Texture getTexture() const;

            void setSprite(sf::IntRect const &rect);
            sf::Sprite getSprite() const;

            void setPosition(float x, float y);
            sf::Vector2f getPosition() const;

            void moveRect(int offset, int maxValue);
            void moveEffect(int offset, int maxValue);
        private:
            sf::Texture _texture;
            sf::IntRect _rect;
            sf::Sprite _sprite;
            sf::Clock _clock;
            sf::Time _time;
            float _second;
    };
}
#endif /* !GRAPHICCHARACTER_HPP_ */
