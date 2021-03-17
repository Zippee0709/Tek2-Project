/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2019
** File description:
** EndGame.hpp
*/

#ifndef ENDGAME_HPP_
#define ENDGAME_HPP_

#include "../scene/Scene.hpp"

namespace IndieStudio {
    class EndGame : public Scene {
        public :
            EndGame(irr::IrrlichtDevice *_device, std::shared_ptr<gameState> _state);
            ~EndGame();
            void setVisible(bool const &status);
            void initScene();
            void setConfigurations();
            void initTextures();
            void run();
            void checkDeath(int param);
        private:
            void initButton();
            int _death;
    };
}

#endif