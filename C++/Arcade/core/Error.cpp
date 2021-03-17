/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Error
*/

#include "Error.hpp"

Error::Error(std::string const &message) throw() : _message(message)
{
}

Error::~Error() throw()
{
}

const char* Error::what() const throw()
{
    return _message.c_str();
}
