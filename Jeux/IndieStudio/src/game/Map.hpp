/*
** EPITECH PROJECT, 2020
** Map
** File description:
** indie
*/

#pragma once

#include <map>
#include <stdlib.h>
#include <time.h>
#include <iostream>

namespace IndieStudio {
    class Map {
        public:
            Map(int size = 20);
            ~Map() {};
            void displayMap();
            int getSize() {return _size;};
            void createNewMap(int size);
            bool isThatCorner(int i, int j, int size);
            bool placeSolid(int i, int j);
            bool placeCrate();

            std::map<int, std::map<int, char>> getMap() const;

        protected:
        private:
            std::map<int, std::map<int, char>> _map;
            int _size;
            int _solidChance = 100;
            int _crateChance = 100;
    };
}
