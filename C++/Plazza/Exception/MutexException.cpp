/*
** EPITECH PROJECT, 2020
** bootstrap_plaza
** File description:
** MutexException
*/

#include "MutexException.hpp"

MutexException::MutexException(std::string const &message) throw() : _message(message)

{
}

MutexException::~MutexException()
{
}

const char* MutexException::what() const throw()
{
    return _message.c_str();
}
