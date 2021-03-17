/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Object
*/

#include "Entity.hpp"

namespace IndieStudio {
    Entity::Entity(EntityType type, irr::scene::ISceneNode *sceneNode) :
        _type(type), _sceneNode(sceneNode)
    {
    }

    Entity::Entity(EntityType type, irr::scene::ISceneNode *sceneNode, float time, std::string const &playerID) :
        _type(type), _sceneNode(sceneNode), _time(time), _startBomb(std::chrono::high_resolution_clock::now())
    {
        if (playerID == "PLAYERONE")
            _idPlayer = 0;
        else if (playerID == "PLAYERTWO")
            _idPlayer = 1;
        else if (playerID == "PLAYERTHREE")
            _idPlayer = 2;
        else if (playerID == "PLAYERFOUR")
            _idPlayer = 3;
    }

    Entity::Entity(int idPlayer, irr::scene::ISceneNode *sceneNode) :
        _type(BOMB), _sceneNode(sceneNode), _startBomb(std::chrono::high_resolution_clock::now()), _idPlayer(idPlayer)
    {
    }


    Entity::~Entity()
    {
    }

    bool Entity::checkTimer(int time)
    {
        if (_clock.getElapsedTimeInSecondWithStartPoint(_startBomb) > time) {
            this->_toRemove = true;
            return true;
        }
        return false;
    }

    bool Entity::checkTimer()
    {
        if (_clock.getElapsedTimeInSecondWithStartPoint(_startBomb) > _time) {
            this->_toRemove = true;
            return true;
        }
        return false;
    }

    std::string Entity::getPlayerID()
    {
        switch (_idPlayer) {
            case 0:
                return "PLAYERONE";
            case 1:
                return "PLAYERTWO";
            case 2:
                return "PLAYERTHREE";
            case 3:
                return "PLAYERFOUR";
            default:
                return "PLAYERONE";
        }
    }
}