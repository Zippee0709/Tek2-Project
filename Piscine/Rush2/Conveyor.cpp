/*
** EPITECH PROJECT, 2019
** Conveyor.cpp
** File description:
** Conveyor functions
*/

#include "Conveyor.hpp"
#include "PapaXmasConveyorBelt.hpp"

ConveyorBelt::ConveyorBelt()
{
    _isEmpty = true;
}

ConveyorBelt::~ConveyorBelt()
{
}

void ConveyorBelt::put(Object &obj)
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

Object *ConveyorBelt::take()
{
    if (_isEmpty == true)
        std::cerr << "Nothing to take on Conveyor Belt" << std::endl;
    else {
        _isEmpty = true;
        return (_obj);
    }
    return (0);
}

void ConveyorBelt::initConveyor()
{
    _isInit = YES;
}

void ConveyorBelt::send(PapaXmasConveyorBelt &papaconv)
{
    if (_isInit == NO || _isEmpty == true)
        std::cout << "You can't press on the OUT button : Init or put something on the conveyor" << std::endl;
    else {
        papaconv.put(*_obj);
        _isEmpty = true;
        _obj = NULL;
    }
}

void ConveyorBelt::receive(Object &obj)
{
    if (_isInit == NO || _isEmpty == false)
        std::cout << "You can't press on the IN button : Init or put something on the conveyor" << std::endl;
    else
        put(obj);
}

void ConveyorBelt::print_obj()
{
    if (_obj == NULL)
        std::cout << "obj vide" << std::endl;
    else
        std::cout << _obj->getTitle() << std::endl;
}

void ConveyorBelt::press_buton(Hand button, Object &obj, PapaXmasConveyorBelt &papaconv)
{
    if (button == IN)
        receive(obj);
    if (button == OUT)
        send(papaconv);
}