/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** my_sfml
*/

#include <SFML/Window.hpp>
#include <iostream>
#include <unistd.h>
#include "../core/Error.hpp"
#include "Graphic.hpp"
#include "my_sfml.hpp"

Graphic::Sfml::Sfml(std::map<int, std::string> graphList, std::map<int, std::string> gameList
    , std::shared_ptr<timePoint> start) 
    : Graphic::Graphic(start), _graphList(graphList), _gameList(gameList)
{
    _wall = nullptr;
    _fontMenu.loadFromFile("./lib/font/ARCADE_I.TTF");
    // _window.create(sf::VideoMode(600, 800, 32), "Arcade");
}

Graphic::Sfml::~Sfml()
{
}

void Graphic::Sfml::loadCursor()
{
    _cursor.init(this);
    _cursor._shape.setRadius(20);
    _cursor._shape.setPointCount(3);
    _cursor._shape.setPosition(_cursor._gamePosition.begin()->second.x,
        _cursor._gamePosition.begin()->second.y);
    _cursor._shape.setRotation(90);
}

void Graphic::Sfml::loadMenuName()
{
    sf::Vector2u windowSize = _window.getSize();

    _playerNameText.setFont(_fontMenu);
    _playerNameText.setCharacterSize(80);
    _playerNameText.setPosition(sf::Vector2f((_window.getSize().x / 2) - ((_playerName.getSize() / 2) * _playerNameText.getCharacterSize()),
        (_window.getSize().y / 2)));
    _rectangleName.setSize(sf::Vector2f(windowSize.x - windowSize.x * 0.1, windowSize.y - windowSize.y * 0.8));
    _rectangleName.setFillColor(sf::Color::Transparent);
    _rectangleName.setOutlineColor(sf::Color::Green);
    _rectangleName.setOutlineThickness(1);
    _rectangleName.setPosition(sf::Vector2f((windowSize.x / 2) -(_rectangleName.getSize().x / 2),
         (windowSize.y / 2) - (_rectangleName.getSize().y / 2)));
}

void Graphic::Sfml::loadMenu()
{
    sf::Vector2u windowSize = _window.getSize();
    int offsize = 30;
    int counter = 0;

    _rectangleGame = createRectangle(sf::Vector2f(windowSize.x / 3, windowSize.y - windowSize.y * 0.4),
        sf::Vector2f(windowSize.x * 0.05, windowSize.y * 0.05),
        sf::Color::Transparent);

    _rectangleGraph = createRectangle(sf::Vector2f(windowSize.x / 3, windowSize.y - windowSize.y * 0.4),
        sf::Vector2f(windowSize.x - windowSize.x * 0.05 - windowSize.x / 3, windowSize.y * 0.05),
        sf::Color::Transparent);

    _playerNameText.setCharacterSize(50);
    _playerNameText.setPosition(sf::Vector2f((windowSize.x / 2) - ((_playerName.getSize() / 2) * _playerNameText.getCharacterSize()),
        (windowSize.y / 2) - 300));

    _welcomeText.setCharacterSize(50);
    _welcomeText.setString("Welcome");
    _welcomeText.setFont(_fontMenu);
    _welcomeText.setPosition(sf::Vector2f((_window.getSize().x / 2) - ((_welcomeText.getString().getSize() / 2) * _welcomeText.getCharacterSize()) - 20,
        _playerNameText.getPosition().y - _playerNameText.getCharacterSize() - 15));

    _scoreText.setCharacterSize(50);
    _scoreText.setString("Score");
    _scoreText.setFont(_fontMenu);
    _scoreText.setPosition(sf::Vector2f((_window.getSize().x / 2) - ((_scoreText.getString().getSize() / 2) * _scoreText.getCharacterSize()) - 20,
        _playerNameText.getPosition().y - _playerNameText.getCharacterSize() + 200));

    _scoreValueText.setCharacterSize(50);
    _scoreValueText.setString(std::to_string(*_score));
    _scoreValueText.setFont(_fontMenu);
    _scoreValueText.setPosition(sf::Vector2f((_window.getSize().x / 2) - ((_scoreValueText.getString().getSize() / 2) * _scoreValueText.getCharacterSize()) - 20,
        _playerNameText.getPosition().y - _playerNameText.getCharacterSize() + 260));

    _pressSpaceText.setCharacterSize(80);
    _pressSpaceText.setString("Press \"Space\" to start");
    _pressSpaceText.setFont(_fontMenu);
    _pressSpaceText.setPosition(sf::Vector2f((_window.getSize().x / 2) - ((_pressSpaceText.getString().getSize() / 2) * _pressSpaceText.getCharacterSize()),
        (_window.getSize().y - _pressSpaceText.getCharacterSize() - 10)));

    for (auto graph : _graphList) {
        sf::Text text(graph.second.substr(15), _fontMenu, 20);
        text.setPosition(_rectangleGraph.getPosition().x + 50, _rectangleGraph.getPosition().y + 10 + offsize);
        text.setFillColor(counter == *_actualGraphic ? sf::Color::Red : sf::Color::White);
        offsize += 30;
        _graphTextList.insert(std::pair<int, sf::Text>(counter, text));
        counter += 1;
    }
    offsize = 30;
    counter = 0;
    for (auto game : _gameList) {
        sf::Text text(game.second.substr(17), _fontMenu, 20);
        text.setPosition(_rectangleGame.getPosition().x + 50, _rectangleGame.getPosition().y + 10 + offsize);
        text.setFillColor(counter == *_actualGame ? sf::Color::Red : sf::Color::White);
        offsize += 30;
        _gameTextList.insert(std::pair<int, sf::Text>(counter, text));
        counter += 1;
    }
}

