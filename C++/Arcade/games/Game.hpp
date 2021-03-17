/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Game abstraite class
*/

#ifndef GAME_HPP_
#define GAME_HPP_

#include "IGame.hpp"
#include "Character.hpp"
#include <string>
#include <map>
#include <iostream>
#include <memory>
#include <fstream>

namespace myGame {
    using timePoint = std::chrono::time_point<std::chrono::high_resolution_clock>;
    class Game : public IGame {
        public:
            Game(std::shared_ptr<timePoint>, std::shared_ptr<int>);
            virtual bool updateGame(Controller::Key key) = 0;
            virtual std::pair<int, int> getMapSize() const = 0;
            virtual std::map<int, std::map<int, char>> getMap() const = 0;
            ~Game();
        protected:
            std::map<int, std::map<int, char>> _map;
            std::pair<int , int> _mapSize;
            std::shared_ptr<timePoint> _start = nullptr;
            std::shared_ptr<int> _score = nullptr;
        private:
            void parseDataInMap(std::string const &data);
            void createMap(std::string const &filename);
    };
}

#endif /* !GAME_HPP_ */