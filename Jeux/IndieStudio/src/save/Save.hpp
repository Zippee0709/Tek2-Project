/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Save
*/

#pragma once
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <fstream>
#include "../core/Error.hpp"
#include "../game/Game.hpp"

namespace pt = boost::property_tree;

namespace IndieStudio {
    class Save {
        public:
            Save() = default;
            ~Save() = default;

            static void saveGame(std::map<std::string, std::shared_ptr<Entity>> _entities, selectMenuConfig settings, std::map<std::string, Player> players);
            std::map<int, std::map<int,char>> createMapFromIrrlicht(std::map<std::string, irr::scene::ISceneNode *>);
            static void loadGame(IndieStudio::Game *game);

        protected:
        private:
            static void convertIrrlichtMap(std::map<std::string, std::shared_ptr<Entity>> entities);
            static std::map<int, std::map<int, char>> fillMap();
            static void createTxt(std::map<int, std::map<int, char>>);
            static void createJson(std::map<std::string, Player> players, selectMenuConfig settings);
            static std::map<int, std::map<int, char>> convertTxtToMap(const std::string &filename);
    };
    const std::string _mapFilename = "gameSave/map.txt";
    const std::string _gameFilename = "gameSave/gameSaving.json";
}
