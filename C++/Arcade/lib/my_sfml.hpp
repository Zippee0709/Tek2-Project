/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** my_sfml
*/

#ifndef MY_SFML_HPP_
#define MY_SFML_HPP_

#include <chrono>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "SFML/System.hpp"
#include "SFML/Audio/Music.hpp"
#include "SFML/Audio/Sound.hpp"
#include "SFML/Audio/SoundBuffer.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Font.hpp"
#include "SFML/Graphics/Text.hpp"
#include "SFML/Graphics/CircleShape.hpp"
#include "Graphic.hpp"
#include "GraphicCharacter.hpp"

namespace Graphic {
    class Sfml : public Graphic {
        public:
            Sfml(std::map<int, std::string>, std::map<int, std::string>, std::shared_ptr<timePoint>);
            int createWindow(std::shared_ptr<Controller::Scene> scene,
                std::shared_ptr<int> actualGraphic, std::shared_ptr<int> actualGame,
                std::shared_ptr<int> score);
            void displayMap(std::map<int, std::map<int, char>> const &map);
            void displayObject(std::map<int, std::map<int, char>> const &map);
            ~Sfml();
        private:
            void createPlayer();
            void selectGraphics(const std::vector<std::string> &graphics);
            void loadMenu();
            void loadCursor();
            void playMusic();
            void loadBackground();
            void displayMenu();
            void loadCursorSound();
            void selectLib();
            void loadMenuName();
            void displayMenuName();
            void menuNameEventHandler();
            void displayStars();
            void menuEventHandler();
            void launchGame();
            void initMenuScene();
            void initMenuNameScene();
            void initPacmanScene();
            void textAnimationRendering();

        private:
            sf::RectangleShape createRectangle(sf::Vector2f size, sf::Vector2f position, sf::Color color);
            void updateShape();
            Controller::Key eventHandler();
            Controller::Key getKey();
            void drawMenu();
            void close();

            GraphicCharacter _player;
            std::map<int, GraphicCharacter> _ghost;
            GraphicCharacter _pacGum;
            GraphicCharacter _pacPower;

            /*               TEMPORARY              */
            timePoint _end;

            /*           BACKGROUND OBJET           */
            sf::Texture _backgroundTexture;
            sf::Sprite _backgroundSprite;
            sf::Texture _starsTexture;
            sf::Sprite _starsSprite;
            sf::IntRect _starsIntRect;

            /*              MENU NAME               */
            sf::RectangleShape _rectangleName;
            sf::String _playerName;
            sf::Text _playerNameText;

            /*              MENU OBJECT             */
            sf::RectangleShape _rectangleGame;
            sf::RectangleShape _rectangleGraph;
            std::map<int, std::string> _graphList;
            std::map<int, std::string> _gameList;
            std::map<int, sf::Text> _graphTextList;
            std::map<int, sf::Text> _gameTextList;
            sf::Text _welcomeText;
            sf::Text _scoreText;
            sf::Text _pressSpaceText;
            int _flashText = 255;
            int _colorIndex = 0;
            std::vector<sf::Color> _colors = {
                sf::Color::Green,
                sf::Color::Blue,
                sf::Color::Yellow,
                sf::Color::Cyan,
                sf::Color::Magenta,
            };
            sf::Text _scoreValueText;

            /*              MENU CURSOR             */ 
            class Cursor {
                public:
                    Cursor() = default;
                    ~Cursor() = default;
                    void init(Sfml *); 
                    void checkVertical(bool isCheckTop);
                    void checkHorizontal(bool isCheckLeft);
                    void moveCursorVertical(bool moveTop, std::map<int, sf::Vector2f>&);
                    void moveCursorHorizontal(bool moveTop);

                    sf::CircleShape _shape;
                    bool _isGameTab = true;
                    int _actualPosition = 0;
                    std::map<int, sf::Vector2f> _graphicPosition; 
                    std::map<int, sf::Vector2f> _gamePosition;
                    sf::SoundBuffer _moveCursorBuffer;
                    sf::Sound _moveCursorSound;
                    sf::SoundBuffer _selectCursorBuffer;
                    sf::Sound _selectCursorSound;
                private:
            };
            Cursor _cursor;
            /*              MENU SOUND              */
            sf::Music music;

            sf::Font _fontMenu;
            sf::RenderWindow _window;
            sf::Event _event;
            sf::RectangleShape *_wall;
    };
}
#endif /* !MY_SFML_HPP_ */
