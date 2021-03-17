/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Event
*/

#include <iostream>
#include "Event.hpp"

namespace IndieStudio {
    Event::Event(irr::IrrlichtDevice *device, std::shared_ptr<gameState> state, std::map<gameState, Scene *> &scene, std::shared_ptr<selectMenuConfig> selectMenuConfig, std::shared_ptr<menuSettingConfig> menuSettingConfig) :
        _device(device), _lock1Pressed(false), _lock2Pressed(false), _state(state),
        _scene(scene), _isMoving(false), _selectMenuConfig(selectMenuConfig), _playerOneKeyBinding(playerOneKeyBinding()), _playerTwoKeyBinding(playerTwoKeyBinding()), _menuSettingConfig(menuSettingConfig)
    {
        _sound.initSoundEffect();
    }

    Event::~Event()
    {
    }

    bool Event::OnEvent(const irr::SEvent &event)
    {
        bool status = false;

        if (event.EventType == irr::EET_GUI_EVENT) {
            irr::s32 id = event.GUIEvent.Caller->getID();
            if (event.GUIEvent.EventType == irr::gui::EGET_BUTTON_CLICKED) {
                status = menuEvent(id);
                status = selectMenuEvent(id);
                status = pauseEvent(id);
                status = settingEvent(id);
                status = gameOverEvent(id);

            }
        }
        else if (event.EventType == irr::EET_KEY_INPUT_EVENT) {
            if ((*_state) == gameState::GAME && event.KeyInput.Key == irr::KEY_ESCAPE && !event.KeyInput.PressedDown) {
                    (*_state) = gameState::INGAMEMENU;
            } else if ((*_state) == gameState::INGAMEMENU && event.KeyInput.Key == irr::KEY_ESCAPE && !event.KeyInput.PressedDown) {
                (*_state) = gameState::GAME;
            }
            status = playerEvent("PLAYERONE", event, _playerOneKeyBinding);
            if (_selectMenuConfig->haveTwoPlayer)
                status = playerEvent("PLAYERTWO", event, _playerTwoKeyBinding);
        }
        return status;
    }

    bool Event::playerEvent(std::string const &name, const irr::SEvent &event, playerKeyBinding pkb)
    {
        auto gameScene = dynamic_cast<IndieStudio::Game *>(_scene[gameState::GAME]);
        if ((*_state) == gameState::GAME && gameScene->getPlayer(name).getIsAlive() && !gameScene->getPlayer(name).getUpdateMove()) {
            if (event.KeyInput.Key == pkb.moveUp) {
                if (gameScene->haveCollision(gameScene->getPlayer(name), 0, 10))
                    return true;
                gameScene->getPlayer(name).setUpdateMove(true, 0, 10);
                gameScene->getMesh(name)->setRotation(irr::core::vector3df(0, 180, 0));
                return (true);
            }
            else if (event.KeyInput.Key == pkb.moveDown) {
                if (gameScene->haveCollision(gameScene->getPlayer(name), 0, -10))
                    return true;
                gameScene->getPlayer(name).setUpdateMove(true, 0, -10);

                gameScene->getMesh(name)->setRotation(irr::core::vector3df(0, 0, 0));
                return (true);
            }
            else if (event.KeyInput.Key == pkb.moveLeft) {
                if (gameScene->haveCollision(gameScene->getPlayer(name), -10, 0))
                    return true;
                gameScene->getPlayer(name).setUpdateMove(true, -10, 0);

                gameScene->getMesh(name)->setRotation(irr::core::vector3df(0, 90, 0));
                return (true);
            }
            else if (event.KeyInput.Key == pkb.moveRight) {
                if (gameScene->haveCollision(gameScene->getPlayer(name), 10, 0))
                    return true;
                gameScene->getPlayer(name).setUpdateMove(true, 10, 0);
                gameScene->getMesh(name)->setRotation(irr::core::vector3df(0, -90, 0));
                return (true);
            }
            else if (event.KeyInput.Key == pkb.plantBomb
                && gameScene->getPlayer(name).getBombPlanted() < gameScene->getPlayer(name).getBombs()) {
                _sound.initBombSound(_menuSettingConfig->volume);
                gameScene->getPlayer(name).plantBomb();
                return true;
            }
        }
        return (false);
    }

    bool Event::menuEvent(irr::s32 id)
    {
        if (*_state == gameState::MENU) {
            auto sceneGame = dynamic_cast<IndieStudio::Game *>(_scene[gameState::GAME]);

            switch (id) {
                case menuButton::PLAY:
                    *_state = gameState::SELECTMENU;
                    return true;
                case menuButton::LOAD:
                    Save::loadGame(sceneGame);
                    return true;
                case menuButton::OPTIONS:
                    *_state = gameState::SETTINGS;
                    return true;
                case menuButton::QUIT:
                    *_state = gameState::EXIT;
                    return true;
                default:
                    return false;
            }
        }
        return false;
    }

