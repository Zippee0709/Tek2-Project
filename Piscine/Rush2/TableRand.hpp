/*
** EPITECH PROJECT, 2019
** cpp_rush2_2019
** File description:
** TableRand
*/

#ifndef TABLERAND_H_
#define TABLERAND_H_

#include "PapaXmaxTable.hpp"
#include <ctime>

class TableRand {
	public:
		TableRand();
		~TableRand();
		PapaXmaxTable *randTable();
	protected:
	private:
};

#endif