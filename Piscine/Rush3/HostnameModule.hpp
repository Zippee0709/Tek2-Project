/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** HostnameModule
*/

#ifndef HOSTNAMEMODULE_HPP_
#define HOSTNAMEMODULE_HPP_
#include "IModuleMonitor.hpp"
#include "unistd.h"

class HostnameModule : public IModuleMonitor {
	public:
		HostnameModule();
		~HostnameModule();
		void readHostname();
		void update();
	protected:
        std::string _hostname;
};

#endif /* !HOSTNAMEMODULE_HPP_ */

