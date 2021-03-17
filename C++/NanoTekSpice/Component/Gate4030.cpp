/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Gate4030
*/

#include "Gate4030.hpp"
#include "../Exception/PinException.hpp"
#include "Pin.hpp"

nts::Gate4030::Gate4030(std::string name) : Component(name)
{
    _Pins[1] = new PinNamespace::Pin(1, this, PinNamespace::Input);
    _Pins[2] = new PinNamespace::Pin(2, this, PinNamespace::Input);
    _Pins[3] = new PinNamespace::Pin(3, this, PinNamespace::Output);
    _Pins[4] = new PinNamespace::Pin(4, this, PinNamespace::Output);
    _Pins[5] = new PinNamespace::Pin(5, this, PinNamespace::Input);
    _Pins[6] = new PinNamespace::Pin(6, this, PinNamespace::Input);
    _Pins[7] = new PinNamespace::Pin(7, this, PinNamespace::Input);
    _Pins[8] = new PinNamespace::Pin(8, this, PinNamespace::Input);
    _Pins[9] = new PinNamespace::Pin(9, this, PinNamespace::Input);
    _Pins[10] = new PinNamespace::Pin(10, this, PinNamespace::Output);
    _Pins[11] = new PinNamespace::Pin(11, this, PinNamespace::Output);
    _Pins[12] = new PinNamespace::Pin(12, this, PinNamespace::Input);
    _Pins[13] = new PinNamespace::Pin(13, this, PinNamespace::Input);
    _type = Parser::GATE4030;
}

nts::Gate4030::~Gate4030()
{
}

nts::Tristate nts::Gate4030::compute(std::size_t pin)
{
    if (pin <= 0 || pin > 13)
        throw Exception::PinException("Error: pin doesn't exists");
    switch (pin) {  
        case 3:
            return operatorXOR(_Pins[1]->getState(), _Pins[2]->getState());
        case 4:
            return operatorXOR(_Pins[5]->getState(), _Pins[6]->getState());
        case 10:
            return operatorXOR(_Pins[8]->getState(), _Pins[9]->getState());
        case 11:
            return operatorXOR(_Pins[12]->getState(), _Pins[13]->getState());
        default:
            return _Pins[pin]->getState();
    }
}

void nts::Gate4030::dump() const
{
    std::cout << "DUMP" << std::endl;
}
