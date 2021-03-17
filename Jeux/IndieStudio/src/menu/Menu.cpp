/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Menu
*/

#include "Menu.hpp"

namespace IndieStudio {
    Menu::Menu(irr::IrrlichtDevice *device, std::shared_ptr<gameState> state) : Scene(device, state),  _backgroundCurrent(0)
    {
        initScene();
    }

    Menu::~Menu()
    {
    }

    void Menu::initScene()
    {
        initTextures();
        initTexturesBackground("/resources/Menu/BG/", "menuBG", 4, ".png");
        addTexturestoImages("menuBG", 4);
        initImages();
        initButtons();
        setConfigurations();
    }

    void Menu::initTextures()
    {
        _textures["PLAY"] = _driver->getTexture(irr::io::path(pathProject) + "/resources/Menu/Buttons/PlayUnpressed.png");
        _textures["PLAY_PRESSED"] = _driver->getTexture(irr::io::path(pathProject) + "/resources/Menu/Buttons/PlayPressed.png");

        _textures["LOAD"] = _driver->getTexture(irr::io::path(pathProject) + "/resources/Menu/Buttons/LoadUnpressed.png");
        _textures["LOAD_PRESSED"] = _driver->getTexture(irr::io::path(pathProject) + "/resources/Menu/Buttons/LoadPressed.png");

        _textures["OPTION"] = _driver->getTexture(irr::io::path(pathProject) + "/resources/Menu/Buttons/OptionUnpressed.png");
        _textures["OPTION_PRESSED"] = _driver->getTexture(irr::io::path(pathProject) + "/resources/Menu/Buttons/OptionPressed.png");

        _textures["QUIT"] = _driver->getTexture(irr::io::path(pathProject) + "/resources/Menu/Buttons/QuitUnpressed.png");
        _textures["QUIT_PRESSED"] = _driver->getTexture(irr::io::path(pathProject) + "/resources/Menu/Buttons/QuitPressed.png");

        _textures["LOGO"] = _driver->getTexture(irr::io::path(pathProject) + "/resources/Menu/BG/logo.png");
    }

    void Menu::initImages()
    {
        _images["LOGO"] = _guienv->addImage(_textures["LOGO"], irr::core::position2di(0, 0));
    }

    void Menu::initButtons()
    {
        _buttons["PLAY"] = _guienv->addButton(irr::core::rect<irr::s32>(860, 400, (860 + 200), (400 + 100)), 0, menuButton::PLAY);
        _buttons["LOAD"] = _guienv->addButton(irr::core::rect<irr::s32>(860, 510, (860 + 200), (510 + 100)), 0, menuButton::LOAD);
        _buttons["OPTION"] = _guienv->addButton(irr::core::rect<irr::s32>(860, 620, (860 + 200), (620 + 100)), 0, menuButton::OPTIONS);
        _buttons["QUIT"] = _guienv->addButton(irr::core::rect<irr::s32>(860, 730, (860 + 200), (730 + 100)), 0, menuButton::QUIT);

        _buttons["PLAY"]->setImage(_textures["PLAY"]);
        _buttons["LOAD"]->setImage(_textures["LOAD"]);
        _buttons["OPTION"]->setImage(_textures["OPTION"]);
        _buttons["QUIT"]->setImage(_textures["QUIT"]);

        _buttons["PLAY"]->setPressedImage(_textures["PLAY_PRESSED"]);
        _buttons["LOAD"]->setPressedImage(_textures["LOAD_PRESSED"]);
        _buttons["OPTION"]->setPressedImage(_textures["OPTION_PRESSED"]);
        _buttons["QUIT"]->setPressedImage(_textures["QUIT_PRESSED"]);
    }

    void Menu::setConfigurations()
    {
        for (auto button : _buttons) {
            button.second->setUseAlphaChannel(true);
            button.second->setDrawBorder(false);
        }
    }

    void Menu::setVisible(bool const &status)
    {
        for (auto button : _buttons)
            button.second->setVisible(status);
        for (auto image : _images)
            image.second->setVisible(status);
    }

    void Menu::run()
    {
        backgroundEffect("menuBG", 75, 4);
    }
}