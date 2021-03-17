/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** MakePizza
*/

#ifndef MAKEPIZZA_HPP_
#define MAKEPIZZA_HPP_

#include <iostream>
#include <chrono>
#include <unistd.h>
#include "../Plazza/PlazzaProject.hpp"

namespace PlazzaProject {
    class MakePizza {
        public:
            MakePizza(float const);
            ~MakePizza();

            void *lookWhichPizzaToMake(void *);
            static void * get_func(void *pizza);
            void makePizza(int nb) const;
        private:
            float _multiplier;
    };
}

#endif /* !MAKEPIZZA_HPP_ */