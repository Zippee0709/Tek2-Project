/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Clock
*/

#include "Clock.hpp"
#include "../Exception/PinException.hpp"
#include "Pin.hpp"

nts::Clock::Clock(std::string name) 
    : Component(name)
{
    _Pins[1] = new PinNamespace::Pin(1, this, PinNamespace::Output);
    _type = Parser::Type::CLOCK;
}

nts::Clock::~Clock()
{
}

nts::Tristate nts::Clock::compute(std::size_t pin)
{
    if (pin != 1)
        throw Exception::PinException("Error: pin doesn't exists");
    return _Pins[1]->getState();
}