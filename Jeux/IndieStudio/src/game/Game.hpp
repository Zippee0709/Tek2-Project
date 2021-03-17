/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Game
*/

#pragma once
#include <vector>
#include "../scene/Scene.hpp"
#include "Map.hpp"
#include "Player.hpp"
#include "Entity.hpp"


namespace IndieStudio {
    class Game : public Scene {
        public:
            Game(irr::IrrlichtDevice *device, std::shared_ptr<gameState> state, std::shared_ptr<selectMenuConfig> selectMenuConfig);
            ~Game();
            void run();
            void initScene();
            void initTextures();
            void initConfiguration();
            void setConfigurations();
            void setVisible(bool const &status);
            bool haveCollision(Player player, float offsetX, float offsetZ);
            void setAllObjectOnMap(float x, float z, std::map<int, std::map<int, char>> map);
            void quit();
            void findMoveIa(Player player);
            void moveIa(Player player, irr::core::vector3df actualPos, irr::core::vector3df bestMov);
            void setSelectMenuConfig(selectMenuConfig config) { *_selectMenuConfig = config; };
            void setHasPositions(bool const &status) { *_hasPositions = status; };
            void updatePlayerPos();
            void checkWhoIsAlive();

            /* Getters */
            std::map<std::string, Player> getPlayers() const { return _players; };
            Player getPlayer(std::string id) { return _players[id]; };
            std::map<std::string, std::shared_ptr<Entity>> getEntities() const { return *_entities; };
            selectMenuConfig getSelectMenuConfig() const { return *_selectMenuConfig; };
            std::shared_ptr<selectMenuConfig> getSelectMenuConfigPtr() { return _selectMenuConfig; };
            Clock clock;


        private:
            void setObjectOnMap(float x, float z, std::string const &name, EntityType type, float time, std::string const &playerID = "PLAYERONE");
            void addContourWallSceneNode(float x, float z, std::string const &name);
            void addExplosionByRange(irr::core::vector3df const &pos, int range, irr::scene::ISceneNode *node, std::string const &playerID = "PLAYERONE");
            void addPowerUpWhenWallIsDestroy(irr::core::vector3df const &pos);
            void dropEntityByPos( irr::core::vector3df const &pos);
            void updatePlayerStat(Player player, EntityType const &type, irr::core::vector3df const &entityPos);

            bool checkWallByPos(float x, float z);
            std::shared_ptr<selectMenuConfig> _selectMenuConfig;
            Map _map;
            irr::scene::ISceneNode *_ground;
            int _nbObj;
            Player _playerOne;
            Player _playerTwo;
            std::map<std::string, irr::scene::IMesh *> _meshes;
            std::shared_ptr<std::map<std::string, std::shared_ptr<Entity>>> _entities;
            std::map<std::string, Player> _players;
            bool _isFirstTime = true;
            std::shared_ptr<bool> _hasPositions = std::make_shared<bool>(false);
            Clock _clockPlayer;
            std::vector<std::string> _removeEntities;
    };
}
