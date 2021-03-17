/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2019
** File description:
** EndGame.cpp
*/

#include "GameOver.hpp"

namespace IndieStudio {
    EndGame::EndGame(irr::IrrlichtDevice *device, std::shared_ptr<gameState> state) : Scene(device, state) 
    {
        initScene();
    }

    EndGame::~EndGame()
    {
    }

    void EndGame::checkDeath(int param) {

    }

    void EndGame::initTextures()
    {
        _textures["PLAY"] = _driver->getTexture(irr::io::path(pathProject) + "/resources/Menu/Buttons/PlayUnpressed.png");
        _textures["PLAY_PRESSED"] = _driver->getTexture(irr::io::path(pathProject) + "/resources/Menu/Buttons/PlayPressed.png");

        _textures["QUIT"] = _driver->getTexture(irr::io::path(pathProject) + "/resources/Menu/Buttons/QuitUnpressed.png");
        _textures["QUIT_PRESSED"] = _driver->getTexture(irr::io::path(pathProject) + "/resources/Menu/Buttons/QuitPressed.png");
   }

    void EndGame::setVisible(bool const &status) {
        for (auto i : _buttons) {
            i.second->setVisible(status);
        }
        for (auto image : _images)
            image.second->setVisible(status);
    }

    void EndGame::setConfigurations() {
        for (auto button : _buttons) {
            button.second->setUseAlphaChannel(true);
            button.second->setDrawBorder(false);
        }
    }

    void EndGame::initButton()
    {
        _buttons["REMATCH"] = _guienv->addButton(irr::core::rect<irr::s32>(500, 800, (500 + 200), (800+100)), 0, gameOverButton::REMATCH);
        _buttons["QUIT"] = _guienv->addButton(irr::core::rect<irr::s32>(1280, 800, (1280 + 200), (800+100)), 0, gameOverButton::BACKTOMENU);

        _buttons["REMATCH"]->setImage(_textures["PLAY"]);
        _buttons["REMATCH"]->setPressedImage(_textures["PLAY_PRESSED"]);

        _buttons["QUIT"]->setImage(_textures["QUIT"]);
        _buttons["QUIT"]->setPressedImage(_textures["QUIT_PRESSED"]);
    }

    void EndGame::run()
    {
        static bool isFirst = true;
        if (isFirst) {
            if (*_state == gameState::GAMEOVER)
                addTexturestoImages("gameover", 1);
            else if (*_state == gameState::PLAYER1)
                addTexturestoImages("player1_", 1);
            else
                addTexturestoImages("player2_", 1);
            initTextures();
            initButton();
            setConfigurations();
            isFirst = false;
        }
    }

    void EndGame::initScene() {
        initTexturesBackground("/resources/Game/End/", "gameover", 1, ".png");
        initTexturesBackground("/resources/Game/End/", "player1_", 1, ".png");
        initTexturesBackground("/resources/Game/End/", "player2_", 1, ".png");
    }
}