void Graphic::Sfml::loadBackground()
{
    if (!_backgroundTexture.loadFromFile("lib/img/retro.jpg")) {
        throw("ERROR SFML BACKGROUND IMAGE NOT FOUND");
    }
    if (!_starsTexture.loadFromFile("lib/img/stars.png")) {
        throw("ERROR SFML BACKGROUND IMAGE NOT FOUND");
    }
    _backgroundSprite.setTexture(_backgroundTexture);
    _backgroundSprite.setScale(4.5, 4.5);
    _backgroundSprite.setOrigin(0, 0);
    _starsIntRect = {4000, 4000, 1920, 500};
    _starsSprite.setTexture(_starsTexture);
    _starsSprite.setTextureRect(_starsIntRect);
}

void Graphic::Sfml::displayMap(std::map<int, std::map<int, char>> const &map)
{
    // std::cout << "Sfml : Try to display map" << std::endl;
    int posx = 0;
    int posy = 0;

    // std::cout << "SMFL MAP DISPLAY" << std::endl;
    // for (auto x : map ) {
    //     for (auto y : x.second) {
    //         std::cout << y.second;
    //     }
    //     std::cout << std::endl;
    // }
    // std::cout << std::endl;
    // _player.moveEffect(43, 120);
    // _ghost[0].moveEffect(43, 80);
    _window.clear();
    for (auto x : map ) {
        for (auto y : x.second) {
            if (y.second == 'x') {
                _wall->setPosition((posx * _wall->getSize().x), (posy * _wall->getSize().y));
                _window.draw(*_wall);
            }
            if (y.second == 'C') {
                // std::cout << "ok it C" << std::endl;
                // std::cout << "posx = " << posx * _wall->getSize().x << " posy = " << posy * _wall->getSize().y << std::endl;
                _player.setPosition(posx * _wall->getSize().x, posy * _wall->getSize().y);
                _window.draw(_player.getSprite());
            }
            if (y.second == 'G') {
                _ghost[0].setPosition(posx * _wall->getSize().x, posy * _wall->getSize().y);
                _window.draw(_ghost[0].getSprite());
            }
            // bizarre ce truc faut le changer
            posx += 1;
            if (y.second == 'p') {
                _pacGum.setPosition(posx * _wall->getSize().x - 40, posy * _wall->getSize().y + 20);
                _window.draw(_pacGum.getSprite());
            }
            if (y.second == 'P') {
                _pacPower.setPosition(posx * _wall->getSize().x - 50, posy * _wall->getSize().y + 15);
                _window.draw (_pacPower.getSprite());
            }
        }
        posx = 0;
        posy += 1;
    }
    // displayObject(map);
    _window.display();
}

void Graphic::Sfml::displayObject(std::map<int, std::map<int, char>> const &map)
{    
    int posx = 0;
    int posy = 0;

    // _player.moveEffect();

    // for (auto x : map ) {
    //     for (auto y : x.second) {
    //         if (y.second == 'C') {
    //             // std::cout << "ok it C" << std::endl;
    //             // std::cout << "posx = " << posx * 40 << "posy = " << posy * 40 << std::endl;
    //             _player.setPosition(posx * 40, posy * 40);
    //             _window.draw(_player.getSprite());
    //         }
    //         posx += 1;
    //     }
    //     posx = 0;
    //     posy += 1;
    // }
}

void Graphic::Sfml::launchGame()
{
     initPacmanScene();
     music.stop();
     *_scene = Controller::Scene::PACMAN;
}

Controller::Key Graphic::Sfml::eventHandler()
{
    while (_window.pollEvent(_event))
    {
        if (_event.type == sf::Event::Closed) {
            close();
            return Controller::Key::CLOSE;
        }
        if (*_scene == Controller::Scene::MENU)
            menuEventHandler();
        if (*_scene == Controller::Scene::NAME)
            menuNameEventHandler();
        if (_event.type == sf::Event::KeyPressed) {
            // keyHandler();
            return getKey();
        }
    }
    _window.display();
    return Controller::Key::OTHER;
}

