/*
** EPITECH PROJECT, 2020
** indie
** File description:
** Creates a new map
*/

#include "Map.hpp"

namespace IndieStudio {

    Map::Map(int size) : _size(size)
    {
        createNewMap(size);
    }

    bool Map::isThatCorner(int i, int j, int size)
    {
        size -= 1;
        if ((i == 0 && j == 0) || (i == 1 && j == 0) ||(i == 0 && j == 1))
            return true;
        else if ((i == 0 && j == size) || (i == 1 && j == size) ||(i == 0 && j == size - 1))
            return true;
        else if ((i == size && j == size) || (i == size - 1 && j == size) ||(i == size && j == size - 1))
            return true;
        else if ((i == size && j == 0) || (i == size - 1 && j == 0) ||(i == size && j == 1))
            return true;
        return false;
    }

    bool Map::placeSolid(int i, int j)
    {
        int rdm = rand() % 100 + 1;

        if (i % 2 == 0 && j % 2 != 0 && rdm <= _solidChance)
            return true;
        return false;
    }

    bool Map::placeCrate()
    {
        int rdm = rand() % 100 + 1;

        if (rdm <= _crateChance)
            return true;
        return false;
    }

    void Map::createNewMap(int size)
    {
        srand((unsigned)time(NULL));
        for (int i = 0; i != size; i++) {
            for (int j = 0; j != size; j++) {
                _map[i][j] = '.';
                if (placeCrate())
                    _map[i][j] = 'c';
                if (placeSolid(i, j))
                    _map[i][j] = 'u';
                if (isThatCorner(i, j, size))
                    _map[i][j] = '.';
            }
        }
    }

    std::map<int, std::map<int, char>> Map::getMap() const
    {
        return _map;
    }
}