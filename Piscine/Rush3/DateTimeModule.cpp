/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** DateTimeModule
*/

#include "DateTimeModule.hpp"

DateTimeModule::DateTimeModule()
{
}

DateTimeModule::~DateTimeModule()
{
}

void DateTimeModule::readDateTime()
{
    _datetime = std::time(nullptr);
}

void DateTimeModule::update()
{
    readDateTime();
}