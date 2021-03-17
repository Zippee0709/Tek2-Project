/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Bomb
*/

#include <string>
#include "Bomb.hpp"

namespace IndieStudio {
    Bomb::Bomb(int idPlayer, std::shared_ptr<std::map<std::string, irr::scene::IMesh *>> meshes,
        std::shared_ptr<std::map<std::string, std::shared_ptr<Entity>>> sceneNodes, irr::scene::ISceneManager *smng)
        : Item(), _meshes(meshes), _entities(sceneNodes), _smng(smng), _idPlayer(idPlayer)
    {
    }

    bool Bomb::checkCanCreateBomb(float x, float z)
    {
        for (auto &entity : (*_entities)) {
            if (entity.second->getType() == EntityType::BOMB) {
                if (entity.second->getSceneNode()->getPosition().X == x && entity.second->getSceneNode()->getPosition().Z == z)
                    return false;
            }
        }
        return true;
    }

    void Bomb::createBomb(float x, float z)
    {
        static int bombId = 0;

        if (checkCanCreateBomb(x, z)) {
            std::string tmp = "BOMB" + std::to_string(bombId);
            (*_entities)[tmp] = std::make_shared<Entity>(_idPlayer,_smng->addMeshSceneNode(((*_meshes)["BOMB"])));
            (*_entities)[tmp]->getSceneNode()->setScale({4, 4, 4});
            (*_entities)[tmp]->getSceneNode()->setMaterialFlag(irr::video::EMF_LIGHTING, true);
            (*_entities)[tmp]->getSceneNode()->setPosition({x, 0, z});
            bombId += 1;
        }
    }

    int Bomb::getRange() const {
        return _range;
    }

    Bomb::~Bomb()
    {
    }
}
