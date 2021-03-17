/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** Plazza
*/

#ifndef PLAZZA_HPP_
#define PLAZZA_HPP_

#include <iostream>
#include "../Reception/Reception.hpp"

namespace PlazzaProject {
    class Plazza {
        public:
            Plazza();
            void setParameters(int ac, char **argv);
            void start();
            ~Plazza();
        protected:
            float _cookingTimeMultiplier;
            int _numberOfCooks;
            int _replaceStockCooldown;
        private:
    };
}

#endif /* !PLAZZA_HPP_ */
