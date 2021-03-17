/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Item
*/

#pragma once

#include "../core/Clock.hpp"
#include "../../irrlicht-1.8.4/include/irrlicht.h"

namespace IndieStudio {
    class Item {
        public:
            Item() = default;
            Item(int x, int y);
            ~Item();

        protected:
            Clock _clock;
            void setTimer(int milliseconds);
        private:
            int _x;
            int _y;
    };
}
