/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Output
*/

#include "Output.hpp"
#include "../Exception/PinException.hpp"
#include "Pin.hpp"

nts::Output::Output(const std::string name)
    : Component(name)
{
    _Pins[1] = new PinNamespace::Pin(1, this, PinNamespace::Input);
    _type = Parser::Type::OUTPUT;
}

nts::Output::~Output()
{
}

nts::Tristate nts::Output::compute(std::size_t pin)
{
    if (pin != 1)
        throw Exception::PinException("Error: pin doesn't exists");
    return _Pins[pin]->getState();
}

void nts::Output::dump() const
{
    std::cout << "DUMP" << std::endl;
}