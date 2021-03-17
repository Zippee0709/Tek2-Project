/*
** EPITECH PROJECT, 2020
** indie
** File description:
** In-Game pause
*/

#include "Pause.hpp"

namespace IndieStudio {
    Pause::Pause(irr::IrrlichtDevice *device, std::shared_ptr<gameState> state) : Scene(device, state)
    {
        initScene();
    }

    Pause::~Pause()
    {
    }

    void Pause::initScene()
    {
        initTextures();
        initButtons();
        setConfigurations();
    }

    void Pause::initButtons()
    {
        _buttons["RESUME"] = _guienv->addButton(irr::core::rect<irr::s32>(860, 400, (860 + 200), (400 + 100)), 0, inGameMenuButtons::RESUME);
        _buttons["SAVE"] = _guienv->addButton(irr::core::rect<irr::s32>(860, 510, (860 + 200), (510 + 100)), 0, inGameMenuButtons::SAVE);
        _buttons["OPTIONINGAME"] = _guienv->addButton(irr::core::rect<irr::s32>(860, 620, (860 + 200), (620 + 100)), 0, inGameMenuButtons::OPTIONINGAME);
        _buttons["QUITINGAME"] = _guienv->addButton(irr::core::rect<irr::s32>(860, 730, (860 + 200), (730 + 100)), 0, inGameMenuButtons::QUITINGAME);

        _buttons["RESUME"]->setImage(_textures["RESUME"]);
        _buttons["SAVE"]->setImage(_textures["SAVE"]);
        _buttons["OPTIONINGAME"]->setImage(_textures["OPTIONINGAME"]);
        _buttons["QUITINGAME"]->setImage(_textures["QUITINGAME"]);

        _buttons["RESUME"]->setPressedImage(_textures["RESUME_PRESSED"]);
        _buttons["SAVE"]->setPressedImage(_textures["SAVE_PRESSED"]);
        _buttons["OPTIONINGAME"]->setPressedImage(_textures["OPTIONINGAME_PRESSED"]);
        _buttons["QUITINGAME"]->setPressedImage(_textures["QUITINGAME_PRESSED"]);
    }

    void Pause::initTextures()
    {
        _textures["RESUME"] = _driver->getTexture(irr::io::path(pathProject) + "/resources/Menu/Buttons/ResumeUnpressed.png");
        _textures["RESUME_PRESSED"] = _driver->getTexture(irr::io::path(pathProject) + "/resources/Menu/Buttons/ResumePressed.png");

        _textures["SAVE"] = _driver->getTexture(irr::io::path(pathProject) + "/resources/Menu/Buttons/SaveUnpressed.png");
        _textures["SAVE_PRESSED"] = _driver->getTexture(irr::io::path(pathProject) + "/resources/Menu/Buttons/SavePressed.png");

        _textures["OPTIONINGAME"] = _driver->getTexture(irr::io::path(pathProject) + "/resources/Menu/Buttons/OptionUnpressed.png");
        _textures["OPTIONINGAME_PRESSED"] = _driver->getTexture(irr::io::path(pathProject) + "/resources/Menu/Buttons/OptionPressed.png");

        _textures["QUITINGAME"] = _driver->getTexture(irr::io::path(pathProject) + "/resources/Menu/Buttons/QuitUnpressed.png");
        _textures["QUITINGAME_PRESSED"] = _driver->getTexture(irr::io::path(pathProject) + "/resources/Menu/Buttons/QuitPressed.png");
    }

    void Pause::setConfigurations()
    {
        for (auto button : _buttons) {
            button.second->setUseAlphaChannel(true);
            button.second->setDrawBorder(false);
        }
    }

    void Pause::setVisible(bool const &status)
    {
        for (auto button : _buttons)
            button.second->setVisible(status);
        for (auto image : _images)
            image.second->setVisible(status);
    }

    void Pause::run()
    {
        return;
    }
}