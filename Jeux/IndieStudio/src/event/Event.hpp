/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Event
*/

#ifndef EVENT_HPP_
#define EVENT_HPP_

#include <memory>
#include <map>
#include "../../irrlicht-1.8.4/include/irrlicht.h"
#include "../data/IndieStudioData.hpp"
#include "../scene/Scene.hpp"
#include "../selectMenu/SelectMenu.hpp"
#include "../game/Game.hpp"
#include "../save/Save.hpp"
#include "../sound/Sound.hpp"

namespace IndieStudio {
    class Event : public irr::IEventReceiver {
        public:
            Event(irr::IrrlichtDevice *device, std::shared_ptr<gameState> state, std::map<gameState, Scene *> &scene, std::shared_ptr<selectMenuConfig> selectMenuConfig, std::shared_ptr<menuSettingConfig> menuSettingConfig);
            ~Event();
            virtual bool OnEvent(const irr::SEvent &event);
        protected:
        private:
            bool menuEvent(irr::s32 id);
            bool selectMenuEvent(irr::s32 id);
            bool settingEvent(irr::s32 id);
            bool playerEvent(std::string const &name, const irr::SEvent &event, playerKeyBinding pkb);
            bool pauseEvent(irr::s32 id);
            bool gameOverEvent(irr::s32 id);
            void pressedExit(const irr::SEvent &event); // NOTE : TEMPORAIRE POUR GAME
            irr::IrrlichtDevice *_device;
            std::shared_ptr<gameState> _state;
            std::map<gameState, Scene *> _scene;
            std::shared_ptr<selectMenuConfig> _selectMenuConfig;
            std::shared_ptr<menuSettingConfig> _menuSettingConfig;
            playerKeyBinding _playerOneKeyBinding;
            playerKeyBinding _playerTwoKeyBinding;
            bool _lock1Pressed;
            bool _lock2Pressed;
            bool _gameState;
            bool _isMoving;
            bool _returnInGame;
            Sound _sound;
    };
}
#endif /* !EVENT_HPP_ */