/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** DateTimeModule
*/

#ifndef DATETIMEMODULE_HPP_
#define DATETIMEMODULE_HPP_

#include "IModuleMonitor.hpp"

class DateTimeModule : public IModuleMonitor {
	public:
		DateTimeModule();

		void update();
		void readDateTime();

		~DateTimeModule();
	protected:
        std::time_t _datetime;
	private:
};

#endif /* !DATETIMEMODULE_HPP_ */
