/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** main
*/

#include "Plazza/Plazza.hpp"
#include "Exception/PlazzaException.hpp"

int main(int ac, char **argv)
{
    try {
        PlazzaProject::Plazza plazza;
        plazza.setParameters(ac, argv);
        plazza.start();
        return 0;
    } catch (PlazzaProject::PlazzaException const &e) {
        std::cerr << e.getSpot() << " : " << e.what() << std::endl;
        return 84;
    }   
}