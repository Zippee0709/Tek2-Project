/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** RamModule
*/

#ifndef RAMMODULE_HPP_
#define RAMMODULE_HPP_

#include <sys/sysinfo.h>
#include <map>
#include "IModuleMonitor.hpp"

class RamModule : public IModuleMonitor {
	public:
		RamModule();

        void update();
        void ReadRam();

		~RamModule();
	protected:
        struct sysinfo sysInfo;
		std::map<std::string, long long> _ram_info;
	private:
};

#endif /* !RAMMODULE_HPP_ */
