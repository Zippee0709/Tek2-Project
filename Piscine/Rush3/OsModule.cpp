/*
** EPITECH PROJECT, 2019
** cpp_rush3_2019
** File description:
** OsModule
*/

#include "OsModule.hpp"

OsModule::OsModule()
{
}

OsModule::~OsModule()
{
}

void OsModule::readOsName()
{
    struct utsname osname;
    if (uname(&osname) == -1)
        std::cerr << "Failled read OSName" << std::endl;
    this->_osname = osname.sysname;
    // std::cout << "name = " << _osname << std::endl;
}

void OsModule::update()
{
    readOsName();
}