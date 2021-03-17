/*
** EPITECH PROJECT, 2019
** Conveyor.cpp
** File description:
** Conveyor functions
*/

#include "PapaXmasConveyorBelt.hpp"

PapaXmasConveyorBelt::PapaXmasConveyorBelt()
{
    _isEmpty = true;
}

PapaXmasConveyorBelt::~PapaXmasConveyorBelt()
{
}

void PapaXmasConveyorBelt::put(Object &obj)
{
    if (_isInit == NO)
        std::cerr << "Conveyor not init" << std::endl;
    if (_isEmpty == false)
        std::cerr << "Conveyor Belt have not place" << std::endl;
    else {
        _isEmpty = false;
        _obj = &obj;
    }
}

Object *PapaXmasConveyorBelt::take()
{
    if (_isEmpty == true)
        std::cerr << "Nothing to take on Conveyor Belt" << std::endl;
    else {
        Object *tmp = _obj;
        _isEmpty = true;
        _obj = NULL;
        return (tmp);
    }
    return (0);
}

void PapaXmasConveyorBelt::initConveyor()
{
    _isInit = YES;
}

void PapaXmasConveyorBelt::send()
{
    if (_isInit == NO || _isEmpty == true)
        std::cout << "You can't press on the OUT button : Init or put something on the conveyor" << std::endl;
    else {
        _isEmpty = true;
        delete _obj;
    }
}

void PapaXmasConveyorBelt::receive(Object &obj)
{
    if (_isInit == NO || _isEmpty == false)
        std::cout << "You can't press on the IN button : Init or put something on the conveyor" << std::endl;
    else
        put(obj);
}

void PapaXmasConveyorBelt::print_obj()
{
    if (_obj == NULL)
        std::cout << "obj vide" << std::endl;
    else
        std::cout << _obj->getTitle() << std::endl;
}

void PapaXmasConveyorBelt::press_buton(Hand button, Object &obj)
{
    if (button == IN)
        receive(obj);
    if (button == OUT)
        send();
}