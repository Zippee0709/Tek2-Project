/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Core
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#include <iostream>
#include <experimental/filesystem>
#include <vector>
#include <chrono>
#include "../lib/Graphic.hpp"
#include "../games/Game.hpp"

class Core {
    using timePoint = std::chrono::time_point<std::chrono::high_resolution_clock>;
    using getGraph = Graphic::Graphic *(*)(std::map<int, std::string>, std::map<int, std::string>, std::shared_ptr<timePoint>);
    using getGame = myGame::Game *(*)(std::shared_ptr<timePoint>, std::shared_ptr<int>);

    public:
        Core(const std::string &libPath);
        void startArcade();
        void loadGraphicLibrary(const std::string &libPath, bool isOn);
        void loadGameLibrary(const std::string &gameLibPath, bool isOn);
        void changeLib();
        bool readGameDir();
        void setActualGraphic(const std::string &libPath);
        void setActualGame(const std::string &gameLibPath);
        bool readGraphDir();
        ~Core();
    
    protected:
    private:
        bool readDir(const std::string &path, bool isGameDir);
        void *_dynamicLibrary;
        void *_dynamicLibraryGame;
        Graphic::Graphic *_myGraph;
        myGame::Game *_myGame;
        getGame _createGame;
        getGraph _createGraph;
        std::shared_ptr<timePoint> _start;
        std::shared_ptr<int> _score;

        std::shared_ptr<Controller::Scene> _scene;
        std::shared_ptr<int> _actualGraphic;
        std::shared_ptr<int> _actualGame;
        int _precedentGraphic;
        int _precedentGame;
        std::map<int, std::string> _graphLibs;
        std::map<int, std::string> _gameLibs;
        std::string _actualLib; // Temporaire a enlever puis remplacer par un stack
};

#endif /* !CORE_HPP_ */
