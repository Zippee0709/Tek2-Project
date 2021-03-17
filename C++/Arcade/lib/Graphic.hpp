/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** IGraphic
*/

#ifndef GRAPHIC_HPP_
#define GRAPHIC_HPP_

#include <iostream>
#include <memory>
#include <string>
#include <map>
#include <iostream>
#include <chrono>
#include "IGraphic.hpp"

namespace Graphic {
    using timePoint = std::chrono::time_point<std::chrono::high_resolution_clock>;
    class Graphic : public IGraphic {
        public:
            Graphic(std::shared_ptr<timePoint>);
            ~Graphic() = default;
            virtual int createWindow(std::shared_ptr<Controller::Scene> scene,
                std::shared_ptr<int> actualGraphic, std::shared_ptr<int> actualGame,
                std::shared_ptr<int> scores) = 0;
            virtual void displayMap(std::map<int, std::map<int, char>> const &map) = 0;
            virtual void displayMenu() = 0;
            virtual void displayMenuName() = 0;
            void setMapSize(std::pair<int, int> const &mapSize);

            virtual Controller::Key getKey() = 0;
            virtual Controller::Key eventHandler() = 0;
            virtual void close() = 0;
        protected:
            std::pair<int, int> _mapSize;
            std::shared_ptr<Controller::Scene> _scene = nullptr;
            std::shared_ptr<int> _actualGraphic = nullptr;
            std::shared_ptr<int> _actualGame = nullptr;
            std::shared_ptr<timePoint> _start = nullptr;
            std::shared_ptr<int> _score = nullptr;
        private:
    };
}

#endif /* !GRAPHIC_HPP_ */
