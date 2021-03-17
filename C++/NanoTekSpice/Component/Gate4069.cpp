/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Gate4069
*/

#include "Gate4069.hpp"
#include "../Exception/PinException.hpp"
#include "Pin.hpp"

nts::Gate4069::Gate4069(std::string name) : Component(name)
{
    _Pins[1] = new PinNamespace::Pin(1, this, PinNamespace::Input);
    _Pins[2] = new PinNamespace::Pin(2, this, PinNamespace::Output);
    _Pins[3] = new PinNamespace::Pin(3, this, PinNamespace::Input);
    _Pins[4] = new PinNamespace::Pin(4, this, PinNamespace::Output);
    _Pins[5] = new PinNamespace::Pin(5, this, PinNamespace::Input);
    _Pins[6] = new PinNamespace::Pin(6, this, PinNamespace::Output);
    _Pins[7] = new PinNamespace::Pin(7, this, PinNamespace::Input);
    _Pins[8] = new PinNamespace::Pin(8, this, PinNamespace::Output);
    _Pins[9] = new PinNamespace::Pin(9, this, PinNamespace::Input);
    _Pins[10] = new PinNamespace::Pin(10, this, PinNamespace::Output);
    _Pins[11] = new PinNamespace::Pin(11, this, PinNamespace::Input);
    _Pins[12] = new PinNamespace::Pin(12, this, PinNamespace::Output);
    _Pins[13] = new PinNamespace::Pin(13, this, PinNamespace::Input);
    _type = Parser::GATE4069;
}

nts::Gate4069::~Gate4069()
{
}

nts::Tristate nts::Gate4069::compute(std::size_t pin)
{
    if (pin <= 0 || pin > 13)
        throw Exception::PinException("Error: pin doesn't exists");
    switch (pin) {  
        case 2:
            return !(_Pins[1]->getState());
        case 4:
            return !(_Pins[3]->getState());
        case 6:
            return !(_Pins[5]->getState());
        case 8:
            return !(_Pins[9]->getState());
        case 10:
            return !(_Pins[11]->getState());
        case 12:
            return !(_Pins[13]->getState());
        default:
            return _Pins[pin]->getState();
    }
}

void nts::Gate4069::dump() const
{
    std::cout << "DUMP" << std::endl;
}