void Graphic::Sfml::menuNameEventHandler()
{
    if (_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::Return) {
        initMenuScene();
        *_scene = Controller::Scene::MENU;
    }
    if (_event.type == sf::Event::TextEntered) {
        if (_playerName.getSize() >= 8 && _event.text.unicode != 8)
            return;
        if (_event.text.unicode == 8 && _playerName.getSize() > 0) {
                _playerName.erase(_playerName.getSize() - 1);
        } else if (_event.text.unicode >= 32 && _event.text.unicode <= 126) 
            _playerName += _event.text.unicode;
        _playerNameText.setString(_playerName);
        _playerNameText.setPosition((sf::Vector2f((_window.getSize().x / 2) - ((_playerName.getSize() / 2) * _playerNameText.getCharacterSize()),
        (_window.getSize().y / 2))));
    }
}

void Graphic::Sfml::menuEventHandler()
{
    if (_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::Z) {
        _cursor.checkVertical(true);
    }
    if (_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::S) {
        _cursor.checkVertical(false);
    }
    if (_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::Q) {
        _cursor.checkHorizontal(true);
    }
    if (_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::D) {
        _cursor.checkHorizontal(false);
    }
    if (_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::Return) {
        selectLib();
    }
    if (_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::Space) {
        launchGame();
    }
}

void Graphic::Sfml::close()
{
    _window.close();
}

Controller::Key Graphic::Sfml::getKey()
{
    switch (_event.key.code) {
        case sf::Keyboard::Escape:
            _window.close();
            return Controller::Key::CLOSE;
        case sf::Keyboard::Z:
            return Controller::Key::Z;
        case sf::Keyboard::Q:
            return Controller::Key::Q;
        case sf::Keyboard::S:
            return Controller::Key::S;
        case sf::Keyboard::D:
            return Controller::Key::D;
        case sf::Keyboard::N:
            return Controller::Key::N;
        case sf::Keyboard::Space:
            return Controller::Key::SPACE;
        case sf::Keyboard::Tab:
            return Controller::Key::TAB;
        default:
            return Controller::Key::OTHER;
    }
}

void Graphic::Sfml::updateShape()
{
    sf::Vector2u winSize = _window.getSize();
    float x = winSize.x / _mapSize.first;
    float y = winSize.y / _mapSize.second;
    sf::Vector2f wallSize(x, y);
    if (_wall != nullptr)
        delete _wall;
    _wall = new sf::RectangleShape(wallSize);
    _wall->setPosition(0, 0);
    _wall->setFillColor(sf::Color(0, 50, 255));
}

void Graphic::Sfml::createPlayer()
{
    _player.setTexture("pacman.png", sf::IntRect(750, 40, 40, 510));
    _player.setSprite(sf::IntRect(0, 0, 40, 40));
    _ghost[0].setTexture("pacman.png", sf::IntRect(710, 40, 40, 335));
    _ghost[0].setSprite(sf::IntRect(0, 0, 40, 40));
    _pacGum.setTexture("pacman.png", sf::IntRect(378, 216, 10, 10));
    _pacGum.setSprite(sf::IntRect(0, 0, 10, 10));
    _pacPower.setTexture("pacman.png", sf::IntRect(510, 550, 25, 25));
    _pacPower.setSprite(sf::IntRect(0, 0, 25, 25));
}

void Graphic::Sfml::initMenuScene()
{
    loadBackground();
    loadMenu();
    loadCursor();
    loadCursorSound();
}

void Graphic::Sfml::initMenuNameScene()
{
    loadBackground();
    loadMenuName();
    playMusic();
}

void Graphic::Sfml::initPacmanScene()
{
    createPlayer();
    updateShape();
}

int Graphic::Sfml::createWindow(std::shared_ptr<Controller::Scene> scene,
                std::shared_ptr<int> actualGraphic, std::shared_ptr<int> actualGame,
                std::shared_ptr<int> score)
{
    _scene = scene;
    _actualGame = actualGame;
    _actualGraphic = actualGraphic;
    _score = score;

    _window.create(sf::VideoMode(1920, 1080, 32), "Arcade");
    _window.setFramerateLimit(60);
    updateShape();

    if (*_scene == Controller::Scene::PACMAN) {
        initPacmanScene();
    }
    if (*_scene == Controller::Scene::MENU) {
        initMenuScene();
    }
    if (*_scene == Controller::Scene::NAME) {
        initMenuNameScene();
    }
    return 1;
}

// void Graphic::Sfml::setMapSize(std::pair<int, int> const &mapSize) 
// {
//     _mapSize = mapSize;
// }
// void Graphic::Sfml::drawMenu()
// {
//     for (int i = 0; i < 3; i++) {
//         _window.draw()
//     }
// }

