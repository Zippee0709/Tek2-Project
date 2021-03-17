/*
** EPITECH PROJECT, 2020
** PapaXmaxTable.hpp
** File description:
** PapaXmaxTable
*/

#ifndef PAPAXMAXTABLE_HPP_
#define PAPAXMAXTABLE_HPP_

#include "ITable.hpp"
#include "Box.hpp"

class PapaXmaxTable : public ITable
{
	public:
        PapaXmaxTable();
        ~PapaXmaxTable();
        void put(Object &obj);
        Object* take(int index);
        std::string* look();
        int getNbObject() const;
        Object **getObjects() { return this->_object; };
	protected:
	private:
};

ITable *createTable();

#endif /* !PAPAXMAXTABLE_HPP_ */
