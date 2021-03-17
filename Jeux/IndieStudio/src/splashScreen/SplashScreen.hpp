/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2019
** File description:
** splashscreen
*/

#ifndef SPLASHSCREEN_HPP_
#define SPLASHSCREEN_HPP_

#include "../scene/Scene.hpp"

namespace IndieStudio {
    class SplashScreen : public Scene {
        public:
            SplashScreen(irr::IrrlichtDevice *device, std::shared_ptr<gameState> state);
            ~SplashScreen();
            void run();
        private:
            float _opacity = 255;
            Clock clock;
            void initScene();
            void initTextures();
            void goToMenu();
            void setVisible(bool const &status);
            void setConfigurations();
            void drawScreen();
    };
}
#endif