/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Character
*/

#include "Character.hpp"
#include <unistd.h>

myGame::Character::Character(std::map<int, std::map<int, char>> const &newMap, char const who, int nb)
{
    _map = newMap;
    _me = who;
    _oldChar = ' ';
    _lastOldChar = ' ';
    setPosition(who, nb);
    _posDefault = _pos;
    _life = 3;
    _resetStatus = 0;
    _lastDirection = Controller::Key::OTHER;
}

myGame::Character::~Character()
{
}

void myGame::Character::setPosition(char const who, int nb)
{
    int pos_x = 0;
    int pos_y = 0;
    int idx = 0;

    for (auto x : _map ) {
        for (auto y : x.second) {
            if (y.second == who) {
                idx += 1;
                if (idx == nb)
                    setPosition(pos_x, pos_y + 1);
            }
            pos_y += 1;
        }
        pos_x += 1;
        pos_y = 0;
    }
}

void myGame::Character::setPosition(int x, int y)
{
    // std::cout << "x = " << x << " y = " << y << std::endl;
    _pos = std::make_pair(x, y);
}

std::pair<int, int> myGame::Character::getPosition() const
{
    return _pos;
}

std::map<int, std::map<int, char>> myGame::Character::getMap() const
{
    return _map;
}

void myGame::Character::setMap(std::map<int, std::map<int, char>> const &map) 
{
    _map = map;
}

int myGame::Character::countIntersection()
{
    int nbIntersection = 0;

    if (_map[_pos.first + 1][_pos.second] != 'x' && _map[_pos.first + 1][_pos.second] != 'd')
        nbIntersection += 1;
    if (_map[_pos.first - 1][_pos.second] != 'x' && _map[_pos.first - 1][_pos.second] != 'd')
        nbIntersection += 1;
    if (_map[_pos.first][_pos.second + 1] != 'x' && _map[_pos.first][_pos.second + 1] != 'd')
        nbIntersection += 1;
    if (_map[_pos.first][_pos.second - 1] != 'x' && _map[_pos.first][_pos.second - 1] != 'd')
        nbIntersection += 1;
    return nbIntersection;
}

Controller::Key myGame::Character::genRandom() const
{
    int random = std::rand() % 4 + 0;
    Controller::Key tmp;
   
    // std::cout << "random = " <<  random << std::endl;
    if (random == 0)
        tmp = Controller::Key::Z;
    else if (random == 1)
        tmp = Controller::Key::Q;
    else if (random == 2)
        tmp = Controller::Key::S;
    else if (random == 3)
        tmp = Controller::Key::D;
    if (_lastDirection == Controller::Key::D && tmp == Controller::Key::Q)
        return genRandom();
    if (_lastDirection == Controller::Key::Q && tmp == Controller::Key::D)
        return genRandom();
    if (_lastDirection == Controller::Key::Z && tmp == Controller::Key::S)
        return genRandom();
    if (_lastDirection == Controller::Key::S && tmp == Controller::Key::Z)
        return genRandom();
    return tmp;
}

Controller::Key myGame::Character::genRandomDirection()
{
    if (_lastDirection == Controller::Key::OTHER)
        return (genRandom());
    if (countIntersection() == 2) {
        if (_lastDirection == Controller::Key::Q && _map[_pos.first - 1][_pos.second] == 'x' && _map[_pos.first][_pos.second - 1] == 'x')
            return Controller::Key::S;
        if (_lastDirection == Controller::Key::D && _map[_pos.first - 1][_pos.second] == 'x' && _map[_pos.first][_pos.second + 1] == 'x')
            return Controller::Key::S;

        if (_lastDirection == Controller::Key::Q && _map[_pos.first + 1][_pos.second] == 'x' && _map[_pos.first][_pos.second - 1] == 'x')
            return Controller::Key::Z;
        if (_lastDirection == Controller::Key::D && _map[_pos.first + 1][_pos.second] == 'x' && _map[_pos.first][_pos.second + 1] == 'x')
            return Controller::Key::Z;

        if (_lastDirection == Controller::Key::Z && _map[_pos.first - 1][_pos.second] == 'x' && _map[_pos.first][_pos.second + 1] == 'x')
            return Controller::Key::Q;
        if (_lastDirection == Controller::Key::S && _map[_pos.first + 1][_pos.second] == 'x' && _map[_pos.first][_pos.second + 1] == 'x')
            return Controller::Key::Q;

        if (_lastDirection == Controller::Key::Z && _map[_pos.first - 1][_pos.second] == 'x' && _map[_pos.first][_pos.second - 1] == 'x')
            return Controller::Key::D;
        if (_lastDirection == Controller::Key::S && _map[_pos.first + 1][_pos.second] == 'x' && _map[_pos.first][_pos.second - 1] == 'x')
            return Controller::Key::D;
        return _lastDirection;
    }
    return genRandom();
}

