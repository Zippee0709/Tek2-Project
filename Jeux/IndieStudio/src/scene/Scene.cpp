/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Scene
*/

#include <string>
#include "Scene.hpp"

namespace IndieStudio {
    Scene::Scene(irr::IrrlichtDevice *device, std::shared_ptr<gameState> state) : 
    _state(state), _driver(device->getVideoDriver()), _guienv(device->getGUIEnvironment()),
    _smng(device->getSceneManager()), _backgroundCurrent(0)
    {
    }

    Scene::~Scene()
    {
    }

    std::shared_ptr<gameState> Scene::getState() const
    {
        return _state;
    }

    irr::gui::IGUIButton *Scene::getButtons(std::string const &name)
    {
        return _buttons[name];
    }
    irr::video::ITexture *Scene::getTextures(std::string const &name)
    {
        return _textures[name];
    }
    irr::gui::IGUIImage *Scene::getImages(std::string const &name)
    {
        return _images[name];
    }
    irr::scene::IAnimatedMeshSceneNode *Scene::getMesh(std::string const &name)
    {
        return _mesh[name];
    }

    irr::scene::ICameraSceneNode *Scene::getCamera()
    {
        return _camera;
    }

    void Scene::backgroundEffect(std::string const &key, int time, int max)
    {
        if (_clock.getDiff() >= time) {
            _backgroundCurrent += 1;
            if (_backgroundCurrent > max)
                _backgroundCurrent = 1;

            std::string tmp = key;
            tmp += std::to_string(_backgroundCurrent);

            for (auto bg : _images) {
                if (bg.first == tmp) {
                    bg.second->setVisible(true);
                }
                else if (bg.first.find(key) == std::string::npos) {
                    bg.second->setVisible(true);
                }
                else {
                    bg.second->setVisible(false);
                }
            }
            _clock.restart();
        }
    }

    void Scene::initTexturesBackground(std::string const &path, std::string const &name, int end, std::string const &extension)
    {
        for (int i = 1; i <= end; i++) {
            std::string tmp(path);
            std::string key(name);
            tmp += name;
            tmp += std::to_string(i);
            key += std::to_string(i);
            tmp += extension;
            irr::core::stringc completePath(tmp.c_str());
            _textures[key] = _driver->getTexture(irr::io::path(pathProject) + completePath);
        }
    }

    void Scene::addTexturestoImages(std::string const &key, int end)
    {
        for (int i = 1; i <= end; i++) {
            std::string completeKey(key);
            completeKey += std::to_string(i);
            _images[completeKey] = _guienv->addImage(_textures[completeKey], irr::core::position2di(0, 0));
        }
    }
}