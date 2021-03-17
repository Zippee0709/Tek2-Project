/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** SelectMenu
*/

#include "SelectMenu.hpp"

namespace IndieStudio {
    SelectMenu::SelectMenu(irr::IrrlichtDevice *device, std::shared_ptr<gameState> state) : 
    Scene(device, state), _player1Lock(false), _player2Lock(false),
    _player1Select(0), _player2Select(1)
    {
        initScene();
    }

    SelectMenu::~SelectMenu()
    {
    }

    void SelectMenu::initTextures()
    {
        _textures["LEFT"] = _driver->getTexture(irr::io::path(pathProject) + "/resources/SelectMenu/Buttons/left.png");
        _textures["LEFT_PRESSED"] = _driver->getTexture(irr::io::path(pathProject) + "/resources/SelectMenu/Buttons/left_pressed.png");

        _textures["RIGHT"] = _driver->getTexture(irr::io::path(pathProject) + "/resources/SelectMenu/Buttons/right.png");
        _textures["RIGHT_PRESSED"] = _driver->getTexture(irr::io::path(pathProject) + "/resources/SelectMenu/Buttons/right_pressed.png");

        _textures["LOCK"] = _driver->getTexture(irr::io::path(pathProject) + "/resources/SelectMenu/Buttons/lock.png");
        _textures["UNLOCK"] = _driver->getTexture(irr::io::path(pathProject) + "/resources/SelectMenu/Buttons/unlock.png");

        _textures["PLAY"] = _driver->getTexture(irr::io::path(pathProject) + "/resources/SelectMenu/Buttons/play.png");
        _textures["PLAY_PRESSED"] = _driver->getTexture(irr::io::path(pathProject) + "/resources/SelectMenu/Buttons/play_pressed.png");
 
        _textures["HOME"] = _driver->getTexture(irr::io::path(pathProject) + "/resources/SelectMenu/Buttons/home.png");
        _textures["HOME_PRESSED"] = _driver->getTexture(irr::io::path(pathProject) + "/resources/SelectMenu/Buttons/home_pressed.png");
        initCharacters();
    }

    void SelectMenu::initCharacters()
    {
        _textures["AJSELECT"] = _driver->getTexture(irr::io::path(pathProject) + "/resources/SelectMenu/Personnages/ajSelect.jpg");
        _textures["CLAIRESELECT"] = _driver->getTexture(irr::io::path(pathProject) + "/resources/SelectMenu/Personnages/claireSelect.jpg");
        _textures["GRANDMASELECT"] = _driver->getTexture(irr::io::path(pathProject) + "/resources/SelectMenu/Personnages/grandmaSelect.jpg");
        _textures["KAYASELECT"] = _driver->getTexture(irr::io::path(pathProject) + "/resources/SelectMenu/Personnages/kayaSelect.jpg");
    }

    void SelectMenu::initButtons()
    {
        _buttons["PLAYER1_LEFT"] = _guienv->addButton(irr::core::rect<irr::s32>(210, 325, 310, 425), 0, selectMenuButton::PLAYER1LEFT);
        _buttons["PLAYER1_SELECT"] = _guienv->addButton(irr::core::rect<irr::s32>(330, 100, 630, 550), 0, selectMenuButton::PLAYER1SELECT);
        _buttons["PLAYER1_RIGHT"] = _guienv->addButton(irr::core::rect<irr::s32>(650, 325, 750, 425), 0, selectMenuButton::PLAYER1RIGHT);
        _buttons["PLAYER1_LOCK"] = _guienv->addButton(irr::core::rect<irr::s32>(415, 600, 515, 700), 0, selectMenuButton::PLAYER1LOCK);

        _buttons["PLAYER2_LEFT"] = _guienv->addButton(irr::core::rect<irr::s32>(1170, 325, 1270, 425), 0, selectMenuButton::PLAYER2LEFT);
        _buttons["PLAYER2_SELECT"] = _guienv->addButton(irr::core::rect<irr::s32>(1290, 110, 1590, 550), 0, selectMenuButton::PLAYER2SELECT);
        _buttons["PLAYER2_RIGHT"] = _guienv->addButton(irr::core::rect<irr::s32>(1610, 325, 1710, 425), 0, selectMenuButton::PLAYER2RIGHT);
        _buttons["PLAYER2_LOCK"] = _guienv->addButton(irr::core::rect<irr::s32>(1375, 600, 1475, 700), 0, selectMenuButton::PLAYER2LOCK);

        _buttons["SELECT_PLAY"] = _guienv->addButton(irr::core::rect<irr::s32>(415, 750, 515, 850), 0, selectMenuButton::SELECTPLAY);
        _buttons["SELECT_HOME"] = _guienv->addButton(irr::core::rect<irr::s32>(1375, 750, 1475, 850), 0, selectMenuButton::SELECTHOME);

        _buttons["PLAYER1_LEFT"]->setImage(_textures["LEFT"]);
        _buttons["PLAYER1_LEFT"]->setPressedImage(_textures["LEFT_PRESSED"]);
        _buttons["PLAYER1_SELECT"]->setImage(_textures["AJSELECT"]);
        _buttons["PLAYER1_RIGHT"]->setImage(_textures["RIGHT"]);
        _buttons["PLAYER1_RIGHT"]->setPressedImage(_textures["RIGHT_PRESSED"]);
        _buttons["PLAYER1_LOCK"]->setImage(_textures["LOCK"]);
        _buttons["PLAYER1_LOCK"]->setPressedImage(_textures["LOCK"]);

        _buttons["PLAYER2_LEFT"]->setImage(_textures["LEFT"]);
        _buttons["PLAYER2_LEFT"]->setPressedImage(_textures["LEFT_PRESSED"]);
        _buttons["PLAYER2_SELECT"]->setImage(_textures["CLAIRESELECT"]);
        _buttons["PLAYER2_RIGHT"]->setImage(_textures["RIGHT"]);
        _buttons["PLAYER2_RIGHT"]->setPressedImage(_textures["RIGHT_PRESSED"]);
        _buttons["PLAYER2_LOCK"]->setImage(_textures["UNLOCK"]);
        _buttons["PLAYER2_LOCK"]->setPressedImage(_textures["LOCK"]);

        _buttons["SELECT_PLAY"]->setImage(_textures["PLAY"]);
        _buttons["SELECT_PLAY"]->setPressedImage(_textures["PLAY_PRESSED"]);

        _buttons["SELECT_HOME"]->setImage(_textures["HOME"]);
        _buttons["SELECT_HOME"]->setPressedImage(_textures["HOME_PRESSED"]);
    }

