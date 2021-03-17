/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** IModuleMonitor
*/

#ifndef IMODULEMONITOR_HPP_
#define IMODULEMONITOR_HPP_

#include <iostream>
#include <ctime>

class IModuleMonitor {
	public:
        virtual void update() = 0;
		virtual ~IModuleMonitor() { };
	protected:
	private:
};
#endif /* !IMODULEMONITOR_HPP_ */
