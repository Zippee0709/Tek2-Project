/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Game
*/

#include "Game.hpp"

myGame::Game::Game(std::shared_ptr<timePoint> start, std::shared_ptr<int> score)
    : _start(start), _score(score)
{
    createMap("pac_map.txt");
}

myGame::Game::~Game()
{
}

std::map<int, std::map<int, char>> myGame::Game::getMap() const
{
    std::cout << "return map from Game class" << std::endl;
    return _map;
}

void myGame::Game::createMap(std::string const &filename)
{
    std::ifstream file(filename);
    std :: string line;
    std::string data = "";

    if (file) {
        while (getline(file, line))
            data += line + "\n";
    } else {
        std :: cerr << "Error: "<< filename << " not found !" << std :: endl;
        return;
    }
    file.close();
    parseDataInMap(data);
}

void myGame::Game::parseDataInMap(std::string const &data)
{
    int x = 0;
    int y = 0;
    int max_x = 0;
    int max_y = 0;

    for (char c: data) {
        if (c != '\n' && c != '\0')
            _map[x][y] = c;
        else {
            _map[x][y] = '\0';
            x += 1;
            max_y = y - 1;
            y = 0;
        }
        y += 1;
    }
    max_x = x - 1;
    _mapSize = std::make_pair(max_x, max_y);
}