/*
** EPITECH PROJECT, 2020
** pac
** File description:
** man
*/

#pragma once

#include <string>
#include <memory>
#include <fstream>
#include <iostream>
#include <map>
#include <ncurses.h>
#include <unistd.h>


class Character {
    public:
        Character();
        ~Character();
    protected:
};

class Pacman {
    public:
        Pacman() {};
        ~Pacman() {};
        enum Direction{
            NONE,
            LEFT,
            UP,
            RIGHT,
            DOWN
        };
        int getY() const { return _posX; }
        int getX() const { return _posY; }
        Direction getDirection() const { return _dir; }
        void setDirection(Direction dir) { _dir = dir; }
        void setPos(int X, int Y) {
            _posX = X;
            _posY = Y;
        }
    protected:
    private:
        int _points = 0;
        int _lifes = 3;
        int _posX = 14;
        int _posY = 21;
        Direction _dir = NONE;
};

class Game {
    public:
        Game() { createMap("pac_map.txt"); }
        ~Game() {}
        void displayMap();
        void cmdDisplayMap();
        void createMap(std::string const &filename);
        void parseDataInMap(std::string const &data);
        Pacman pac;
        std::map<int, std::map<int, char>> _map;
        enum Status {
            PLAYING,
            END
        };
        void setGameStatus(Status newStatus) { _status = newStatus; }
        Status getGameStatus() const { return _status; }
    private:
        std::pair<int , int> _mapSize;
        Status _status = PLAYING;
};