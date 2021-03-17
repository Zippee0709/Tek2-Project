/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Entity
*/

#ifndef Entity_HPP_
#define Entity_HPP_

#include <iostream>
#include "../core/Clock.hpp"
#include "../../irrlicht-1.8.4/include/irrlicht.h"

namespace IndieStudio {
    enum EntityType {
        WALL,
        UNBREAKWALL,
        UNBREAKWALLBORDURE,
        PBOMB,
        PRANGE,
        PPASSWALL,
        PSPEED,
        BOMB,
        EXPLOSION,
    };
    class Entity {
        public:
            Entity(EntityType type, irr::scene::ISceneNode *sceneNode);
            Entity(EntityType type, irr::scene::ISceneNode *sceneNode, float time, std::string const &playerID = "PLAYERONE");
            Entity(int idPlayer, irr::scene::ISceneNode *sceneNode);
            ~Entity();
            irr::scene::ISceneNode *getSceneNode() {return _sceneNode;};
            void setSceneNode(irr::scene::ISceneNode *sceneNode) {_sceneNode = sceneNode;};
            bool checkTimer(int time); // NOTE : ONLY FOR POWER UP AND BOMB
            bool checkTimer();
            EntityType getType() {return _type;};
            bool getToRemove() { return _toRemove;};
            std::string getPlayerID();
        private:
            irr::scene::ISceneNode *_sceneNode;
            EntityType _type;
            std::chrono::high_resolution_clock::time_point _startBomb;
            Clock _clock;
            bool _toRemove = false;
            int _idPlayer;
            int _time;
    };
}

#endif /* !Entity_HPP_ */
