/*
** EPITECH PROJECT, 2020
** PapaXmasElf.cpp
** File description:
** PapaXmasElf
*/

#include <string>
#include "Box.hpp"
#include "GiftPaper.hpp"
#include "PapaXmasElf.hpp"
#include "LittlePony.hpp"
#include "Teddy.hpp"

PapaXmasElf::PapaXmasElf() : _conveyor(new PapaXmasConveyorBelt), _table(new PapaXmaxTable)
{
    _conveyor->initConveyor();
}

PapaXmasElf::~PapaXmasElf() {
    if (_conveyor)
        delete _conveyor;
    if (_table)
        delete _table;
}

void PapaXmasElf::trigger(PapaXmasConveyorBelt::Hand button, Object &obj)
{
    this->_conveyor->press_buton(button, obj);
}

void PapaXmasElf::conveyorToTable()
{
    this->_table->put(*(this->_conveyor->take()));
}

void PapaXmasElf::checkComponentTable()
{
    Object *obj;
    int gift = -42;
    int box = -42;
    int toy = -42;
    
    for (int i = 0; i < 10; i++) {
        obj = this->_table->getObjects()[i];
        if (obj != NULL) {
            if ((obj->getType() == Object::TYPE::PONY || obj->getType() == Object::TYPE::TED)
              && toy == -42)
                toy = i;
            if (obj->getType() == Object::TYPE::BOXES && box == -42)
                box = i;
            if (obj->getType() == Object::TYPE::GIFTPAPERS && gift == -42)
                gift = i;
        }
    }
    if (gift != -42 && box != -42 && toy != -42) {
        this->wrap(gift, box, toy);
        return;
    }
    std::cerr << "Wesh y'a pas les composants nécessaires." << std::endl;
    if (this->_table->getNbObject() == 10) {
        std::cerr << "COLLAAAAAAAAAAPPPPSSSSSSSEEEEEEEE" << std::endl;
        this->_table->~PapaXmaxTable();
        this->_table = new PapaXmaxTable();
    }
}

void PapaXmasElf::wrap(int gift, int box, int toy)
{
    Box *newBox = new Box(*(this->_table->getObjects())[box]);
    GiftPaper *newGift = new GiftPaper(*(this->_table->getObjects())[gift]);

    if (this->_table->getObjects()[toy]->getType() == Object::TYPE::PONY) {
        LittlePony *newToy = dynamic_cast<LittlePony*>(this->_table->getObjects()[toy]);
        newToy->isTaken();
    } else {
        Teddy *newToy = dynamic_cast<Teddy*>(this->_table->getObjects()[toy]);
        newToy->isTaken();
    }

    std::cout << "whistles while working" << std::endl;
    newBox->wrapMeThat(this->_table->getObjects()[toy]);
    newBox->closeMe();
    std::cout << "tuuuut tuuut tuut" << std::endl;
    std::cout << "whistles while working" << std::endl;
    newGift->wrapMeThat(newBox);
    std::cout << "tuuuut tuuut tuut" << std::endl;

    delete newBox;
    this->_table->take(gift);
    this->_table->take(toy);
    this->_table->take(box);
    this->tableToConveyor(*newGift);
}

void PapaXmasElf::tableToConveyor(GiftPaper &newGift)
{
    this->_conveyor->put(newGift);
    this->_conveyor->press_buton(PapaXmasConveyorBelt::OUT, newGift);
}