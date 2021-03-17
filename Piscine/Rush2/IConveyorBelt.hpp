/*
** EPITECH PROJECT, 2019
** IConveyor.hpp
** File description:
** IConveyor include
*/

#ifndef ICONVEYOR_H_
#define ICONVEYOR_H_
#include "Object.hpp"

class IConveyorBelt {
	public:
    	virtual ~IConveyorBelt() {};
        virtual void put(Object &obj) = 0;
        virtual Object *take() = 0;
};

IConveyorBelt *createConveyorBelt();

#endif