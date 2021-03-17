/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** getCommand
*/

#include "getCommand.hpp"
#include "../Component/Pin.hpp"

Command::getCommand::getCommand(std::map<std::string, std::unique_ptr<nts::Component>> &componentMap)
{
    _status = 0;
    for (auto const &component : componentMap) {
        if (component.second->getType() == Parser::Type::OUTPUT) {
            _map_info.insert(std::make_pair(component.second->getName(), component.second->compute()));
        }
    }
    signal(SIGINT, Command::getCommand::staticSignalHandler);
    _status = 0;

    while (_status == 0) {
        getInput(componentMap);
    }
}

Command::getCommand::~getCommand()
{

}

void Command::getCommand::staticSignalHandler(int signum)
{
    // _loop = 1;
}

void Command::getCommand::loop(std::map<std::string, std::unique_ptr<nts::Component>> &componentMap)
{
    // _loop = 0;
    // std::signal(SIGINT, SIG);   

    // while (_loop == 0) {
    //     simulate(componentMap);
    // }
}


void Command::getCommand::check_input(std::string const &input, std::map<std::string, std::unique_ptr<nts::Component>> &componentMap)
{
    //Dans le cas ou il y pas de sign = donc appeler une fonction membre
    try {
        if (input.find("=") == std::string::npos) {
            if (input == "simulate")
                simulate(componentMap);
            else if (input == "display")
                display();
            else if (input == "exit")
                exit();
            else if (input == "loop")
                loop(componentMap);
            else if (input == "dump")
                dump();
            else
                throw Exception::InvalidArgv("Command not found");
        } else {
            if (input.find("=") != std::string::npos) {
                std::string first_word = input.substr(0, input.find("="));
                std::string second_word = input.substr(input.find("=") + 1);
                if (componentMap.count(first_word) > 0) {
                    if (second_word == "0") {
                        componentMap[first_word]->getSinglePin(1)->setState(nts::Tristate::FALSE);
                    } else if (second_word == "1") {
                        componentMap[first_word]->getSinglePin(1)->setState(nts::Tristate::TRUE);
                    } else if (second_word == "UNDEFINE"){
                        componentMap[first_word]->getSinglePin(1)->setState(nts::Tristate::UNDEFINED);
                    }else
                        throw Exception::InvalidArgv("Error: Invalid State");
                } else
                    throw Exception::InvalidArgv("Error: Invalid Input");
            } 
        }
    } catch (Exception::InvalidArgv &e) {
        std::cerr << e.what() << std::endl;
        getInput(componentMap);
    }
}

void Command::getCommand::getInput(std::map<std::string, std::unique_ptr<nts::Component>> &componentMap)
{
    std::string input = "";

    std::cout << "> ";
    if (getline(std::cin, input)) {
        check_input(input, componentMap);
    } else
        _status = 1;
}

void Command::getCommand::exit()
{
    _status = 1;
}

void Command::getCommand::display()
{
    for (auto const &component : _map_info) {
        std::cout << component.first << "=" << component.second << std::endl;
    }
}

void Command::getCommand::simulate(std::map<std::string, std::unique_ptr<nts::Component>> &componentMap)
{
    for (auto &component : componentMap) {
        if (component.second->getType() == Parser::Type::CLOCK) {
            if (component.second->compute(1) == nts::Tristate::TRUE)
                component.second->getSinglePin(1)->setState(nts::Tristate::FALSE);
            else
                component.second->getSinglePin(1)->setState(nts::Tristate::TRUE);
        }
        if (component.second->getType() != Parser::Type::INPUT && component.second->getType() != Parser::Type::CLOCK
            && component.second->getType() != Parser::Type::TRUE && component.second->getType() != Parser::Type::FALSE)
            component.second->reset();
    }
    for (auto &component : componentMap) {
        if (component.second->getType() == Parser::Type::OUTPUT) {
            componentMap[component.first]->getSinglePin(1)->setState(nts::Tristate::UNDEFINED);
            component.second->getSinglePin(1)->setState(nts::Tristate::UNDEFINED);
            nts::Tristate mode = component.second->compute(1);
            _map_info[component.second->getName()] = mode;
        }
    }
}

void Command::getCommand::dump()
{
    std::cout << "dump function" << std::endl;
}