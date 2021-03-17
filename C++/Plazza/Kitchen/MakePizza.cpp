/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** MakePizza
*/

#include "MakePizza.hpp"

namespace PlazzaProject {

    MakePizza::MakePizza(float const multiplier) : _multiplier(multiplier)
    {
    }

    MakePizza::~MakePizza()
    {
    }

    void *MakePizza::lookWhichPizzaToMake(void * pizza) 
    {
        PizzaType tmp = *(PizzaType *)pizza;
    
        if (tmp == PizzaType::margarita) {
            std::cout << "cook margarita" << std::endl;
            makePizza(1 * _multiplier);
        }
        else if (tmp == PizzaType::regina || tmp == PizzaType::americana) {
            std::cout << "cook regina or americana" << std::endl;
            makePizza(2 * _multiplier);
        }
        else if (tmp == PizzaType::fantasia) {
            std::cout << "cook fantasia" << std::endl;
            makePizza(4 * _multiplier);
        }
        return NULL;
    }

    static void * get_func(void * pizza)
    {
        // return ((MakePizza*)pizza)->lookWhichPizzaToMake(pizza);
    }

    void MakePizza::makePizza(int nb) const
    {
        std::cout << "start to make pizza" << std::endl;
        sleep(nb);
        std::cout << "finish" << std::endl;
    }
}