/*
** EPITECH PROJECT, 2020
** cpp_d14a_2019
** File description:
** Errors
*/

#include "Errors.hpp"

NasaError::NasaError(std::string const &message, std::string const &component) : _message(message), _component(component)
{
}

std::string const &NasaError::getComponent() const
{
    return _component;
}

const char* NasaError::what() const throw()
{
    return _message.c_str();
}

MissionCriticalError::MissionCriticalError(std::string const &message, std::string const &component) : NasaError(message, component)
{
}

LifeCriticalError::LifeCriticalError(std::string const &message, std::string const &component) : NasaError(message, component)
{
}

UserError::UserError(std::string const &message, std::string const &component) : NasaError(message, component)
{
}

CommunicationError::CommunicationError(std::string const &message) : NasaError(message, "CommunicationDevice")
{
}