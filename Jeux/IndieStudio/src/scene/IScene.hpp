/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** IScene
*/

#ifndef ISCENE_HPP_
#define ISCENE_HPP_

namespace IndieStudio {
    class IScene {
        public:
            virtual void initScene() = 0;
            virtual void initTextures() = 0;
            virtual void setConfigurations() = 0;
            virtual void setVisible(bool const &status) = 0;
            virtual ~IScene() = default;
    };
}

#endif /* !ISCENE_HPP_ */
