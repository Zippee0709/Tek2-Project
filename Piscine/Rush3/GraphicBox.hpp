/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** GraphicBox
*/

#ifndef GRAPHICBOX_HPP_
#define GRAPHICBOX_HPP_
#include "Box.hpp"

class GraphicBox : public Box {
	public:
		GraphicBox(sf::Vector2f size, sf::Vector2f pos, const std::string &str) 
        : Box(size, pos) { }

		void setText(const std::string &text);
		sf::Text getTitle() const { return _title;};
		~GraphicBox();
	protected:
        sf::VertexArray arr;
		sf::Text _title;
		sf::Font _font;
	private:
};

#endif /* !GRAPHICBOX_HPP_ */

