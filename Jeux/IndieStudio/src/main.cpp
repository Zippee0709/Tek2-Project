/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** main
*/

#include "config.h"
#include "core/Error.hpp"
#include "core/Core.hpp"

int main(void)
{
    Error error;

    try {
        IndieStudio::Core core;
        core.run();
    } catch (const std::exception &e) {
        error.error(e.what());
    }
    return (0);
}