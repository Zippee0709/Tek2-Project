/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2019
** File description:
** Sound.hpp
*/

#ifndef SOUND_HPP_
#define SOUND_HPP_

#include <SFML/Audio.hpp>
#include "../scene/Scene.hpp"
#include "../core/Error.hpp"

namespace IndieStudio {
    class Sound {
        public:
            Sound();
            ~Sound();
            void initSoundSystem();
            void initSoundEffect();
            void initBombSound(int volume);

            void initScene();
            void initTextures();
            void setVisible(bool const &status);
            void setConfigurations();
            void switchMusic(std::shared_ptr<gameState> state, int param);

        private:
            void initSound();
            sf::Sound createMusic(sf::SoundBuffer get, int volume);
            gameState _oldState = SPLASHSCREEN;

            sf::SoundBuffer _getmenu;
            sf::SoundBuffer _getgame;
            sf::SoundBuffer _getbomb;
            sf::Sound _menu;
            sf::Sound _game;
            sf::Sound _bomb;
    };
}

#endif