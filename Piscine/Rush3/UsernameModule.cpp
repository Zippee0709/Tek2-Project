/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** UsernameModule
*/

#include <unistd.h>
#include "UsernameModule.hpp"

void UsernameModule::update()
{
    readUsername();
}

void UsernameModule::readUsername()
{
    _username.assign(getlogin());
}