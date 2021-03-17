/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** OsModule
*/

#ifndef OSMODULE_HPP_
#define OSMODULE_HPP_
#include "IModuleMonitor.hpp"
#include <sys/utsname.h>

class OsModule : public IModuleMonitor {
	public:
		OsModule();
		~OsModule();
		void readOsName();
		void update();
	protected:
        std::string _osname;
};

#endif /* !OSMODULE_HPP_ */

