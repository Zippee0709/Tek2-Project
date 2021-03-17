/*
** EPITECH PROJECT, 2020
** Component.cpp
** File description:
** Component
*/

#include <string>
#include "Component.hpp"
#include "../Exception/PinException.hpp"
#include "Pin.hpp"

nts::Component::Component(std::string name)
{
    this->_name = name;
}

void nts::Component::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    // TODO : Pin déjà set  
    if (_Pins.count(pin) <= 0)
        throw Exception::PinException("This pin doesn't exist.");
    if (this->_Pins[pin]->getType() == other.getSinglePin(otherPin)->getType())
        throw Exception::PinException("Invalid Pin, a pin need to be connect to a diferrent type of pin");
    this->_Pins[pin]->setOtherPin(other.getSinglePin(otherPin));
    other.getSinglePin(otherPin)->setOtherPin(_Pins[pin]);
}

std::map<int, PinNamespace::Pin *> nts::Component::getPins() const
{
    return this->_Pins;
}

PinNamespace::Pin *nts::Component::getSinglePin(std::size_t pinId)
{
    return this->_Pins[pinId];
}

void nts::Component::setPins(int pinNumber, PinNamespace::Pin *pin)
{
    _Pins[pinNumber] = pin;
}

std::string nts::Component::getName() const
{
    return this->_name;
}

nts::Tristate nts::operator!(const nts::Tristate &state) {
    if (state == nts::TRUE)
        return nts::FALSE;
    else if (state == nts::FALSE)
        return nts::TRUE;
    return nts::UNDEFINED;
}

nts::Tristate nts::operator&(const nts::Tristate &state, const nts::Tristate &state2) {
    if (state == nts::TRUE && state2 == nts::TRUE)
        return nts::TRUE;
    else if (state == nts::FALSE || state2 == nts::FALSE)
        return nts::FALSE;
    return nts::UNDEFINED;
}

nts::Tristate nts::operator|(const nts::Tristate &state, const nts::Tristate &state2) {
    if (state == nts::TRUE || state2 == nts::TRUE)
        return nts::TRUE;
    else if (state == nts::FALSE || state2 == nts::FALSE) {
        return nts::FALSE;
    }
    return nts::UNDEFINED;
}

nts::Tristate nts::operatorXOR(const nts::Tristate &state, const nts::Tristate &state2) {
    if (state == nts::TRUE && state2 == nts::TRUE)
        return nts::FALSE;
    else if (state == nts::FALSE && state2 == nts::FALSE)
        return nts::FALSE;
    else if (state == nts::TRUE || state2 == TRUE) {
        return nts::TRUE;
    }
    return nts::UNDEFINED;
}


nts::Tristate nts::Component::compute(std::size_t pin)
{

    std::cout << "COMPUTE" << std::endl;
    return nts::UNDEFINED;
}

void nts::Component::dump() const
{
    std::cout << "DUMP" << std::endl;
}

Parser::Type nts::Component::getType()
{
    return _type;
}


void nts::Component::checkPinLink()
{
    std::map<int, PinNamespace::Pin *>::iterator it =_Pins.begin();

    while (it != _Pins.end()) {
        std::cout << "Pin " << it->first << " from " << _name << (it->second->getOtherPin() ? " component is link to " : " doesn't have link");
            if (it->second->getOtherPin()) {
            std::cout << "Pin " << it->second->getOtherPin()->getId() << " from " <<  (it->second->getOtherPin() ? it->second->getOtherPin()->getActualComponent()->getName() : "NULL")
            << " component" << std::endl;
        } else
            std::cout << std::endl;
    
        it++;
    }
}

void nts::Component::reset()
{
    for (auto const &pin : _Pins) {
        pin.second->setState(nts::Tristate::UNDEFINED);
    }
}
