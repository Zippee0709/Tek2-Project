/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Core
*/

#include <dirent.h>
#include <unistd.h>
#include <dlfcn.h>
#include "Core.hpp"
#include "Error.hpp"

Core::Core(const std::string &libPath)
{
    _start = std::make_shared<timePoint>(std::chrono::high_resolution_clock::now());
    _score = std::make_shared<int>(0);
    loadGraphicLibrary(libPath, false);
    loadGameLibrary("games/lib_arcade_pacman.so", false);
    _scene = std::make_shared<Controller::Scene>(Controller::Scene::NAME);
}

Core::~Core()
{

}

void Core::loadGameLibrary(const std::string &gameLibPath = nullptr, bool isOn = true)
{
    if ((_dynamicLibraryGame = dlopen(gameLibPath.c_str(), RTLD_LAZY)) == nullptr) {
        throw Error("Error dynamic library games" + gameLibPath + " does not exist.\n" + dlerror());
    }
    if (!isOn)
        setActualGame(gameLibPath);
    _createGame = (getGame)dlsym(_dynamicLibraryGame, "createGame");
    _myGame = _createGame(_start, _score);
    _precedentGame = *_actualGame;
}


void Core::loadGraphicLibrary(const std::string &libPath = nullptr, bool isOn = true)
{
    if ((_dynamicLibrary = dlopen(libPath.c_str(), RTLD_LAZY)) == nullptr) {
        throw Error("Error dynamic library " + libPath + " does not exist.\n" + dlerror());
    }
    _createGraph = (getGraph)dlsym(_dynamicLibrary, "createLib");
    if (!isOn) {
        if (!readGameDir() || !readGraphDir()) {
            throw Error("./lib or ./games directory doesn't exists");
        }
        setActualGraphic(libPath);
    }
    _myGraph = _createGraph(_graphLibs, _gameLibs, _start);
    _precedentGraphic = *_actualGraphic;
}

void Core::changeLib() // TODO : Parametre à enelver et utiliser une stack contenant les lib dispos 
{
    std::cout << "Game Id: " << *_actualGame << "\nGraphic Id: " << *_actualGraphic <<std::endl;
    std::cout << "Scene : " << *_scene << std::endl;
    for (auto a : _graphLibs) {
        std::cout << "Graph libs : " << a.second << std::endl;
    }
    for (auto a : _gameLibs) {
        std::cout << "Game libs : " << a.second << std::endl;
    }
    if (*_actualGraphic != _precedentGraphic && dlopen(_graphLibs[*_actualGraphic].c_str() , RTLD_LAZY) != nullptr) {
        _myGraph->close();
    } else
        return;
    if (dlclose(_dynamicLibrary) != 0)
        throw Error("Error :  Can't close the lib.");
    if (*_actualGraphic != _precedentGraphic) {
        std::cout << "change acutal graphic" << std::endl;
        loadGraphicLibrary(_graphLibs[*_actualGraphic]);
    }
    if (*_actualGame != _precedentGame) {
        std::cout << "change actual game" << std::endl;
        loadGameLibrary(_gameLibs[*_actualGame]);
    }
    _myGraph->setMapSize(_myGame->getMapSize());
    _myGraph->createWindow(_scene, _actualGraphic, _actualGame, _score);
}

bool Core::readGameDir()
{
    return readDir("games", true);
}

bool Core::readGraphDir()
{
    return readDir("lib", false);
}

bool Core::readDir(const std::string &path, bool isGameDir)
{
    struct dirent *dirStruct;
    DIR *directory = opendir(path.c_str());
    int counter = 0;
    std::map<int, std::string> *lib = isGameDir ? &_gameLibs : &_graphLibs;

    if (directory == nullptr) {
        std::cerr << "Path: " << path << " doesn't exists" << std::endl;
        return false;
    }
    while ((dirStruct = readdir(directory)) != NULL) {
        if (std::string(dirStruct->d_name).find(".so") != std::string::npos) {
            lib->insert(std::pair<int, std::string>(counter, (path + "/" + std::string(dirStruct->d_name))));
            counter++;
        }
    }
    return true;
}

void Core::setActualGraphic(const std::string &libPath)
{
    for (auto &graph : _graphLibs) {
        if (libPath == graph.second) {
            _actualGraphic = std::make_shared<int>(graph.first);
            break;
        } 
    }
}

void Core::setActualGame(const std::string &gameLibPath)
{
    for (auto &game : _gameLibs) {
        if (gameLibPath == game.second) {
            _actualGame = std::make_shared<int>(game.first);
            break;
        } 
    }
}

void Core::startArcade()
{
    Controller::Key key = Controller::Key::OTHER;
    _myGraph->setMapSize(_myGame->getMapSize());
    _myGraph->createWindow(_scene, _actualGraphic, _actualGame, _score);

    auto start = std::chrono::high_resolution_clock::now;

    while (key != Controller::Key::CLOSE) { // NOTE: Gestion d'event
        key = _myGraph->eventHandler();
        if (*_scene == Controller::Scene::MENU)
            _myGraph->displayMenu();
        if (*_scene == Controller::Scene::NAME)
            _myGraph->displayMenuName();
        if (*_scene == Controller::Scene::PACMAN) {
            _myGame->updateGame(key);
            _myGraph->displayMap(_myGame->getMap());
        }

        if (key == Controller::Key::N) {
            try {
                std::cout << _actualLib << std::endl;
                changeLib(); // Temporaire
                // changeLib((_actualLib == "lib/lib_arcade_sfml.so") ? "lib/lib_arcade_ncurses.so" : "lib/lib_arcade_sfml.so"); // Temporaire
            } catch (Error e) {
                std::cerr << e.what() << std::endl;
            }
        }
        if (key == Controller::Key::SPACE) {
            std::cout << "Game Id: " << *_actualGame << "\nGraphic Id: " << *_actualGraphic <<std::endl;
            std::cout << "Scene : " << *_scene << std::endl;
        }
    }
    delete _myGraph;
}
