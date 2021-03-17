/*
** EPITECH PROJECT, 2019
** IConveyor.cpp
** File description:
** IConveyor functions
*/

#include "PapaXmasConveyorBelt.hpp"

IConveyorBelt *createConveyorBelt()
{
    PapaXmasConveyorBelt *tmp = new PapaXmasConveyorBelt;
    std::cout << "Conveyor Belt test create" << std::endl;
    return (tmp);
}
