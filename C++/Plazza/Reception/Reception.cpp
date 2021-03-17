/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** Reception
*/

#include <vector>
#include <sys/mman.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include "Reception.hpp"
#include "../Kitchen/Kitchen.hpp"

namespace PlazzaProject {

Reception::Reception(float cookingTimeMultiplier, int numberOfCooks, int replaceStockCoolDown)
    :_cookingTimeMultiplier(cookingTimeMultiplier), _numberOfCooks(numberOfCooks), _replaceStockCooldown(replaceStockCoolDown)
{
}

Reception::~Reception()
{
}

std::vector<std::string> Reception::parseInput(void) const
{
    std::vector<std::string> result;
    std::string order;
    auto start = 0;
    auto end = _userInput.find(";");

    while (end != std::string::npos) {
        while (_userInput[start] == ' ')
            start += 1;
        while (_userInput[end - 1] == ' ')
            end -= 1;
        order = _userInput.substr(start, end - start);
        // std::cout << order << std::endl;
        result.push_back(order);
        start = end + 1;
        end = _userInput.find(";", start);
    }
    while (_userInput[start] == ' ')
        start += 1;
    order = _userInput.substr(start, end);
    std::cout << order << std::endl;
    result.push_back(order);
    return result;
}

PizzaType Reception::checkPizzaType(std::string const &str) const
{
    if (str == "margarita")
        return margarita;
    else if (str == "regina")
        return regina;
    else if (str == "americana")
        return americana;
    else if (str == "fantasia")
        return fantasia;
    throw PizzaTypeError("The type " + str + " of pizza does not exist");
}

PizzaSize Reception::checkPizzaSize(std::string const &str) const
{
    if (str == "S")
        return S;
    else if (str == "M")
        return M;
    else if (str == "L")
        return L;
    else if (str == "XL")
        return XL;
    else if (str == "XXL")
        return XXL;
    throw PizzaSizeError("The size" + str + " of pizza does not exist");
}

int Reception::checkNumberPizzaAsk(std::string const &str) const
{
    if (str.length() < 2 || str.length() > 3)
        return (-1);
    else {
        if (str.length() == 2 && str[1] < '1' && str[1] > '9')
            return (-1);
        else if (str.length() == 3 && str[2] < '0' && str[2] > '9')
            return (-1);
    }
    return std::stoi(str.substr(1, std::string::npos));
}

void Reception::checkCommand(std::vector<std::string> const &tmp)
{
    Command pizza;

    //Peut etre pas throw des erreurs ici mais des return ?
    //Sinon le reste c'est comme ta demander bg
    if (tmp.size() != 3)
        throw ReceptionError("Invalid reception format.\nSyntax : [TYPE SIZE NUMBER]");
    pizza.pizzaType = checkPizzaType(tmp.at(0));
    pizza.pizzaSize = checkPizzaSize(tmp.at(1));
    pizza.pizzaNumber = checkNumberPizzaAsk(tmp.at(2));
    if (pizza.pizzaNumber == -1)
        throw PizzaNumberError("The syntax for the number of pizza is \"x[NUMBER]\"");
    _commands.push_back(pizza);
}

void Reception::parseOrderIntoCommand(std::vector<std::string> const &order)
{
    for (auto stringOrder : order) {
        auto start = 0;
        auto end = stringOrder.find(" ");
        std::vector<std::string> tmp;
        while (end != std::string::npos) {
            std::string ptr = stringOrder.substr(start, end - start);
            tmp.push_back(ptr);
            start = end + 1;
            end = stringOrder.find(" ", start);
        }
        std::string ptr = stringOrder.substr(start, end);
        tmp.push_back(ptr);
        checkCommand(tmp);
    }
}

void Reception::takeUserCommmand()
{
    try {
        std::vector<std::string> order = parseInput();
        parseOrderIntoCommand(order);
        std::cout << "Check Parsing :" << std::endl;
        for (auto tmp : _commands) {
            std::cout << "pizza type = " << tmp.pizzaType << std::endl;
            std::cout << "pizza size = " << tmp.pizzaSize << std::endl;
            std::cout << "pizza number = " << tmp.pizzaNumber << std::endl;
        }
        sendCommandToKitchen();
    } catch (ReceptionError e) {
        std::cout << e.getSpot() << ": " << e.what() << std::endl;
    }
}

void Reception::sendCommandToKitchen()
{
    bool needToFork = false;
    int pid;
    std::cout << "COMMAND VALID -- SEND TO KITCHEN: " << _userInput << std::endl;
    for (auto command : _commands) {
        std::cout << "Serialized Data : \n" << command << std::endl;
    }
    _sharedMemoryData.commands = &_commands;
    _sharedMemoryData.kitchenStatus[0] = true;
    _sharedMemoryData.numberOfKitchen = 1;

    _shMem.writeData(_sharedMemoryData);
    //fork
    for (auto kitchen : _sharedMemoryData.kitchenStatus) {
        if (kitchen.second == true)
            needToFork = true;
    }
    if (needToFork) {
        pid = fork();
    }
    if (pid == 0) {
        Kitchen kitchen(_cookingTimeMultiplier, _numberOfCooks, _replaceStockCooldown, _shMem);
        kitchen.receiveCommand();
    }
}

void Reception::takeCommand()
{
    while (1) {
        std::cout << ">";
        std::getline(std::cin, _userInput);
        takeUserCommmand();
    }
}

}