bool myGame::Character::makeMove(Controller::Key key, int resetStatus, std::shared_ptr<timePoint> _start)
{

    auto tmp_end = std::chrono::high_resolution_clock::now();
    auto time_elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(tmp_end - *_start);

    // std::cout << "time in pacman = " << time_elapsed.count() << std::endl;
    // if (time_elapsed.count() >= 100) {
    //     std::cout << "time in pacman ----- = " << time_elapsed.count() << std::endl;
    //     *_start = std::chrono::high_resolution_clock::now();
    // }
    auto tmp = _lastDirection;

    if (key == Controller::Key::OTHER)
        key = _lastDirection;
    else
        _lastDirection = key;
    if (key == Controller::Key::Z) {
        if (time_elapsed.count() >= 200) {
            *_start = std::chrono::high_resolution_clock::now();
            if (moveUp(resetStatus) == false)
                _lastDirection = tmp;
            return (true);
        }
    }
    else if (key == Controller::Key::S) {
        if (time_elapsed.count() >= 200) {
            *_start = std::chrono::high_resolution_clock::now();
            if (moveDown(resetStatus) == false)
                _lastDirection = tmp;
            return (true);
        }
    }
    else if (key == Controller::Key::Q) {
        if (time_elapsed.count() >= 200) {
            *_start = std::chrono::high_resolution_clock::now();
            if (moveLeft(resetStatus) == false)
                _lastDirection = tmp;
            return (true);
        }
    }
    else if (key == Controller::Key::D) {
        if (time_elapsed.count() >= 200) {
            *_start = std::chrono::high_resolution_clock::now();
            if (moveRight(resetStatus) == false)
                _lastDirection = tmp;
            return (true);
        }
    }
    return false;
}

int myGame::Character::getResetStatus() const
{
    return _resetStatus;
}

bool myGame::Character::moveUp(int resetStatus)
{
    if (_map[_pos.first - 1][_pos.second] == 'x')
        return false;
    // std::cout << "MAP BEFOR" << std::endl;
    // for (auto x : _map ) {
    //     for (auto y : x.second) {
    //         std::cout << y.second;
    //     }
    //     std::cout << std::endl;
    // }
    // std::cout << std::endl;
    // std::cout << "_map character = " << _map[_pos.first][_pos.second] << std::endl;
    if (_me == 'C') {
        if (_map[_pos.first - 1][_pos.second] == 'G') {
            _life = 0;
            _resetStatus = 1;
            // Gestion de la vie mais ca fait bugger tout le jeu
            // _map[_pos.first][_pos.second] = ' ';
            // _pos = _posDefault;
            // _map[_pos.first][_pos.second] = 'C';
            // if (resetStatus == 1) {
            //     std::cout << "ghost c'est bien 1" << std::endl;
            //     _resetStatus = 0;
            // }
            // else
            //     _resetStatus = 1;
        }
        else {
            _map[_pos.first - 1][_pos.second] = _map[_pos.first][_pos.second];
            _map[_pos.first][_pos.second] = ' ';
            setPosition(_pos.first - 1, _pos.second);
        }
    }
    else if (_me == 'G') {
        if (_map[_pos.first - 1][_pos.second] == 'C') {
            _life = 0;
            _resetStatus = 1;
            // _map[_pos.first][_pos.second] = ' ';
            // _pos = _posDefault;
            // _map[_pos.first][_pos.second] = 'G';
            // if (resetStatus == 1)
            //     _resetStatus = 0;
            // else
            //     _resetStatus = 1;
        }
        else {
            _oldChar = _map[_pos.first - 1][_pos.second];
            _map[_pos.first - 1][_pos.second] = _map[_pos.first][_pos.second];
            _map[_pos.first][_pos.second] = _lastOldChar;
            _lastOldChar = _oldChar;
            setPosition(_pos.first - 1, _pos.second);
        }
    }
    // std::cout << "MAP AFTER" << std::endl;
    // for (auto x : _map ) {
    //     for (auto y : x.second) {
    //         std::cout << y.second;
    //     }
    //     std::cout << std::endl;
    // }
    // std::cout << std::endl;
    return true;
}

