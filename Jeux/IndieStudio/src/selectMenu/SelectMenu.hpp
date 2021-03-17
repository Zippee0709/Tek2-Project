/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** SelectMenu
*/

#ifndef SELECTMENU_HPP_
#define SELECTMENU_HPP_

#include "../scene/Scene.hpp"

namespace IndieStudio {
    class SelectMenu : public Scene{
        public:
            SelectMenu(irr::IrrlichtDevice *_device, std::shared_ptr<gameState> _state);
            ~SelectMenu();
            void initScene();
            void setVisible(bool const &status);

            void setPlayerLock(int const &player, bool const &status, std::shared_ptr<selectMenuConfig> config);
            void PlayerSelectRight(int const &player, std::shared_ptr<selectMenuConfig> config);
            void PlayerSelectLeft(int const &player, std::shared_ptr<selectMenuConfig> config);
            bool getPlayerLock(int const &player) const;
            void reset();
            void run();
        private:
            void initTextures();
            void checkSkins(std::string const &player, int select);
            void initButtons();
            void initImages();
            void initCharacters();
            void setConfigurations();
            bool _player1Lock = true;
            bool _player2Lock;
            int _player1Select;
            int _player2Select;
            std::map<int, irr::core::stringc> skinSelectedImagePath = {
                {0, irr::io::path(pathProject) + "/resources/Game/Personnage/Aj/Aj.jpg"},
                {1, irr::io::path(pathProject) + "/resources/Game/Personnage/Claire/Claire.jpg"},
                {2, irr::io::path(pathProject) + "/resources/Game/Personnage/GrandMa/GrandMa.jpg"},
                {3, irr::io::path(pathProject) + "/resources/Game/Personnage/Kaya/Kaya.jpg"}
            };
            std::map<int, irr::core::stringc> skinSelectedDaePath = {
                {0, irr::io::path(pathProject) + "/resources/Game/Personnage/Aj/Aj.MD3"},
                {1, irr::io::path(pathProject) + "/resources/Game/Personnage/Claire/Claire.MD3"},
                {2, irr::io::path(pathProject) + "/resources/Game/Personnage/GrandMa/GrandMa.MD3"},
                {3, irr::io::path(pathProject) + "/resources/Game/Personnage/Kaya/Kaya.MD3"},
            };
    };
}

#endif /* !SELECTMENU_HPP_ */
