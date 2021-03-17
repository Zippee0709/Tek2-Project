/*
** EPITECH PROJECT, 2019
** Conveyor.hpp
** File description:
** Conveyor include
*/

#pragma once
#include "IConveyorBelt.hpp"
#include "PapaXmasConveyorBelt.hpp"
#include "Object.hpp"

class ConveyorBelt : public IConveyorBelt {
	public:
	    ConveyorBelt();
		~ConveyorBelt();
        void put(Object &obj);
        Object *take();
        void initConveyor();
        void send(PapaXmasConveyorBelt &papaconv);
        void receive(Object &obj);
        void print_obj();
        typedef enum hand {IN, OUT} Hand;
        void press_buton(Hand button, Object &obj, PapaXmasConveyorBelt &papaconv);
	protected:
        typedef enum init {YES, NO} Init;
        Init _isInit = NO;
        bool _isEmpty;
        Object *_obj;
};