bool myGame::Character::moveDown(int resetStatus)
{
    if (_map[_pos.first + 1][_pos.second] == 'x')
        return false;
    // std::cout << "MAP BEFOR" << std::endl;
    // for (auto x : _map ) {
    //     for (auto y : x.second) {
    //         std::cout << y.second;
    //     }
    //     std::cout << std::endl;
    // }
    // std::cout << std::endl;
    // std::cout << "_map character = " << _map[_pos.first][_pos.second] << std::endl;
    if (_me == 'C') {
        if (_map[_pos.first + 1][_pos.second] == 'G') {
            _life = 0;
            _resetStatus = 1;
            // _life -= 1;
            // _map[_pos.first][_pos.second] = ' ';
            // _pos = _posDefault;
            // _map[_pos.first][_pos.second] = 'C';
            // if (resetStatus == 1) {
            //     std::cout << "ghost c'est bien 1" << std::endl;
            //     _resetStatus = 0;
            // }
            // else
            //     _resetStatus = 1;
        }
        else {
            _map[_pos.first + 1][_pos.second] = _map[_pos.first][_pos.second];
            _map[_pos.first][_pos.second] = ' ';
            setPosition(_pos.first + 1, _pos.second);
        }
    }
    else if (_me == 'G') {
        if (_map[_pos.first + 1][_pos.second] == 'C') {
            _life = 0;
            _resetStatus = 1;
            // _map[_pos.first][_pos.second] = ' ';
            // _pos = _posDefault;
            // _map[_pos.first][_pos.second] = 'G';
            // if (resetStatus == 1)
            //     _resetStatus = 0;
            // else
            //     _resetStatus = 1;
        }
        else {
            _oldChar = _map[_pos.first + 1][_pos.second];
            _map[_pos.first + 1][_pos.second] = _map[_pos.first][_pos.second];
            _map[_pos.first][_pos.second] = _lastOldChar;
            _lastOldChar = _oldChar;
            setPosition(_pos.first + 1, _pos.second);
        }
    }
    // std::cout << "MAP AFTER" << std::endl;
    // for (auto x : _map ) {
    //     for (auto y : x.second) {
    //         std::cout << y.second;
    //     }
    //     std::cout << std::endl;
    // }
    // std::cout << std::endl;
    return true;
}

