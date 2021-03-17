/*
** EPITECH PROJECT, 2020
** indie
** File description:
** In-Game pause functionality
*/

#pragma once

#include "../scene/Scene.hpp"

namespace IndieStudio {
    class Pause : public Scene {
        public:
            Pause(irr::IrrlichtDevice *device, std::shared_ptr<gameState> state);
            ~Pause();
            void initScene();
            void run();
            void setVisible(bool const &status);

        private:
            void initTextures();
            void setConfigurations();
            void initButtons();
    };
}