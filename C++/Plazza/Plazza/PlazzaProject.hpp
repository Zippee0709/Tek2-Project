/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** PlazzaProject, contains all struct need to shared in the project
*/

#ifndef PLAZZAPROJECT_HPP_
#define PLAZZAPROJECT_HPP_
#include <iostream>
#include <vector>
#include <map>

namespace PlazzaProject {
    enum PizzaType {
        margarita = 1,
        regina = 2,
        americana = 4,
        fantasia = 8,
        errorPizza = 404
    };
    enum PizzaSize {
        S = 1,
        M = 2,
        L = 4,
        XL = 8,
        XXL = 16,
        errorSize = 404
    };
    struct Command {
        PizzaType pizzaType;
        PizzaSize pizzaSize;
        int pizzaNumber;
    };
    struct SharedMemoryData {
        std::vector<Command>* commands;
        std::map<int, bool> kitchenStatus;
        int numberOfKitchen;
    };
    inline std::ostream& operator<<(std::ostream& os, const PlazzaProject::Command &c) {
        os << "pizzaType: " << c.pizzaType << std::endl << "pizzaSize: " << c.pizzaSize << std::endl << "pizzaNumber: " << c.pizzaNumber;
        return os;
    }
}

#endif /* !PLAZZAPROJECT_HPP_ */
