/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2019
** File description:
** splashscreen.cpp
*/

#include "SplashScreen.hpp"
#include "../core/Core.hpp"

#ifdef WINDOWS
#include <Windows.h>
#else
#include <unistd.h>
#endif

namespace IndieStudio {
    SplashScreen::SplashScreen(irr::IrrlichtDevice *device, std::shared_ptr<gameState> state) : Scene(device, state)
    {
        initScene();
    }

    SplashScreen::~SplashScreen() {

    }
    void SplashScreen::initTextures() {
        _textures["SPLASH_SCREEN1"] = _driver->getTexture(irr::io::path(pathProject) + "/resources/SplashScreen/splash2.png");
        _textures["SPLASH_SCREEN2"] = _driver->getTexture(irr::io::path(pathProject) + "/resources/SplashScreen/splash1.png");
        _textures["SPLASH_SCREEN3"] = _driver->getTexture(irr::io::path(pathProject) + "/resources/SplashScreen/splash3.png");
    }

    void SplashScreen::drawScreen() {
        irr::core::rect<irr::s32> rectangle(0, 0, 1920, 1080);
        float time;
        bool reverse = false;
        int i = 1;
        _driver->beginScene(true, true, irr::video::SColor(255, 255, 255, 255));
        _driver->draw2DImage(_textures["SPLASH_SCREEN1"], irr::core::position2d<irr::s32>(0, 0), rectangle, 0, irr::video::SColor(_opacity, _opacity, _opacity, _opacity), true);
        _smng->drawAll();
        _guienv->drawAll();
        _driver->endScene();
        #ifdef WINDOWS
        Sleep(2);
        #else
        sleep(2);
        #endif
        while (i != 4) {
            _driver->beginScene(true, true, irr::video::SColor(255, 255, 255, 255));
            _driver->draw2DImage(_textures["SPLASH_SCREEN" + std::to_string(i)], irr::core::position2d<irr::s32>(0, 0), rectangle, 0, irr::video::SColor(_opacity, _opacity, _opacity, _opacity), true);
            time = clock.getElapsedTimeInSecond();
            if (time > 0.01) {
                _opacity = reverse ? _opacity + 2 : _opacity - 2;
                _opacity = (_opacity < 0) ? 0 : _opacity;
                clock.restart();
            }
            if (_opacity >= 255 || _opacity <= 0) {
                reverse = !reverse;
            }
            if (_opacity <= 0)
                i += 1;
            _smng->drawAll();
            _guienv->drawAll();
            _driver->endScene();
        }
        *_state = gameState::MENU;
    }

    void SplashScreen::setVisible(bool const &status)
    {
    }

    void SplashScreen::setConfigurations()
    {
    }

    void SplashScreen::initScene() {
        initTextures();
    }

    void SplashScreen::run() {
        drawScreen();
    }
}