    void SelectMenu::setPlayerLock(int const &player, bool const &status, std::shared_ptr<selectMenuConfig> config)
    {
        if (player == 1) {
            _player1Lock = status;
            if (status == true)
                _buttons["PLAYER1_LOCK"]->setImage(_textures["LOCK"]);
            else
                _buttons["PLAYER1_LOCK"]->setImage(_textures["UNLOCK"]);
        }
        else if (player == 2) {
            _player2Lock = status;
            if (status == true) {
                _buttons["PLAYER2_LOCK"]->setImage(_textures["LOCK"]);
                config->haveTwoPlayer = true;
            }
            else {
                _buttons["PLAYER2_LOCK"]->setImage(_textures["UNLOCK"]);
                config->haveTwoPlayer = false;
            }
        }
    }

    void SelectMenu::checkSkins(std::string const &player, int select)
    {
        switch (select) {
            case 0:
                _buttons[player]->setImage(_textures["AJSELECT"]);
                return;
            case 1:
                _buttons[player]->setImage(_textures["CLAIRESELECT"]);
                return;
            case 2:
                _buttons[player]->setImage(_textures["GRANDMASELECT"]);
                return;
            case 3:
                _buttons[player]->setImage(_textures["KAYASELECT"]);
                return;
            default:
                return;
        }
    }

    void SelectMenu::PlayerSelectRight(int const &player, std::shared_ptr<selectMenuConfig> config)
    {
        if (player == 1) {
            _player1Select += 1;
            if (_player1Select > 3)
                _player1Select = 0;
            checkSkins("PLAYER1_SELECT", _player1Select);
            config->playersSkinImage[player - 1] = skinSelectedImagePath[_player1Select];
            config->playersSkinDae[player - 1] = skinSelectedDaePath[_player1Select];
        }
        else if (player == 2) {
            _player2Select += 1;
            if (_player2Select > 3)
                _player2Select = 0;
            checkSkins("PLAYER2_SELECT", _player2Select);
            config->playersSkinImage[player - 1] = skinSelectedImagePath[_player2Select];
            config->playersSkinDae[player - 1] = skinSelectedDaePath[_player2Select];
        }
    }

    void SelectMenu::PlayerSelectLeft(int const &player, std::shared_ptr<selectMenuConfig> config)
    {
        if (player == 1) {
            _player1Select -= 1;
            if (_player1Select < 0)
                _player1Select = 3;
            checkSkins("PLAYER1_SELECT", _player1Select);
            config->playersSkinImage[player - 1] = skinSelectedImagePath[_player1Select];
            config->playersSkinDae[player - 1] = skinSelectedDaePath[_player1Select];
        }
        else if (player == 2) {
            _player2Select -= 1;
            if (_player2Select < 0)
                _player2Select = 3;
            checkSkins("PLAYER2_SELECT", _player2Select);
            config->playersSkinImage[player - 1] = skinSelectedImagePath[_player2Select];
            config->playersSkinDae[player - 1] = skinSelectedDaePath[_player2Select];
        }
    }

    bool SelectMenu::getPlayerLock(int const &player) const
    {
        if (player == 1)
            return _player1Lock;
        return _player2Lock;
    }

    void SelectMenu::initImages()
    {
    }

    void SelectMenu::setConfigurations()
    {
        for (auto button : _buttons) {
            button.second->setUseAlphaChannel(true);
            button.second->setDrawBorder(false);
        }
    }

     void SelectMenu::setVisible(bool const &status)
    {
        for (auto button : _buttons)
            button.second->setVisible(status);
        for (auto image : _images)
            image.second->setVisible(status);
    }

    void SelectMenu::reset()
    {
        _player1Lock = false;
        _player2Lock = false;
        _player1Select = 0;
        _player2Select = 1;
        _buttons["PLAYER1_LOCK"]->setImage(_textures["LOCK"]);
        _buttons["PLAYER2_LOCK"]->setImage(_textures["UNLOCK"]);
        _buttons["PLAYER1_SELECT"]->setImage(_textures["AJSELECT"]);
        _buttons["PLAYER2_SELECT"]->setImage(_textures["CLAIRESELECT"]);
    }

    void SelectMenu::initScene()
    {
        initTexturesBackground("/resources/SelectMenu/BG/", "selectBG", 1, ".png");
        initTextures();
        addTexturestoImages("selectBG", 1);
        initImages();
        initButtons();
        setConfigurations();
        initCharacters();
    }

    void SelectMenu::run()
    {
    }
}