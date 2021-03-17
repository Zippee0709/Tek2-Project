/*
** EPITECH PROJECT, 2020
** Pin.cpp
** File description:
** Pin
*/

#include <string>
#include "Component.hpp"
#include "Pin.hpp"

PinNamespace::pinType PinNamespace::Pin::getType() const
{
    return _type;
}

nts::Tristate PinNamespace::Pin::getState()
{
    if (_actual->getType() == Parser::Type::INPUT)
        return _state;
    if (_type == PinNamespace::pinType::Output && _state == nts::Tristate::UNDEFINED)
        _state = _actual->compute(_id);
    else if (_type == PinNamespace::pinType::Input &&_state == nts::Tristate::UNDEFINED) {
        _state = _otherPin->getState();
    }
    return _state;
}

nts::Component *PinNamespace::Pin::getActualComponent() const
{
    return _actual;
}

PinNamespace::Pin *PinNamespace::Pin::getOtherPin()
{
    return _otherPin;
}

void PinNamespace::Pin::setState(nts::Tristate value)
{
    _state = value;
}

void PinNamespace::Pin::setOtherPin(Pin *otherPin)
{
    _otherPin = otherPin;
}

std::size_t PinNamespace::Pin::getId()
{
    return _id;
}