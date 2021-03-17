/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Factory
*/

#include "Factory.hpp"

nts::ComponentFactory::ComponentFactory()
{
    _componentPointerFunction[Parser::Type::INPUT] = &ComponentFactory::createInput;
    _componentPointerFunction[Parser::Type::OUTPUT] = &ComponentFactory::createOutput;
    _componentPointerFunction[Parser::Type::CLOCK] = &ComponentFactory::createClock;
    _componentPointerFunction[Parser::Type::TRUE] = &ComponentFactory::createTrue;
    _componentPointerFunction[Parser::Type::FALSE] = &ComponentFactory::createFalse;
    _componentPointerFunction[Parser::Type::GATE4001] = &ComponentFactory::createNorGate;
    _componentPointerFunction[Parser::Type::GATE4030] = &ComponentFactory::create4030;
    _componentPointerFunction[Parser::Type::GATE4069] = &ComponentFactory::create4069;
    _componentPointerFunction[Parser::Type::GATE4071] = &ComponentFactory::createOrGate;
    _componentPointerFunction[Parser::Type::GATE4081] = &ComponentFactory::createAndGate;
    _componentPointerFunction[Parser::Type::GATE4011] = &ComponentFactory::createNandGate;
    _componentPointerFunction[Parser::Type::GATE4008] = &ComponentFactory::createFourBitAdderGate;
}

std::unique_ptr<nts::Component> nts::ComponentFactory::createComponent(Parser::Type componentType, const std::string &name)
{
    return (this->*_componentPointerFunction[componentType])(name);
}

std::unique_ptr<nts::Component> nts::ComponentFactory::createOrGate(const std::string &name) const
{
    return std::make_unique<OrGate>(name);
}

std::unique_ptr<nts::Component> nts::ComponentFactory::createInput(const std::string &name) const
{
    return std::make_unique<Input>(name);
}

std::unique_ptr<nts::Component> nts::ComponentFactory::createOutput(const std::string &name) const
{
    return std::make_unique<Output>(name);
}

std::unique_ptr<nts::Component> nts::ComponentFactory::createTrue(const std::string &name) const
{
    return std::make_unique<True>(name);
}

std::unique_ptr<nts::Component> nts::ComponentFactory::createFalse(const std::string &name) const
{
    return std::make_unique<False>(name);
}

std::unique_ptr<nts::Component> nts::ComponentFactory::createClock(const std::string &name) const
{
    return std::make_unique<Clock>(name);
}

std::unique_ptr<nts::Component> nts::ComponentFactory::createNorGate(const std::string &name) const
{
    return std::make_unique<NorGate>(name);
}


std::unique_ptr<nts::Component> nts::ComponentFactory::create4069(const std::string &name) const
{
    return std::make_unique<Gate4069>(name);
}

std::unique_ptr<nts::Component> nts::ComponentFactory::createAndGate(const std::string &name) const
{
    return std::make_unique<AndGate>(name);
}

std::unique_ptr<nts::Component> nts::ComponentFactory::createNandGate(const std::string &name) const
{
    return std::make_unique<NandGate>(name);
}

std::unique_ptr<nts::Component> nts::ComponentFactory::create4030(const std::string &name) const
{
    return std::make_unique<Gate4030>(name);
}

std::unique_ptr<nts::Component> nts::ComponentFactory::createFourBitAdderGate(const std::string &name) const
{
    return std::make_unique<FourBitAdder>(name);   
}

