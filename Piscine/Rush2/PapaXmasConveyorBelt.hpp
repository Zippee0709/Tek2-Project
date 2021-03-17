/*
** EPITECH PROJECT, 2019
** Conveyor.hpp
** File description:
** Conveyor include
*/

#pragma once
#include "IConveyorBelt.hpp"
#include "Object.hpp"

class PapaXmasConveyorBelt : public IConveyorBelt {
	public:
	    PapaXmasConveyorBelt();
		~PapaXmasConveyorBelt();
        void put(Object &obj);
        Object *take();
        void initConveyor();
        void send();
        void receive(Object &obj);
        void print_obj();
        typedef enum hand {IN, OUT} Hand;
        void press_buton(Hand button, Object &obj);
	protected:
        typedef enum init {YES, NO} Init;
        Init _isInit = NO;
        bool _isEmpty;
        Object *_obj;
};
