/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** IGraphic
*/

#ifndef IGRAPHIC_HPP_
#define IGRAPHIC_HPP_

#include <iostream>
#include <memory>
#include "Key.hpp"
#include "Scene.hpp"

namespace Graphic {
    class IGraphic {
        public:
            virtual ~IGraphic(){};
            // virtual int createWindow(std::pair<int, int> const &mapSize) = 0;
            virtual Controller::Key eventHandler() = 0;
            virtual int createWindow(std::shared_ptr<Controller::Scene>,
            // std::shared_ptr<int> actualGraphic, std::shared_ptr<int> actualGame) = 0;
            std::shared_ptr<int> actualGraphic, std::shared_ptr<int> actualGame,
            std::shared_ptr<int> score) = 0;
            // virtual int eventHandler() = 0;
            virtual void setMapSize(std::pair<int, int> const &mapSize) = 0;
        protected:
        private:
    };
}

#endif /* !IGRAPHIC_HPP_ */
