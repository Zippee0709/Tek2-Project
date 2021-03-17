/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Player
*/

#pragma once
#include <memory>
#include <map>
#include "../../irrlicht-1.8.4/include/irrlicht.h"
#include "Map.hpp"
#include "Bomb.hpp"
#include "Entity.hpp"

namespace IndieStudio {
    class Player {
        public:
            Player() = default;
            Player(int id, Map map, irr::scene::IAnimatedMeshSceneNode *mesh,
                irr::video::ITexture *texture, const irr::core::vector3df &position,
                std::shared_ptr<std::map<std::string, irr::scene::IMesh *>> meshes,
                std::shared_ptr<std::map<std::string, std::shared_ptr<Entity>>> sceneNodes,
                irr::scene::ISceneManager *smng,
                bool isIA = false);
            ~Player();

            irr::scene::IAnimatedMeshSceneNode *getMesh() const;

            void plantBomb();

            /* Getters */
            int getBombs() const { return *_bombs; };
            int getSpeed() const { return *_speed; };
            int getRange() const { return *_range; };
            int getPassWall() const { return *_passWall; };
            int getIAStatus() const { return _isIA; };
            int getScore() const { return _score; };
            int getId() const { return _id; };
            int getIsAlive() const { return *_isAlive; };
            bool getUpdateMove() const { return *_updateMove;};
            int getOffsetX() const { return *_offsetX;};
            int getOffsetZ() const { return *_offsetZ;};
            int getLastPositionX() const { return *_lastPositionX;};
            int getLastPositionZ() const { return *_lastPositionZ;};

            /* Setters */
            void setBombs(int const allBombs) { *_bombs = allBombs; };
            void setSpeed(int const allSpeed) { *_speed = allSpeed; };
            void setRange(int const allRange) { *_range = allRange; };
            void setPassWall(bool const pw) { *_passWall = pw; };
            void setIAStatus(bool const ia) { _isIA = ia; };
            void setScore(int const allScore) { _score = allScore; };
            void setId(int const formerId) { _id = formerId; };
            void setIsAlive(bool const &status) { *_isAlive = status ;};
            void setUpdateMove(bool const &status, int newCoordX, int newCoordZ ) 
                {*_updateMove = status; *_offsetX = newCoordX; *_offsetZ = newCoordZ;
                *_lastPositionX = _mesh->getPosition().X + newCoordX; *_lastPositionZ = _mesh->getPosition().Z + newCoordZ;};
            int getBombPlanted() { return *_bombPlanted;};
            void decreaseBombPlanted();
            void addBombs() { *_bombs += 1;};
            void addSpeed() { *_speed += 1;};
            void addRange() { *_range += 1;};
            void addPassWall() { *_passWall = true;};

        protected:
        private:
            irr::scene::IAnimatedMeshSceneNode *_mesh;
            irr::video::ITexture *_texture;

            Bomb _bomb;
            Map _map;

            std::shared_ptr<int> _speed = std::make_shared<int>(1);
            std::shared_ptr<int> _range = std::make_shared<int>(1);
            std::shared_ptr<int> _bombs = std::make_shared<int>(1);
            std::shared_ptr<int> _passWall = std::make_shared<int>(false);

            std::shared_ptr<bool> _updateMove = std::make_shared<bool>(false);
            std::shared_ptr<int> _bombPlanted = std::make_shared<int>(0);

            std::shared_ptr<int> _offsetX = std::make_shared<int>(0);
            std::shared_ptr<int> _offsetZ = std::make_shared<int>(0);

            std::shared_ptr<int> _lastPositionX = std::make_shared<int>(0);;
            std::shared_ptr<int> _lastPositionZ = std::make_shared<int>(0);;
            bool _isIA;
            int _score = 0;
            int _id;
            std::shared_ptr<bool> _isAlive = std::make_shared<bool>(true);
    };
}
