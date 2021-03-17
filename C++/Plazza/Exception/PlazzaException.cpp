/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** PlazzaException
*/

#include "PlazzaException.hpp"

namespace PlazzaProject {

PlazzaException::PlazzaException(std::string const &message, std::string const &spot) : _message(message), _spot(spot)
{
}

std::string const &PlazzaException::getSpot() const
{
    return _spot;
}

const char * PlazzaException::what() const throw ()
{
    return _message.c_str();
}

MainParsingError::MainParsingError(std::string const &message, std::string const &spot) : PlazzaException(message, spot)
{
}

ReceptionError::ReceptionError(std::string const &message, std::string const &spot) : PlazzaException(message, spot)
{
}

PizzaTypeError::PizzaTypeError(std::string const &message, std::string const &spot) : ReceptionError(message, spot)
{
}

PizzaSizeError::PizzaSizeError(std::string const &message, std::string const &spot) : ReceptionError(message, spot)
{
}

PizzaNumberError::PizzaNumberError(std::string const &message, std::string const &spot) : ReceptionError(message, spot)
{
}

KitchenError::KitchenError(std::string const &message, std::string const &spot) : PlazzaException(message, spot)
{
}

}