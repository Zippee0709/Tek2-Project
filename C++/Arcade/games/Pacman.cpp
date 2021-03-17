/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Pacman
*/

#include "Pacman.hpp"

myGame::Pacman::Pacman(std::shared_ptr<timePoint> start, std::shared_ptr<int> score)
    : myGame::Game::Game(start, score)
{
    _player = new myGame::Character(_map, 'C', 1);
    _ghost[0] = new myGame::Character(_map, 'G', 1);
    _ghost[1] = new myGame::Character(_map, 'G', 2);
    _ghost[2] = new myGame::Character(_map, 'G', 3);
    _ghost[3] = new myGame::Character(_map, 'G', 4);
}

myGame::Pacman::~Pacman()
{
    delete _player;
    delete _ghost[0];
    delete _ghost[1];
    delete _ghost[2];
    delete _ghost[3];
}

bool myGame::Pacman::updateGame(Controller::Key key)
{
    if (_player->getResetStatus() == 1)
        std::cout << "exit le jeu" << std::endl;

    updatePlayer(key, _ghost[0]->getResetStatus());

    // auto tmp_end = std::chrono::high_resolution_clock::now();
    // auto time_elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(tmp_end - *_start);

    // std::cout << "time in pacman = " << time_elapsed.count() << std::endl;
    // if (time_elapsed.count() >= 100) {
    //     std::cout << "time in pacman ----- = " << time_elapsed.count() << std::endl;
    //     *_start = std::chrono::high_resolution_clock::now();
    // }
    // auto end = std::chrono::high_resolution_clock::now();
    // if (std::chrono::duration_cast<std::chrono::milliseconds>(end - *_start).count() > 500) {
    //     updatePlayer(key, _ghost[0]->getResetStatus());
    //     // *_start = std::chrono::high_resolution_clock::now();
    // }
    // if (std::chrono::duration_cast<std::chrono::milliseconds>(end - *_start).count() > 100) {
    //     updateGhost(key, _player->getResetStatus());
    //     *_start = std::chrono::high_resolution_clock::now();
    // }
    // updateObject(key);
    return true;
}

bool myGame::Pacman::updatePlayer(Controller::Key const &key, int resetStatus)
{
    _player->setMap(_map);
    if (_player->makeMove(key, resetStatus, _start) == true) {
        _map = _player->getMap();
        return true;
    }
    return false;
}

bool myGame::Pacman::updateObject(Controller::Key const &key)
{
    return true;   
}

bool myGame::Pacman::updateGhost(Controller::Key const &key, int resetStatus)
{
    // _ghost[0]->setMap(_map);
    // if (_ghost[0]->makeMove(_ghost[0]->genRandomDirection()) == true) {
    //     _map = _ghost[0]->getMap();
    // }
    _ghost[0]->setMap(_map);
    if (_ghost[0]->makeMove(_ghost[0]->genRandomDirection(), resetStatus, _start) == true) {
        _map = _ghost[0]->getMap();
    }
    // _ghost[1]->setMap(_map);
    // if (_ghost[1]->makeMove(_ghost[1]->genRandomDirection()) == true) {
    //     _map = _ghost[1]->getMap();
    // }
    // _ghost[2]->setMap(_map);
    // if (_ghost[2]->makeMove(_ghost[2]->genRandomDirection()) == true) {
    //     _map = _ghost[2]->getMap();
    // }
    // _ghost[3]->setMap(_map);
    // if (_ghost[3]->makeMove(_ghost[3]->genRandomDirection()) == true) {
    //     _map = _ghost[3]->getMap();
    // }
    return true;
}

std::map<int, std::map<int, char>> myGame::Pacman::getMap() const
{
    return _map;
}

std::pair<int, int> myGame::Pacman::getMapSize() const
{
    return _mapSize;
}

extern "C" myGame::Game *createGame(std::shared_ptr<myGame::timePoint> start,
    std::shared_ptr<int> score)
{
    std::cout << "createGame Pacman" << std::endl;
    return new myGame::Pacman(start, score);
}

