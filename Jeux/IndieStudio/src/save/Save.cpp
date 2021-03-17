/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Save
*/

#include <iostream>
#include "Save.hpp"

namespace IndieStudio
{
    void Save::saveGame(std::map<std::string, std::shared_ptr<Entity>> entities, selectMenuConfig settings, std::map<std::string, Player> players)
    {
        Save::convertIrrlichtMap(entities);
        createJson(players, settings);
    }

    void Save::convertIrrlichtMap(std::map<std::string, std::shared_ptr<Entity>> entities)
    {
        std::map<int, std::map<int, char>> map = fillMap();
        irr::core::vector3df pos;
        EntityType type;
        char c;

        for (auto &entity : entities) {
            pos = entity.second->getSceneNode()->getPosition();
            type = entity.second->getType();
            switch (type) {
                case EntityType::BOMB:
                    c = 'b';
                    break;
                case EntityType::EXPLOSION:
                    c = 'e';
                    break;
                case EntityType::UNBREAKWALL:
                    c = 'u';
                    break;
                case EntityType::WALL:
                    c = 'c';
                    break;
                case EntityType::PBOMB:
                    c = 'B';
                    break;
                case EntityType::PPASSWALL:
                    c = 'P';
                    break;
                case EntityType::PRANGE:
                    c = 'R';
                    break;
                case EntityType::PSPEED:
                    c = 'S';
                    break;
            }
            map[pos.X][pos.Z] = c;
        }
        Save::createTxt(map);
    }

    void Save::createTxt(std::map<int, std::map<int, char>> map)
    {
        std::ofstream outfile(_mapFilename);

        for (auto x : map) {
            for (auto y : x.second) {
                outfile << y.second;
            }
            outfile << std::endl;
        }
        outfile.close();
    }

    std::map<int, std::map<int, char>> Save::fillMap()
    {
        std::map<int, std::map<int, char>> map;
        const int min = -100;
        const int max = 101;

        for (int i = min; i != max; i++) {
            for (int j = min; j != max; j++) {
                map[i][j] = '.';
            }
        }
        return map;
    }

    void Save::createJson(std::map<std::string, Player> players, selectMenuConfig settings)
    {
        pt::ptree root;

        try {
            for (auto &player : players) {
                pt::ptree playerNode;
                pt::ptree playerStats;
                pt::ptree playerCoords;

                playerStats.put("bombs", player.second.getBombs());
                playerStats.put("speed", player.second.getSpeed());
                playerStats.put("range", player.second.getRange());
                playerStats.put("passWall", player.second.getPassWall() );

                playerCoords.put("X", player.second.getMesh()->getPosition().X);
                playerCoords.put("Z", player.second.getMesh()->getPosition().Z);

                playerNode.add_child("stats", playerStats);
                playerNode.add_child("coords", playerCoords);

                playerNode.put("id", player.second.getId());
                playerNode.put("isAlive", player.second.getIsAlive());
                playerNode.put("score", player.second.getScore());
                playerNode.put("isIA", player.second.getIAStatus());
                playerNode.put("skinDae", settings.playersSkinDae   [player.second.getId()].c_str());
                playerNode.put("skinImage", settings.playersSkinImage   [player.second.getId()].c_str());

                root.add_child("player" + std::to_string(player.second.getId()), playerNode);
                root.put("map", _mapFilename);
                pt::write_json(_gameFilename, root);
            }
        } catch (std::exception &err) {
            std::cerr << err.what() << std::endl;
        }
    }

    void Save::loadGame(IndieStudio::Game *game)
    {
        pt::ptree root;
        selectMenuConfig config;
        std::string mapFilename;
        std::map<int, std::map<int, char>> map;

        try {
            pt::read_json(_gameFilename, root);
            int nbPlayer = -1;

            for (int i = 0; i != root.size() - 1; i++) {
                Player actualPlayer;

                switch (i) {
                    case 0:
                        actualPlayer = game->getPlayer("PLAYERONE");
                        break;
                    case 1:
                        actualPlayer = game->getPlayer("PLAYERTWO");
                        break;
                }

                for (auto &player : root.get_child("player" + std::to_string(i)))
                {
                    std::string field = player.first;

                    if (field == "stats") {
                        actualPlayer.setBombs(player.second.get<int>("bombs", 0));
                        actualPlayer.setSpeed(player.second.get<int>("speed", 0));
                        actualPlayer.setRange(player.second.get<int>("range", 0));
                        actualPlayer.setPassWall(player.second.get<int>("passWall", 0));
                    } else if (field == "coords") {
                        actualPlayer.getMesh()->setPosition({ player.second.get<float>("X", 0), 0, player.second.get<float>("Z", 0) });
                        game->setHasPositions(true);
                    }
                    else if (field == "id")
                        actualPlayer.setId(std::stoi(player.second.data()));
                    else if (field == "isAlive")
                        actualPlayer.setIsAlive(std::stoi(player.second.data()));
                    else if (field == "score")
                        actualPlayer.setScore(std::stoi(player.second.data()));
                    else if (field == "isIA") {
                        actualPlayer.setIAStatus(std::stoi(player.second.data()));
                        if (actualPlayer.getIAStatus() == false)
                            nbPlayer += 1;
                    }
                    else if (field == "skinDae")
                        config.playersSkinDae[actualPlayer.getId()] = irr::io::path(player.second.data().c_str());
                    else if (field == "skinImage")
                        config.playersSkinImage[actualPlayer.getId()] = irr::io::path(player.second.data().c_str());
                }
            }
            config.haveTwoPlayer = nbPlayer;
            mapFilename = root.get<std::string>("map");
            map = convertTxtToMap(mapFilename);
            game->setAllObjectOnMap(-100, 100, map);
            game->setSelectMenuConfig(config);
            game->setState(gameState::GAME);
        } catch (std::exception &err) {
            std::string errMsg = err.what();

            if (errMsg == "gameSave/gameSaving.json: cannot open file")
                game->setState(gameState::SELECTMENU);
            else
                throw Error(err.what(), "loadGame");
        }
    }

    std::map<int, std::map<int, char>> Save::convertTxtToMap(const std::string &filename)
    {
        std::ifstream file(filename);
        std::string content;
        std::map<int, std::map<int, char>> map;
        int x = 0;

        if (file.is_open() == false)
            throw Error("can't open map.txt", "convertTxtToMap");
        content.assign((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
        file.close();

        for (int i = 0; i != 201; i++) {
            for (int j = 0; j != 201; j++) {
                map[i][j] = content[x];
                x++;
            }
            x++;
        }
        return map;
    }
}