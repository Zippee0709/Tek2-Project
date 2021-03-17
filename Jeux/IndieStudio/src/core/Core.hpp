/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Core
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#include <iostream>
#include <memory>
#include "../../irrlicht-1.8.4/include/irrlicht.h"
#include "../data/IndieStudioData.hpp"
#include "../menu/Menu.hpp"
#include "../selectMenu/SelectMenu.hpp"
#include "../event/Event.hpp"
#include "../splashScreen/SplashScreen.hpp"
#include "../sound/Sound.hpp"
#include "../game/Game.hpp"
#include "../inGameMenu/Pause.hpp"
#include "../option/Option.hpp"
#include "../endGame/GameOver.hpp"
namespace IndieStudio{
    class Core {
        public:
            Core(int x = 1920, int y = 1080, int bits = 32);
            void run();
            ~Core();
        private:
            void initDevice();
            void initTexture();
            void initButton();
            void initMeshs();
            void stateChecker();
            void setVisible();
            void calculateDT();
            void renderFPS();

            irr::IrrlichtDevice *_device;
            irr::video::IVideoDriver *_driver;
            irr::scene::ISceneManager *_smng;
            irr::gui::IGUIEnvironment *_guienv;
            std::shared_ptr<gameState> _state;
            gameState _oldState;
            Sound _sound;

            std::map<gameState, Scene *> _scene;
            irr::u32 _begin;
            irr::u32 _now;
            irr::u32 _deltaTime;
            int _fps;

            bool _sceneBeginned = false;

            std::shared_ptr<selectMenuConfig> _selectMenuConfig;
            std::shared_ptr<menuSettingConfig> _menuSettingConfig;
    };
}

#endif /* !CORE_HPP_ */