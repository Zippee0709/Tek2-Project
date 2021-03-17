/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** False
*/

#include "False.hpp"
#include "../Exception/PinException.hpp"
#include "Pin.hpp"

nts::False::False(std::string name) 
    : Component(name)
{
    _Pins[1] = new PinNamespace::Pin(1, this, PinNamespace::Output);
    _Pins[1]->setState(nts::Tristate::FALSE);
    _type = Parser::Type::FALSE;
}

nts::False::~False()
{
}

nts::Tristate nts::False::compute(std::size_t pin)
{
    if (pin != 1)
        throw Exception::PinException("Error: pin doesn't exists");
    return _Pins[1]->getState();
}