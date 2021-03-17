/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** getCommand
*/

#ifndef GETCOMMAND_HPP_
#define GETCOMMAND_HPP_

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include <csignal>
#include "../Parsing/Parsing.hpp"
#include "../Exception/InvalidArgv.hpp"
#include "../Component/Factory.hpp"

namespace Command {
    class getCommand
    {
        public:
            getCommand(std::map<std::string, std::unique_ptr<nts::Component>> &componentMap);
            ~getCommand();

            void getInput(std::map<std::string, std::unique_ptr<nts::Component>> &componentMap);
            void exit();
            void display();
            void simulate(std::map<std::string, std::unique_ptr<nts::Component>> &componentMap);
            void loop(std::map<std::string, std::unique_ptr<nts::Component>> &componentMap);
            void dump();
        private:
            int _status;
            static void staticSignalHandler(int signum);
            void check_input(std::string const &input, std::map<std::string, std::unique_ptr<nts::Component>> &componentMap);
            void reset_component_state(std::map<std::string, std::unique_ptr<nts::Component>> &componentMap);
            std::map<std::string, nts::Tristate> _map_info;
    };
}
#endif /* !GETCOMMAND_HPP_ */

