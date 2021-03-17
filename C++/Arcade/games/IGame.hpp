/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** IGame interface class
*/

#ifndef IGAME_HPP_
#define IGAME_HPP_

#include "../lib/Key.hpp"
#include <chrono>

namespace myGame {
    class Game;
}

namespace myGame {
    class IGame {
        public:
            virtual ~IGame() {};
            virtual bool updateGame(Controller::Key key) = 0;
        private:
    };
}
#endif /* !IGAME_HPP_ */