/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2019
** File description:
** option.cpp
*/

#include "Option.hpp"

namespace IndieStudio {
    Option::Option(irr::IrrlichtDevice *device, std::shared_ptr<gameState> state) : Scene(device, state)
    {
        initScene();
    }
    Option::~Option()
    {
    }
    void Option::initTextures()
    {
        _textures["MORE"] = _driver->getTexture(irr::io::path(pathProject) +"/resources/Option/moreNoPress.png");
        _textures["MORE_PRESS"] = _driver->getTexture(irr::io::path(pathProject) +"/resources/Option/morePress.png");

        _textures["LESS"] = _driver->getTexture(irr::io::path(pathProject) +"/resources/Option/lessNoPress.png");
        _textures["LESS_PRESS"] = _driver->getTexture(irr::io::path(pathProject) +"/resources/Option/lessPress.png");

        _textures["QUIT_SETTING"] = _driver->getTexture(irr::io::path(pathProject) +"/resources/SelectMenu/Buttons/home.png");
        _textures["QUIT_SETTING_PRESS"] = _driver->getTexture(irr::io::path(pathProject) +"/resources/SelectMenu/Buttons/home_pressed.png");

        _textures["RETURN_IN_GAME"] = _driver->getTexture(irr::io::path(pathProject) +"/resources/SelectMenu/Buttons/play.png");
        _textures["RETURN_IN_GAME_PRESS"] = _driver->getTexture(irr::io::path(pathProject) +"/resources/SelectMenu/Buttons/play_pressed.png");
    }
    void Option::initButton() {
        _buttons["MORE"] = _guienv->addButton(irr::core::rect<irr::s32>(860, 600, (860 + 74), (600 + 69)), 0, settingButton::MORE);
        _buttons["LESS"] = _guienv->addButton(irr::core::rect<irr::s32>(950, 600, (950 + 74), (600 + 69)), 0, settingButton::LESS);
        _buttons["QUIT_SETTING"] = _guienv->addButton(irr::core::rect<irr::s32>(1800, 900, (1800 + 100), (900 + 100)), 0, settingButton::QUIT_SETTING);
        _buttons["RETURN_IN_GAME"] = _guienv->addButton(irr::core::rect<irr::s32>(1800, 800, (1800 + 100), (800 + 100)), 0, settingButton::RETURN_IN_GAME);

        _buttons["MORE"]->setImage(_textures["MORE"]);
        _buttons["MORE"]->setPressedImage(_textures["MORE_PRESS"]);

        _buttons["LESS"]->setImage(_textures["LESS"]);
        _buttons["LESS"]->setPressedImage(_textures["LESS_PRESS"]);

        _buttons["QUIT_SETTING"]->setImage(_textures["QUIT_SETTING"]);
        _buttons["QUIT_SETTING"]->setPressedImage(_textures["QUIT_SETTING_PRESS"]);

        _buttons["RETURN_IN_GAME"]->setImage(_textures["RETURN_IN_GAME"]);
        _buttons["RETURN_IN_GAME"]->setPressedImage(_textures["RETURN_IN_GAME_PRESS"]);
    }

    void Option::setVisible(bool const &status) {
        for (auto i : _buttons) {
            i.second->setVisible(status);
        }
        for (auto image : _images)
            image.second->setVisible(status);
    }

    void Option::setConfigurations() {
        for (auto button : _buttons) {
            button.second->setUseAlphaChannel(true);
            button.second->setDrawBorder(false);
        }
    }

    void Option::run() {

    }
    void Option::initScene() {
        initTexturesBackground("/resources/Option/", "setting", 1, ".png");
        addTexturestoImages("setting", 1);
        initTextures();
        initButton();
        setConfigurations();
    }
}