    bool Event::pauseEvent(irr::s32 id)
    {
        if (*_state == gameState::INGAMEMENU) {
            auto sceneGame = dynamic_cast<IndieStudio::Game *>(_scene[gameState::GAME]);
            _returnInGame = true;

            switch (id) {
                case inGameMenuButtons::RESUME:
                    *_state = gameState::GAME;
                    return true;
                case inGameMenuButtons::SAVE:
                    Save::saveGame
                    (sceneGame->getEntities(), sceneGame->getSelectMenuConfig(), sceneGame->getPlayers());
                    return true;
                case inGameMenuButtons::OPTIONINGAME:
                    *_state = gameState::SETTINGS;
                    return true;
                case inGameMenuButtons::QUITINGAME:
                    _returnInGame = false;
                    sceneGame->quit();
                    *_state = gameState::MENU;
                    return true;
                default:
                    return false;
            }
        }
        return false;
    }

    bool Event::selectMenuEvent(irr::s32 id)
    {
        if (*_state == gameState::SELECTMENU) {
            switch (id) {
                case selectMenuButton::PLAYER1LEFT:
                    dynamic_cast<IndieStudio::SelectMenu *>(_scene[gameState::SELECTMENU])->
                        PlayerSelectLeft(1, _selectMenuConfig);
                    return true;
                case selectMenuButton::PLAYER1SELECT:
                    return true;
                case selectMenuButton::PLAYER1RIGHT:
                    dynamic_cast<IndieStudio::SelectMenu *>(_scene[gameState::SELECTMENU])->
                        PlayerSelectRight(1, _selectMenuConfig);
                    return true;
                case selectMenuButton::PLAYER1LOCK:
                    return true;
                case selectMenuButton::PLAYER2LEFT:
                    dynamic_cast<IndieStudio::SelectMenu *>(_scene[gameState::SELECTMENU])->
                        PlayerSelectLeft(2, _selectMenuConfig);
                    return true;
                case selectMenuButton::PLAYER2SELECT:
                    return true;
                case selectMenuButton::PLAYER2RIGHT:
                    dynamic_cast<IndieStudio::SelectMenu *>(_scene[gameState::SELECTMENU])->
                        PlayerSelectRight(2, _selectMenuConfig);
                    return true;
                case selectMenuButton::PLAYER2LOCK:
                    dynamic_cast<IndieStudio::SelectMenu *>(_scene[gameState::SELECTMENU])->
                        setPlayerLock(2, !dynamic_cast<IndieStudio::SelectMenu *>(_scene[gameState::SELECTMENU])->getPlayerLock(2), _selectMenuConfig);
                    return true;
                case selectMenuButton::SELECTPLAY:
                    *_state = gameState::GAME;
                    return true;
                case selectMenuButton::SELECTHOME:
                    dynamic_cast<IndieStudio::SelectMenu *>(_scene[gameState::SELECTMENU])->reset();
                    *_state = gameState::MENU;
                    return true;
                default:
                    return false;
            }
        }
        return false;
    }
    bool Event::settingEvent(irr::s32 id) {
        static bool state = true;

        if (*_state == gameState::SETTINGS) {
            switch (id) {
                case settingButton::MORE:
                    _menuSettingConfig->volume+=10;
                    if (_menuSettingConfig->volume > 100)
                        _menuSettingConfig->volume = 100;
                    return true;
                case settingButton::LESS:
                    _menuSettingConfig->volume-=10;
                    if (_menuSettingConfig->volume < 0)
                        _menuSettingConfig->volume = 0;
                    return true;
                case settingButton::RETURN_IN_GAME:
                    if(_returnInGame == true) {
                        *_state = gameState::GAME;
                    }
                    return true;
                case settingButton::QUIT_SETTING:
                    state ? *_state = gameState::SETTINGS : *_state = gameState::MENU;
                    if (*_state == gameState::MENU)
                        state = true;
                    else if (*_state == SETTINGS)
                        state = false;
                    return true;
                default:
                    return false;
            }
        }
        return false;
    }

    bool Event::gameOverEvent(irr::s32 id) {
        if (*_state == gameState::GAMEOVER || *_state == gameState::PLAYER1 || *_state == gameState::PLAYER2) {
            auto sceneGame = dynamic_cast<IndieStudio::Game *>(_scene[gameState::GAME]);
            switch (id) {
               case gameOverButton::REMATCH:
                    *_state = gameState::SELECTMENU;
                    return true;
                case gameOverButton::BACKTOMENU:
                    *_state = gameState::MENU;
                    return true;
                default:
                    return false;
            }
        }
        return false;
    }
}