/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2019
** File description:
** sound.cpp
*/

#include "Sound.hpp"

namespace IndieStudio {
    Sound::Sound() {}

    Sound::~Sound()
    {
        _game.stop();
        _menu.stop();
        _bomb.stop();
    }

    void Sound::initSoundSystem()
    {
        try {
            _getgame.loadFromFile(std::string(pathProject) + "/resources/Sound/game.wav");
            _getmenu.loadFromFile(std::string(pathProject) + "/resources/Sound/menu.wav");
            initSound();
        } catch (const std::exception &err) {
            throw Error(err.what(), "initSoundSystem");
        }
    }

    void Sound::initSound() {
        _menu.setBuffer(_getmenu);
        _game.setBuffer(_getgame);
        _menu.setLoop(true);
        _game.setLoop(true);
    }

    void Sound::initSoundEffect()
    {
        try {
            _getbomb.loadFromFile(std::string(pathProject) + "/resources/Sound/boom.wav");
            _bomb.setBuffer(_getbomb);
        } catch (const std::exception &err) {
            throw Error(err.what(), "initSoundEffect");
        }
    }

    sf::Sound Sound::createMusic(sf::SoundBuffer get, int volume)
    {
        sf::Sound music;

        music.setBuffer(get);
        music.setVolume(volume);
        music.setLoop(true);
        return (music);
    }

    void Sound::switchMusic(std::shared_ptr<gameState> state, int param)
    {
        static bool setting = false;

        _game.setVolume(param);
        _menu.setVolume(param);
        if (_oldState == *state)
            return;
        _oldState = *state;
        if (*state == gameState::SPLASHSCREEN) {
        } else if (*state == gameState::SELECTMENU) {
            _game.play();
            _menu.stop();
        } else if (*state == gameState::MENU && !setting) {
            _menu.play();
            _game.stop();
            setting = true;
        }
    }

    void Sound::initBombSound(int volume) {
        _bomb.setVolume(volume);
        _bomb.play();
    }

    void Sound::initScene() {}

    void Sound::initTextures() {}

    void Sound::setVisible(bool const &status){}

    void Sound::setConfigurations() {}
}