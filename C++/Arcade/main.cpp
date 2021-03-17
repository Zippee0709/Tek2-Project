/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** main
*/

#include <iostream>
#include <dlfcn.h>
#include "lib/Graphic.hpp"
#include "lib/my_sfml.hpp"
#include "lib/my_ncurses.hpp"
#include "games/Game.hpp"
#include "games/Pacman.hpp"

#include "lib/Key.hpp"
#include "core/Core.hpp"
#include "core/Error.hpp"

int main(int ac, char **av)
{
    try {
        if (ac != 2) {
            std::cerr << "You need to start with one argument" << std::endl;
            return 84;
        }
        try {
            Core core(av[1]);
            core.startArcade();
        } catch (Error e) {
            std::cerr << e.what() << std::endl;
            return 84;
        }
        return 0;
    } catch(...) {
        std::cerr << "Unknown Error Happend." << std::endl;
        return 84;
    }
}