void Graphic::Sfml::selectLib()
{
    _cursor._selectCursorSound.play();
    if (_cursor._isGameTab) {
        _gameTextList[*_actualGraphic].setFillColor(sf::Color::White);
        *_actualGame = _cursor._actualPosition;
        _gameTextList[_cursor._actualPosition].setFillColor(sf::Color::Red);
        return;
    }
    _graphTextList[*_actualGraphic].setFillColor(sf::Color::White);
    *_actualGraphic = _cursor._actualPosition;
    _graphTextList[_cursor._actualPosition].setFillColor(sf::Color::Red);
}

sf::RectangleShape Graphic::Sfml::createRectangle(sf::Vector2f size, sf::Vector2f position, sf::Color color)
{
    sf::RectangleShape rectangle(size);
    rectangle.setFillColor(color);
    rectangle.setOutlineColor(sf::Color::Red);
    rectangle.setOutlineThickness(1);
    rectangle.setPosition(position.x, position.y);

    return rectangle;
}

void Graphic::Sfml::displayMenu()
{
    _window.clear();
    _window.draw(_backgroundSprite);
    displayStars();
    _window.draw(_rectangleGame);
    _window.draw(_rectangleGraph);
    _window.draw(_welcomeText);
    _window.draw(_scoreText);
    _window.draw(_scoreValueText);
    for (auto graphText : _graphTextList) {
        _window.draw(graphText.second);
    }
    for (auto gameText : _gameTextList) {
        _window.draw(gameText.second);
    }
    _window.draw(_cursor._shape);
    textAnimationRendering();
}

void Graphic::Sfml::textAnimationRendering()
{
    auto end = std::chrono::high_resolution_clock::now();
    if (std::chrono::duration_cast<std::chrono::microseconds>(end - *_start).count() > 100) {
        if (_flashText >= 50) {
            _pressSpaceText.setFillColor(sf::Color(255, 255, 255, _flashText));
            _flashText -= 4;
        } else {
            _flashText = 255; 
        }
        if (_colorIndex < 4) {
            _playerNameText.setFillColor(_colors[_colorIndex]);
            _colorIndex +=1;
        } else {
            _colorIndex = 0;
        }
        // *_start = std::chrono::high_resolution_clock::now();
    }
    _window.draw(_pressSpaceText);
    _window.draw(_playerNameText);
}

void Graphic::Sfml::displayStars()
{
    auto end = std::chrono::high_resolution_clock::now();

    if (std::chrono::duration_cast<std::chrono::microseconds>(end - *_start).count() > 100) {
        if (_starsIntRect.top <= 10) {
            _starsIntRect.top = 3300;
            _starsIntRect.left = 3300;
        }
        else {
            _starsIntRect.top -= 5;
            _starsIntRect.left -= 5;
        }
        _starsSprite.setTextureRect(_starsIntRect);
        if (_flashText >= 50) {
            _pressSpaceText.setFillColor(sf::Color(255, 255, 255, _flashText));
            _flashText -= 4;
        } else {
            _flashText = 255; 
        }
        
        // *_start = std::chrono::high_resolution_clock::now();
    }
    _window.draw(_starsSprite);
}

void Graphic::Sfml::displayMenuName()
{
    std::string text("Enter Your Name");
    sf::Text menuNameText(text, _fontMenu, 80);

    _window.clear();
    _window.draw(_backgroundSprite);
    menuNameText.setPosition(sf::Vector2f((_window.getSize().x / 2) - ((text.length() / 2) * menuNameText.getCharacterSize()),
        (_window.getSize().y / 2) - _rectangleName.getSize().y));
    _window.draw(menuNameText);
    _window.draw(_playerNameText);
    _window.draw(_rectangleName);
    displayStars();
}

void Graphic::Sfml::playMusic()
{
    if (!music.openFromFile("lib/sound/menu_music.wav"))
        throw("Error Music");
    music.play();
    music.setLoop(true);
}

void Graphic::Sfml::loadCursorSound()
{
    if (!_cursor._moveCursorBuffer.loadFromFile("lib/sound/menu_move.wav"))
        throw("Error Music");
    if (!_cursor._selectCursorBuffer.loadFromFile("lib/sound/menu_select.wav"))
        throw("Error Music");
    _cursor._moveCursorSound.setBuffer(_cursor._moveCursorBuffer);
    _cursor._selectCursorSound.setBuffer(_cursor._selectCursorBuffer);
}


void Graphic::Sfml::selectGraphics(const std::vector<std::string> &graphics)
{
}

extern "C" Graphic::Graphic *createLib(std::map<int, std::string> graphList, std::map<int, std::string> gameList, std::shared_ptr<Graphic::timePoint> start)
{
    std::cout << "createLib SFML" << std::endl;
    return new Graphic::Sfml(graphList, gameList, start);
}