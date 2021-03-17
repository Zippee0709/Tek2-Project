/*
** EPITECH PROJECT, 2020
** PapaXmasElf.hpp
** File description:
** PapaXmasElf
*/

#ifndef PAPAXMASELF
#define PAPAXMASELF
#include <iostream>
#include "PapaXmasConveyorBelt.hpp"
#include "PapaXmasTable.hpp"
#include "GiftPaper.hpp"
#include "IElf.hpp"
#include "Object.hpp"

class PapaXmasElf : public virtual IElf{
    public:
        PapaXmasElf();

        void trigger(PapaXmasConveyorBelt::Hand button, Object &obj);
        void conveyorToTable();
        void checkComponentTable();
        void wrap(int gift, int box, int toy);
        void tableToConveyor(GiftPaper &newGift);

        ~PapaXmasElf();
    private:
        PapaXmasConveyorBelt *_conveyor;
        PapaXmaxTable *_table;
};

#endif
