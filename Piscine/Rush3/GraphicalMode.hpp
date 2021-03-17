/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** GraphicalMode
*/

#ifndef GRAPHICALMODE_HPP_
#define GRAPHICALMODE_HPP_
#include <SFML/Graphics.hpp>
#include "ModuleMonitor.hpp"
#include "Box.hpp"

#include <map>

class GraphicalMode
{
	public:
		GraphicalMode();
		virtual ~GraphicalMode();
		void setImage(std::string);
		sf::Text setText(std::string, int x, int y);
		void window();
	protected:
		sf::Texture texture;
		sf::Sprite sprite;
		sf::Text text;
		sf::Font font;
		ModuleMonitor info;
	private:
};

#endif /* !GRAPHICALMODE_HPP_ */
