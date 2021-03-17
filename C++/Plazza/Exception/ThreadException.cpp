/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** ThreadException
*/

#include "ThreadException.hpp"

ThreadException::ThreadException(std::string const &message) throw() : _message(message)

{
}

ThreadException::~ThreadException()
{
}

const char* ThreadException::what() const throw()
{
    return _message.c_str();
}
