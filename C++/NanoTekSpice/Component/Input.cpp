/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Input
*/

#include "Pin.hpp"
#include "../Exception/PinException.hpp"
#include "Input.hpp"

nts::Input::Input(const std::string name) : Component(name)
{
    _Pins[1] = new PinNamespace::Pin(1, this, PinNamespace::Output);
    _type = Parser::Type::INPUT;
}

nts::Input::~Input()
{
}

nts::Tristate nts::Input::compute(std::size_t pin)
{
    if (pin != 1)
        throw Exception::PinException("Error: pin doesn't exists");
    return _Pins[1]->getState();
}

void nts::Input::dump() const
{
    std::cout << "DUMP" << std::endl;
}