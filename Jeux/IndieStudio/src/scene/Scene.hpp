/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Scene #Abstract Class
*/

#ifndef SCENE_HPP_
#define SCENE_HPP_

#include <memory>
#include <map>
#include <iostream>
#include "../../irrlicht-1.8.4/include/irrlicht.h"
#include "../data/IndieStudioData.hpp"
#include "IScene.hpp"
#include "../core/Clock.hpp"
#include "../config.h"

namespace IndieStudio {
    class Scene : public IScene {
        public:
            Scene(irr::IrrlichtDevice *device, std::shared_ptr<gameState> state);
            ~Scene();
            void setState(gameState state) { *_state = state; };
            std::shared_ptr<gameState> getState() const;
            irr::gui::IGUIButton *getButtons(std::string const &);
            irr::video::ITexture *getTextures(std::string const &);
            irr::gui::IGUIImage *getImages(std::string const &);
            irr::scene::IAnimatedMeshSceneNode *getMesh(std::string const &);
            irr::scene::ICameraSceneNode * getCamera();
            virtual void run() = 0;
        protected:
            void backgroundEffect(std::string const &key, int time, int max);
            void initTexturesBackground(std::string const &path, std::string const &name, int end, std::string const &extension);
            void addTexturestoImages(std::string const &key, int end);

            Clock _clock;
            int _backgroundCurrent;
            std::shared_ptr<gameState> _state;
            std::map<std::string, irr::gui::IGUIButton *> _buttons;
            std::map<std::string, irr::video::ITexture *> _textures;
            std::map<std::string, irr::gui::IGUIImage *> _images;
            std::map<std::string, irr::scene::IAnimatedMeshSceneNode *> _mesh;
            irr::IrrlichtDevice *_device;
            irr::video::IVideoDriver *_driver;
            irr::gui::IGUIEnvironment *_guienv;
            irr::scene::ISceneManager *_smng;
            irr::scene::ICameraSceneNode *_camera;
        private:
            void init();
    };
}
#endif /* !SCENE_HPP_ */
