/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** Reception
*/

#ifndef RECEPTION_HPP_
#define RECEPTION_HPP_

#include <iostream>
#include <vector>
#include "../Plazza/Plazza.hpp"
#include "../Plazza/PlazzaProject.hpp"
#include "../Exception/PlazzaException.hpp"
#include "../Plazza/SharedMemory.hpp"

namespace PlazzaProject {
    class Reception {
        public:
            Reception(float, int, int);
            void takeCommand();
            void takeUserCommmand();
            ~Reception();
        protected:
        private:
            std::vector<std::string> parseInput(void) const;
            void parseOrderIntoCommand(std::vector<std::string> const &);
            void checkCommand(std::vector<std::string> const &);
            PizzaType checkPizzaType(std::string const &) const;
            PizzaSize checkPizzaSize(std::string const &) const;
            int checkNumberPizzaAsk(std::string const &) const;
            void sendCommandToKitchen();

            std::string _userInput;
            float _cookingTimeMultiplier;
            int _numberOfCooks;
            int _replaceStockCooldown;
            std::vector<PlazzaProject::Command> _commands;
            SharedMemory _shMem;
            SharedMemoryData _sharedMemoryData;
    };
}

#endif /* !RECEPTION_HPP_ */
