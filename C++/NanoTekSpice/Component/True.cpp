/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** True
*/

#include "True.hpp"
#include "../Exception/PinException.hpp"
#include "Pin.hpp"

nts::True::True(std::string name)
    : Component(name)
{
    _Pins[1] = new PinNamespace::Pin(1, this, PinNamespace::Output);
    _Pins[1]->setState(nts::Tristate::TRUE);
    _type = Parser::Type::TRUE;
}

nts::True::~True()
{
}

nts::Tristate nts::True::compute(std::size_t pin)
{
    if (pin != 1)
        throw Exception::PinException("Error: pin doesn't exists");
    return _Pins[1]->getState();
}