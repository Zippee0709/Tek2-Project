/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** Kitchen
*/

#ifndef KITCHEN_HPP_
#define KITCHEN_HPP_

#include <map>
#include <chrono>
#include <vector>
#include "ScopedLock.hpp"
#include "Thread.hpp"
#include "../Plazza/SharedMemory.hpp"

namespace PlazzaProject {
    class Kitchen {
        public:
            Kitchen(float, int, int, SharedMemory);
            void receiveCommand();
            ~Kitchen();
        protected:
        private:
        enum Ingredient {
            doe,
            tomato,
            gruyere,
            ham,
            mushroom,
            steak,
            eggplant,
            goatCheese,
            chiefLove
        };
        std::map<Ingredient, int> _stock;
        float _cookingTimeMultiplier;
        int _numberOfCooks;
        int _replaceStockCooldown;
        bool _isFull;
        std::chrono::time_point<std::chrono::high_resolution_clock> _start;
        std::vector<PlazzaProject::Thread *> _cooks;
        bool isAlive = true;
        SharedMemory _shMem;
    };
}

#endif /* !KITCHEN_HPP_ */
