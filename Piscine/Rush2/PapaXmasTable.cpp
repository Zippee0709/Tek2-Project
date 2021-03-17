/*
** EPITECH PROJECT, 2020
** PapaXmaxTable.cpp
** File description:
** PapaXmaxTable.cpp
*/

#include "PapaXmasTable.hpp"

PapaXmaxTable::PapaXmaxTable()
{
    int i = 0;
    for (; i < 10; i++)
        _object[i] = NULL;
}

PapaXmaxTable::~PapaXmaxTable()
{
    int i = 0;

    for (i = 0; i < 10; i++) {
        if (_object[i] != NULL)
            delete _object[i];
    }
}

int PapaXmaxTable::getNbObject() const
{
    int i = 0;
    int nb = 0;
    while (i < 10) {
        if (_object[i] != NULL)
            nb++;
        i++;
    }
    return (nb);
}

void PapaXmaxTable::put(Object &obj)
{
    int i = 0;

    for (; i < 10; i++) {
        if (_object[i] == NULL && i < 10) {
            _object[i] = &obj;
            return;
        }
    }
    std::cerr << "Error : no enought place on table" << std::endl;
}

Object* PapaXmaxTable::take(int index)
{
    Object *obj = NULL;

    if (_object[index] == NULL)
        std::cerr << "Error: no object at this index" << std::endl;
    else {
        obj = _object[index];
        _object[index] = NULL;
    }
    return (obj);
}

std::string* PapaXmaxTable::look()
{
    int i = 0;
    int j = 0;
    int size = getNbObject();
    std::string *tab_name = nullptr;
    if (size != 0) {
        tab_name = new std::string[size + 1];
        for (i = 0; i < 10; i++) {
            if (_object[i] != NULL) {
                tab_name[j] = _object[i]->getTitle();
                j++;
            }
        }
    } else {
        std::cerr << "Error : no object on table" << std::endl;
    }
    return (tab_name);
}

ITable *createTable()
{
    PapaXmaxTable *tab = new PapaXmaxTable;
    return (tab);
}