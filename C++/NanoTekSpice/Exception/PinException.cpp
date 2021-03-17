/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** PinException
*/

#include "PinException.hpp"

Exception::PinException::PinException(std::string const &message) throw() : _message(message)
{
}

Exception::PinException::~PinException() throw()
{
}

const char* Exception::PinException::what() const throw ()
{
    return _message.c_str();
}

