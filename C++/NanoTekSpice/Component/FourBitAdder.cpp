/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** FourBitAdder
*/

#include "FourBitAdder.hpp"
#include "../Exception/PinException.hpp"
#include "Pin.hpp"

nts::FourBitAdder::FourBitAdder(std::string name) 
    : Component(name), C2(nts::UNDEFINED), C3(nts::UNDEFINED), C4(nts::UNDEFINED),
    CO(nts::UNDEFINED)
{
    _Pins[1] = new PinNamespace::Pin(1, this, PinNamespace::Input);
    _Pins[2] = new PinNamespace::Pin(2, this, PinNamespace::Input);
    _Pins[3] = new PinNamespace::Pin(3, this, PinNamespace::Input);
    _Pins[4] = new PinNamespace::Pin(4, this, PinNamespace::Input);
    _Pins[5] = new PinNamespace::Pin(5, this, PinNamespace::Input);
    _Pins[6] = new PinNamespace::Pin(6, this, PinNamespace::Input);
    _Pins[7] = new PinNamespace::Pin(7, this, PinNamespace::Input);
    // _Pins[8] = new PinNamespace::Pin(8, this, PinNamespace::Input);
    _Pins[9] = new PinNamespace::Pin(9, this, PinNamespace::Input);
    _Pins[10] = new PinNamespace::Pin(10, this, PinNamespace::Output);
    _Pins[11] = new PinNamespace::Pin(11, this, PinNamespace::Output);
    _Pins[12] = new PinNamespace::Pin(12, this, PinNamespace::Output);
    _Pins[13] = new PinNamespace::Pin(13, this, PinNamespace::Output);
    _Pins[14] = new PinNamespace::Pin(14, this, PinNamespace::Output);
    _Pins[15] = new PinNamespace::Pin(15, this, PinNamespace::Input);
    _type = Parser::GATE4008;
}

nts::FourBitAdder::~FourBitAdder()
{

}

nts::Tristate nts::FourBitAdder::setCarryOut(const nts::Tristate &state, const nts::Tristate &state2,
    const nts::Tristate &CarryIn, nts::Tristate &CarryOut)
{
    if (state == nts::TRUE && state2 == nts::TRUE && CarryIn == nts::FALSE) {
        CarryOut = nts::TRUE;
        return nts::FALSE;
    } else if (state == nts::TRUE && state2 == nts::TRUE && CarryIn == nts::TRUE) {
        CarryOut = nts::TRUE;
        return nts::TRUE;
    } else if (state == nts::FALSE && state2 == nts::FALSE && CarryIn == nts::TRUE) {
        CarryOut = nts::FALSE;
        return nts::TRUE;
    } else if (state == nts::FALSE && state2 == nts::FALSE && CarryIn == nts::FALSE) {
        CarryOut = nts::FALSE;
        return nts::FALSE;
    } else if (state == nts::TRUE && state2 == nts::FALSE && CarryIn == nts::TRUE) {
        CarryOut = nts::TRUE;
        return nts::FALSE;
    } else if (state == nts::TRUE && state2 == nts::FALSE && CarryIn == nts::FALSE) {
        CarryOut = nts::FALSE;
        return nts::TRUE;
    } else if (state == nts::FALSE && state2 == nts::TRUE && CarryIn == nts::FALSE) {
        CarryOut = nts::FALSE;
        return nts::TRUE;
    } else if (state == nts::FALSE && state2 == nts::TRUE && CarryIn == nts::TRUE) {
        CarryOut = nts::TRUE;
        return nts::FALSE;
    }
    return nts::UNDEFINED;
}

nts::Tristate nts::FourBitAdder::compute(std::size_t pin)
{
    if (pin <= 0 || pin > 14) {
        throw Exception::PinException("Error: pin doesn't exists");
    }
    switch (pin) {
        case 10:
            return setCarryOut(_Pins[6]->getState(), _Pins[7]->getState(),
                    _Pins[9]->getState(), C2);
        case 11:
            if (C2 == nts::UNDEFINED)
                compute(10);
            return setCarryOut(_Pins[4]->getState(), _Pins[5]->getState(),
                    C2, C3);
        case 12:
            if (C3 == nts::UNDEFINED)
                compute(11);
            return setCarryOut(_Pins[2]->getState(), _Pins[3]->getState(),
                    C3, C4);
        case 13:
            if (C4 == nts::UNDEFINED)
                compute(12);
            return setCarryOut(_Pins[15]->getState(), _Pins[1]->getState(),
                    C4, CO);
        case 14:
            if (CO == nts::UNDEFINED)
                compute(13);
            _Pins[14]->setState(CO);
            return CO;
        default:
            return _Pins[pin]->getState();
    }
}

void nts::FourBitAdder::dump() const
{
    std::cout << "DUMP" << std::endl;
}