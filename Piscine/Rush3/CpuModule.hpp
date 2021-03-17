/*
** EPITECH PROJECT, 2019
** cpp_rush3_2019
** File description:
** CpuModule
*/

#ifndef CPUMODULE_HPP_
#define CPUMODULE_HPP_

#include "IModuleMonitor.hpp"
#include <sys/sysinfo.h>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <cctype>
#include <map>

class CpuModule : public IModuleMonitor {
	public:
		CpuModule();
		~CpuModule();
		void update();
		void readNbrCpu();
		bool read_cpu_file();
		void fill_cpu_info(std::string name, std::string value);
	protected:
		int _nbr_proc;
		int _conf_nbr_proc;
		std::string _CPU_name;
		std::string _CPU_Mhz;
		std::map<std::string, std::string> _all_cpu_info;
};

#endif /* !CPUMODULE_HPP_ */
