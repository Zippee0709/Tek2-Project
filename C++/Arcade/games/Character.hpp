/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Character
*/

#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

#include "../lib/Key.hpp"
#include <map>
#include <iostream>
#include <string>
#include <chrono>
#include <memory>

namespace myGame {
    using timePoint = std::chrono::time_point<std::chrono::high_resolution_clock>;
    class Character {
        public:
            Character(std::map<int, std::map<int, char>> const &_map, char const who, int nb);
            ~Character();

            bool makeMove(Controller::Key key, int resetStatus, std::shared_ptr<timePoint>);

            void setPosition(int x, int y);
            std::pair<int, int> getPosition() const;

            std::map<int, std::map<int, char>> getMap() const;
            void setMap(std::map<int, std::map<int, char>> const &map);

            Controller::Key genRandomDirection();
            void aStar(std::pair<int, int> const &player);

            int getResetStatus() const;
        protected:
            bool moveUp(int resetStatus);
            bool moveDown(int resetStatus);
            bool moveLeft(int resetStatus);
            bool moveRight(int resetStatus);

            Controller::Key genRandom() const;

            int countIntersection();

            void setPosition(char const who, int nb);
            std::map<int, std::map<int, char>> _map;
            std::pair<int, int> _pos;
            std::pair<int, int> _posDefault;
            Controller::Key _lastDirection;
            
            char _me;
            char _oldChar;
            char _lastOldChar;
            int _speed;
            int _life;
            int _resetStatus;
    };
}
#endif /* !CHARACTER_HPP_ */