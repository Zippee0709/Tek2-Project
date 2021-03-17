/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Core
*/

#include "Core.hpp"

namespace IndieStudio {
    Core::Core(int x, int y, int bits) : _state(std::make_shared<gameState>(SPLASHSCREEN)),
        _device(irr::createDevice(irr::video::EDT_SOFTWARE, irr::core::dimension2d<irr::u32>(x, y), bits, false, false, true, 0)),
        _selectMenuConfig(std::make_shared<selectMenuConfig>()),
        _menuSettingConfig(std::make_shared<menuSettingConfig>())
    {
        if (!_device)
            throw Error("Error Create device", "core constructor");
        _scene[gameState::SPLASHSCREEN] = new SplashScreen(_device, _state);
        _scene[gameState::MENU] = new Menu(_device, _state);
        _scene[gameState::SELECTMENU] = new SelectMenu(_device, _state);
        _scene[gameState::GAME] = new Game(_device, _state, _selectMenuConfig);
        _scene[gameState::INGAMEMENU] = new Pause(_device, _state);
        _scene[gameState::SETTINGS] = new Option(_device, _state);
        _scene[gameState::GAMEOVER] = new EndGame(_device, _state);
        _scene[gameState::PLAYER1] = _scene[gameState::GAMEOVER];
        _scene[gameState::PLAYER2] = _scene[gameState::GAMEOVER];
        _oldState = *_state;
        _begin = _device->getTimer()->getTime();
        _now = 0;
        _fps = 0;
    }

    Core::~Core()
    {
        _device->drop();
        delete _scene[gameState::SPLASHSCREEN];
        delete _scene[gameState::MENU];
        delete _scene[gameState::SELECTMENU];
        delete _scene[gameState::GAME];
        delete _scene[gameState::INGAMEMENU];
        delete _scene[gameState::SETTINGS];
        delete _scene[gameState::GAMEOVER];
    }

    void Core::calculateDT()
    {
        _now = _device->getTimer()->getTime();
        _deltaTime = (irr::u32)(_now - _begin);
        _begin = _now;
    }

    void Core::renderFPS()
    {
        int lastFPS = _fps;
        _fps = _driver->getFPS();

        if (lastFPS != _fps) {
            irr::core::stringw tmp(L"Bomberman");
            tmp += L" FPS : ";
            tmp += _fps;
            _device->setWindowCaption(tmp.c_str());
        }
    }

    void Core::initDevice()
    {
        _driver = _device->getVideoDriver();
        _smng = _device->getSceneManager();
        _guienv = _device->getGUIEnvironment();
    }

    void Core::setVisible()
    {
        const int arraySize = 10;
        gameState array[arraySize] = {gameState::SPLASHSCREEN, gameState::MENU, gameState::SELECTMENU,
        gameState::GAME, gameState::INGAMEMENU, gameState::SETTINGS, gameState::GAME, gameState::GAMEOVER, gameState::PLAYER1, gameState::PLAYER2};

        for (int i = 0; i < arraySize; i++) {
            if (array[i] == gameState::GAMEOVER || array[i] == gameState::PLAYER1 || array[i] == gameState::PLAYER2) {
                if ( *_state == gameState::GAMEOVER || *_state == gameState::PLAYER1 || *_state == gameState::PLAYER2) {
                    _scene[gameState::GAMEOVER]->setVisible(true);
                } else if (*_state != gameState::GAMEOVER && *_state != gameState::PLAYER1 && *_state != gameState::PLAYER2) {
                    _scene[gameState::GAMEOVER]->setVisible(false);
                }
            } else if (*_state != array[i]) {
               _scene[array[i]]->setVisible(false);
            }
        }
    }

    void Core::stateChecker()
    {
        setVisible();
        if (!_sceneBeginned) {
            _scene[*_state]->setVisible(true);
            _sceneBeginned = true;
        }
        if (_oldState != *_state) {
            _oldState = *_state;
            _sceneBeginned = false;
        }
        _scene[*_state]->run();
    }

    void Core::run()
    {
        initDevice();
        Event event(_device, _state, _scene, _selectMenuConfig, _menuSettingConfig);
        _device->setEventReceiver(&event);
        _sound.initSoundSystem();
        while (_device->run() == true && *_state != gameState::EXIT) {
            calculateDT();
            _driver->beginScene(true, true, irr::video::SColor(255, 255, 255, 255));
            stateChecker();
            _smng->drawAll();
            _guienv->drawAll();
            _driver->endScene();
            _sound.switchMusic(_state, _menuSettingConfig->volume);
            renderFPS();
        }
        _device->closeDevice();
    }
}