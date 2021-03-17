/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2019
** File description:
** option.hpp
*/

#ifndef OPTION_HPP_
#define OPTION_HPP_

#include "../scene/Scene.hpp"

namespace IndieStudio {
    class Option : public Scene {
        public:
            Option(irr::IrrlichtDevice *_device, std::shared_ptr<gameState> _state);
            ~Option();
            void setVisible(bool const &status);
            void initScene();
            void setConfigurations();
            void initTextures();
            void run();
        private:
            void initButton();
    };
}

#endif
