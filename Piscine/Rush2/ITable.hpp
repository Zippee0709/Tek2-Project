/*
** EPITECH PROJECT, 2020
** ITable.hpp
** File description:
** ITable
*/

#ifndef ITABLE
#define ITABLE

#include "Object.hpp"
#include <iostream>
#include <string>

class ITable {
    public:
        ITable();
        virtual ~ITable() = 0;
        virtual void put(Object &obj) = 0;
        virtual Object* take(int index) = 0;
        virtual std::string* look() = 0;
        virtual Object **getObjects() = 0;
    protected:
        Object *_object[10];
    private:
};
#endif
