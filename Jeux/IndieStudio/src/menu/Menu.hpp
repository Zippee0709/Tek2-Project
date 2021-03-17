/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Menu
*/

#ifndef MENU_HPP_
#define MENU_HPP_

#include "../scene/Scene.hpp"

namespace IndieStudio {
    class Menu : public Scene {
        public:
            Menu(irr::IrrlichtDevice *_device, std::shared_ptr<gameState> _state);
            ~Menu();
            void setVisible(bool const &status);
            void initScene();
            void run();
        private:
            void initTextures();
            void initButtons();
            void initImages();
            void setConfigurations();
            void logoEffect();

            Clock _menuClock;
            int _backgroundCurrent;
    };
}
#endif /* !MENU_HPP_ */