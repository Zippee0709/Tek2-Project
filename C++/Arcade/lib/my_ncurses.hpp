/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** my_ncurse
*/

#ifndef MY_NCURSE_HPP_
#define MY_NCURSE_HPP_

#include <ncurses.h>
#include "Key.hpp"
#include "Graphic.hpp"
#include <string>
#include <vector>
#include <map>
#include <iostream>

namespace Graphic {
    class Ncurses : public Graphic {
        public:
            Ncurses(std::map<int, std::string>, std::map<int, std::string>, std::shared_ptr<timePoint>);
            int createWindow(std::shared_ptr<Controller::Scene>,
                std::shared_ptr<int> actualGraphic, std::shared_ptr<int> actualGame,
                std::shared_ptr<int> score);
            void displayMap(std::map<int, std::map<int, char>> const &map);
            Controller::Key eventHandler();
            void displayMenu();
            void displayMenuName();
            Controller::Key getKey();
            void close();
            ~Ncurses();
        private:
            std::map<int, std::string> _graphList;
            std::map<int, std::string> _gameList;
            WINDOW *_window;
    };
}

#endif /* !MY_NCURSE_HPP_ */
