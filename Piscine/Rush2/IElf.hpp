/*
** EPITECH PROJECT, 2020
** IElf.hpp
** File description:
** IElf
*/

#ifndef IELF
#define IELF
#include <iostream>
#include "PapaXmasConveyorBelt.hpp"
#include "PapaXmasTable.hpp"
#include "GiftPaper.hpp"
#include "Object.hpp"

class IElf {
    public:
        virtual void trigger(PapaXmasConveyorBelt::Hand button, Object &obj) = 0;
        virtual void conveyorToTable() = 0;
        virtual void checkComponentTable() = 0;
        virtual void wrap(int, int, int) = 0;
        virtual void tableToConveyor(GiftPaper &newGift) = 0;
        virtual ~IElf() { };
    private:
};

#endif
