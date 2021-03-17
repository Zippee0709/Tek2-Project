/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** InvalidArgv
*/

#include "InvalidArgv.hpp"

Exception::InvalidArgv::InvalidArgv(std::string const &message) throw() : _message(message)
{
}

Exception::InvalidArgv::~InvalidArgv() throw()
{
}

const char* Exception::InvalidArgv::what() const throw()
{
    return _message.c_str();
}
