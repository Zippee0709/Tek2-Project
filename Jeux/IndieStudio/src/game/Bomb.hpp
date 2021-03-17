/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Bomb
*/

#pragma once
#include "Item.hpp"
#include "Entity.hpp"
#include <memory>
#include <map>

namespace IndieStudio {
    class Bomb : public Item {
        public:
            Bomb() = default;
            Bomb(int idPlayer, std::shared_ptr<std::map<std::string, irr::scene::IMesh *>> meshes,
                std::shared_ptr<std::map<std::string, std::shared_ptr<Entity>>> sceneNodes,
                irr::scene::ISceneManager *smng);
            ~Bomb();

            void createBomb(float x, float z);
            int getRange() const;
            bool checkTimer();
        protected:
        private:
            bool checkCanCreateBomb(float x, float z);
            int _range = 1;
            int _idPlayer;
            std::shared_ptr<std::map<std::string, irr::scene::IMesh *>> _meshes;
            std::shared_ptr<std::map<std::string, std::shared_ptr<Entity>>> _entities;
            irr::scene::ISceneManager *_smng;
    };
}
