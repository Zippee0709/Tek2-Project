/*
** EPITECH PROJECT, 2019
** cpp_rush3_2019
** File description:
** HostnameModule
*/

#include "HostnameModule.hpp"

HostnameModule::HostnameModule()
{
}

HostnameModule::~HostnameModule()
{
}

void HostnameModule::readHostname()
{
    size_t HOST_NAME_MAX = 100;
    
    char hostname[HOST_NAME_MAX];
    gethostname(hostname, HOST_NAME_MAX);
    this->_hostname = hostname;
}

void HostnameModule::update()
{
    readHostname();
}