bool myGame::Character::moveLeft(int resetStatus)
{
    if (_map[_pos.first][_pos.second - 1] == 'x')
        return false;
    // std::cout << "_map character = " << _map[_pos.first][_pos.second] << std::endl;
    // std::cout << "MAP BEFOR" << std::endl;
    // for (auto x : _map ) {
    //     for (auto y : x.second) {
    //         std::cout << y.second;
    //     }
    //     std::cout << std::endl;
    // }
    // std::cout << std::endl;

    // std::cout << "_map character = " << _map[_pos.first][_pos.second] << std::endl;
    if (_me == 'C') {
        if (_map[_pos.first][_pos.second - 1] == 'G') {
            _life = 0;
            _resetStatus = 1;
            // _life -= 1;
            // _map[_pos.first][_pos.second] = ' ';
            // _pos = _posDefault;
            // _map[_pos.first][_pos.second] = 'C';
            // if (resetStatus == 1) {
            //     std::cout << "ghost c'est bien 1" << std::endl;
            //     _resetStatus = 0;
            // }
            // else
            //     _resetStatus = 1;
        }
        else {
            _map[_pos.first][_pos.second - 1] = _map[_pos.first][_pos.second];
            _map[_pos.first][_pos.second] = ' ';
            setPosition(_pos.first, _pos.second - 1);
        }
    }
    else if (_me == 'G') {
        if (_map[_pos.first][_pos.second - 1] == 'C') {
            _life = 0;
            _resetStatus = 1;
            // _map[_pos.first][_pos.second] = ' ';
            // _pos = _posDefault;
            // _map[_pos.first][_pos.second] = 'G';
            // if (resetStatus == 1)
            //     _resetStatus = 0;
            // else
            //     _resetStatus = 1;
        }
        else {
            _oldChar = _map[_pos.first][_pos.second - 1];
            _map[_pos.first][_pos.second - 1] = _map[_pos.first][_pos.second];
            _map[_pos.first][_pos.second] = _lastOldChar;
            _lastOldChar = _oldChar;
            setPosition(_pos.first, _pos.second - 1);
        }
    }
    // std::cout << "MAP AFTER" << std::endl;
    // for (auto x : _map ) {
    //     for (auto y : x.second) {
    //         std::cout << y.second;
    //     }
    //     std::cout << std::endl;
    // }
    // std::cout << std::endl;

    return true;
}

bool myGame::Character::moveRight(int resetStatus)
{
    if (_map[_pos.first][_pos.second + 1] == 'x')
        return false;
    // std::cout << "_map character = " << _map[_pos.first][_pos.second] << std::endl;
    // std::cout << "MAP BEFOR" << std::endl;
    // for (auto x : _map ) {
    //     for (auto y : x.second) {
    //         std::cout << y.second;
    //     }
    //     std::cout << std::endl;
    // }

    // std::cout << std::endl;
    // std::cout << "_map character = " << _map[_pos.first][_pos.second] << std::endl;
    if (_me == 'C') {
        if (_map[_pos.first][_pos.second + 1] == 'G') {
            _life = 0;
            _resetStatus = 1;
            // _life -= 1;
            // _map[_pos.first][_pos.second] = ' ';
            // _pos = _posDefault;
            // _map[_pos.first][_pos.second] = 'C';
            // if (resetStatus == 1) {
            //     std::cout << "ghost c'est bien 1" << std::endl;
            //     _resetStatus = 0;
            // }
            // else
            //     _resetStatus = 1;
        } else {
            _map[_pos.first][_pos.second + 1] = _map[_pos.first][_pos.second];
            _map[_pos.first][_pos.second] = ' ';
            setPosition(_pos.first, _pos.second + 1);
        }
    }
    else if (_me == 'G') {
        if (_map[_pos.first][_pos.second + 1] == 'C') {
            _life = 0;
            _resetStatus = 1;
            // _map[_pos.first][_pos.second] = ' ';
            // _pos = _posDefault;
            // _map[_pos.first][_pos.second] = 'G';
            // if (resetStatus == 1)
            //     _resetStatus = 0;
            // else
            //     _resetStatus = 1;
        }
        else {
            _oldChar = _map[_pos.first][_pos.second + 1];
            _map[_pos.first][_pos.second + 1] = _map[_pos.first][_pos.second];
            _map[_pos.first][_pos.second] = _lastOldChar;
            _lastOldChar = _oldChar;
            setPosition(_pos.first, _pos.second + 1);
        }
    }
    // std::cout << "MAP AFTER" << std::endl;
    // for (auto x : _map ) {
    //     for (auto y : x.second) {
    //         std::cout << y.second;
    //     }
    //     std::cout << std::endl;
    // }
    // std::cout << std::endl;
    return true;
}