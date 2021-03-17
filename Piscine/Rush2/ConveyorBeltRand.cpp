/*
** EPITECH PROJECT, 2019
** cpp_rush2_2019
** File description:
** ConveyorBeltRand
*/

#include "ConveyorBeltRand.hpp"
#include "GiftPaper.hpp"

ConveyorBeltRand::ConveyorBeltRand()
{
}

ConveyorBeltRand::~ConveyorBeltRand()
{
}

Wrap *ConveyorBeltRand::randWrap()
{
    std::srand(std::time(nullptr));
    int rand_nbr = 1 + std::rand()/((RAND_MAX + 1u)/2);
    if (rand_nbr == 1) {
        GiftPaper *paper = new GiftPaper;
        return (paper);
    } else {
        Box *boxi = new Box;
        return (boxi);
    }
}