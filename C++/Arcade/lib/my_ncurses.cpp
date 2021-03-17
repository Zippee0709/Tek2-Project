/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** my_ncurse
*/

#include <ncurses.h>
#include <iostream>
#include "my_ncurses.hpp"

Graphic::Ncurses::Ncurses(std::map<int, std::string> graphList, std::map<int, std::string> gameList,
    std::shared_ptr<timePoint> start)
    : Graphic::Graphic(start), _graphList(graphList), _gameList(gameList)
{
    // createWindow();
}

Graphic::Ncurses::~Ncurses()
{
}

void Graphic::Ncurses::displayMap(std::map<int, std::map<int, char>> const &map)
{
    // std::cout << "Ncurses : Try to display map" << std::endl;
    clear();
    for (auto x : map ) {
        for (auto y : x.second) {
            printw("%c", y.second);
        }
        printw("\n");
    }
    printw("\n");
    // printw("Hello");
    refresh();
}

int Graphic::Ncurses::createWindow(std::shared_ptr<Controller::Scene> scene,
                std::shared_ptr<int> actualGraphic, std::shared_ptr<int> actualGame,
                std::shared_ptr<int> score)
{
    _scene = scene;
    _score = score;
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    _window = newwin(0, 0, 0, 0);
    refresh();

    return 1;
}

Controller::Key Graphic::Ncurses::eventHandler()
{
    // wprintw(_window, "OK");
    // wrefresh(_window);
    return getKey();
}

void Graphic::Ncurses::close()
{
    endwin();
}

Controller::Key Graphic::Ncurses::getKey()
{
    switch(getch()) {
        case 27: // NOTE : 27 == ESCAPE KEY
            endwin();
            return Controller::Key::CLOSE;
        case 'z':
            wprintw(_window, "Z");
            return Controller::Key::Z;
        case 'q':
            wprintw(_window, "Q");
            return Controller::Key::Q;
        case 's':
            wprintw(_window, "S");
            return Controller::Key::S;
        case 'd':
            wprintw(_window, "D");
            return Controller::Key::D;
        case 'n':
            return Controller::Key::N;
        case ' ':
            return Controller::Key::SPACE;
        default:
            wclear(_window);
            return Controller::Key::OTHER;
    }
}

void Graphic::Ncurses::displayMenu()
{
    
}

void Graphic::Ncurses::displayMenuName()
{
    
}

extern "C" Graphic::Graphic *createLib(std::map<int, std::string> graphList, std::map<int, std::string> gameList,
    std::shared_ptr<Graphic::timePoint> start)
{
    std::cout << "createLib Ncurses" << std::endl;
    return new Graphic::Ncurses(graphList, gameList, start);
}
