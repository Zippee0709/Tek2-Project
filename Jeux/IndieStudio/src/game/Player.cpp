/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Player
*/

#include "Player.hpp"
#include "Map.hpp"

namespace IndieStudio {
    Player::Player(int id, Map map, irr::scene::IAnimatedMeshSceneNode *mesh, irr::video::ITexture *texture, const irr::core::vector3df &position,
    std::shared_ptr<std::map<std::string, irr::scene::IMesh *>> meshes, std::shared_ptr<std::map<std::string, std::shared_ptr<Entity>>> sceneNodes, irr::scene::ISceneManager *smng, bool isIA)
        : _map(map), _mesh(mesh), _texture(texture)
    {
        _id = id;
        _isIA = isIA;
        _mesh->setScale(irr::core::vector3df(0.2, 0.2, 0.2));
        _mesh->setPosition(position);
        _mesh->setRotation(irr::core::vector3df(0, 0, 0));
        _mesh->setMaterialFlag(irr::video::EMF_LIGHTING, false);
        _mesh->setMaterialTexture(0, _texture);
        _bomb = Bomb(id, meshes, sceneNodes, smng);
    }

    Player::~Player()
    {
    }

    void Player::plantBomb()
    {
        *_bombPlanted += 1;
        _bomb.createBomb(_mesh->getPosition().X, _mesh->getPosition().Z);
    }

    void Player::decreaseBombPlanted()
    {
        if (*_bombPlanted == 0)
            return;
        *_bombPlanted -= 1;
    }

    irr::scene::IAnimatedMeshSceneNode *Player::getMesh() const
    {
        return _mesh;
    }
}
