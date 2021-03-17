/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Pacman
*/

#ifndef PACMAN_HPP_
#define PACMAN_HPP_

#include "Game.hpp"

namespace myGame {
    class Pacman : public Game
    {
        public:
            Pacman(std::shared_ptr<timePoint>, std::shared_ptr<int>);
            bool updateGame(Controller::Key key);
            std::map<int, std::map<int, char>> getMap() const;
            std::map<int, std::map<int, char>> tmp_map() const;
            std::pair<int, int> getMapSize() const;
            ~Pacman();
        private:
            Character *_player;
            std::map<int, Character *> _ghost;
            bool updatePlayer(Controller::Key const &key, int reset);
            bool updateGhost(Controller::Key const &key, int reset);
            bool updateObject(Controller::Key const &key);
    };
}

#endif /* !PACMAN_HPP_ */
