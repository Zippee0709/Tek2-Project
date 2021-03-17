/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** main
*/
/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** main_comp
*/

#include <iostream>
#include "Component/IComponent.hpp"
#include "Component/OrGate.hpp"
#include "Component/Pin.hpp"
#include "Component/Factory.hpp"
#include "Parsing/Parsing.hpp"
#include "GetCommand/getCommand.hpp"
#include "Exception/PinException.hpp"

typedef std::map<std::string, Parser::Type> chipsetsMap;
typedef std::map<std::string, std::string> linksMap;
typedef std::map<std::string, std::string> Argv;

int main(int ac, char **av)
{
    try {
        Parser::Parsing myParse(ac, av);
        Parser::Argv myArgv(ac, av);
        nts::ComponentFactory componentFactory;
        chipsetsMap myChipsets = myParse.getChipsetsVector();
        linksMap myLinks =  myParse.getLinksVector();
        Argv argv = myArgv.getAllInput();
        std::map<std::string, std::unique_ptr<nts::Component>> componentMap;

        int counter = 0;
        std::string componentOne;
        std::string componentTwo;
        size_t linkOne;
        size_t linkTwo;
        nts::Tristate argvState;
        for (auto const &parsedChipset : myChipsets) {
            componentMap[parsedChipset.first] = componentFactory.createComponent(parsedChipset.second, parsedChipset.first);
        }
        for (auto const &av : argv) {
            if (componentMap.count(av.first) <= 0) {
                throw Exception::InvalidArgv("This input doesn't exists");
            }
            if (av.second == "0") {
                argvState = nts::Tristate::FALSE;
            } else if (av.second == "1") {
                argvState = nts::Tristate::TRUE;
            } else {
                throw Exception::InvalidArgv("Error doesn't exists");
            }
            componentMap[av.first]->getSinglePin(1)->setState(argvState); 
        }
        for (auto const &parsedLink : myLinks) {
            componentTwo = parsedLink.second.substr(0, parsedLink.second.find(":"));
            componentOne = parsedLink.first.substr(0, parsedLink.first.find(":"));
            if (componentMap.count(componentOne) <= 0 || componentMap.count(componentTwo) <= 0) {
                throw Exception::InvalidArgv("The composent doesn't exist, please check your nts file.");
            }
            linkOne = std::stoi(parsedLink.first.substr(parsedLink.first.find(":") + 1));
            linkTwo = std::stoi(parsedLink.second.substr(parsedLink.second.find(":") + 1));

            componentMap[componentOne]->setLink(linkOne, *componentMap[componentTwo].get(), linkTwo);
        }
        for (auto const &component : componentMap) {
            if (component.second->getType() == Parser::Type::OUTPUT) {
                std::cout << component.second->getName() << "=" << component.second->compute(1) << std::endl;
            }
        }
        Command::getCommand mycommand(componentMap);
    } catch (Exception::InvalidArgv e) {
        std::cerr << e.what() << std::endl;
        return 84;
    } catch (Exception::PinException e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
}